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
    while (a)
    {
        printf("%d\n", a->num);
        a = a->next;
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int l;

    if (argc == 1)
        printf("Error\nInvalid number of args\n");
    else
    {
        l = argc - 1;
        a = NULL;
        fill_stack(l, argv, &a);
        b = NULL;
        pushswap(&a, &b, l);
        // print_stack(a);
        free_stack(&a); 
        free_stack(&b);
    }
    return (0);
}
