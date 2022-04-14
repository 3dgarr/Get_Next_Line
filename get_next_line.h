#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_join(int fd, char *temp, char);
char	*ft_strjoin_gnl(char *temp, char *buff);
char	*ft_del_end(char *temp);
char	*ft_del_beg(char *temp);
char	*ft_strjoin_gnl(char *temp, char *buff);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strlen;//maybenot

#endif