#include "../inc/pushswap.h"

int	ft_exit(t_stack *a)
{
	free_stack(&a);
	exit(0);
}

void	write_cmd(int c)
{
	if (c)
	{
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

static int	to_down(t_stack **a, int mid, int l)
{
	int	max;

	max = get_max(*a);
	if (l == 3)
		return ((*a)->next->next->num != max);
	return (*a && (*a)->next && (*a)->num >= mid && ((*a)->num > last(*a)));
}

static int	to_up(t_stack **a, int mid, int l)
{
	int	min;

	min = get_min(*a);
	if (l == 3)
		return ((*a)->next->next->num != min);
	return ((*a)->next && (*a)->num >= mid && *a && (*a)->num < last(*a));
}

void	sort_three(t_stack **a, int mid, int l)
{
	while (not_sorted(*a, mid, l)
		&& to_down(a, mid, l) && (*a)->num >= mid)
		ft_shiftdown(a, 'a');
	while (not_sorted(*a, mid, l)
		&& to_up(a, mid, l) && (*a)->num >= mid)
		ft_shiftup(a, 'a');
}
