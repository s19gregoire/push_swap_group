#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int					num;
	int					pos;
	struct s_stack		*prev;
	struct s_stack		*next;
}				t_stack;

int		ft_atoi(const char *str, t_stack *a);
int		not_sorted(t_stack *a, int mid, int l);
int		sorted(t_stack *a);
int		last(t_stack *a);
int		get_min(t_stack *s);
int		get_max(t_stack *s);
int		get_stacksize(t_stack *a);
int		get_stacksize(t_stack *a);
int		fill_stack(int c, int ac, char **ag, t_stack **a);
int		ft_exit(t_stack *a);
void	new_stack(t_stack **a, int value);
void	free_stack(t_stack **a);
void	normalise_stack(t_stack **a);
void	ft_push(t_stack **s, int i, char c);
void	ft_swap(t_stack *s, char c);
void	ft_pop(t_stack **s, int i);
void	ft_emptystack(t_stack **a, t_stack **b);
void	ft_shiftdown(t_stack **s, char c);
void	ft_shiftup(t_stack **s, char c);
void	ft_rr(t_stack **a, t_stack **b, char c);
void	ft_rrr(t_stack **a, t_stack **b, char c);
void	pushswap(t_stack **a, t_stack **b, int l);
void	small_sort(t_stack **a, t_stack **b, int mid, int l);
void	sort_three(t_stack **a, int mid, int l);
void	write_cmd(int c);
t_stack	*copy_stack(t_stack *s);

#	endif
