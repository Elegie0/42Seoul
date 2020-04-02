#include "factorization_header.h"

void	ft_memset(void *p, int v, unsigned int s)
{
	unsigned char	*c;

	c = (unsigned char*)p;
	while (s)
	{
		*c++ = v;
		s--;
	}
}

void	ft_put_positive_nbr(number n)
{
	if (n)
	{
		ft_put_positive_nbr(n / 10);
		write(1, &"0123456789"[n % 10], 1);
	}
}

void	ft_putstr(char	*s)
{
	while (*s)
		write(1, s++, 1);
}

int		contain(char c, char *s)
{
	while (*s)
		if (c == *s++)
			return (c);
	return (0);
}