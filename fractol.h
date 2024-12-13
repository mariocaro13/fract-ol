/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 06:58:17 by mcaro-ro          #+#    #+#             */
/*   Updated: 2024/12/13 20:05:25 by mcaro-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/** INCLUDES */
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

/** WINDOW */
# define WIDTH 800
# define HEIGHT 800

/** LOGIC */
# define MIN_ITERATIONS 5
# define ESCAPE_VALUE 4
# define COMPLEX_MIN -2.0
# define COMPLEX_MAX 2.0

/** ERRORS DEFINITIONS */
# define MALLOC_ERROR 1
# define USAGE "Usage: ./fractol [mandelbrot | burning_ship | julia <r> <i>]\n"

/** FRACTALS NAMES */
# define JULIA "julia"
# define MANDELBROT "mandelbrot"
# define BURNING_SHIP "burning_ship"

/** COLORS */
# define RED 0X000FF0000
# define GREEN 0X0000FF00
# define BLUE 0X0000FF
# define BLACK 0X000000
# define WHITE 0XFFFFFF
# define PINK 0XFF1493
# define ORANGE 0XFFA500
# define YELLOW 0XFFFF66

/** struct s_complex:
 * 	- Data structure for representing complex numbers.
 *
 * Params:
 *	@r: The real part of the complex number.
 *	@i: The imaginary part of the complex number.
 *
 * Description:
 *  This structure is used to represent complex numbers,
 * 	which consist of a real part and an imaginary part.
 *
 * Example usage:
 *  t_complex z;
 *  z.r = 1.0;
 *  z.i = 2.0;
 *  // z now represents the complex number 1.0 + 2.0i
 */
typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

/** struct s_img_data:
 * 	- Data structure for storing image information.
 *
 * Params:
 *	@ptr: Pointer to the image object.
 *	@pixels_ptr: Pointer to the pixel data of the image.
 *	@bits_per_pixel: The number of bits per pixel in the image.
 *	@line_length: The length of a line in bytes.
 *	@endian: The endian type of the image data (0 for little-endian,
 * 	1 for big-endian).
 *
 * Description:
 * 	Holds the information needed to manage and manipulate an image
 *  in memory. It includes a pointer to the image object, a pointer
 * 	to the raw pixel data, the number of bits per pixel,
 * 	the length of each line of pixels in bytes,
 * 	and the endian type of the image.
 *
 * Example usage:
 *  t_img_data img;
 *  img.ptr = mlx_new_image(connection, WIDTH, HEIGHT);
 *  img.pixels_ptr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel,
 * 	&img.line_length, &img.endian);
 *  // Use img for drawing or manipulating image data...
 */
typedef struct s_img_data
{
	void		*ptr;
	char		*pixels_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img_data;

/** struct s_fractal:
 * - Data structure for storing fractal parameters and resources.
 *
 * Params:
 *	@name: The name of the fractal.
 *	@mlx_connection: Pointer to the MiniLibX connection object.
 *	@mlx_window: Pointer to the MiniLibX window object.
 *	@img: Image data structure containing information about the fractal image.
 *	@num_of_iterations: Number of iterations for computing the fractal.
 *	@offset: Offset in for fractal positioning.
 *	@zoom: Zoom level for the fractal.
 *	@mouse: Complex for save mouse position.
 *	@init_point: Initial point for the fractal (Used for Julia set).
 *
 * Description:
 *  This structure holds all the necessary parameters and resources required
 *  for rendering and manipulating a fractal using the MiniLibX library. It
 *  includes the fractal's name, connection and window objects for MiniLibX,
 *  an image data structure for the fractal image, and parameters such as the
 *  number of iterations, offsets, and zoom level.
 *
 * Example usage:
 *  t_fractal fractal;
 *  fractal.name = "Mandelbrot";
 *  fractal.num_of_iterations = 1000;
 *  fractal.offset_x = 0.0;
 *  fractal.offset_y = 0.0;
 *  fractal.zoom = 1.0;
 *	fractal.init_point.r = 0.0;
 *  fractal.init_point.i = 0.0;
 *  // Initialize other fields and use fractal in computations...
 */
typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	int			num_of_iterations;
	double		zoom;
	t_img_data	img;
	t_complex	offset;
	t_complex	mouse;
	t_complex	init_point;
}				t_fractal;

