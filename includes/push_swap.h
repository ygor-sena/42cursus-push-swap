/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorgsena <ygorgsena@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:19:38 by yde-goes          #+#    #+#             */
/*   Updated: 2022/10/25 14:50:43 by ygorgsena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ERROR_MSG "Error\n"
# define SPACE_CHR ' '
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	size_t				index;
	long long			nbr;
	struct s_stack		*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	size_a;
	size_t	size_b;
}	t_push_swap;

t_stack		*create_new_nbr(long long nbr);
t_stack		*get_last_nbr(t_stack *lst);
t_stack		*get_penul_nbr(t_stack *lst);
void		add_back_nbr(t_stack **lst, t_stack *new);

t_bool		is_valid_arg(t_stack **stack_a);
t_bool		is_nondigit(char *string);
t_stack		*fill_stack(int argc, char **argv);

t_bool		is_ordered_stack(t_stack *stack_a);
void		fill_index_stack(t_stack **stack_a);
size_t		get_stack_size(t_stack *lst);
size_t		get_smallest_index(t_stack **stack_a);

void		push_a(t_push_swap **data, t_stack **stack_a, t_stack **stack_b);
void		push_b(t_push_swap **data, t_stack **stack_a, t_stack **stack_b);

void		rotate_a(t_stack **stack_a);
void		rotate_b(t_stack **stack_b);
void		rotate_both(t_stack **stack_a, t_stack **stack_b);

void		reverse_a(t_stack **stack_a);
void		reverse_b(t_stack **stack_b);
void		reverse_both(t_stack **stack_a, t_stack **stack_b);

void		swap_a(t_stack **stack_a);
void		swap_b(t_stack **stack_b);
void		swap_both(t_stack **stack_a, t_stack **stack_b);

void		sort_three(t_stack **stack_a);
void		sort_five(t_push_swap *data);
void		sort_many(t_push_swap *data);

void		free_split(char **split);
void		free_stack(t_stack **stack);
void		exit_program(t_stack **stack_a, t_stack **stack_b);

void		print_stack_a(t_stack *stack);
void		print_stack_b(t_stack *stack);
#endif
