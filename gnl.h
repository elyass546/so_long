#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char c);
size_t	ft_strlen(char *str);

#endif