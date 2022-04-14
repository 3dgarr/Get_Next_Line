#include "get_next_line.h"

char	*ft_del_end(char *temp)
{
	size_t	size;

	size = ft_strchr(temp, '\n') - temp + 1;
	return (ft_substr(temp, 0, size));
}

char	*ft_del_beg(char *temp)
{
	char	*end;

	end = ft_strdup(ft_strchr(temp, '\n') + 1);
	free(temp);
	return (end);
}

char	*ft_strjoin_gnl(char *temp, char *buff)
{
	char *joined_string;

	joined_string = NULL;
	if (!temp)
		return (ft_strdup(buff));
	joined_string = ft_strjoin(temp, buff);
	free(temp);
	return (joined_string);
}

char	*ft_read_join(int fd, char *temp)
{
	ssize_t		bytes_read;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 65535)
		return (NULL);
	if (ft_strchr(temp, '\n'))
		return (temp);
    bytes_read = 1;
    while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE)
		buff[bytes_read] = '\0';
		temp = ft_strjoin_gnl(temp, buff);
		if(ft_strchr(buff, '\n'))
			return (temp);
	}
	return  (temp);
}

char    *get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	*line = NULL;
	temp = ft_read_join(fd, temp);
	line = ft_del_end(temp);
	temp = ft_del_beg(temp);
	return (line);
}