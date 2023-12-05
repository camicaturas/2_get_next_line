/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:09:57 by cberneri          #+#    #+#             */
/*   Updated: 2023/11/30 19:10:16 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_readed_line(char *start)
{
	int		i;
	char	*line;

	if (!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] && start[i] != '\n')
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char	*start)
{
	char	*new_buff;
	int		i;
	int		j;

	i = 0;
	while (start[i] && start[i] != '\n')
		i++;
	if (start[i] == '\0')
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	new_buff = (char *)malloc(1 + ft_strlen(start) - i);
	if (!new_buff)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		new_buff[j] = start[i + j];
		j++;
	}
	new_buff[j] = '\0';
	free(start);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	char		*buffer_content;
	int			fd_read;
	static char	*start_str[2048];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	buffer_content = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_content)
		return (NULL);
	while (fd_read != 0)
	{
		fd_read = read(fd, buffer_content, BUFFER_SIZE);
		if (fd_read == -1)
			return ((free(buffer_content), (NULL)));
		buffer_content[fd_read] = '\0';
		start_str = ft_strjoin(start_str, buffer_content);
		if (ft_strchr (start_str, '\n'))
			break ;
	}
	free(buffer_content);
	buffer_content = ft_readed_line(start_str[fd]);
	start_str[fd] = ft_next_line(start_str[fd]);
	return (buffer_content);
}

/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("himno.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}
*/
