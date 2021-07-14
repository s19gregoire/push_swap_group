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

void	new_stack(t_stack **a, int value)
{
	t_stack	*curr;
	t_stack	*last;

	curr = malloc(sizeof(t_stack));
	if (!curr)
		return (free_stack(a));
	curr->num = value;
	curr->next = 0;
	curr->pos = 0;
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

int	fill_stack(int c, int ac, char **ag, t_stack **a)
{
	int	i;
	int	j;
	int	value;

	i = 0;
	while (++i <= c)
	{
		value = ft_atoi(ag[i], *a);
		new_stack(a, value);
		j = i + 1;
		while (j < ac)
		{
			if (value == ft_atoi(ag[j], *a))
				return (0);
			j++;
		}
	}
	return (1);
}

static void	ft_quicksort(t_stack *tmp, t_stack *head)
{
	while (tmp)
	{
		if (tmp->next && tmp->num > tmp->next->num)
		{
			ft_swap(tmp, 0);
			tmp = head;
		}
		else
			tmp = tmp->next;
	}
}

static void	normal_value(t_stack **a, t_stack *tmp, int i)
{
	if (a && *a && !(*a)->pos)
	{
		(*a)->num = i;
		(*a)->pos = 1;
	}
	else
	{
		if (a && *a)
			*a = (*a)->next;
		while (a && *a && (*a)->num != tmp->num)
			*a = (*a)->next;
		if (a && *a)
		{
			(*a)->num = i;
			(*a)->pos = 1;
		}
	}
}

void	normalise_stack(t_stack **a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*head;

	tmp = copy_stack(*a);
	if (!tmp)
		ft_exit(*a);
	head = tmp;
	i = 0;
	ft_quicksort(tmp, head);
	tmp = head;
	while (tmp)
	{
		while (a && *a && (*a)->num != tmp->num)
			*a = (*a)->next;
		normal_value(a, tmp, i);
		while (a && *a && (*a)->prev)
			*a = (*a)->prev;
		i++;
		tmp = tmp->next;
	}
	free_stack(&head);
}
