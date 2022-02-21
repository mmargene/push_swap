/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 03:11:49 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/11 03:13:20 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_chr_n_o(char *s)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s) - i + 1));
	if (!new)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			i++;
			n = 0;
			while (s[i] != '\0')
				new[n++] = s[i++];
			new[n] = '\0';
			free(s);
			return (new);
		}
		i++;
	}
	free(s);
	return (new);
}

char	*copy_n_to_o(char *buf, int number_n)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	n = 0;
	new = (char *)malloc(sizeof(char) * (number_n + 1));
	if (!new)
		return (0);
	while (buf[i] != '\n')
		i++;
	i++;
	while ((buf[i] != '\0'))
		new[n++] = buf[i++];
	new[n] = '\0';
	return (new);
}

char	*ft_read_buf(int fd, char **line, char **buf, char *memory)
{
	size_t	b_read;
	char	*btmp;
	char	*ntmp;

	b_read = 1;
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (NULL);
	btmp = *buf;
	while (b_read != 0)
	{
		b_read = read(fd, *buf, BUFFER_SIZE);
		buf[0][b_read] = '\0';
		if (ft_strchr_int(*buf, '\n'))
		{
			memory = copy_n_to_o(*buf, b_read);
			*line = ft_strjoin_f(*line, (ntmp = ft_strdup_n(*buf, b_read)), 1);
			ft_free(NULL, btmp, ntmp);
			return (memory);
		}
		*line = ft_strjoin_f(*line, *buf, 1);
	}
	ft_free(btmp, NULL, NULL);
	return (NULL);
}

char	*ft_read_memory(char *memory, char **line, int fd)
{
	char	*buf;

	buf = NULL;
	if (memory && (ft_strchr_int(memory, '\n')))
	{
		*line = ft_strdup_n(memory, BUFFER_SIZE);
		memory = ft_chr_n_o(memory);
	}
	else
	{
		if (!memory)
		{
			memory = (char *)malloc(sizeof(char));
			*memory = 0;
		}
		*line = ft_strjoin_f(memory, NULL, 1);
		memory = ft_read_buf(fd, line, &buf, memory);
	}
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 \
	|| BUFFER_SIZE > INT32_MAX)
		return (NULL);
	memory = ft_read_memory(memory, &line, fd);
	if (memory == NULL)
	{
		if (*line != '\0')
			return (line);
		free(line);
		return (NULL);
	}
	return (line);
}
