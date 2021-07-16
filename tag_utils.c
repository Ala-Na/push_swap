/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:52:29 by anadege           #+#    #+#             */
/*   Updated: 2021/07/16 16:02:53 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_sub_arrays(int *tmp_1, int *tmp_2)
{
	int	res;

	res = 0;
	if (!tmp_1 || !tmp_2)
		res = -1;
	if (tmp_1)
		free(tmp_1);
	if (tmp_2)
		free(tmp_2);
	return (res);
}

int	*init_sub_arrays(int *list, int *tmp, int start, int end)
{
	int	i;
	int	*sub_array;

	i = 0;
	sub_array = malloc(sizeof(*sub_array) * end);
	if (!sub_array)
		return (NULL);
	while (i < end)
	{
		sub_array[i] = list[start + i];
		i++;
	}
	return (sub_array);
}

int	merge(int *list, int start, int center, int end)
{
	int	i;
	int	j;
	int	k;
	int	*left;
	int	*right;

	i = 0;
	j = 0;
	k = start;
	left = init_sub_arrays(list, left, start, center - start + 1);
	right = init_sub_arrays(list, right, center + 1, end - center);
	while (left && right && i < center - start + 1 && j < end - center)
	{
		if (left[i] <= right[j])
			list[k++] = left[i++];
		else
			list[k++] = right[j++];
	}
	while (left && right && i < center - start + 1)
		list[k++] = left[i++];
	while (left && right && j < end - center)
		list[k++] = right[j++];
	return (free_sub_arrays(left, right));
}

int	merge_sort(int *list, int start, int end)
{
	int	center;

	if (start < end)
	{
		center = (start + end) / 2;
		if (merge_sort(list, start, center) == -1
			|| merge_sort(list, center + 1, end) == -1
			|| merge(list, start, center, end) == -1)
			return (-1);
	}
	return (0);
}

int	*copy_array(int *list, int size)
{
	int	i;
	int	*new_list;

	new_list = malloc(sizeof(*new_list) * size);
	if (!new_list)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_list[i] = list[i];
		i++;
	}
	return (new_list);
}
