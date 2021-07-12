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

static	void	small_sort(t_stack **a, t_stack **b, int mid, int l)
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
		while (not_sorted(*a, mid, l) && to_down(a, mid, l))
			ft_shiftdown(a, 'a');
		if (not_sorted(*a, mid, l) && *a && (*a)->next && (to_swap(a, mid, l)))
			ft_swap(*a, 'a');
		while (not_sorted(*a, mid, l) && to_up(a, mid, l))
			ft_shiftup(a, 'a');
	}
	ft_emptystack(b, a);
}

void	ft_quicksort(t_stack *tmp, t_stack *head)
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

static	void	bucket_sort(t_stack **a, t_stack **b)
{
	int	bits;
	int	stack;
	int	i;

	bits = 0;
	i = 0;
	while (get_max(*a) >> bits)
		bits++;
	normalise_stack(a);
	while (a && *a && !sorted(*a) && i < bits)
	{
		stack = get_stacksize(*a);
		while (a && *a && stack--)
		{
			if ((((*a)->num >> i) & 1 ))
				ft_shiftup(a, 'a');
			else
			{
				ft_push(b, (*a)->num, 'b');
				ft_pop(a, (*a)->num);
			}
		}
		ft_emptystack(b, a);
		i++;
	}
}

static	int	find_middle(t_stack *a, int l)
{
	int		mid;
	t_stack	*tmp;
	t_stack	*head;

	tmp = copy_stack(a);
	head = tmp;
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
	tmp = head;
	l = l / 2;
	if (l % 2)
		l += 1;
	while (--l)
		tmp = tmp->next;
	mid = tmp->num;
	free_stack(&tmp);
	return (mid);
}

void	pushswap(t_stack **a, t_stack **b, int l)
{
	int	mid;

	if (sorted(*a))
		return ;
	mid = find_middle(*a, l);
	if (l <= 5)
		small_sort(a, b, mid, l);
	else
		bucket_sort(a, b);
}
