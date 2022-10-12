
#ifndef ENV_H
# define ENV_H

# include "../libftv2/libftv2.h"
# include "../error/error.h"
# include "../const.h"

typedef struct s_env
{
	int		len;
	char	**envp;
}		t_env;

t_env	*init_env(char **envp);
char	*get_env(t_env *env, char *param);
int		set_env(t_env *env, char *param, char *value);
int		del_env(t_env *env, char *param);
int		env_par_exist(t_env *env, char *param);

#endif