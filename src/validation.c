#include "../includes/push_swap.h"

static t_bool   is_ordered_stack(t_stack *stack_a);
static t_bool   is_duplicate_nbr(t_stack *stack_a);
static int      fill_stack(int argc, char **argv, t_stack *stack_a);
static t_bool   is_long(long long nbr);

t_bool  is_valid_arg(int argc, char **argv, t_stack *stack_a)
{  
    if (argc == 1 || fill_stack(argc, argv, stack_a))
        return (FALSE);
    if (stack_size(stack_a) < 2 \
        || is_ordered_stack(stack_a) \
        || !is_duplicate_nbr(stack_a))
        return (FALSE);
    return (TRUE);
}

static t_bool   is_ordered_stack(t_stack *stack_a)
{
    while (stack_a->next != NULL)
    {
        if (stack_a->nbr > stack_a->next->nbr)
            return (FALSE);
        stack_a = stack_a->next;
    }
    return (TRUE);
}

static t_bool   is_duplicate_nbr(t_stack *stack_a)
{
    t_stack *tmp;

    while (stack_a->next != NULL)
    {
        tmp = stack_a->next;
        while (tmp != NULL)
        {
            if (stack_a->nbr == tmp->nbr)
                return (TRUE); 
            tmp = tmp->next; 
        }
        stack_a = stack_a->next;
    }
    return (FALSE);
}

static int  fill_stack(int argc, char **argv, t_stack *stack_a)
{
    int         param;
    int         index;
    char        **input_nbr;
    long long   converted;
    t_stack   *new_node;

    param = 1;
    while (param < argc)
    {
        input_nbr = ft_split(argv[param], SPACE_CHR); 
        index = 0;
        /* THIS CAN BE ANOTHER FUNCTION */
        while (input_nbr[index])
        {
            converted = ft_atol(input_nbr[index]);
            if (!is_nondigit(input_nbr[index]) \
                || is_long(converted))
            {
                ft_printf(ERROR_MSG);
                free_split(input_nbr);
                return (FALSE);
            }
            if (!stack_a->nbr)
                stack_a->nbr = ft_atol(input_nbr[index]);
            else
            {
                new_node = create_node(converted);
                if (!new_node)
                    return (FALSE);
                add_back_nbr(&stack_a, new_node);
            }
            index++;
        }
        free_split(input_nbr);
        param++;
    }
    return (TRUE);
}

static t_bool   is_long(long long nbr)
{
    if (nbr > MAX_INT || nbr < MIN_INT)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
