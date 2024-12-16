/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:39:38 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/16 17:45:57 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error(void *value)
{
	if (!value)
		exit(EXIT_FAILURE);
}

static void	data_init(t_data *data)
{
	if (!ft_strcmp(data->name, "julia"))
		data->color = 0xF0FF0000;
	else
		data->color = 0x00050709;
	data->iterations = 100;
	data->zoom = 1.0;
	data->lock_mouse = 1;
	data->x_offset = 0.0;
	data->y_offset = 0.0;
	data->mlx = mlx_init();
	ft_error(data->mlx);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, TITLE);
	ft_error(data->win);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	ft_error(data->img);
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->size_line,
			&data->endian);
	ft_error(data->addr);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 6, 0, mouse_move, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, CLOSE_BUTTON, 0, close_window, data);
}

static void	display_usage(void)
{
	write(1, "#####Usage#####\n", 17);
	write(1, "./fractol mandelbrot\n", 22);
	write(1, "./fractol julia 0.45 0.2 (between -2 and 2)\n", 45);
	write(1, "./fractol burningship\n", 23);
	write(1, "#####Controls#####\n", 20);
	write(1, "arrow keys move\n", 17);
	write(1, "mouse wheel zoom\n", 18);
	write(1, "left click change color\n", 25);
	write(1, "right click lock/unlock julia\n", 31);
	write(1, "+/- add/reduce detail\n", 23);
	write(1, "r key reset\n", 13);
}

static void	handle_args(int argc, char **argv, t_data *data)
{
	if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
	{
		data->name = "mandelbrot";
		return ;
	}
	else if (argc == 4 && !ft_strcmp(argv[1], "julia")
		&& valid_value(argv[2])
		&& valid_value(argv[3]))
	{
		data->name = "julia";
		data->c.real = ft_atodouble(argv[2]);
		data->c.imaginary = -ft_atodouble(argv[3]);
		return ;
	}
	else if (argc == 2 && !ft_strcmp(argv[1], "burningship"))
	{
		data->name = "burningship";
		return ;
	}
	display_usage();
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	handle_args(argc, argv, &data);
	data_init(&data);
	render(data);
	mlx_loop(data.mlx);
}
