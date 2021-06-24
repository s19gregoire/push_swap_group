/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:22:34 by mlazzare          #+#    #+#             */
/*   Updated: 2021/04/28 21:41:22 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strrchr(const char *s, int c)
{
	char	*ret;
	int		l;

	l = (int)ft_strlen(s) + 1;
	ret = (char *)s;
	while (l >= 0)
	{
		if (ret[l] == (char)c)
			return (1);
		l--;
	}
	return (0);
}
