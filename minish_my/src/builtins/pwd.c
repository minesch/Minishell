#include "main.h"

void	pwd_built(void)
{
	char	pwd[PATH_MAX];
	char	*pwd_ptr;

	getcwd(pwd, sizeof(pwd));
	pwd_ptr = ft_strdup(pwd);
	ft_putstr_fd(pwd_ptr, 1);
	ft_putstr_fd("\n", 1);
	free (pwd_ptr);
	set_status(0);
}
