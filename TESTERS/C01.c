/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 05:39:05 by magostin          #+#    #+#             */
/*   Updated: 2020/01/29 10:39:10 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testers.h"

/*
**			EX00
*/

void	my_ft(int *nbr)
{
	*nbr = 42;
}

/*
**			EX01
*/

void	my_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/*
**			EX02
*/

void	my_swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
**			EX03
*/

void	my_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
**			EX04
*/

void	my_ultimate_div_mod(int *a, int *b)
{
	int		temp_a;
	int		temp_b;

	temp_a = *a;
	temp_b = *b;
	*a = temp_a / temp_b;
	*b = temp_a % temp_b;
}

/*
**			EX05
*/

void	my_putstr(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		write(fd, &*str, 1);
		str++;
	}
}

/*
**			EX06
*/

int		my_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/*
**			EX07
*/

void	my_rev_int_tab(int *tab, int size)
{
	int		i;

	i = -1;
	while (++i < size / 2)
		my_swap(tab + i, tab + size - i - 1);
}

/*
**			EX08
*/

void	my_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		min_int;
	int		min_pos;

	i = -1;
	while (++i < size)
	{
		min_int = 2147483647;
		j = i - 1;
		while (++j < size)
			if (*(tab + j) < min_int)
			{
				min_int = *(tab + j);
				min_pos = j;
			}
		my_swap(tab + i, tab + min_pos);
	}
}
