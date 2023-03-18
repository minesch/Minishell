#include "main.h"

void	built_exec(t_element **ptr)
{
	t_element	*elem;

	elem = *ptr;
	if (ft_strcmp(elem->command->args[0], "echo") == 0)
		echo_built(elem);
	else if (ft_strcmp(elem->command->args[0], "cd") == 0)
		cd_built(elem);
	else if (ft_strcmp(elem->command->args[0], "pwd") == 0)
		pwd_built();
	else if (ft_strcmp(elem->command->args[0], "env") == 0)
		env_built(g_lobal->env);
	else if (ft_strcmp(elem->command->args[0], "export") == 0)
		export_built(elem);
	else if (ft_strcmp(elem->command->args[0], "unset") == 0)
		unset_built(elem);
	else if (ft_strcmp(elem->command->args[0], "exit") == 0)
		exit_built(elem);
	elem = elem->next;
	*ptr = elem;
}
