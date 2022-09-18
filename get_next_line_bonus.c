/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leyeghia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:24:26 by leyeghia          #+#    #+#             */
/*   Updated: 2022/04/22 18:48:53 by leyeghia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*line[OPEN_MAX];
	char		*ret_line;
	char		*free_line;
	long		len;

	line[fd] = get_line(fd, line[fd]);
	if (!line[fd])
		return (0);
	len = ft_strlen(line[fd]) - ft_strlen(ft_strchr(line[fd], '\n')) + 1;
	ret_line = ft_substr(line[fd], 0, len);
	free_line = line[fd];
	line[fd] = ft_substr(line[fd], len, ft_strlen(line[fd]));
	free(free_line);
	return (ret_line);
}
