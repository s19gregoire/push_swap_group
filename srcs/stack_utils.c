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

int	get_stacksize(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*copy_stack(t_stack *s)
{
	t_stack	*c;

	c = NULL;
	while (s)
	{
		new_stack(&c, s->num);
		s = s->next;
	}
	return (c);
}
