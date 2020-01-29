/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 07:51:24 by magostin          #+#    #+#             */
/*   Updated: 2020/01/29 08:16:24 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTERS_H
# define TESTERS_H

# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


void			my_putchar(char c, int fd);
void			my_print_alphabet(int fd);
void			my_print_reverse_alphabet(int fd);
void			my_print_numbers(int fd);
void			my_is_negative(int n, int fd);
void			my_print_comb(int fd);
void			my_print_comb2(int fd);
void			my_putnbr(int nb, int fd);
void			my_print_combn(int n, int fd);

void			my_ft(int *nbr);
void			my_ultimate_ft(int *********nbr);
void			my_swap(int *a, int *b);
void			my_div_mod(int a, int b, int *div, int *mod);
void			my_ultimate_div_mod(int *a, int *b);
void			my_putstr(char *str, int fd);
int				my_strlen(char *str);
void			my_rev_int_tab(int *tab, int size);
void			my_sort_int_tab(int *tab, int size);

char			*my_strcpy(char *dest, char *src);
char			*my_strncpy(char *dest, char *src, unsigned int n);
int				my_str_is_alpha(char *str);
int				my_str_is_numeric(char *str);
int				my_str_is_lowercase(char *str);
int				my_str_is_uppercase(char *str);
int				my_str_is_printable(char *str);
char			*my_strupcase(char *str);
char			*my_strlowcase(char *str);
char			*my_strcapitilize(char *str);
unsigned int	my_strlcpy(char *dest, char *src, unsigned int size);
void			my_putstr_non_printable(char *str, int fd);
void			*my_print_memory(void *addr, unsigned int size, int fd);

int				my_strcmp(char *s1, char *s2);
int				my_strncmp(char *s1, char *s2, unsigned int n);
char			*my_strcat(char *dest, char *src);
char			*my_strncat(char *dest, char *src, unsigned int nb);
char			*my_strstr(char *str, char *to_find);
unsigned int	my_strlcat(char *dest, char *src, unsigned int size);

int				my_atoi(const char *str);
void			my_putnbr_base(int nbr, char *base, int fd);
int				my_atoi_base(char *str, char *base);
#endif