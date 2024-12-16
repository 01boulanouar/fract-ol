/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:16:42 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/16 18:15:11 by moboulan         ###   ########.fr       */
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
	else if (keycode == R_KEY)
		data->zoom = 1;
	else if (keycode == PLUS_KEY)
		data->iterations += 10;
	else if (keycode == MINUS_KEY)
		data->iterations -= 10;
	mlx_clear_window(data->mlx, data->win);
	render(*data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (button == SCROLL_UP)
		data->zoom *= 1.10;
	else if (button == SCROLL_DOWN)
		data->zoom *= 0.90;
	mlx_clear_window(data->mlx, data->win);
	render(*data);
	return (0);
}
