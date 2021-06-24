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

void    free_stack(t_stack **a)
{
    t_stack *tmp;

    while (*a)
    {
        tmp = (*a)->next;
        free(*a);
        *a = tmp;
    }
}

void    new_stack(t_stack **a, int value)
{
    t_stack *curr;
    t_stack *last;

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

void    fill_stack(int c, char **ag, t_stack **a)
{
    int i;
    int value;

    i = 0;
    while (++i <= c)
    {
        value = ft_atoi(ag[i], *a);
        new_stack(a, value);
    }
}