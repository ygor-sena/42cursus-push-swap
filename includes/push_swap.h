/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:19:38 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/20 10:42:04 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ERROR_MSG "Error\n"
# define SPACE_CHR ' '
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct t_stack
{
	long long			nbr;
	struct t_stack		*next;
}	t_stack;

t_stack		*create_node(long long nbr);
t_stack		*get_last_nbr(t_stack *lst);
t_stack		*get_penul_nbr(t_stack *lst);
void		add_back_nbr(t_stack **lst, t_stack *new);
void		stack_cleaning(t_stack **lst);
int			stack_size(t_stack *lst);

void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);

void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_both(t_stack **stack_a, t_stack **stack_b);

void		reverse_a(t_stack **stack_a);
void		reverse_b(t_stack **stack_b);
void		reverse_both(t_stack **stack_a, t_stack **stack_b);

void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_both(t_stack **stack_a, t_stack **stack_b);

t_bool		is_valid_arg(int argc, char **argv, t_stack **stack_a);
t_bool		is_nondigit(char *string);

void		free_split(char **split);

#endif
