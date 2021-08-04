/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:00:45 by anadege           #+#    #+#             */
/*   Updated: 2021/08/04 16:36:21 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_duplicate(int *list_a, int size_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_a - 1)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (list_a[i] == list_a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_list_from_mult_strings(char **arr_str, int **list_a, int *size_a,
		int *check_limit)
{
	int	arr_i;
	int	str_i;

	arr_i = 0;
	*list_a = malloc(sizeof(**list_a) * (*size_a));
	while (arr_i < *size_a)
	{
		str_i = 0;
		while (arr_str[arr_i][str_i])
		{
			if (arr_str[arr_i][str_i] == '-')
				str_i++;
			if (!ft_isdigit(arr_str[arr_i][str_i]))
				return (-1);
			str_i++;
		}
		(*list_a)[arr_i] = ft_atoi_like(arr_str[arr_i], check_limit);
		arr_i++;
	}
	return (0);
}

int	get_list_size_from_string(char *str)
{
	int	i;
	int	begin_number;
	int	size_list;

	i = 0;
	size_list = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		begin_number = 0;
		while (str[i] && (ft_isdigit(str[i])
				|| (begin_number == 0 && str[i] == '-')))
		{
			if (begin_number == 0)
			{
				size_list++;
				begin_number = 1;
			}
			i++;
		}
		if (str[i] && str[i] != ' ')
			return (-1);
	}
	return (size_list);
}

int	get_list_from_single_string(char *str, int **list_a, int *size_a,
		int *check_limit)
{
	int	i;
	int	list_i;
	int	begin_number;

	i = 0;
	list_i = 0;
	*size_a = get_list_size_from_string(str);
	if (*size_a == -1)
		return (-1);
	*list_a = malloc(sizeof(**list_a) * (*size_a));
	if (!list_a)
		return (-1);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		begin_number = 0;
		while (str[i] && (ft_isdigit(str[i]) || str[i] == '-'))
		{
			if (begin_number++ == 0 && list_i < (*size_a))
				(*list_a)[list_i++] = ft_atoi_like(str + i, check_limit);
			i++;
		}
	}
	return (0);
}

int	check_and_extract_list(int argc, char **argv, int **list_a, int *size_a)
{
	int	check_limit;

	check_limit = 0;
	if (argc == 2)
	{
		if (get_list_from_single_string(argv[1], list_a, size_a,
				&check_limit) == -1)
			return (-1);
	}
	else
	{
		*size_a = argc - 1;
		if (get_list_from_mult_strings(argv + 1, list_a, size_a,
				&check_limit) == -1)
			return (-1);
	}
	if (check_limit == -1 || check_duplicate(*list_a, *size_a) == -1)
		return (-1);
	return (0);
}
