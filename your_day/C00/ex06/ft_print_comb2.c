#include <unistd.h>

void ft_putccchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb2()
{
	int i;
	int j;

	i = -1;
	while (++i <= 98)
	{
		j = i;
		while(++j <= 99)
		{
			ft_putccchar((char)(i / 10) + '0');
			ft_putccchar((char)(i % 10) + '0');
			ft_putccchar(' ');
			ft_putccchar((char)(j / 10) + '0');
			ft_putccchar((char)(j % 10) + '0');
			if (i != 98)
			{
				ft_putccchar(',');
				ft_putccchar(' ');
			}
		}
	}
}
