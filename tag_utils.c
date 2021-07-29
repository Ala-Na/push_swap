/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:52:29 by anadege           #+#    #+#             */
/*   Updated: 2021/07/29 11:27:04 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Merge sort recursive algorithm to quickly sort elements.
** For each call of the merge sort, start and end are modified.
*/
int	merge_sort(int *lst, int start, int end)
{
	int	center;

	if (start < end)
	{
		center = (start + end) / 2;
		if (merge_sort(lst, start, center) == -1
			|| merge_sort(lst, center + 1, end) == -1
			|| merge(lst, start, center, end) == -1)
			return (-1);
	}
	return (0);
}

/*
** Sub-function of the merge sort recursive algorithm.
** Merge the differents elements of each piece of array,
** in sorted order.
*/
int	merge(int *lst, int start, int center, int end)
{
	int	i;
	int	j;
	int	k;
	int	*left;
	int	*right;

	i = 0;
	j = 0;
	k = start;
	left = init_sub_arrays(lst, left, start, center - start + 1);
	right = init_sub_arrays(lst, right, center + 1, end - center);
	while (left && right && i < center - start + 1 && j < end - center)
	{
		if (left[i] <= right[j])
			lst[k++] = left[i++];
		else
			lst[k++] = right[j++];
	}
	while (left && right && i < center - start + 1)
		lst[k++] = left[i++];
	while (left && right && j < end - center)
		lst[k++] = right[j++];
	return (free_sub_arrays(left, right));
}

/*
** Sub-function of the merge sort recursive algortihm to malloc
** and fill each sub-array.
*/
int	*init_sub_arrays(int *lst, int *tmp, int start, int end)
{
	int	i;
	int	*sub_array;

	i = 0;
	sub_array = malloc(sizeof(*sub_array) * end);
	if (!sub_array)
		return (NULL);
	while (i < end)
	{
		sub_array[i] = lst[start + i];
		i++;
	}
	return (sub_array);
}

/*
** Sub-function of the merge sort recursive algorithm to free
** each sub-array.
*/
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

/*
** Function to malloc and copy an array of int.
*/
int	*copy_array(int *lst, int size)
{
	int	i;
	int	*new_lst;

	new_lst = malloc(sizeof(*new_lst) * size);
	if (!new_lst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_lst[i] = lst[i];
		i++;
	}
	return (new_lst);
}
