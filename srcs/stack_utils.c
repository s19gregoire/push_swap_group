/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:19:57 by mlazzare          #+#    #+#             */
/*   Updated: 2021/05/13 20:00:54 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

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

int	not_sorted(t_stack *s, int mid, int l)
{
	while (s && s->next)
	{
		if (s->num > s->next->num
			|| (s->num < mid && l != 3))
			return (1);
		s = s->next;
	}
	return (0);
}

int	last(t_stack *s)
{
	if (!s)
		return (-1);
	while (s && s->next)
		s = s->next;
	return (s->num);
}
