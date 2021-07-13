/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:53:34 by mlazzare          #+#    #+#             */
/*   Updated: 2021/05/13 19:58:26 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static int	desc(t_stack *s)
{
	while (s->prev)
		s = s->prev;
	while (s && s->next)
	{
		if (s->num < s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
}

static int	to_swap(t_stack **a, int mid, int l)
{
	int	max;
	int	min;

	min = get_min(*a);
	max = get_max(*a);
	if (l == 3)
		return (!(((*a)->num == max && (*a)->next->num == min)
				|| ((*a)->num == mid && (*a)->next->num == max)));
	return ((*a)->num >= mid && (*a)->num > (*a)->next->num);
}

static int	distance(t_stack *a, int min)
{
	int	i;

	i = 0;
	while (a && a->num != min)
	{
		i++;
		a = a->next;
	}
	return (i);
}

static void	sort_five(t_stack **a, int mid, int l)
{
	int	min;

	min = get_min(*a);
	if (distance(*a, min) < (l / 2))
	{
		while (not_sorted(*a, mid, l) && (*a)->num != min)
			ft_shiftup(a, 'a');
	}
	else
	{
		while (not_sorted(*a, mid, l) && (*a)->num != min)
			ft_shiftdown(a, 'a');
	}
}


void	small_sort(t_stack **a, t_stack **b, int mid, int l)
{
	while (not_sorted(*a, mid, l) && a && *a)
	{
		if (*a && (*a)->next && to_swap(a, mid, l))
			ft_swap(*a, 'a');
		while (l != 3 && *a && not_sorted(*a, mid, l) && (*a)->num < mid)
		{
			ft_push(b, (*a)->num, 'b');
			ft_pop(a, (*a)->num);
			if (*b && (*b)->next && (*b)->num < (*b)->next->num)
				ft_swap(*b, 'b');
			else if (*b && !desc(*b) && (*b)->num > last(*b))
				ft_shiftdown(b, 'b');
			else if (*b && !desc(*b) && (*b)->num < last(*b))
				ft_shiftup(b, 'b');
		}
		if (get_stacksize(*a) != 3)
			sort_five(a, mid, l);
		else
			sort_three(a, mid, l);
	}
	ft_emptystack(b, a);
}
