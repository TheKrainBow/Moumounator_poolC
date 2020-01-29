/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C02.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 06:04:35 by magostin          #+#    #+#             */
/*   Updated: 2020/01/29 08:22:04 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testers.h"

/*
**			EX00
*/

char	*my_strcpy(char *dest, char *src)
{
	return (strcpy(dest, src));
}

/*
**			EX01
*/

char	*my_strncpy(char *dest, char *src, unsigned int n)
{
	return (strncpy(dest, src, n));
}

/*
**			EX02
*/

int		my_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!isalpha(*str))
			return (0);
		str++;
	}
	return (1);
}

/*
**			EX03
*/

int		my_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/*
**			EX04
*/

int		my_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!islower(*str))
			return (0);
		str++;
	}
	return (1);
}

/*
**			EX05
*/

int		my_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!isupper(*str))
			return (0);
		str++;
	}
	return (1);
}

/*
**			EX06
*/

int		my_str_is_printable(char *str)
{
	while (*str)
	{
		if (!isprint(*str))
			return (0);
		str++;
	}
	return (1);
}

/*
**			EX07
*/
char	*my_strupcase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	return (str);
}

/*
**			EX08
*/
char	*my_strlowcase(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	return (str);
}


/*
**			EX09
*/

char	*my_strcapitilize(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && (i == 0 || !isalnum(str[i - 1])))
			str[i] -= 32;
	}
	return (str);
}

/*
**			EX10
*/

unsigned int	my_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	while (src[count] != '\0')
		++count;
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}
/*
**			EX11
*/

void			my_putstr_non_printable(char *str, int fd)
{
	while (*str)
	{
		if (!isprint(*str))
		{
			my_putchar('\\', fd);
			my_putchar(((*str / 16) + '0'), fd);
			my_putchar(((*str % 10) + 'a'), fd);
		}
		else
			my_putchar(*str, fd);
		str++;
	}
}

/*
**			EX12
*/

int				my_get_size_hexa(long int n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void			my_puthexa_recu(long int n, int fd)
{
	if (!n)
		return ;
	my_puthexa_recu(n / 16, fd);
	my_putchar("0123456789abcdef"[n % 16], fd);
}

void			*my_print_memory(void *addr, unsigned int size, int fd)
{
	int		i_compteur[4];
	char	*buff;

	i_compteur[0] = 0;
	buff = addr;
	while (i_compteur[0] < size)
	{
		i_compteur[3] = -1;
		while (++i_compteur[3] < 16 - my_get_size_hexa((long int)(addr + i_compteur[0])))
			my_putchar('0', fd);
		my_puthexa_recu((long int)(addr + i_compteur[0]), fd);
		write(fd, ": ", 2);
		i_compteur[1] = i_compteur[0];
		i_compteur[2] = 0;
		while (i_compteur[2] < 16)
		{
			my_putchar((i_compteur[0] < size) ? ((buff[i_compteur[0]] / 16) + '0') : ' ', fd);
			my_putchar((i_compteur[0] < size) ? ((buff[i_compteur[0]] % 10) + 'a') : ' ', fd);
			if (i_compteur[2] % 2 == 1)
				my_putchar(' ', fd);
			i_compteur[0]++;
			i_compteur[2]++;
		}
		i_compteur[0] = i_compteur[1] - 1;
		my_putchar(' ', fd);
		i_compteur[2] = -1;
		while (++i_compteur[0] < size && ++i_compteur[2] < 16)
			my_putchar(!isprint(buff[i_compteur[0]]) ? '.' : buff[i_compteur[0]], fd);
		my_putchar('\n', fd);
	}
	return (addr);
}