/** MAIN */
/** main
 * 	- Entry point of the program.
 *
 * Params:
 * 	@param argc: Number of command-line arguments.
 * 	@param argv: Array of command-line arguments.
 *
 * Description:
 * 	This program accepts different fractals as arguments.
 * 	It can accept:
 * 	- MANDELBROT or BURNING_SHIP with 2 arguments (the fractal name).
 * 	- JULIA with 4 arguments (the fractal name and two floating-point numbers).
 *
 * 	The program validates the arguments and initializes the fractal.
 * 	For the JULIA fractal,
 * 	it also initializes the points with floating-point numbers.
 * 	It renders the fractal and enters the MiniLibX event loop.
 * 	If the arguments are not valid, the program exits with an error.
 *
 * Helper functions:
 *  - ft_strcmp: Compares two strings.
 *  - ft_init(t_fractal *fractal): Initializes the fractal.
 *  - ft_atoi_float(char *str): Converts a string to a floating-point number.
 *  - ft_exit_failure(void): Handles the failure case and exits the program.
 *  - ft_render(t_fractal *fractal): Renders the fractal.
 *  - mlx_loop(void *mlx_connection): Enters the MiniLibX event loop.
 *  - ft_mlx_clean(t_fractal *fractal): Cleans up resources.
 *
 * Example usage:
 *  ./fractal MANDELBROT
 *  ./fractal JULIA 0.285 0.01
 *  // This will initialize and render the specified fractal.
 *
 * Return:
 *  EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int			main(int argc, char **argv);

/** UTILS */
/** ft_exit_failure:
 * 	- Handles failure cases and exits the program.
 *
 * Description:
 * This function handles failure scenarios within the program.
 * It prints a usage message to the standard error output,
 * then exits the program with a failure status.
 * This is typically used when an error condition is detected
 *  and the program cannot continue execution safely.
 *
 * Helper functions:
 *  - ft_putstr_fd(const char *s, int fd):
 * 		Writes a string to the given file descriptor.
 *
 * Example usage:
 *  if (error_condition)
 *      ft_exit_failure();
 *
 * Return:
 *  This function does not return a value as it exits the program.
 */
void		ft_exit_failure(void);

/** STRINGS UTILS */
/** ft_isdigit:
 *  - Checks if the given character is a digit (0-9).
 *
 * Params:
 *  @c: The character to be checked.
 *
 * Description:
 *  This function checks if the given character `c` is a digit,
 *  which means it falls within the range of '0' to '9' in the ASCII table.
 *  It returns a non-zero value if `c` is a digit, and 0 if it is not.
 *
 * Example usage:
 *  int result = ft_isdigit('5');
 *  // result will be non-zero because '5' is a digit.
 *
 * Return:
 *  A non-zero value if `c` is a digit, and 0 if it is not.
 */
int			ft_isdigit(int c);

/** ft_strcmp:
 * 	- Compares characters of two strings.
 *
 * Params:
 *	@s1: The first string to compare.
 *	@s2: The second string to compare.
 *
 * Description:
 *  This function compares characters of the null-terminated strings s1
 *  and s2. The comparison is done lexicographically.
 * 	If the strings are identical, the function returns 0.
 * 	If they differ, the function returns the difference between
 * 	the first differing characters (treated as unsigned char values).
 *
 *  The comparison stops as soon as a differing character is found or if the
 *  end of either string is reached.
 *
 * Example usage:
 *  const char *str1 = "Hello";
 *  const char *str2 = "Helium";
 *  int result = ft_strcmp(str1, str2);
 *  // result will be 1 because the strings are not identical
 *
 * Return:
 *  An integer less than, equal to, or greater than zero if the
 *  characters of s1 are found to be less than, to match, or be greater than
 *  the characters of s2, respectively.
 */
int			ft_strcmp(const char *s1, const char *s2);

/** ft_putstr_fd:
 * 	- Writes a string to a file descriptor.
 *
 * Params:
 * 	@s: The string to be written.
 *	@fd: The file descriptor to write to.
 *
 * Description:
 *  This function writes the null-terminated string s to the file descriptor fd.
 *  It iterates through each character of the string and writes it one by one
 *  using the write system call.
 *
 * Example usage:
 *  char *str = "Hello, World!";
 *  int fd = 1; // 1 is the file descriptor for standard output
 *  ft_putstr_fd(str, fd);
 *  // This will print "Hello, World!" to the standard output
 *
 * Return:
 *  This function does not return a value.
 */
void		ft_putstr_fd(char *s, int fd);

/** ft_atoi_float:
 *  - Converts a string to a floating-point number.
 *
 * Params:
 *  @str: The string to be converted.
 *
 * Description:
 *  This function converts a null-terminated string to a floating-point number.
 *  It handles optional signs and decimal points.
 *  The function first parses the integer part of the number,
 *  then the decimal part,
 *  and finally combines them to produce the resulting floating-point number.
 * 	If the string contains invalid characters, calls ft_exit_failure.
 *
 * Helper functions:
 *  - isdigit(int c): Checks if the character is a digit (0-9).
 *  - ft_exit_failure(void): Handles the failure case and exits the program.
 *
 * Example usage:
 *  char *str = "   -123.456";
 *  double num = ft_atoi_float(str);
 *  // num will be -123.456
 *
 * Return:
 *  The converted floating-point number (double).
 */
double		ft_atoi_float(const char *str);

