/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuanena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:09:24 by sjuanena          #+#    #+#             */
/*   Updated: 2022/01/13 19:56:22 by sjuanena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	calcu_line(char	*buffer, char *read_line)
{
	int		flag;
	size_t	i;
	size_t	lenb;
	size_t	lenf;
	char	*found;

	flag = 0;
	lenb = ft_strlen(buffer);
	found = ft_strchr(buffer, '\n');
	if (found != NULL)
	{
		lenf = ft_strlen(found);
		i = lenb - lenf + 1;
		buffer[i] = '\0';
		flag = 1;
	}
	if (read_line == NULL)
		read_line = buffer;
	else
		read_line = ft_strjoin(read_line, buffer);
	printf("read line: %s, flag: %d\n", read_line, flag);
	return (flag);
}

char	*get_next_line(int fd)
{
	int			nbytes;
	int			flag;
	char		*buffer;
	static char	*read_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nbytes = 1;
	flag = 0;
	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	while (nbytes > 0 && flag == 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		flag = calcu_line(buffer, read_line);
	}
	free(buffer);
	return (read_line);
}

int	main(void)
{
	int		i;
	char	*line;
	int		fd;

	i = 1;
	fd = open("prueba.txt", O_RDONLY);
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("Fichero: %d\n", fd);
		printf("%s", line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}
