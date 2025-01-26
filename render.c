/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 01:59:24 by moboulan          #+#    #+#             */
/*   Updated: 2025/01/26 15:09:27 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include "fractol.h"

static void	pixel_put(t_data data, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	offset = y * data.size_line + x * (data.bits_per_pixel / 8);
	*(int *)(data.addr + offset) = color;
}

double	scale(double value, double min, double max, double dimension)
{
	return ((value / dimension) * (max - min) + min);
}

static int	get_fractal_pixel_color(int x, int y, t_data data)
{
	int			i;
	t_complex	point;

	point.real = scale(x, -2, 2, WIDTH) * data.zoom + data.x_offset;
	point.imaginary = scale(y, -2, 2, HEIGHT) * data.zoom + data.y_offset;
	if (!ft_strcmp(data.name, "mandelbrot")
		|| !ft_strcmp(data.name, "burningship"))
		data.c = point;
	else if (!ft_strcmp(data.name, "julia"))
		data.z = point;
	i = 0;
	while (i < data.iterations)
	{
		if (!ft_strcmp(data.name, "burningship"))
			data.z = sum(square(absolute(data.z)), data.c);
		else
			data.z = sum(square(data.z), data.c);
		if (magnitude(data.z) > 4)
			return (i * data.color);
		i++;
	}
	return (0);
}

void	render(t_data data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = get_fractal_pixel_color(x, y, data);
			pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
}
