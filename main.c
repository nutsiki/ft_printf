#include "includes/ft_printf.h"

int main()
{
	int i;

	i=13;
	ft_printf("%d%i%x%X%u%s%c%p", 1, 2, 3, 4, 5, "coucou", 'c', &i);
	return (0);
}