/** MINILIBX-LINUX */
/** ft_mlx_init:
 * - Initializes the MiniLibX connection and window.
 *
 * Params:
 * @mlx: Pointer to the fractal data structure.
 *
 * Description:
 * 	This function sets up the connection to the MiniLibX,
 * 	and creates a new window.
 * 	If the connection or window creation fails, it cleans up
 * 	any allocated resources and returns an error code.
 *
 * Specifically, the function:
 * 	- Establishes a connection to MiniLibX.
 * 	- Creates a new window with specified width, height, and title.
 * 	- Cleans up allocated resources if any step fails.
 *
 * Helper functions:
 * 	- ft_mlx_clean(void *mlx_connection, void *mlx_window):
 * 		Cleans up MiniLibX resources in case of failure.
 *
 * Constants:
 * 	- WIDTH: The width of the window.
 * 	- HEIGHT: The height of the window.
 * 	- MALLOC_ERROR: The error code returned when memory allocation fails.
 * 	- EXIT_SUCCESS: The success code returned when initialization is successful.
 *
 * Example usage:
 * 	t_fractal fractal;
 * 	int result = ft_mlx_init(&fractal);
 * 	if (result == EXIT_SUCCESS) {
 * 	// MiniLibX initialized successfully
 * 	} else {
 * 	// Handle initialization error
 * 	}
 *
 * Return:
 * 	EXIT_SUCCESS on successful initialization,
		or MALLOC_ERROR if a failure occurs.
 * */
int			ft_mlx_init(t_fractal *mlx);

/** ft_mlx_img_init:
 * 	- Initializes the MiniLibX image buffer.
 *
 * Params:
 * 	@mlx: Pointer to the fractal data structure.
 *
 * Description:
 * This function creates a new image buffer in MiniLibX,
 * and retrieves the pixel data address of the image buffer.
 * If the image creation fails, it cleans up any allocated resources,
 * and returns an error code. *
 *
 * Specifically, the function:
 * 	- Creates a new image buffer with specified width and height.
 * 	- Retrieves the pixel data address of the image buffer.
 * 	- Cleans up allocated resources if image creation fails.
 *
 * Helper functions:
 * 	- ft_mlx_clean(void *mlx_connection, void *mlx_window):
 * 		Cleans up MiniLibX resources in case of failure.
 *
 * Constants:
 * 	- WIDTH: The width of the image.
 * 	- HEIGHT: The height of the image.
 * 	- MALLOC_ERROR: The error code returned when memory allocation fails.
 * 	- EXIT_SUCCESS: The success code returned when initialization is successful.
 *
 * Example usage:
 * 	t_fractal fractal;
 * 	int result = ft_mlx_img_init(&fractal);
 * 	if (result == EXIT_SUCCESS) {
 * 	//MiniLibX image buffer initialized successfully
 * 	} else {
 * 	// Handle initialization error
 * 	}
 *
 * Return:
 * 	EXIT_SUCCESS on successful initialization, or MALLOC_ERROR if failure.
 * */
int			ft_mlx_img_init(t_fractal *mlx);

/** ft_mlx_clean:
 * 	- Cleans up MiniLibX resources.
 *
 * Params:
 *	@fractal: Pointer to the fractal with the MiniLibX connection object.
 *
 * Description:
 * 	This function cleans up the resources allocated by MiniLibX.
 * 	It first checks if the window pointer is not NULL, and if so,
 * 	it destroys the img and the window, and then the display associated
 * 	with the connection and frees the connection object itself.
 *
 * Example usage:
 * 	void *mlx_connection = mlx_init();
 * 	void *mlx_window = mlx_new_window(mlx_connection, 800, 600, "Fractal");
 * 	// Perform operations with the window...
 * 	ft_mlx_clean(mlx_connection, mlx_window);
 * 	// This will destroy the window, display, and free the connection.
 *
 * Return:
 * 	This function does not return a value.
 * */
void		ft_mlx_clean(t_fractal *fractal);

/** ft_offset:
 * 	- Computes the memory offset for a pixel in an image.
 *
 * Params:
 *	@x: The x-coordinate of the pixel.
 *	@y: The y-coordinate of the pixel.
 *	@line_length: The length of a line in bytes.
 *	@bits_per_pixel: The number of bits per pixel.
 *
 * Description:
 *  This function calculates the offset for a pixel in an image buffer,
 *  given its coordinates, the line length, and the number of bits per pixel.
 *  It returns the offset in bytes where the pixel's data is located.
 *
 * Example usage:
 *  int x = 10;
 *  int y = 5;
 *  int line_length = 800;
 *  int bpp = 32;
 *  int offset = ft_offset(x, y, line_length, bpp);
 *  // offset will be the byte position of the pixel at (10,
	5) in the image buffer
 *
 * Return:
 *  The memory offset in bytes for the specified pixel.
 */
int			ft_offset(int x, int y, int line_length, int bits_per_pixel);

