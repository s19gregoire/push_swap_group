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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		l;

	if (argc != 1)
	{
		l = argc - 1;
		a = NULL;
		if (!fill_stack(l, argc, argv, &a))
		{
			printf("Error\n");
			free_stack(&a);
			return (0);
		}
		b = NULL;
		pushswap(&a, &b, l);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
