/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:01:52 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/24 19:51:06 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_f(char *s1, char *s2, int f);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup_n(char *buf, int b_read);
int		ft_strchr_int(const char *s, int c);
char	*ft_free(char *one, char *two, char *three);
char	*get_next_line(int fd);

#endif
