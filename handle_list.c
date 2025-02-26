#include "ft_mini_ls.h"

t_file  *get_last_node(t_file *files)
{
    t_file  *tmp;

    tmp = files;
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

void	append_node(t_file *files, t_file *new_node)
{
	t_list	*op_node;
	t_list	*current;

	current = ops;
	op_node = ft_calloc(1, sizeof(t_list));
	if (!op_node)
	{
		free_stack(stacks);
		free_ops(ops);
		exit (EXIT_FAILURE);
	}
	op_node->value = op;
	op_node->next = NULL;
	while (current->next)
		current = current->next;
	current->next = op_node;
}
