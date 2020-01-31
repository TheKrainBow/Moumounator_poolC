/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magostin <magostin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 08:08:00 by magostin          #+#    #+#             */
/*   Updated: 2020/01/29 11:43:12 by magostin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET   "\033[0m"
#define BLACK   "\033[30m"					/* Black */
#define RED     "\033[31m"					/* Red */
#define GREEN   "\033[32m"					/* Green */
#define YELLOW  "\033[33m"					/* Yellow */
#define BLUE    "\033[34m"					/* Blue */
#define MAGENTA "\033[35m"					/* Magenta */
#define CYAN    "\033[36m"					/* Cyan */
#define WHITE   "\033[37m"					/* White */
#define BOLDBLACK   "\033[1m\033[30m"		/* Bold Black */
#define BOLDRED     "\033[1m\033[31m"		/* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"		/* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"		/* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"		/* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"		/* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"		/* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"		/* Bold White */
#include "TESTERS/testers.h"
#include "TESTERS/user.h"

int		ft_comparelines(char *s1, char *s2)
{
	int		i = 0;

	if (!s1 || !s2)
		return ((!s1 && !s2) ? 1 : 0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int			ft_checkline(int fd_user, int fd_fonc, int fd_stdout, int toggleok)
{
	int		ret_val = 1;
	char	*line_user = NULL;
	char	*line_fonc = NULL;

	dup2(fd_stdout, 1);
	get_next_line(fd_user, &line_user);
	get_next_line(fd_fonc, &line_fonc);
	if (!(ft_comparelines(line_user, line_fonc)))
	{
		printf( BOLDRED "\nDIFF!\n" RESET);
		printf("Your Function: |%s|\n", line_user);
		printf("Good Function: |%s|\n", line_fonc);
		ret_val = 0;
	}
	else if (toggleok != 0)
	{
		printf( BOLDGREEN "OK for |%s|\n" RESET, line_fonc);
	}
	free(line_fonc);
	free(line_user);
	return (ret_val);
}

static char	*main_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)(&s[i]));
	return (0);
}

