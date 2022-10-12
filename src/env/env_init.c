
#include "env.h"

void	copy_envp(t_env *env, char **envp)
{
	int	i;

	i = -1;
	env->envp = ft_zalloc(sizeof(char **) * (env->len + 1));
	while (++i < env->len)
		env->envp[i] = ft_strdup(envp[i]);
}

t_env	*init_env(char **envp)
{
	t_env	*env;
	int		size;

	size = 0;
	while (envp[size])
		size++;
	env = ft_zalloc(sizeof(t_env) * size);
	env->len = size;
	copy_envp(env, envp);
	set_env(env, "?", "0");
	return (env);
}
