/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C00.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 05:14:50 by magostin          #+#    #+#             */
/*   Updated: 2020/01/29 11:27:26 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testers.h"

/*
**	EX00
*/

void	my_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

/*
**	EX01
*/

void	my_print_alphabet(int fd)
{
	write(fd, "abcdefghijklmnopqrstuvwxyz", 26);
}

/*
**	EX02
*/

void	my_print_reverse_alphabet(int fd)
{
	write(fd, "zyxwvutsrqponmlkjihgfedcba", 26);
}

/*
**	EX03
*/

void	my_print_numbers(int fd)
{
	write(fd, "0123456789", 10);
}

/*
**	EX04
*/

void	my_is_negative(int n, int fd)
{
	if (n < 0)
		write(fd, "N", 1);
	else
		write(fd, "P", 1);
}

/*
**	EX05
*/

void	my_print_comb(int fd)
{
	int		i;

	i = -1;
	while (++i <= 789)
	{
		if (i % 1000 / 100 < i % 100 / 10 && i % 100 / 10 < i % 10)
		{
			my_putchar((i % 1000 / 100) + '0', fd);
			my_putchar((i % 100 / 10) + '0', fd);
			my_putchar((i % 10 + '0'), fd);
			if (i != 789)
				write(fd, ", ", 2);
		}
	}
}

/*
**	EX06
*/

void	print(int a, int b, int fd)
{
	my_putchar('0' + a / 10, fd);
	my_putchar('0' + a % 10, fd);
	my_putchar(' ', fd);
	my_putchar('0' + b / 10, fd);
	my_putchar('0' + b % 10, fd);
	if (a != 98 || b != 99)
	{
		my_putchar(',', fd);
		my_putchar(' ', fd);
	}
}

void	my_print_comb2(int fd)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print(a, b, fd);
			b++;
		}
		a++;
	}
}
/*
**	EX07
*/

void	my_putnbr_recu(long int n, int fd)
{
	if (n == 0)
		return ;
	my_putnbr_recu(n / 10, fd);
	my_putchar((n % 10) + '0', fd);
}

void	my_putnbr(int nb, int fd)
{
	long int		n;

	n = nb;
	if (n < 0)
	{
		my_putchar('-', fd);
		n = -n;
		my_putnbr_recu(n, fd);
	}
	else if (n == 0)
		my_putchar('0', fd);
	else
		my_putnbr_recu(n, fd);
	
}

/*
**	EX08
*/

void	my_printtab(int tab[9], int n, int fd)
{
	char	c;

	if (n == 0)
		return ;
	my_printtab(tab, n - 1, fd);
	c = tab[n - 1] + '0';
	write(fd, &c, 1);
}

void	my_checktab(int tab[9], int n, int end, int fd)
{
	int		i;

	i = -1;
	while (++i < n - 1 && end)
	{
		if (tab[i] >= tab[i + 1])
			return ;
	}
	my_printtab(tab, n, fd);
	if (end)
		write(fd, ", ", 2);
}

int		my_endoftable(int tab[9], int n)
{
	int i;

	i = -1;
	while (++i < n)
		if (tab[i] != (10 - n) + i)
			return (1);
	return (0);
}

void	my_print_combn(int n, int fd)
{
	int		tab[9];
	int		i;

	i = -1;
	while (++i < 9)
		tab[i] = 0;
	i = 1;
	while (my_endoftable(tab, n))
	{
		my_checktab(tab, n, 1, fd);
		while (tab[n - i] == 9)
		{
			tab[n - i] = 0;
			tab[n - ++i]++;
		}
		i = 1;
		tab[n - 1] = tab[n - 1] + 1;
	}
	my_checktab(tab, n, 0, fd);
}
