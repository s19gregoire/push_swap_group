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

static int get_min(t_stack *s)
{
	int min;

	min = s->num;
	while (s)
	{
		if (s->num < min)
			min = s->num;
		s = s->next;
	}
	return (min);
}

static int get_max(t_stack *s)
{
	int min;

	min = s->num;
	while (s)
	{
		if (s->num > min)
			min = s->num;
		s = s->next;
	}
	return (min);

}

static t_stack *copy_stack(t_stack *s)
{
	t_stack *c;

	c = NULL;
	while (s)
	{
		new_stack(&c, s->num);
		s = s->next;
	}
	return (c);
}

static int  sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
}

static int  not_sorted(t_stack *s, int mid, int l)
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

static int last(t_stack *s)
{
	if (!s)
		return (-1);
	while (s && s->next)
		s = s->next;
	return (s->num);
}

static int  desc(t_stack *s)
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

static int to_swap(t_stack **a, int mid, int l)
{
	int max;
	int min;

	min = get_min(*a);
	max = get_max(*a);
	if (l == 3)
		return (!(((*a)->num == max && (*a)->next->num == min) || ((*a)->num == mid && (*a)->next->num == max)));
	return ((*a)->num >= mid && (*a)->num > (*a)->next->num);
}

static int to_down(t_stack **a, int mid, int l)
{
	int max;

	max = get_max(*a);
	if (l == 3)
		return ((*a)->next->next->num != max);
	return (*a && (*a)->next && (*a)->num >= mid && ((*a)->num > last(*a)));
}

static int to_up(t_stack **a, int mid, int l)
{
	int min;

	min = get_min(*a);
	if (l == 3)
		return ((*a)->next->next->num != min);
	return ((*a)->next && (*a)->num >= mid && *a && (*a)->num < last(*a));
}

static void    small_sort(t_stack **a, t_stack **b, int mid, int l)
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

static void ft_quicksort(t_stack *tmp, t_stack *head)
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

static void normalise_stack(t_stack **a)
{
	int i;
	t_stack *tmp;
	t_stack *head;

	tmp = copy_stack(*a);
	head = tmp;
	i = 0;
	ft_quicksort(tmp, head);
	tmp = head;
	while (tmp)
	{
		while (*a && (*a)->num != tmp->num)
			*a = (*a)->next;
		if (*a && !(*a)->pos)
		{
			(*a)->num = i;
			(*a)->pos = 1;
		}
		else
		{
			if (*a)
				*a = (*a)->next;
			while (*a && (*a)->num != tmp->num)
				*a = (*a)->next;
			if (*a)
			{
				(*a)->num = i;
				(*a)->pos = 1;
			}
		}
		while (*a && (*a)->prev)
			*a = (*a)->prev;
		i++;
		tmp = tmp->next;
	}
	free_stack(&tmp);
}

static int  get_stacksize(t_stack *a)
{
	int i;
	
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

static void    bucket_sort(t_stack **a, t_stack **b)
{
	int bits;
	int max;
	int stack;
	int i;

	bits = 0;
	i = 0;
	max = get_max(*a);
	while (max >> bits)
		bits++;
	normalise_stack(a);
	while (a && *a && !sorted(*a) && i < bits)
	{
		stack = get_stacksize(*a);
		while (a && *a && stack--)
		{
			if ((((*a)->num >> i)&1))
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

static int find_middle(t_stack *a, int l)
{
	int			mid;
	t_stack		*tmp;
	t_stack		*head;

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
	if (l % 2)
		l = l / 2 + 1;
	else
		l = l / 2;
	while (--l)
		tmp = tmp->next;
	mid = tmp->num;
	free_stack(&tmp);
	return (mid);
}

void pushswap(t_stack **a, t_stack **b, int l)
{
	int mid;

	if (sorted(*a))
		return ;
	mid = find_middle(*a, l);
	if (l <= 5)
		small_sort(a, b, mid, l);
	else
		bucket_sort(a, b);
}