
#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include "../shell/shell.h"
# include "../libftv2/libftv2.h"

int		check_exit_eof(char *read);
void	handler_child_quit(int signum);
void	sig_int_empty(int signum);
void	sig_int_proc(int signum);

#endif