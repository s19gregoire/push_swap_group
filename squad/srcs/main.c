/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:44:34 by mlazzare          #+#    #+#             */
/*   Updated: 2021/05/13 19:57:20 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void print_stack(t_stack *a)
{
    // t_stack *last;

    // last = 0;
    while (a)
    {
        printf("%d\n", a->num);
        // last = a;
        a = a->next;
    }
    // while (last)
    // {
    //     printf("%d\n", last->num);
    //     last = last->prev;
    // }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int l;

    if (argc == 1)
        printf("Error\nInvalid number of args");
    else
    {
        l = argc - 1;
        a = NULL;
        fill_stack(l, argv, &a);
        // print_stack(a);
        b = NULL;
        pushswap(&a, &b, l);
        // print_stack(a);
        // print_stack(b);
        free_stack(&a);
        free_stack(&b);
    }
    return (0);
}