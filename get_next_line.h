/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skodama <skodama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 07:50:00 by skodama           #+#    #+#             */
/*   Updated: 2021/01/08 08:02:26 by skodama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR -1
# define ENDFILE 0
# define ENDL '\n'
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif
# ifndef FD_MAX
#  define FD_MAX 256
# endif

typedef	struct	s_list
{
	char			*saved_line;
	int				saved_fd;
	struct s_list	*next;
}				t_list;
int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strndup(const char *s1, size_t n);
#endif
