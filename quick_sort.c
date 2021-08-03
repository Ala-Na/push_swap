/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:42:50 by anadege           #+#    #+#             */
/*   Updated: 2021/08/03 12:02:31 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function to get the pivot for sort algorithm.
** Pivot is the mediane value of either pile a or pile b.
** To determine which pile is studied (and depending on the
** size argument of the sort algortihm), start (beginning of pile)
** and end (last element included in size argument) are given.
*/
int	get_pivot(t_piles *piles, int start, int end)
{
	int		i;
	double	pivot;
	int		approx;

	i = start;
	pivot = 0;
	while (i < end)
		pivot += piles->content[i++];
	pivot /= (end - start);
	approx = pivot;
	pivot += 0.5;
	if (approx < (int)pivot)
		return ((int)pivot);
	return (approx);
}

/*
** Function to make recursively call of a_half_sort and b_half_sort.
** Separated from the rest of sort functions to respect norm.
*/
int	return_res(t_piles *piles, t_operations **ope, int old_size)
{
	int	size_a_half;
	int	size_b_half;
	int	res;

	size_a_half = old_size / 2 + old_size % 2;
	size_b_half = old_size / 2;
	res = a_half_sort(piles, ope, size_a_half);
	if (res == 1)
		return (b_half_sort(piles, ope, size_b_half));
	return (res);
}

/*
** Function to sort b pile half made from previous calls.
** This algorithm is based on a recursive quick sort with mediane
** value as pivot.
*/
int	b_half_sort(t_piles *piles, t_operations **ope, int size)
{
	int	pivot;
	int	old_size;
	int	deplaced_elems;

	deplaced_elems = 0;
	old_size = size;
	if (size <= 3)
	{
		sort_top_b(piles, ope, size);
		return (1);
	}
	pivot = get_pivot(piles, piles->size_a, piles->size_a + size);
	while (size != old_size / 2)
	{
		if (piles->content[piles->size_a] >= pivot && size--)
			push_a(piles, ope);
		else if (++deplaced_elems)
			rotate_b(piles, ope);
	}
	while (old_size / 2 != piles->size_b && deplaced_elems--)
		reverse_rotate_b(piles, ope);
	return (return_res(piles, ope, old_size));
}

/*
** Function to sort a piel half made from previous calls.
** This algortihm is based on a recursive quick sort with mediane
** value as pivot.
** On first call, size is equal to the number of elements to sort.
** Elements under pivot value will be placed inside b.
** Recursive calls a_half_sort will be made in return_res function
** until pile a is made of 3 or less elements in sorted order.
** Then, calls between b_half_sort and a_half_sort will be made in
** order to progressively sort the whole array.
** Note that every time that elements are placed inside b, biggest
** elements of b will be on top (not always in sorted order) and
** will be sorted when b_half_sort is called with the 
** corresponding size.
*/
int	a_half_sort(t_piles *piles, t_operations **ope, int size)
{
	int	pivot;
	int	old_size;
	int	deplaced_elems;

	deplaced_elems = 0;
	if (is_part_sorted(piles, 0, size) == 1 || size <= 1)
		return (1);
	old_size = size;
	if (size <= 3)
	{
		sort_top_a(piles, ope, size);
		return (1);
	}
	pivot = get_pivot(piles, 0, size);
	while (size != old_size / 2 + old_size % 2)
	{
		if (piles->content[0] < pivot && (size--))
			push_b(piles, ope);
		else if ((++deplaced_elems))
			rotate_a(piles, ope);
	}
	while (piles->size_a != old_size / 2 + old_size % 2 && deplaced_elems--)
		reverse_rotate_a(piles, ope);
	return (return_res(piles, ope, old_size));
}
