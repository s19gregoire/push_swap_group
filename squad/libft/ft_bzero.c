/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 08:47:23 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/28 18:56:30 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_bzero(void *s, size_t n)
{
	size_t	i;
	char 	*buf;

	buf = (void *)s;
	i = -1;
	while (++i < n)
		buf[i] = 0;
	s = (void *)buf;
	return (s);
}
