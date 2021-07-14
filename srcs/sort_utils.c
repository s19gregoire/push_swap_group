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

int	get_min(t_stack *s)
{
	int	min;

	min = s->num;
	while (s)
	{
		if (s->num < min)
			min = s->num;
		s = s->next;
	}
	return (min);
}

int	get_max(t_stack *s)
{
	int	min;

	min = s->num;
	while (s)
	{
		if (s->num > min)
			min = s->num;
		s = s->next;
	}
	return (min);
}

int	sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
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
