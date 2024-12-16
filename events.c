/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:16:42 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/15 11:59:26 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == LEFT_ARROW)
		data->x_offset -= 0.5 * data->zoom;
	else if (keycode == RIGHT_ARROW)
		data->x_offset += 0.5 * data->zoom;
	else if (keycode == DOWN_ARROW)
		data->y_offset -= 0.5 * data->zoom;
	else if (keycode == UP_ARROW)
		data->y_offset += 0.5 * data->zoom;
	else if (keycode == R_KEY)
	{
		data->zoom = 1;
		data->x_offset = 0;
		data->y_offset = 0;
	}
	else if (keycode == PLUS_KEY)
		data->iterations += 10;
	else if (keycode == MINUS_KEY)
		data->iterations -= 10;
	mlx_clear_window(data->mlx, data->win);
	render(*data);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	if (data->lock_mouse == 1)
		return (0);
	data->c.real = scale(x, -2, 2, WIDTH);
	data->c.imaginary = scale(y, -2, 2, HEIGHT);
	mlx_clear_window(data->mlx, data->win);
	render(*data);
	return (0);
}

static void	color(t_data *data)
{
	if (data->color == 0xF0FF0000)
		data->color = 0x00050709;
	else
		data->color = 0xF0FF0000;
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	double	old_zoom;

	old_zoom = data->zoom;
	if (button == SCROLL_UP)
		data->zoom *= 1.10;
	else if (button == SCROLL_DOWN)
		data->zoom *= 0.90;
	else if (button == RIGHT_MOUSE)
		data->lock_mouse = !data->lock_mouse;
	else if (button == LEFT_MOUSE)
		color(data);
	data->x_offset += scale(x, -2, 2, WIDTH) * (old_zoom - data->zoom);
	data->y_offset += scale(y, -2, 2, HEIGHT) * (old_zoom - data->zoom);
	mlx_clear_window(data->mlx, data->win);
	render(*data);
	return (0);
}
