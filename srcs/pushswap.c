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
    while (s->prev)
        s = s->prev;
    while (s && s->next)
    {
        if (s->num > s->next->num)
            return (0);
        s = s->next;
    }
    return (1);
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

static int last(t_stack *s)
{
    if (!s)
        return (-1);
    while (s && s->next)
        s = s->next;
    return (s->num);
}

// static void get_newhead(t_stack *s)
// {
//     if (!sorted(s))
//     {
//         while (s && s->next && s->num < s->next->num)
//             s = s->next;
//         while (s && s->prev)
//             ft_shiftdown(&s, 'a');
//     }
// }

static void    sorting(t_stack **a, t_stack **b, int mid, int l)
{
    int c;
    int n;

    c = 0;
    n = 0;
    while (!sorted(*a) && *a)
    {
        while (*a && (*a)->next && (*a)->num >= mid && (*a)->num > (*a)->next->num)
            ft_swap(*a, 'a');
        while (*a && !sorted(*a) && (*a)->num < mid)
        {
            // printf("A");
            // print_stack(*a);
            ft_push(b, (*a)->num, 'b');
            ft_pop(a, (*a)->num);
            if (*b && (*b)->next && (*b)->num < (*b)->next->num)
                ft_swap(*b, 'b');
            else if (*b && !desc(*b) && (*b)->num > last(*b))
                ft_shiftdown(b, 'b');
            else if (*b && !desc(*b) && (*b)->num < last(*b))
                ft_shiftup(b, 'b');
        }
        while (!sorted(*a) && *a && (*a)->next && (*a)->num >= mid && ((*a)->num < last(*a))) //ra
            ft_shiftdown(a, 'a');
        while (*a && (*a)->next && (*a)->num >= mid && (*a)->num > (*a)->next->num)
            ft_swap(*a, 'a');
        while (!sorted(*a) && (*a)->next && (*a)->num >= mid && *a && (*a)->num > last(*a)) //rra
            ft_shiftup(a, 'a');
        while (*a && (*a)->next && (*a)->num >= mid && (*a)->num > (*a)->next->num)
            ft_swap(*a, 'a');
        while (!sorted(*a) && *a && (*a)->next && (*a)->num < (*a)->next->num)
        {
            *a = (*a)->next;
            n = (*a)->num;
            c++;
        }
        while (!sorted(*a) && *a && (*a)->prev)
            *a = (*a)->prev;
        if (!sorted(*a) && c != l && (c < l / 2))
        {
            while (*a && (*a)->num != n)
              ft_shiftup(a, 'a');  
        }
        else if (!sorted(*a) && c != l)
        {
            while (*a && (*a)->num != n)
              ft_shiftdown(a, 'a');
        }
    }
    ft_emptystack(b, a);
}

static int find_middle(t_stack *a, int l)
{
    int mid;
    t_stack *tmp;
    t_stack *head;

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
            tmp = tmp->next;       // enum pour identifier les commandes
        // 0^2 quick sort
        // pre sort tu subdivide et tu trouves les pivot
        // tu utilises les pivot dans la stack pas pre trié
        // radix sort 
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

    mid = find_middle(*a, l);
    sorting(a, b, mid, l);
}