/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:02:23 by leyeghia          #+#    #+#             */
/*   Updated: 2022/04/22 18:44:05 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *line)
{
	char	buff[BUFFER_SIZE + 1];
	int		br;

	br = 1;
	while (br)
	{
		br = read(fd, buff, BUFFER_SIZE);
		if (br == -1)
			return (0);
		buff[br] = '\0';
		line = ft_strjoin(line, buff);
		if (ft_strchr(buff, '\n') || !br)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*ret_line;
	char		*free_line;
	long		len;

	line = get_line(fd, line);
	if (!line)
		return (0);
	len = ft_strlen(line) - ft_strlen(ft_strchr(line, '\n')) + 1;
	ret_line = ft_substr(line, 0, len);
	free_line = line;
	line = ft_substr(line, len, ft_strlen(line) - len);
	free(free_line);
	return (ret_line);
}

int	main(void)
{
	printf("%s", get_next_line(open("text.txt", O_RDONLY)));
	printf("%s", get_next_line(open("text.txt", O_RDONLY)));
	printf("%s", get_next_line(open("text.txt", O_RDONLY)));
	printf("%s", get_next_line(open("text.txt", O_RDONLY)));
	printf("%s", get_next_line(open("text.txt", O_RDONLY)));
	printf("%s", get_next_line(open("text.txt", O_RDONLY)));
	printf("%s", get_next_line(open("text.txt", O_RDONLY)));
	printf("%s", get_next_line(open("text.txt", O_RDONLY)));
}
