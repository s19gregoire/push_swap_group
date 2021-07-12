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

// static int check_doubles(int argc, char *argv[])
// {
// 	int i;
// 	int j;
// 	int a;
// 	int b;

// 	i = 0;
// 	j = 1;

// 	while(i < argc)
// 	{
// 		j = i + 1;
// 		while(j < argc)
// 		{
// 			a = atoi_push_swap(argv[i]);
// 			b = atoi_push_swap(argv[j]);
// 			if (a == b)
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }


void print_stack(t_stack *a)
{
    while (a)
    {
        printf("%d\n", a->num);
        a = a->next;
    }
}

// void putstr(char *str)
// {
// 	while(*str)
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// 		write(1, "\n", 1);
// }


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int l;

    if (argc != 1)
    {
        l = argc - 1;
        a = NULL;
        if (!fill_stack(l, argc, argv, &a))
        {
            free_stack(&a);
            return (0);
        }
        b = NULL;
        pushswap(&a, &b, l);
        // print_stack(a);
        free_stack(&a); 
        free_stack(&b);
    }
    return (0);
}
