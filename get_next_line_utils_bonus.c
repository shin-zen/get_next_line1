/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skodama <skodama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 07:50:04 by skodama           #+#    #+#             */
/*   Updated: 2020/12/30 22:40:32 by skodama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!(copy = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(p = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	while (i < len1)
	{
		p[i] = s1[i];
		i++;
	}
	while (j < len2)
		p[i++] = s2[j++];
	p[i] = '\0';
	free((char *)s1);
	s1 = NULL;
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char find;

	if (!s)
		return (NULL);
	find = c;
	while (*s)
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (find == '\0')
		return ((char *)s);
	return ((NULL));
}
