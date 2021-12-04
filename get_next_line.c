/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:13:10 by zzarrafa          #+#    #+#             */
/*   Updated: 2019/11/06 12:01:05 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_last_line(char **str, char *buff, char **line)
{
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	free(buff);
	return (0);
}

int		find(char **str, char *temp, char **line, char *buff)
{
	int position;

	position = ft_strchr(*str, '\n') - *str;
	temp = *str;
	*line = ft_substr(*str, 0, position);
	*str = ft_strdup(*str + position + 1);
	free(temp);
	free(buff);
	return (1);
}

int		test(int fd, char **line)
{
	int		a;
	char	c;

	a = read(fd, &c, 0);
	if (a < 0 || fd < 0 || line == NULL)
		return (0);
	return (1);
}

int		free_buff(char *buff)
{
	free(buff);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	char			*temp;
	static char		*str[4864];
	int				re;

	if (test(fd, line) == 0)
		return (-1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	while (ft_strchr(str[fd], '\n') == NULL)
	{
		temp = str[fd];
		if ((re = read(fd, buff, BUFFER_SIZE)) < 0)
			return (free_buff(buff));
		buff[re] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
		free(temp);
		if (re == 0)
			break ;
	}
	if (ft_strchr(str[fd], '\n'))
		return (find(&str[fd], temp, line, buff));
	else
		return (read_last_line(&str[fd], buff, line));
}