/** ft_mlx_pixel_put:
 * 	- Sets the color of a pixel in the image.
 *
 * Params:
 *	@x: The x-coordinate of the pixel.
 *	@y: The y-coordinate of the pixel.
 *	@img: Pointer to the image data structure.
 *	@color: The color to set the pixel to (as an integer).
 *
 * Description:
 *  This function sets the color of a specific pixel in the image buffer.
 *  It calculates the memory offset for the pixel using the coordinates,
 *  line length, and bits per pixel, then sets the pixel's color at that
 *  offset in the image data.
 *
 * Helper functions:
 *  - ft_offset(int x, int y, int line_length, int bits_per_pixel):
 *      Computes the memory offset of the pixel in the image data.
 *
 * Example usage:
 *  t_img_data img;
 *  // Initialize img, set line_length, bits_per_pixel, and pixels_ptr...
 *  int x = 10;
 *  int y = 5;
 *  int color = 0XFFFFFF; // White color
 *  ft_mlx_pixel_put(x, y, &img, color);
 *  // This sets the pixel at (10, 5) to white
 *
 * Return:
 *  This function does not return a value.
 */
void		ft_mlx_pixel_put(int x, int y, t_img_data *img, int color);

/** MINILIBX EVENTS */
/** ft_events_init:
 * 	- Initializes event hooks for the fractal window.
 *
 * Params:
 *	@fractal: Pointer to the fractal data structure.
 *
 * Description:
 * 	This function sets up event hooks for the fractal window
 * 	using the MiniLibX library.
 *  It attaches handlers for key presses, mouse button presses,
 *	and window close events.
 *
 *  Specifically, it hooks the following events:
 *  - KeyPress: Triggers when a key is pressed.
 *  - ButtonPress: Triggers when a mouse button is pressed.
 *  - DestroyNotify: Triggers when the window is closed.
 *
 * Helper functions:
 *  - ft_mlx_handle_key(int keycode, t_fractal *fractal):
 *      Handles key press events.
 *
 *  - ft_mlx_handle_mouse(int button, int x, int y, t_fractal *fractal):
 *      Handles mouse button press events.
 *
 *  - ft_mlx_handle_close(t_fractal *fractal):
 *      Handles window close events.
 *
 * Example usage:
 *  t_fractal fractal;
 *  // Initialize fractal, create window, etc.
 *  ft_events_init(&fractal);
 *  // This will set up event handlers for key presses, mouse presses,
 * 	and window close events.
 *
 * Return:
 *  This function does not return a value.
 */
void		ft_events_init(t_fractal *fractal);

/** ft_mlx_handle_key:
 * 	- Handles key press events for fractal manipulation.
 *
 * Params:
 *	@keysym: The key symbol of the pressed key.
 *	@fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function handles key press events to manipulate the fractal's view and
 *  parameters. It supports moving the view, zooming in and out, and adjusting
 *  the number of iterations for the fractal computation.
 *
 *  Specifically, it handles the following key events:
 *  - XK_Escape: Closes the fractal window.
 *  - XK_Right: Moves the view to the right.
 *  - XK_Left: Moves the view to the left.
 *  - XK_Up: Moves the view up.
 *  - XK_Down: Moves the view down.
 *  - XK_equal or XK_plus: Increases the number of iterations.
 *  - XK_minus: Decreases the number of iterations.
 *
 * Helper functions:
 *  - ft_mlx_handle_close(t_fractal *fractal):
 *      Handles the event of closing the fractal window.
 *  - ft_fractal_render(t_fractal *fractal):
 *      Renders the fractal with the current parameters.
 *
 * Constants:
 *  - XK_Escape: The key symbol for the Escape key.
 *  - XK_Right: The key symbol for the Right Arrow key.
 *  - XK_Left: The key symbol for the Left Arrow key.
 *  - XK_Up: The key symbol for the Up Arrow key.
 *  - XK_Down: The key symbol for the Down Arrow key.
 *  - XK_equal: The key symbol for the '=' key.
 *  - XK_plus: The key symbol for the '+' key.
 *  - XK_minus: The key symbol for the '-' key.
 *  - EXIT_SUCCESS: The success code returned after handling the key event.
 *
 * Example usage:
 *  t_fractal fractal;
 *  int key = XK_Right;
 *  ft_mlx_handle_key(key, &fractal);
 *	// This will move the view to the right,
 *	and render the fractal with the updated parameters.
 *
 * Return:
 *  EXIT_SUCCESS on successful handling of the key event.
 */
int			ft_mlx_handle_key(int keysym, t_fractal *fractal);

