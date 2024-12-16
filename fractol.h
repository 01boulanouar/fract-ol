/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:25:08 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/15 01:09:59 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define TITLE "Fractol"
# define HEIGHT 800
# define WIDTH 800

# define ESC 53

# define LEFT_MOUSE 1
# define RIGHT_MOUSE 2
# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define UP_ARROW 125
# define DOWN_ARROW 126
# define R_KEY 15
# define PLUS_KEY 69
# define MINUS_KEY 78

# define CLOSE_BUTTON 17

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

t_complex		sum(t_complex z1, t_complex z2);
t_complex		square(t_complex z);
t_complex		absolute(t_complex z);
double			magnitude(t_complex z);

typedef struct s_data
{
	char			*name;
	unsigned int	color;
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				iterations;
	double			zoom;
	double			x_offset;
	double			y_offset;
	double			mouse_x;
	double			mouse_y;
	int				lock_mouse;
	t_complex		c;
	t_complex		z;

}				t_data;

int				close_window(t_data *data);
int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
int				mouse_move(int x, int y, t_data *data);

void			render(t_data data);
double			scale(double value, double min, double max, double dimension);

int				ft_strcmp(const char *s1, const char *s2);
double			ft_atodouble(char *str);
int				valid_value(char *str);
#endif