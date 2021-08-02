#include "../inc/pushswap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (a && *a && (*a)->prev)
	{
		*a = (*a)->prev;
	}
	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	ft_emptystack(t_stack **b, t_stack **a)
{
	while (*b)
	{
		ft_push(a, (*b)->num, 'a');
		ft_pop(b, (*b)->num);
	}
}

int	get_stacksize(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*copy_stack(t_stack *s)
{
	t_stack	*c;

	c = NULL;
	while (s)
	{
		new_stack(&c, s->num);
		s = s->next;
	}
	return (c);
}
