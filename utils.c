/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moboulan <moboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:52:05 by moboulan          #+#    #+#             */
/*   Updated: 2025/01/26 11:42:52 by moboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		r;

	r = 0;
	i = 0;
	while (r == 0)
	{
		if (!(s1[i] || s2[i]))
			break ;
		r = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (r);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

double	ft_atodouble(char *str)
{
	int		i;
	int		signe;
	double	power;
	double	res;

	i = 0;
	res = 0;
	power = 1;
	signe = 1;
	if ((str[i] == '-' || str[i] == '+' ))
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
	{
		power = power / 10;
		res = res + (str[i] - '0') * power;
		i++;
	}
	return (res * signe);
}

int	valid_value(char *str)
{
	double	num;
	size_t	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (ft_strlen(str) != i
		|| !ft_strcmp(str, "")
		|| !ft_strcmp(str, "-")
		|| !ft_strcmp(str, "+")
		|| !ft_strcmp(str, "-.")
		|| !ft_strcmp(str, "+.")
		|| !ft_strcmp(str, "."))
		return (0);
	num = ft_atodouble(str);
	return ((-2 <= num && num <= 2));
}