/** ft_mlx_handle_mouse:
 * 	- Handles mouse button press events for fractal manipulation.
 *
 * Params:
 *	@button: The mouse button pressed.
 *	@x: The x-coordinate of the mouse event.
 *	@y: The y-coordinate of the mouse event.
 * 	@fractal: Pointer to the fractal data structure.
 *
 * Description:
 *	This function handles mouse buttons events to manipulate the fractal's zoom.
 *  It supports zooming in and out based on the mouse button pressed.
 *
 *  Specifically, it handles the following mouse button events:
 *  - Button4: Zooms out (scroll up).
 *  - Button5: Zooms in (scroll down).
 *
 *	The function also updates the fractal rendering after adjusting the zoom.
 *
 * Helper functions:
 *  - ft_fractal_render(t_fractal *fractal):
 *      Renders the fractal with the current parameters.
 *
 * Constants:
 *  - Button4: The mouse button constant for scrolling up.
 *  - Button5: The mouse button constant for scrolling down.
 *  - EXIT_SUCCESS: The success code returned after handling the mouse event.
 *
 * Example usage:
 *  t_fractal fractal;
 *  int button = Button4;
 *  int x = 100;
 *  int y = 200;
 *  ft_mlx_handle_mouse(button, x, y, &fractal);
 *  // This will zoom out the fractal and render it with the updated zoom level.
 *
 * Return:
 *  EXIT_SUCCESS on successful handling of the mouse event.
 */
int			ft_mlx_handle_mouse(int button, int x, int y, t_fractal *fractal);

/** ft_mlx_handle_close:
 *	- Handles the event of closing the fractal window.
 *
 * Params:
 * 	@mlx: Pointer to the fractal data structure.
 *
 * Description:
 * 	This function handles the event of closing the fractal window.
 * 	It cleans up the resources allocated by MiniLibX and exits the program.
 * 	The function calls 'ft_mlx_clean', to destroy the window and free the @mlx.
 * 	After cleaning up the resources, it exits the program with a success status.
 *
 * Helper functions:
 * - ft_mlx_clean(void *connection, void *window):
 * 		Cleans up MiniLibX resources.
 *
 * Example usage:
 * 	t_fractal fractal;
 * // Initialize fractal, create window, etc.
 * ft_mlx_handle_close(&fractal);
 * // This will clean up resources and exit the program successfully.
 *
 * Return:
 * 	EXIT_SUCCESS after handling the close event and cleaning up resources.
 * */
int			ft_mlx_handle_close(t_fractal *mlx);

/** MATH UTILS */
/** ft_sum_complex:
 * 	- Computes the sum of two complex numbers.
 *
 * Params:
 * 	@z1: The first complex number.
 * 	@z2: The second complex number.
 *
 * Description:
 *  This function takes two complex numbers as input and returns their sum.
 *  The real and imaginary parts of the result are computed by adding the
 *  corresponding parts of the input complex numbers.
 *
 *  The result is a new complex number that represents the sum of the two
 *  input complex numbers.
 *
 * Example usage:
 *  t_complex z1 = { z1.r = 1.0, z1.i = 2.0 };
 *  t_complex z2 = { z2.r = 3.0, z2.i = 4.0 };
 *  t_complex result = ft_sum_complex(z1, z2);
 *  // result.r will be 4.0, result.i will be 6.0
 *
 * Return:
 *  A new complex number representing the sum of z1 and z2.
 */
t_complex	ft_sum_complex(t_complex z1, t_complex z2);

/** ft_square_complex:
 * 	- Computes the square of a complex number.
 *
 * Params:
 * 	@z: The complex number to be squared.
 *
 * Description:
 *  This function takes a complex number as input and returns its square.
 *  The real part of the result is computed as (z.r * z.r) - (z.i * z.i),
 *  and the imaginary part is computed as 2 * z.r * z.i.
 *
 *  The result is a new complex number that represents the square of the
 *  input complex number.
 *
 * Example usage:
 *  t_complex z = { z.r = 1.0, z.i = 2.0 };
 *  t_complex result = ft_square_complex(z);
 *  // result.r will be -3.0, result.i will be 4.0
 *
 * Return:
 *  A new complex number representing the square of z.
 */
t_complex	ft_square_complex(t_complex z);

/** ft_square_complex_abs_i:
 *  - Squares a complex number and returns the result with the imaginary part
 *    taken as the absolute value.
 *
 * Params:
 *  @z: The complex number to be squared.
 *
 * Description:
 *  This function takes a complex number `z`, squares it,
 * 	and returns a new complex number where the real part is:
 * 		'(z.r * z.r) - (z.i * z.i)'
 * 	and the imaginary part is the absolute value of '(2 * z.r * z.i)'.
 *
 * Example usage:
 *  t_complex z;
 *  z.r = 3;
 *  z.i = 4;
 *  t_complex result = ft_square_complex_abs_i(z);
 *  // result.r will be -7 and result.i will be 24 (absolute value of -24).
 *
 * Return:
 *  The squared complex number with the imaginary part taken as absolute value.
 */
t_complex	ft_square_complex_abs_i(t_complex z);

