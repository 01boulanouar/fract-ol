/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:19:17 by moboulan          #+#    #+#             */
/*   Updated: 2024/12/16 18:00:42 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.imaginary = z1.imaginary + z2.imaginary;
	return (res);
}

t_complex	square(t_complex z)
{
	t_complex	res;

	res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	res.imaginary = 2 * z.real * z.imaginary;
	return (res);
}

double	magnitude(t_complex z)
{
	return (sqrt((z.real * z.real) + (z.imaginary * z.imaginary)));
}
