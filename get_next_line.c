/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:09:57 by cberneri          #+#    #+#             */
/*   Updated: 2023/11/23 11:55:10 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

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
	line = (char *)malloc(1 + i * sizeof(char));
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

char	*ft_move_start(char	*start)
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
	static char	*start_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = 1;
	//temp es la data que tengo que leer
	buffer_content = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!buffer_content)
		return (NULL);
	//si no encuentro el salto de linea o si no puedo leer el archivo sigo leyendo segund el buffer
	while (!(ft_strchr(start_str, '\n')) && fd_read != 0)
	{
		//leo el archivo y lo meto en un buffer
		fd_read = read(fd, buffer_content, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(buffer_content);
			return (NULL);
		}
		buffer_content[fd_read] = '\0';
		start_str = ft_strjoin(start_str, buffer_content);
	}
	free(buffer_content);
	buffer_content = ft_readed_line(start_str);
	start_str = ft_move_start(start_str);
	return (buffer_content);
}

/*
void countCalls() {
	static int count = 0;
	count++;
	printf("This function has been called %d times.\n", count);
}
*/
/*
 
//esto lo hice yo pero es PURA BASURA

char	*get_next_line(int fd)
{
	size_t	i;
	char	*memtemp;

	//if (fd < 0 || BUFFER_SIZE <= 0 || read(fd,&next_line, 0) < 0)
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memtemp = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!memtemp)
		return (NULL);

	read(fd, buff, BUFFER_SIZE);

	i = 0;
	while(buff > 0)
	{
		printf("%c",buff[i]);
		if(buff[i] == '\n')
			return (0);
		i++;
	}

	//printf("\n\n%s\n\n",buff);

	return (0);
}
*/
int main(void)
{
	fd = open("filestoread/himno.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
}






/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd2 = open(argv[1], O_RDONLY);
	
	if (fd == -1)
	{
		printf("open() error\n");
		return (1);
	}
	
	line = "";
	while (line != NULL)
	{
		line = get_next_line(1);
		printf("%s", line);
		free(line);
	}
	fd = close(fd);
	if (fd == -1)
	{
		printf("close() error\n");
		return (1);
	}
	printf("%d", fd);
	return (0);
}

*/







/*



char	*get_next_line(int fd)
{
	size_t	i;
	
	char buff[8024];
	char path[] = "filestoread/himno.txt";

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd = open(path, O_RDONLY);
	read(fd, buff, 11124);

	i = 0;
	while(buff > 0)
	{
		printf("%c",buff[i]);
		if(buff[i] == '\n')
			return (0);
		i++;
	}

	//printf("\n\n%s\n\n",buff);

	return (0);
}
#include <stdio.h>
#include <fcntl.h>
int main()
{
	get_next_line(1);
}
*/
/*

get_next_line(FILE DESCRIPTOR);

*/