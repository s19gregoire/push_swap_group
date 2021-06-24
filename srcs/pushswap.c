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

static void sort_belowmid(t_stack **a, t_stack **b, int mid)
{
    int min;
    t_stack *tmp;
    t_stack *head;
    
    tmp = *a;
    min = tmp->num;
    head = tmp;
    while (min != mid)
    {
        while (tmp && tmp->next)
        {
            if (tmp->num < tmp->next->num && tmp->num < min)
                min = tmp->num;
            tmp = tmp->next;
        }        
        if (min == mid)
            break ;
        ft_push(b, min, 'b');
        ft_pop(a, min);
        tmp = head;
        min = head->num;
    }
    // printf("b\n");
    // print_stack(*b);
    // printf("a\n");
    // print_stack(*a);
}

static void sort_abovemid(t_stack **a, t_stack **b)
{
    t_stack *head;

    head = *a;
    // printf("a again\n");
    // print_stack(*a);
    while (head)
    {
        // printf("head %d\n", head->num);
        if (head->next && head->num > head->next->num)
            ft_swap(head, 'a');
        if (is_sorted(head))
            break ;
        head = head->next;
    }
    ft_emptystack(b, a);
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
    sort_belowmid(a, b, mid);
    sort_abovemid(a, b);
    // ft_push(&b, mid);
}