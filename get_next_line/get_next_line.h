#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

int					get_next_line(char **line);
int					read_line(char **remainder, char **line);
int					cut_line(char **line, char **remainder);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					ctrl_d(char *remainder);

#endif
