
#ifndef REDIRECT_H
# define REDIRECT_H

# include <fcntl.h>
# include <errno.h>
# include <readline/readline.h>

# include "../error/error.h"
# include "../libftv2/libftv2.h"

# define IN 1
# define OUT 2
# define IN_DOC 3
# define OUT_DOC 4

typedef struct s_redir	t_redir;

struct s_redir
{
	int		type;
	int		fd;
	char	*file;
};

int	open_file(t_redir *new);

#endif