int		ft_test_v_i(void (*f_user)(int), void (*f_f)(int, int), int s, int e, int add)
{
	int		fd_user;
	int		fd_fonc;
	int		fd_strdout = dup(1);
	int		i;
	int		ret = 1;

	i = s;
	while (i < e)
	{
		fd_user = open("output_user.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		system(": > output_user.txt");
		dup2(fd_user, 1);
		fd_fonc = open("output_fonc.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		system(": > output_fonc.txt");
		f_user(i);
		f_f(i, fd_fonc);
		close(fd_user);
		fd_user = open("output_user.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		close(fd_fonc);
		fd_fonc = open("output_fonc.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		if (!ft_checkline(fd_user, fd_fonc, fd_strdout, 0))
			ret = 0;
		close(fd_user);
		close(fd_fonc);
		i += add;
	}
	close(fd_strdout);
	return (ret);
}

int		ft_test_v_v(void (*f_user)(void), void (*f_f)(int))
{
	int		fd_user;
	int		fd_fonc;
	int		fd_strdout = dup(1);
	int		ret = 1;

	fd_user = open("output_user.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	system(": > output_user.txt");
	dup2(fd_user, 1);
	fd_fonc = open("output_fonc.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	system(": > output_fonc.txt");
	f_f(fd_fonc);
	f_user();
	close(fd_user);
	fd_user = open("output_user.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	close(fd_fonc);
	fd_fonc = open("output_fonc.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (!ft_checkline(fd_user, fd_fonc, fd_strdout, 0))
		ret = 0;
	close(fd_user);
	close(fd_fonc);
	close(fd_strdout);
	return (ret);
}

int		ft_test_v_s(void (*f_user)(char *), void (*f_f)(char *, int))
{
	int		fd_user;
	int		fd_fonc;
	int		fd_strdout = dup(1);
	int		ret = 1;
	int		i = 0;
	char	*str[4] =
	{
		"bonJouR JE sUIs uN TEssT 456778qz eheh+254 *9687-t+e*z/a.sdlf",
		"",
		"\f\t\n\r\v\r\v\v\tWowow\t\t",
		NULL
	};
	while (i < 4)
	{
		fd_user = open("output_user.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		system(": > output_user.txt");
		dup2(fd_user, 1);
		fd_fonc = open("output_fonc.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		system(": > output_fonc.txt");
		f_f(str[i], fd_fonc);
		f_user(str[i]);
		close(fd_user);
		fd_user = open("output_user.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		close(fd_fonc);
		fd_fonc = open("output_fonc.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
		if (!ft_checkline(fd_user, fd_fonc, fd_strdout, 0))
			ret = 0;
		close(fd_user);
		close(fd_fonc);
		i++;
	}
	close(fd_strdout);
	return (ret);
}


int		ft_test_i_s(int (*f_user)(char *), int (*f_f)(char *))
{
	int		ret = 1;
	int		user_result;
	int		fonc_result;
	int		i = 0;
	char	*str[4] =
	{
		"bonJouR JE sUIs uN TEssT 456778qz eheh+254 *9687-t+e*z/a.sdlf",
		"",
		"\f\t\n\r\v\r\v\v\tWowow\t\t",
		NULL
	};
	while (i < 4)
	{
		fonc_result = f_f(str[i]);
		user_result = f_user(str[i]);
		if (fonc_result != user_result)
		{
			printf( BOLDRED "\nDIFF!\n" RESET);
			printf("You returned: %d instead of %d\n", user_result, fonc_result);
			printf("Tested string: |%s|\n", str[i]);
			ret = 0;
		}
		i++;
	}
	return (ret);
}

int		ft_test_ft_ft(int test)
{
	int		a = -123456;
	int		*b = &a;
	int		**c = &b;
	int		***d = &c;
	int		****e = &d;
	int		*****f = &e;
	int		******g = &f;
	int		*******h = &g;
	int		********i = &h;
	if (test == 1)
	{
		ft_ft(&a);
		if (a == 42)
			return (1);
		printf( BOLDRED "\nDIFF!\n" RESET);
		(a == -123456) ? printf("Your function doesn't affect a\n") : printf("Your function applied %d to a instead of 42\n", a);
		return (0);
	}
	else
	{
		ft_ultimate_ft(&i);
		if (a == 42)
			return (1);
		printf( BOLDRED "\nDIFF!\n" RESET);
		(a == -123456) ? printf("Your function doesn't affect a\n") : printf("Your function applied %d to a instead of 42\n", a);
		return (0);
	}
}

int		ft_test_div_swap(int test)
{
	int		a;
	int		stock_a;
	int		b;
	int		stock_b;
	int		div = -123456;
	int		mod = -123456;
	int		i;
	int		ret = 1;

	if (test == 1)
	{
		i = -1;
		while (i < 10)
		{
			a = 4 + i;
			stock_a = a;
			b = 67 - i;
			stock_b = b;
			ft_swap(&a, &b);
			if (b != stock_a || a != stock_b)
			{
				printf( BOLDRED "\nDIFF!\n" RESET);
				if (a != stock_b)
					printf("You stocked %d in a instead of %d\n", a, stock_b);
				if (b != stock_a)
					printf("You stocked %d in b instead of %d\n", b, stock_a);
				ret = 0;
			}
			i++;
		}
	}
	else if (test == 2)
	{
		i = -1;
		while (i < 10)
		{
			a = 4 + i;
			b = 67 - i;
			ft_div_mod(a, b, &div, &mod);
			if (div != a / b || mod != a % b)
			{
				printf( BOLDRED "\nDIFF!\n" RESET);
				if (div != a / b)
					printf("You stocked %d in div instead of %d\n", div, a / b);
				if (mod != a % b)
					printf("You stocked %d in mod instead of %d\n", mod, a % b);
				ret = 0;
			}
			i++;
		}
	}
	else
	{
		i = -1;
		while (i < 10)
		{
			a = 4 + i;
			stock_a = a;
			b = 67 - i;
			stock_b = b;
			ft_ultimate_div_mod(&a, &b);
			if (a != stock_a / stock_b || b != stock_a % stock_b)
			{
				printf( BOLDRED "\nDIFF!\n" RESET);
				if (a != stock_a / stock_b)
					printf("You stocked %d in a instead of %d\n", a, stock_a / stock_b);
				if (b != stock_a % stock_b)
					printf("You stocked %d in b instead of %d\n", b, stock_a % stock_b);
				ret = 0;
			}
			i++;
		}
	}
	return (ret);
}

int		ft_test_int_tab(void (*f_user)(int *, int), void (*f_f)(int *, int))
{
	int		tab1_u[] = {5, 6, 7, 8, 9, 4, 5, 3, 2, 1, 7, 9, 6, 3, 5, 4, 7};
	int		tab1_f[] = {5, 6, 7, 8, 9, 4, 5, 3, 2, 1, 7, 9, 6, 3, 5, 4, 7};
	int		size1 = 17;
	int		i = 0;

	f_user(tab1_u, size1);
	f_f(tab1_f, size1);
	while (i < size1)
	{
		if (tab1_u[i] != tab1_f[i])
		{
			printf( BOLDRED "\nDIFF!\n" RESET);
			printf("Your tab is: {");
			i = 0;
			while (i < size1)
				printf("%d ", tab1_u[i++]);
			printf("}\ninstead of:  {");
			i = 0;
			while (i < size1)
				printf("%d ", tab1_f[i++]);
			printf("}\n");
			return (0);
		}
		i++;
	}
}

void	ft_day00(void)
{
	printf( BOLDWHITE "C00:\n" RESET);
	printf("ft_putchar:	");
	ft_test_v_i(&ft_putchar, &my_putchar, 0, 100, 1) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_print_alphabet:");
	ft_test_v_v(&ft_print_alphabet, &my_print_alphabet) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_print_alphabet:");
	ft_test_v_v(&ft_print_reverse_alphabet, &my_print_reverse_alphabet) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_print_numbers:");
	ft_test_v_v(&ft_print_numbers, &my_print_numbers) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_is_negative:	");
	ft_test_v_i(&ft_is_negative, &my_is_negative, 0, 100, 10) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_print_comb:	");
	ft_test_v_v(&ft_print_comb, &my_print_comb) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_print_comb2:	");
	ft_test_v_v(&ft_print_comb2, &my_print_comb2) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_putnbr:	");
	(ft_test_v_i(&ft_putnbr, &my_putnbr, -100, 100, 1) && ft_test_v_i(&ft_putnbr, &my_putnbr, -2147483648, -2147483647, 1)) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_print_combn:	");
	ft_test_v_i(&ft_print_combn, &my_print_combn, 1, 10, 1) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
}

void	ft_day01(void)
{
	printf( BOLDWHITE "C01:\n" RESET);
	printf("ft_ft:			");
	ft_test_ft_ft(1) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_ultimate_ft:		");
	ft_test_ft_ft(2) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_ft:			");
	ft_test_div_swap(1) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_div_mod:		");
	ft_test_div_swap(2) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_ultimate_div_mod:	");
	ft_test_div_swap(3) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_putstr:		");
	ft_test_v_s(&ft_putstr, &my_putstr) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_strlen:		");
	ft_test_i_s(&ft_strlen, &my_strlen) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_rev_int_tab:		");
	ft_test_int_tab(&ft_rev_int_tab, &my_rev_int_tab) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
	printf("ft_sort_int_tab:	");
	ft_test_int_tab(&ft_sort_int_tab, &my_sort_int_tab) ? printf( BOLDGREEN "\t[OK]\n" RESET) : printf( BOLDRED "\t[KO]\n" RESET);
}

int		main(int ac, char **av)
{
	int		day;

	day = -1;
	if (ac == 1)
	{
		printf("\033[0;31m");
		printf("Thanks to specify C number\n");
		printf("Use it like this: \n");
		printf("\033[0m");
		printf("\'./a.out 0\'\n");
		printf("\033[0;31m");
		printf("to specify ");
		printf("\033[0m");
		printf("C00\n");
		return (1);
	}
	day = my_atoi(av[1]);
	if (day < 0 || day > 13)
	{
		printf("\033[0;31m");
		printf("Day %d is invalid.\n", day);
		printf("Day must be in interval [0;13]\n");
		return (1);
	}
	switch (day)
	{
		case 0:
			ft_day00();
			break;
		case 1:
			ft_day01();
			break;
		/*case 2:
			ft_day02();
			break;
		case 3:
			ft_day03();
			break;
		case 4:
			ft_day04();
			break;*/
	}
}