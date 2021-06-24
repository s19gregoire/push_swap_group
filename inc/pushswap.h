/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:55:03 by mlazzare          #+#    #+#             */
/*   Updated: 2021/05/13 19:58:03 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

enum e_cmd
{
    VAL0,
    VAL1,
    VAL2,
    MAXVAL,
    INVALIDVAL = -1
};

typedef struct  s_stack
{
    int num;
    struct s_stack *prev;
    struct s_stack *next;
}               t_stack;

int	    ft_atoi(const char *str, t_stack *a);
void    pushswap(t_stack **a, t_stack **b, int l);
void    fill_stack(int c, char **ag, t_stack **a);
void    new_stack(t_stack **a, int value);
void    free_stack(t_stack **a);
void    ft_push(t_stack **s, int i, char c);
void    ft_swap(t_stack *s, char c);
void    ft_pop(t_stack **s, int i);
void    print_stack(t_stack *a);
void    ft_emptystack(t_stack **a, t_stack **b);
int     is_sorted(t_stack *s);

// int input_length(char *input);
// int check_input(char *input, int *a);

# endif