/** ft_hypotenuse:
 * 	- Computes the hypotenuse of a right triangle.
 *
 * Params:
 * 	@x: The length of the first leg of the triangle.
 * 	@y: The length of the second leg of the triangle.
 *
 * Description:
 *  This function calculates the hypotenuse of a right triangle given the
 *  lengths of its two legs using the Pythagorean theorem. The result is
 *  computed as (x * x) + (y * y).
 *
 * Example usage:
 *  double x = 3.0;
 *  double y = 4.0;
 *  int hypotenuse = ft_hypotenuse(x, y);
 *  // hypotenuse will be 25 (3^2 + 4^2)
 *
 * Return:
 *  The squared length of the hypotenuse.
 */
int			ft_hypotenuse(double x, double y);

/** ft_map:
 * 	- Maps a value from one range to another.
 *
 * Params:
 * 	@input: The value to be mapped.
 * 	@new_min: The minimum value of the new range.
 * 	@new_max: The maximum value of the new range.
 * 	@old_max: The maximum value of the original range (assumes old_min is 0).
 *
 * Description:
 *  This function maps a value from the range [0, old_max] to the range
 *  [new_min, new_max]. It is useful for normalizing values or converting
 *  them to different scales.
 *
 * Example usage:
 *  int value = 50;
 *  double new_min = 0.0;
 *  double new_max = 1.0;
 *  double old_max = 100.0;
 *  double result = ft_map(value, new_min, new_max, old_max);
 *  // result will be 0.5
 *
 * Return:
 *  The mapped value in the range [new_min, new_max].
 */
double		ft_map(int input, double new_min, double new_max, double old_max);

/** VIEW CONTROL */
/** ft_move_up:
 *  - Moves the view of the fractal upwards.
 *
 * Params:
 *  @fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function adjusts the vertical offset to move the view upwards. It takes
 *  into account the fractal type to ensure correct movement direction. For the
 *  Burning Ship fractal, the offset is decreased to move the view up. For other
 *  fractals, the offset is increased to move the view up. After adjusting the
 *  offset, the fractal is re-rendered.
 *
 *  Specifically, the function:
 *  - Checks the fractal type.
 *  - Adjusts the vertical offset based on the fractal type.
 *  - Calls ft_render to re-render the fractal.
 *
 * Return:
 *  None.
 */
void		ft_move_up(t_fractal *fractal);

/** ft_move_down:
 *  - Moves the view of the fractal downwards.
 *
 * Params:
 *  @fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function adjusts the vertical offset to move the view downwards.
 * 	It takes into account the fractal type to ensure correct movement direction.
 * 	For the Burning Ship fractal, the offset is increased to move the view down.
 * 	For other fractals, the offset is decreased to move the view down.
 * 	After adjusting the offset, the fractal is re-rendered.
 *
 *  Specifically, the function:
 *  - Checks the fractal type.
 *  - Adjusts the vertical offset based on the fractal type.
 *  - Calls ft_render to re-render the fractal.
 *
 * Return:
 *  None.
 */
void		ft_move_down(t_fractal *fractal);

/** ft_move_right:
 *  - Moves the view of the fractal to the right.
 *
 * Params:
 *  @fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function adjusts the horizontal offset to move the view to the right.
 *  The offset is increased to move the view right. After adjusting the offset,
 *  the fractal is re-rendered.
 *
 *  Specifically, the function:
 *  - Adjusts the horizontal offset.
 *  - Calls ft_render to re-render the fractal.
 *
 * Return:
 *  None.
 */
void		ft_move_right(t_fractal *fractal);

/** ft_move_left:
 *  - Moves the view of the fractal to the left.
 *
 * Params:
 *  @fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function adjusts the horizontal offset to move the view to the left.
 *  The offset is decreased to move the view left. After adjusting the offset,
 *  the fractal is re-rendered.
 *
 *  Specifically, the function:
 *  - Adjusts the horizontal offset.
 *  - Calls ft_render to re-render the fractal.
 *
 * Return:
 *  None.
 */
void		ft_move_left(t_fractal *fractal);

/** FRACTAL */
/** ft_data_init:
 * 	- Initializes the data structure for fractal computations.
 *
 * Params:
 * 	@fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function initializes the fields of the fractal data structure with
 *  default values. It sets the number of iterations, the offset values for
 *  both x and y coordinates, the zoom level, and the initial point.
 *
 *  The number of iterations is set to NUM_OF_ITERATIONS, which determines
 *  the depth of the fractal computation. The offset values are set to 0.0,
 *  positioning the fractal at the origin. The zoom level is set to 1.0,
 *  representing no zoom.
 *
 * Example usage:
 *  t_fractal fractal;
 *  ft_data_init(&fractal);
 *  // fractal.num_of_iterations will be initialized to NUM_OF_ITERATIONS
 *  // fractal.offset_x will be 0.0
 *  // fractal.offset_y will be 0.0
 *  // fractal.zoom will be 1.0
 * 	// fractal.init_point.r will be 0.0
 *  // fractal.init_point.i will be 0.0
 *
 * Return:
 *  This function does not return a value.
 */
void		ft_data_init(t_fractal *fractal);

