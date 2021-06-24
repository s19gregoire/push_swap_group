/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 04:59:43 by gneve             #+#    #+#             */
/*   Updated: 2021/06/24 04:59:43 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	new_stack(t_stack **a, int value)
{
	t_stack	*curr;
	t_stack	*last;

	curr = malloc(sizeof(t_stack));
	if (!curr)
		return (free_stack(a));
	curr->num = value;
	curr->next = 0;
	if (*a == NULL)
	{
		curr->prev = NULL;
		*a = curr;
		return ;
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = curr;
	curr->prev = last;
	return ;
}

void	fill_stack(int c, char **ag, t_stack **a)
{
	int	i;
	int	value;

	i = 0;
	while (++i <= c)
	{
		value = ft_atoi(ag[i], *a);
		new_stack(a, value);
	}
}
