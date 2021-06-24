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

// static void sort_belowmid(t_stack **a, t_stack **b, int mid)
// {
//     int min;

//     min = 0;
//     while (min != mid)
//     {
//         min = (*a)->num;
//         while (*a)
//         {
//             if ((*a)->num < min)
//                 min = (*a)->num;
//             if (!(*a)->next)
//                 break ;
//             *a = (*a)->next;
//         }        
//         while ((*a)->prev)
//             *a = (*a)->prev;
//         ft_push(b, min, 'b');
//         ft_pop(a, min);
//     }
// }

// static void sort_abovemid(t_stack **a, t_stack **b)
// {
//     t_stack *head;

//     head = *a;
//     // printf("a again\n");
//     // print_stack(*a);
//     while (head)
//     {
//         // printf("head %d\n", head->num);
//         if (head->next && head->num > head->next->num)
//             ft_swap(head, 'a');
//         if (is_sorted(head))
//             break ;
//         head = head->next;
//     }
//     ft_emptystack(b, a);
// }

static int last(t_stack *s)
{
    if (s)
        return (-1);
    while (s)
        s = s->next;
    return (s->num);
}

static void    sorting(t_stack **a, t_stack **b, int mid)
{
    while (*a)
    {
        if (*a && (*a)->num < last(*a))
            ft_shiftdown(a, 'a');
        if (*a && (*a)->next && (*a)->num < (*a)->next->num)
            ft_swap(*a, 'a');
        if ((*a)->num < mid)
        {
            ft_push(b, (*a)->num, 'b');
            ft_pop(a, (*a)->num);
            if (*b && (*b)->num < last(*b))
                ft_shiftup(b, 'b');
            if (*b && (*b)->next && (*b)->num < (*b)->next->num)
                ft_swap(*b, 'b');
        }
        *a = (*a)->next;   

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
    // printf("a\n");
    // print_stack(*a);
    // sort_belowmid(a, b, mid);
    // sort_abovemid(a, b);
    sorting(a, b, mid);
    // ft_push(&b, mid);
}