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

int	is_sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
}

int	desc(t_stack *s)
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

int	to_swap(t_stack **a, int mid, int l)
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

int	to_down(t_stack **a, int mid, int l)
{
	int	max;

	max = get_max(*a);
	if (l == 3)
		return ((*a)->next->next->num != max);
	return (*a && (*a)->next && (*a)->num >= mid && ((*a)->num > last(*a)));
}

int	to_up(t_stack **a, int mid, int l)
{
	int	min;

	min = get_min(*a);
	if (l == 3)
		return ((*a)->next->next->num != min);
	return ((*a)->next && (*a)->num >= mid && *a && (*a)->num < last(*a));
}
