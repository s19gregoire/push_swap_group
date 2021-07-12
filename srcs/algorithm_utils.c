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

void	ft_rr(t_stack **a, t_stack **b, char c)
{
	ft_shiftup(a, c);
	ft_shiftup(b, c);
	printf("rr\n");
}

void	ft_rrr(t_stack **a, t_stack **b, char c)
{
	ft_shiftdown(a, c);
	ft_shiftdown(b, c);
	printf("rrr\n");
}

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
