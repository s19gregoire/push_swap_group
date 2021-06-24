/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 05:00:32 by gneve             #+#    #+#             */
/*   Updated: 2021/06/24 05:00:32 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

static int	check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str, t_stack *a)
{
	int						i;
	int						sign;
	unsigned long long int	n;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = check_sign(str[i++]);
	if (!ft_isdigit(str[i]))
	{
		printf("Error\nArg is not a valid number\n");
		free_stack(&a);
		exit (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (n >= INT_MAX)
		{
			printf("Error\nNumber is not a valid int\n");
			free_stack(&a);
			exit (0);
		}
		n = n * 10 + (str[i++] - '0');
	}
	return (sign * (int)n);
}