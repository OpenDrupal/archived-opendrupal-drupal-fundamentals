var gulp = require('gulp'),
  $ = require('gulp-load-plugins')(),

// Non gulp specific plugins.
  del = require('del');

gulp.task('sass-compile', function () {
  return gulp.src('static/sass/**/*.s+(a|c)ss') // Gets all files ending
    .pipe($.sass())
    .on('error', function (err) {
      console.log(err);
      this.emit('end');
    })
    .pipe($.autoprefixer({
      browsers: ['ie 8-9', 'last 2 versions']
    }))
    .pipe(gulp.dest('static/css'));
});

/**
 * @task js
 * Do javascript stuff.
 */
gulp.task('js', function () {
  return gulp.src(['static/js/**/*.js', '!static/js/lib/*.js'])
    .pipe($.jshint())
    .pipe($.jshint.reporter('default'))
    .pipe($.uglify());
});

/**
 * @task clean
 * Clean the dist folder.
 */
gulp.task('clean', function () {
  return del(['static/css/*']);
});

/**
 * @task watch
 * Watch files and do stuff.
 */
gulp.task('watch', ['clean', 'sass-compile', 'js'], function () {
  gulp.watch('static/sass/**/*.+(scss|sass)', ['sass-compile']);
  gulp.watch('static/js/**/*.js', ['js']);
});

/**
 * @task default
 * Watch files and do stuff.
 */
gulp.task('default', ['watch']);