/** ft_init:
 * 	- Initializes the fractal data structure and related resources.
 *
 * Params:
 * 	@mlx: Pointer to the fractal data structure.
 *
 * Description:
 * Initializes the fractal data structure,
 * creates a connection to the MiniLibX library,
 * and sets up the necessary resources for rendering the fractal.
 * It initializes the fractal parameters,
 * creates a window, and sets up the image buffer.
 * If any step fails, cleans up the allocated resources and returns an error.
 *
 * Specifically, the function:
 * 	- Initializes the fractal data structure with default values.
 * 	- Creates a connection to MiniLibX.
 * 	- Creates a new window for rendering the fractal.
 * 	- Creates a new image buffer for the fractal.
 * 	- Retrieves the pixel data address of the image buffer.
 * 	- Sets up event handlers for the window.
 *
 * Helper functions:
 * 	- ft_data_init(t_fractal *mlx):
 * 		Initializes the fractal data structure with default values.
 *
 * - ft_mlx_init(t_fractal *mlx):
 * 		Creates a connection to MiniLibX and creates a new window.
 *
 * - ft_mlx_img_init(t_fractal *mlx):
 * 		Creates a new image buffer and retrieves its pixel data address.
 *
 * - ft_events_init(t_fractal *mlx):
 * 		Initializes event hooks for the fractal window.
 *
 * Constants:
 * 	- WIDTH: The width of the window and image.
 * 	- HEIGHT: The height of the window and image.
 * 	- MALLOC_ERROR: The error code returned when memory allocation fails.
 * 	- EXIT_SUCCESS: The success code returned when initialization is successful.
 *
 * Example usage:
 * 	t_fractal fractal;
 * 	fractal.name = "Mandelbrot";
 * 	int result = ft_init(&fractal);
 * 	if (result == EXIT_SUCCESS) {
 * 	// Fractal initialized successfully
 * 	} else {
 * 	// Handle initialization error * }
 *
 * Return:
 * 	EXIT_SUCCESS on successful initialization, or MALLOC_ERROR
 * 	if a memory allocation failure occurs.
 * */
int			ft_init(t_fractal *mlx);

/** MANDELBROT */
/** ft_mandelbrot:
 * 	- Computes and colors a point in the Mandelbrot set.
 *
 * Params:
 * 	@x: The x-coordinate of the point in the image.
 * 	@y: The y-coordinate of the point in the image.
 * 	@fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function calculates if a given point (x, y) belongs to the
 *  Mandelbrot set and colors it accordingly.
 * 	It converts the pixel coordinates to the corresponding complex coordinates,
 * 	and iterates the Mandelbrot function to determine the membership.
 *
 *  If the point escapes the Mandelbrot set, it is colored with a gradient from
 *  two setted colors and depending on the number of iterations.
 * 	Points within the set are colored with another setted color.
 *
 * Helper functions:
 *  - ft_map(int value, double min, double max, int size):
 *      Maps a pixel coordinate to a complex number coordinate.
 *
 *  - ft_sum_complex(t_complex a, t_complex b):
 *      Computes the sum of two complex numbers.
 *
 *  - ft_square_complex(t_complex z):
 *      Computes the square of a complex number.
 *
 *  - ft_hypotenuse(double x, double y):
 *      Computes the hypotenuse of a right triangle with sides x and y.
 *
 *  - ft_mlx_pixel_put(int x, int y, t_img_data *img, int color):
 *      Sets the color of a pixel in the image.
 *
 * Constants:
 *  - COMPLEX_MIN: Minimum complex value for mapping.
 *  - COMPLEX_MAX: Maximum complex value for mapping.
 *  - WIDTH: The width of the image.
 *  - HEIGHT: The height of the image.
 *  - ESCAPE_VALUE: The escape threshold for the Mandelbrot iterations.
 *
 * Example usage:
 *  t_fractal fractal;
 *  // Initialize fractal, set parameters, etc.
 *  ft_mandelbrot(x, y, &fractal);
 */
void		ft_mandelbrot(int x, int y, t_fractal *fractal);

/** JULIA */
/** ft_julia:
 * 	- Computes and colors a point in the Julia set.
 *
 * Params:
 *	@x: The x-coordinate of the point in the image.
 * 	@y: The y-coordinate of the point in the image.
 * 	@fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function calculates if a given point (x, y) belongs to the
 *  Julia set and colors it accordingly.
 *  It converts the pixel coordinates to the corresponding complex coordinates,
 *  and iterates the Julia function to determine the membership.
 *
 *  If the point escapes the Julia set, it is colored with a gradient from
 *  two set colors depending on the number of iterations.
 *  Points within the set are colored with another set color.
 *
 * Helper functions:
 *  - ft_map(int value, double min, double max, int size):
 *      Maps a pixel coordinate to a complex number coordinate.
 *
 *  - ft_sum_complex(t_complex a, t_complex b):
 *      Computes the sum of two complex numbers.
 *
 *  - ft_square_complex(t_complex z):
 *      Computes the square of a complex number.
 *
 *  - ft_hypotenuse(double x, double y):
 *      Computes the hypotenuse of a right triangle with sides x and y.
 *
 *  - ft_mlx_pixel_put(int x, int y, t_img_data *img, int color):
 *      Sets the color of a pixel in the image.
 *
 * Constants:
 *  - COMPLEX_MIN: Minimum complex value for mapping.
 *  - COMPLEX_MAX: Maximum complex value for mapping.
 *  - WIDTH: The width of the image.
 *  - HEIGHT: The height of the image.
 *  - ESCAPE_VALUE: The escape threshold for the Julia iterations.
 *
 * Example usage:
 *  t_fractal fractal;
 *  // Initialize fractal, set parameters, etc.
 *  ft_julia(x, y, &fractal);
 */
