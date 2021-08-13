/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:08:30 by anadege           #+#    #+#             */
/*   Updated: 2021/08/07 16:06:08 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dest;
	int		i;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	dest = malloc(sizeof(*dest) * (size + 1));
	if (!dest)
		return (0);
	while (s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = -1;
	size = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[size])
		size++;
	while (s2 && s2[++i])
		size++;
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		str[i++] = *s1++;
	while (s2 && *s2)
		str[i++] = *s2++;
	str[size] = 0;
	return (str);
}

void	fill_full_buffer(char *buffer, char **full_buffer)
{
	char	*tmp;

	if (*full_buffer == NULL)
		*full_buffer = ft_strdup(buffer);
	else
	{
		tmp = *full_buffer;
		*full_buffer = ft_strjoin(*full_buffer, buffer);
		free(tmp);
	}
}
