#include "main.h"

void	free_exported_env(t_env **head)
{
	t_env	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

int	export_free(t_env *new_node, char *name)
{
	free(new_node);
	free(name);
	return (1);
}
