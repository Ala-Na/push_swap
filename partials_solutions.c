/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partials_solutions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:15:17 by anadege           #+#    #+#             */
/*   Updated: 2021/07/21 23:43:17 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** For this function, start is piles->size_a.
*/
void	sort_short_pile_b(t_piles *piles, int start, t_operations **ope)
{
	if (piles->size_b == 2 && piles->content[start] < piles->content[start + 1])
		swap_b(piles, ope);
	else if (piles->size_b == 3 && piles->content[start] > piles->content[start + 1])
	{
		if (piles->content[start] > piles->content[start + 2]
			&& piles->content[start + 1] < piles->content[start + 2])
		{
			reverse_rotate_b(piles, ope);
			swap_b(piles, ope);
		}
		else if (piles->content[start] < piles->content[start + 2])
			reverse_rotate_b(piles, ope);
	}
	else if (piles->size_b == 3)
	{
		if (piles->content[start] > piles->content[start + 2])
			swap_b(piles, ope);
		else if (piles->content[start + 1] > piles->content[start + 2])
			rotate_b(piles, ope);
		else
		{
			swap_b(piles, ope);
			reverse_rotate_b(piles, ope);
		}
	}
}

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

void	sort_shorts_piles(t_piles *piles, t_operations **ope)
{
	int middle = (piles->size_a + piles->size_b) / 2;

	if (piles->size_a >= 2 && piles->size_a <= 3)
		sort_short_pile_a(piles, ope);
	if (piles->size_b >= 2 && piles->size_b <= 3)
		sort_short_pile_b(piles, piles->size_a, ope);
}

void	sort_top_piles(t_piles *piles, int middle, t_operations **ope)
{
	if (piles->size_a > 3)
	{
		if (piles->content[0] > piles->content[1])
			swap_a(piles, ope);
		if (piles->content[0] < piles->content[1] && piles->content[1] > piles->content[2])
		{
			if (piles->content[0] < middle)
			{
				push_b(piles, ope);
				swap_a(piles, ope);
				return ;
			}
			rotate_a(piles, ope);
			swap_a(piles, ope);
			reverse_rotate_a(piles, ope);
		}
		if (piles->content[0] > piles->content[1])
			swap_a(piles, ope);
	}
	if (piles->size_b > 3)
	{
		if (piles->content[piles->size_a] < piles->content[piles->size_a + 1])
			swap_b(piles, ope);
		if (piles->content[piles->size_a] > piles->content[piles->size_a + 1]
				&& piles->content[piles->size_a + 2] > piles->content[piles->size_a + 1])
		{
			rotate_b(piles, ope);
			swap_b(piles, ope);
			reverse_rotate_b(piles, ope);
		}
		if (piles->content[piles->size_a] < piles->content[piles->size_a + 1])
			swap_b(piles, ope);
	}
}
