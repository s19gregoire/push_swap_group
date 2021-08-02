#include "../inc/pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		l;

	if (argc != 1)
	{
		l = argc - 1;
		a = NULL;
		if (!fill_stack(l, argc, argv, &a))
		{
			write(1, "Error\n", 6);
			free_stack(&a);
			return (0);
		}
		b = NULL;
		pushswap(&a, &b, l);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
