/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skodama <skodama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 04:47:19 by skodama           #+#    #+#             */
/*   Updated: 2020/12/31 04:17:29 by skodama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		safe_free(char **p, int check)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
	if (check == -1)
		return (ERROR);
	return (1);
}

static int		create_line(char **line, char **saved_line, char c, int size)
{
	char *tmp;

	tmp = *saved_line;
	while (*tmp && *tmp != c)
		tmp++;
	if (!(*line = ft_strndup(*saved_line, tmp - *saved_line)))
		return (ERROR);
	if (size)
	{
		if (!(*saved_line = ft_strndup(tmp + 1, ft_strlen(tmp))))
			return (ERROR);
	}
	else
		*saved_line = NULL;
	return (1);
}

static int		read_line(const int fd, char **saved_line)
{
	ssize_t		size;
	char		*buf;

	size = 10;
	if (!(buf =
		(char *)malloc((sizeof(char)) * ((unsigned int)BUFFER_SIZE + 1))))
		return (ERROR);
	while (!ft_strchr(*saved_line, ENDL) && size > 0)
	{
		if ((size = read(fd, buf, BUFFER_SIZE)) < 0)
			return (safe_free(&buf, ERROR));
		buf[size] = '\0';
		if (!(*saved_line = ft_strjoin(*saved_line, buf)))
			return (safe_free(&buf, ERROR));
	}
	safe_free(&buf, 1);
	return (size);
}

static t_list	*check_save(int fd, t_list *save)
{
	while (save->saved_fd)
	{
		if (save->saved_fd == fd)
			return (save);
		save++;
	}
	if (!(save->saved_line = ft_strndup("", 1)))
		return (NULL);
	save->saved_fd = fd;
	return (save);
}

int				get_next_line(int fd, char **line)
{
	static t_list	save[FD_MAX];
	t_list			*tmplst;
	long			size;
	char			*tmp;

	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE <= 0 ||
			BUFFER_SIZE > INT_MAX || (!(tmplst = check_save(fd, save))))
		return (ERROR);
	if (tmplst->saved_line == NULL)
	{
		if (!(*line = (char *)malloc((1) * sizeof(char))))
			return (-1);
		**line = '\0';
		return (0);
	}
	if ((size = read_line(fd, &(tmplst->saved_line))) == -1)
		return (safe_free(&(tmplst->saved_line), ERROR));
	tmp = tmplst->saved_line;
	if (create_line(line, &tmplst->saved_line, ENDL, size) == -1)
		return (safe_free(&tmp, ERROR));
	safe_free(&tmp, 1);
	if (fd == 0)
		safe_free(&tmplst->saved_line, 1);
	return (size ? 1 : 0);
}
