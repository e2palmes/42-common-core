#include "ft_printf.h"

#include <stdio.h>

int main(void)
{
	const char str[] = " %u ";
	const int p = -9;
	int r;
	printf("\n====== FT_PRINTF ======\n");
	r = ft_printf(str);
	ft_printf("\nreturn value: %i\n", r);
	printf("\n\n====== PRINT_F ======\n");
	r = printf(str, p);
	printf("\nreturn value: %i\n", r);
	return (0);
}
