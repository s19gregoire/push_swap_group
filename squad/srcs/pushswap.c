/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 04:56:26 by gneve             #+#    #+#             */
/*   Updated: 2021/06/24 04:56:26 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static void	sort_belowmid(t_stack **a, t_stack **b, int mid)
{
	int		min;
	t_stack	*tmp;

	min = mid;
	tmp = *a;
	while (tmp)
	{
		if (tmp->num < mid && tmp->num < min)
		{
			min = tmp->num;
			if (min == mid)
				break ;
			ft_push(b, min, 'b');
			ft_pop(a, min);
		}
		tmp = tmp->next;
	}
}

static void	sort_abovemid(t_stack **a, t_stack **b)
{
	t_stack	*head;

	head = *a;
	while (head)
	{
		if (head->next && head->num > head->next->num)
			ft_swap(head, 'a');
		if (is_sorted(head))
			break ;
		head = head->next;
	}
	ft_emptystack(b, a);
}

static int	find_middle(t_stack *a, int l)
{
	int		mid;
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->next && tmp->num > tmp->next->num)
		{
			ft_swap(tmp, 0);
			tmp = a;
		}
		else
			tmp = tmp->next;
	}
	if (l % 2)
		l = l / 2 + 1;
	else
		l = l / 2;
	while (--l)
		a = a->next;
	mid = a->num;
	return (mid);
}

void	pushswap(t_stack **a, t_stack **b, int l)
{
	int	mid;

	mid = find_middle(*a, l);
	sort_belowmid(a, b, mid);
	sort_abovemid(a, b);
}
