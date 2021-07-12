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
		(*a)->pos = 0;
		j = i + 1;
		while (j < ac)
		{
			if (value == ft_atoi(ag[j], *a))
			{
				printf("Error\n");
				return (0);
			}				
			j++;
		}
	}
	return (1);
}

static void	normal_value(t_stack **a, t_stack *tmp, int i)
{
	if (!(*a)->pos)
	{
		(*a)->num = i;
		(*a)->pos = 1;
	}
	else
	{
		*a = (*a)->next;
		while (*a && (*a)->num != tmp->num)
			*a = (*a)->next;
		(*a)->num = i;
		(*a)->pos = 1;
	}
}

void	normalise_stack(t_stack **a)
{
	int		i;
	t_stack	*tmp;
	t_stack	*head;

	tmp = copy_stack(*a);
	head = tmp;
	i = 0;
	ft_quicksort(tmp, head);
	tmp = head;
	while (tmp)
	{
		while ((*a)->num != tmp->num)
			*a = (*a)->next;
		normal_value(a, tmp, i);
		while (*a && (*a)->prev)
			*a = (*a)->prev;
		i++;
		tmp = tmp->next;
	}
	free_stack(&tmp);
}
