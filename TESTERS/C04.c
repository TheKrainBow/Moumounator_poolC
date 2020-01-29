/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C04.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 06:04:35 by magostin          #+#    #+#             */
/*   Updated: 2020/01/29 08:21:47 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testers.h"

/*
**			EX03
*/

int		my_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

/*
**			EX04
*/

int			my_checkbase(char *base)
{
	int		i;
	int		j;

	i = -1;
	if (!base || base[0] == 0 || base[1] == 0)
		return (0);
	while (base[++i])
	{
		j = i;
		while (base[++j])
			if ((!(base[i] >= 'a' && base[i] <= 'z') && !(base[i] >= 'A' && base[i]
			<= 'Z') && !(base[i] >= '0' && base[i] <= '9')) || base[i] == base[j])
				return (0);
	}
	return (1);
}

void		my_putbase(int nbr, char *base, int i, int fd)
{
	if (nbr > 0)
	{
		my_putbase(nbr / i, base, i, fd);
		write(fd, &base[nbr % i], 1);
	}
}

void		my_putnbr_base(int nbr, char *base, int fd)
{
	int			i;
	long int	nb;

	nb = (long int)nbr;
	i = 0;
	if (!my_checkbase(base))
		return ;
	while (base[i])
		i++;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	else if (nb == 0)
		write(fd, "0", 1);
	else
		my_putbase((int)nb, base, i, fd);
}


/*
**			EX05
*/

int			my_pow(int x, int pow)
{
	int			i;

	i = 1;
	if (!pow)
		return (1);
	while (i < pow)
	{
		x *= x;
		i++;
	}
	return (x);
}

int			my_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int			my_convert(char *str, char *base, int base_len)
{
	char	*end;
	int		res;
	int		value;
	int		i;

	end = str;
	res = 0;
	while (my_strchr(base, *end))
		end++;
	end--;
	i = 0;
	while (end >= str)
	{
		value = 0;
		while (base[value] && base[value] != *end)
			value++;
		res += (value)*(my_pow(base_len, i));
		end--;
		i++;
	}
	return (res);
}

int			check_base(char *base)
{
	int		i;
	int		j;

	i = -1;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[++i])
	{
		j = -1;
		while (++j < i)
			if (base[j] == base[i])
				return (0);
		if (base[i] == '\f' || base[i] == '\t' || base[i] == '\n' ||
		base[i] == '\r' || base[i] == '\v' || base[i] == ' ' ||
		base[i] == '+' || base[i] == '-')
			return (0);
	}
	return (1);
}

int			my_atoi_base(char *str, char *base)
{
	int		neg;
	int		res;
	int		base_len;

	res = 0;
	neg = 1;
	if (!base || !str || !check_base(base))
		return (0);
	while ((*str == '\f' || *str == '\t' || *str == '\n' || *str == '\r'
	|| *str == '\v' || *str == ' '))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	base_len = 0;
	while (base[base_len])
		base_len++;
	res = my_convert(str, base, base_len);
	return (res * neg);
}