void		ft_julia(int x, int y, t_fractal *fractal);

/** ft_burning_ship:
 * 	- Computes and colors a point in the Burning Ship fractal.
 *
 * Params:
 * 	@x: The x-coordinate of the point in the image.
 * 	@y: The y-coordinate of the point in the image.
 * 	@fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function calculates if a given point (x, y) belongs to the
 * 	Burning Ship fractal and colors it accordingly.
 * 	It converts the pixel coordinates to the corresponding complex coordinates,
 * 	and iterates the Burning Ship function to determine the membership.
 *
 *  If the point escapes the Burning Ship fractal, it is colored with a gradient
 * 	from two setted colors and depending on the number of iterations.
 * 	Points within the set are colored with another setted color.
 *
 * Helper functions:
 *  - ft_map(int value, double min, double max, int size):
 *      Maps a pixel coordinate to a complex number coordinate.
 *
 *  - ft_sum_complex(t_complex a, t_complex b):
 *      Computes the sum of two complex numbers.
 *
 *  - ft_square_complex_i_abs(t_complex z):
 *      Computes the square of a complex number whit the absolute
 * 		value of the imaginary part.
 *
 *  - ft_hypotenuse(double x, double y):
 *      Computes the hypotenuse of a right triangle with sides x and y.
 *
 *  - ft_mlx_pixel_put(int x, int y, t_img_data *img, int color):
 *      Sets the color of a pixel in the image.
 *
 * Constants:
 *  - COMPLEX_MIN: Minimum complex value for mapping.
 *  - COMPLEX_MAX: Maximum complex value for mapping.
 *  - WIDTH: The width of the image.
 *  - HEIGHT: The height of the image.
 *  - ESCAPE_VALUE: The escape threshold for the Mandelbrot iterations.
 *
 * Example usage:
 *  t_fractal fractal;
 *  // Initialize fractal, set parameters, etc.
 *  ft_burning-ship(x, y, &fractal);
 */
void		ft_burning_ship(int x, int y, t_fractal *fractal);

/** RENDER */
/** ft_render:
 * - Determines which fractal to render and calls the appropriate function.
 *
 * Params:
 * 	@fractal: Pointer to the fractal data structure.
 *
 * Description:
 *  This function checks the name of the fractal specified in the fractal
 *  data structure and assigns the corresponding fractal function. Then
 *  calls 'ft_render_fractal' with the selected fractal function to render
 *  the fractal on the screen.
 *
 * Helper functions:
 *  - ft_render_fractal(t_fractal *fractal,
 * 			void (*ft_fractal)(int, int, t_fractal *)):
 * 	Renders the fractal using the provided fractal function.
 *
 * Example usage:
 *  t_fractal fractal;
 *  fractal.name = "mandelbrot";
 *  ft_render(&fractal);
 *  // or for Julia set
 *  fractal.name = "julia";
 *  ft_render(&fractal);
 */
void		ft_render(t_fractal *fractal);

/** ft_render_fractal:
 * 	- Renders a fractal using the provided fractal function.
 *
 * Params:
 * 	@fractal: Pointer to the fractal data structure.
 * 	@ft_fractal: Function pointer to the specific fractal calculation function.
 *
 * Description:
 *  This function iterates over each pixel in the window, applies the provided
 *  fractal function to calculate the value for each point, and updates the
 *  image accordingly. Once all pixels are processed, it updates the display
 *  with the new image.
 *
 * Helper functions:
 *  - ft_fractal(int x, int y, t_fractal *fractal):
 *      Computes and sets the color for a point in the fractal.
 *
 * Constants:
 *  - WIDTH: The width of the image.
 *  - HEIGHT: The height of the image.
 *
 * Example usage:
 *  t_fractal fractal;
 *  // Initialize fractal, set parameters, etc.
 *  ft_render_fractal(&fractal, ft_mandelbrot);
 *  // or for Julia set
 *  ft_render_fractal(&fractal, ft_julia);
 */
void		ft_render_fractal(t_fractal *fractal,
				void (*ft_fractal)(int, int, t_fractal *));

#endif