#include "factorization_header.h"

int		check_overflow(char s, number num)
{
	static number	max;

	if (!max)
	{
		ft_memset(&max, 0xff, sizeof(max));
		// if (max < 0)
		// {
		// 	ft_memset((unsigned char*)&max + sizeof(max) - 1, 0x7f, 1);
		// }
	}
	if (num > max / 10 || (num >= max / 10 && (number)(s - '0') > max % 10))
	{
		return (ERR_OVERFLOW);
	}
	else
		return (OK);
}

int		init(int argc, char **argv, number *num)
{
	char	*arg;
	int		arg_available;

	*num = 0;
	arg_available = 0;
	if (argc == 1)
		return (ERR_NO_ARGUMENTS);
	else if (argc > 2)
		return (ERR_TOO_MANY_ARGUMENTS);
	arg = argv[1];
	while (*arg && (contain(*arg, "0123456789")))
	{
		arg_available = 1;
		if (check_overflow(*arg, *num) == ERR_OVERFLOW)
			return (ERR_OVERFLOW);
		*num = *num * 10 + *arg++ - '0';
	}
	if (arg_available == 0 || *arg != 0)
		return (ERR_WRONG_ARGUMENTS);
	if (*num < 2)
		return (ERR_WRONG_NUM);
	return (OK);
}

int		print_err(int err)
{
	number	max;

	if (err == ERR_NO_ARGUMENTS)
		ft_putstr("Error : No arguments.\n");
	else if (err == ERR_WRONG_ARGUMENTS)
		ft_putstr("Error : No available arguments.\n");
	else if (err == ERR_TOO_MANY_ARGUMENTS)
		ft_putstr("Error : Too mant arguments.\n");
	else if (err == ERR_OVERFLOW)
	{
		ft_putstr("Error : Too large number. (Max = ");
		ft_memset(&max, 0xff, sizeof(max));
		// if (max < 0)
		// 	ft_memset((unsigned char*)&max + sizeof(max) - 1, 0x7f, 1);
		ft_put_positive_nbr(max);
		ft_putstr(")\n");
	}
	else if (err == ERR_WRONG_NUM)
		ft_putstr("Error : Wrong number. Argument must be larger than 2.\n");
	else if (err == OK)
		return (OK);
	return (ERR);
}

void	factorization(number n)
{
	number	prev;
	number	i;
	int		space;

	prev = 1;
	i = 2;
	space = 0;
	while (n / i)
	{
		if (n % i == 0)
		{
			if (prev != i)
			{
				if (space++)
					ft_putstr(" ");
				ft_put_positive_nbr(i);
			}
			n /= i;
			prev = i;
		}
		else
		{
			// if (n / i <= i)
			// 	return ;
			i++;
		}
	}
	write(1, "\n", 1);
}

