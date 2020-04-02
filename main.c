#include "factorization_header.h"

int		main(int argc, char **argv)
{
	number	num;
	
	if (print_err(init(argc, argv, &num)) == ERR)
		return (ERR);
	factorization(num);
	return (0);
}