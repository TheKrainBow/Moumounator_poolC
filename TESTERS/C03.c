/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C03.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 06:04:35 by magostin          #+#    #+#             */
/*   Updated: 2020/01/29 07:58:29 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testers.h"

/*
**			EX00
*/

int		my_strcmp(char *s1, char *s2)
{
	return (strcmp(s1, s2));
}

/*
**			EX01
*/

int		my_strncmp(char *s1, char *s2, unsigned int n)
{
	return (strncmp(s1, s2, n));
}

/*
**			EX02
*/

char	*my_strcat(char *dest, char *src)
{
	return (strcat(dest, src));
}

/*
**			EX03
*/

char	*my_strncat(char *dest, char *src, unsigned int nb)
{
	return (strncat(dest, src, nb));
}

/*
**			EX04
*/

char	*my_strstr(char *str, char *to_find)
{
	return (strstr(str, to_find));
}

/*
**			EX05
*/

unsigned int	my_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res;

	i = 0;
	while (dest[i] != '\0')
		++i;
	res = 0;
	while (src[res] != '\0')
		++res;
	if (size <= i)
		res += size;
	else
		res += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}