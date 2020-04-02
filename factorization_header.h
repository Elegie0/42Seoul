#ifndef FACTORIZATION_HEADER_H
# define FACTORIZATION_HEADER_H
# include <unistd.h>
# define ERR 1
# define OK 0
# define ERR_NO_ARGUMENTS 645
# define ERR_WRONG_ARGUMENTS 56745
# define ERR_TOO_MANY_ARGUMENTS 35234
# define ERR_OVERFLOW 245
# define ERR_WRONG_NUM 785
typedef unsigned int number;
# define U_SIGNED_TYPE
# ifdef SIGNED_TYPE
# define INIT_MAX\
	ft_memset(&max, 0xff, sizeof(max));\
	if (max < 0)\
		ft_memset((unsigned char*)&max + sizeof(max) - 1, 0x7f, 1);
# endif
# ifdef U_SIGNED_TYPE
# define INIT_MAX\
	ft_memset(&max, 0xff, sizeof(max));
# endif
/*
** factorization.c
*/
int		check_overflow(char s, number num);
int		init(int argc, char **argv, number *num);
int		print_err(int err);
void	factorization(number n);
/*
** factorization_util.c
*/
void	ft_memset(void *p, int v, unsigned int s);
void	ft_put_positive_nbr(number n);
void	ft_putstr(char	*s);
int		contain(char c, char *s);
#endif