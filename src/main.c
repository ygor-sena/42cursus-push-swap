#include "../includes/push_swap.h"

/* void    print_stack(t_stack *stack)
{
    int index;

    index = 0;
    while (stack->next != NULL)
    {
        ft_printf("Index %d: %ld\n", index + 1, stack->nbr);
        index++;
        stack = stack->next;
    }
    ft_printf("Index %d: %ld\n", index + 1, stack->nbr);
} */

/* TO DO:   1) change t_nbr_list to t_stack (OK)
            2) stack size function (OK)
            3) Conditions left to do (OK)
            4) Change order: create stack and check for letters (OK) */
int main (int argc, char **argv)
{
    t_stack  *stack_a;

    //t_stack  stack_b;
    stack_a = ft_calloc(1, sizeof(*stack_a));
    if (is_valid_arg(argc, argv, stack_a))
        ft_printf("Let's sort it!\n");
    /* else
        ft_printf("Oops\n"); */
    /* NOTE: Temporary function */
    //print_stack(stack_a);
    stack_cleaning(&stack_a);
    return (EXIT_SUCCESS);
}
