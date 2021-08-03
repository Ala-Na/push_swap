/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorts_solutions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:15:17 by anadege           #+#    #+#             */
/*   Updated: 2021/08/03 11:51:17 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function to sort elements of a pile when it's size is of 3 elements.
** In this special case, reverse_rotate_a can be used without the need
** to use rotate_a to keep a sorted order.
*/
void	sort_short_pile_a(t_piles *piles, t_operations **ope)
{
	if (piles->size_a == 2 && piles->content[0] > piles->content[1])
		swap_a(piles, ope);
	else if (piles->size_a == 3 && piles->content[0] < piles->content[1])
	{
		if (piles->content[0] < piles->content[2]
			&& piles->content[1] > piles->content[2])
		{
			swap_a(piles, ope);
			rotate_a(piles, ope);
		}
		else if (piles->content[0] > piles->content[2])
			reverse_rotate_a(piles, ope);
	}
	else if (piles->size_a == 3)
	{
		if (piles->content[0] < piles->content[2])
			swap_a(piles, ope);
		else if (piles->content[1] < piles->content[2])
			rotate_a(piles, ope);
		else
		{
			swap_a(piles, ope);
			reverse_rotate_a(piles, ope);
		}
	}
}

/*
** Function to sort 1 to 3 elements on top of a pile.
** Because elements of pile a are supposed to stay inside that pile
** in sorted order, operations inside pile a are favorised over push_b.
** In the special case where the size of pile a is the same as the size
** argument, function sort_short_pile_a is called.
*/
void	sort_top_a(t_piles *piles, t_operations **ope, int size)
{
	if (size <= 2 || piles->size_a <= 2)
	{
		if (size == 2 && piles->content[0] > piles->content[1])
			swap_a(piles, ope);
	}
	else if (size == 3 && piles->size_a == 3)
		sort_short_pile_a(piles, ope);
	else if (size == 3)
	{
		while (size != 3 || is_part_sorted(piles, 0, size) != TRUE_A)
		{
			if (piles->content[0] > piles->content[1])
				swap_a(piles, ope);
			else if (size == 3 && (piles->content[2] < piles->content[0]
					|| piles->content[2] < piles->content[1]) && size--)
				rotate_a(piles, ope);
			else if (size++)
				reverse_rotate_a(piles, ope);
		}
	}
}

/*
** Function to sort 1 to 3 elements on top of b pile.
** The logic is slightly different from sort_top_a, because
** elements of pile b should be ultimately moved to pile a.
** As such, elements are moved to pile a with push_a and 
** sometimes swap_a is preferred over operations in pile b.
*/
void	sort_top_b(t_piles *piles, t_operations **ope, int size)
{
	int	*arr;

	arr = piles->content;
	if (size <= 2 || piles->size_b <= 2)
	{
		if (size == 2 && arr[piles->size_a] < arr[piles->size_a + 1])
			swap_b(piles, ope);
		while (size != 0 && size--)
			push_a(piles, ope);
	}
	else if (size == 3)
	{
		while (size != 0 || is_part_sorted(piles, 1, size) != TRUE_B)
		{
			arr = piles->content;
			if (size == 1 && arr[0] > arr[1])
				swap_a(piles, ope);
			else if ((size == 1 && size--) || (arr[piles->size_a]
					> arr[piles->size_a + 1] && size--) || (size == 3
					&& arr[piles->size_a] > arr[piles->size_a + 2] && size--))
				push_a(piles, ope);
			else
				swap_b(piles, ope);
		}
	}
}
