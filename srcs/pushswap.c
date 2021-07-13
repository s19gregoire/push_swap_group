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

static	void	big_sort(t_stack **a, t_stack **b)
{
	int	stack;
	int	i;

	i = 0;
	normalise_stack(a);
	while (a && *a && !sorted(*a))
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

static int	get_len(int l)
{
	if (l % 2)
		l = l / 2 + 1;
	else
		l = l / 2;
	return (l);
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
	l = get_len(l);
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
		big_sort(a, b);
}
