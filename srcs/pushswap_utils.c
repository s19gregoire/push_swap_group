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


int    is_sorted(t_stack *s)
{
    while (s && s->next)
    {
        if (s->num > s->next->num)
            return (0);
        s = s->next;
    }
    return (1);
}

void ft_pop(t_stack **s, int i)
{
    t_stack *to_del;

    if (!*s)
        return ; // error and free to handle
    to_del = *s;
    while (to_del && to_del->num != i)
        to_del = to_del->next;
    if (to_del == *s)
        *s = to_del->next;
    if (to_del->next)
        to_del->next->prev = to_del->prev;
    if (to_del->prev)
        to_del->prev->next = to_del->next;
    free(to_del);
}

void ft_push(t_stack **s, int i, char c)
{
    t_stack *top;

    top = malloc(sizeof(t_stack));
    if (!top)
    {
        free_stack(s); // need to free both a and b
        return ;
    }
    if (c)
        printf("p%c\n", c);
    if (*s == NULL)
    {
        *s = top;
        (*s)->num = i;
        (*s)->prev = 0;
        (*s)->next = 0;
        return ;
    }
    top->prev = 0;
    top->next = *s;
    top->num = i;
    *s = top;
}

void ft_swap(t_stack *s, char c)
{
    int tmp;

    tmp = s->next->num;
    s->next->num = s->num;
    s->num = tmp;
    if (c)
        printf("s%c\n", c);
}

void ft_emptystack(t_stack **b, t_stack **a)
{
    while (*b)
    {
        ft_push(a, (*b)->num, 'a');
        ft_pop(b, (*b)->num);
    }
    
}