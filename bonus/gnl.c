/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:38:31 by tkhechoy          #+#    #+#             */
/*   Updated: 2022/12/22 21:09:19 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"gnl.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	char	*arr_to_free;

	i = 0;
	if (!s2)
		return (NULL);
	arr_to_free = s1;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	if (s1)
		while (*s1)
			str[i++] = *s1++;
	while (s2 && *s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free(arr_to_free);
	return (str);
}

int	fun(int fd, char **str)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];

	i = 0;
	while (1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (0);
		buf[i] = '\0';
		if (!*str)
			*str = ft_strdup(buf);
		else
			*str = ft_strjoin(*str, buf);
		if (ft_strchr(buf, '\n') || i == 0)
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			i;
	char		*line;
	char		*tmp;

	if (!fun(fd, &str))
		return (0);
	i = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n')) + 1;
	line = ft_substr(str, 0, i);
	tmp = str;
	str = ft_substr(str, i, ft_strlen(str));
	free(tmp);
	return (line);
}
