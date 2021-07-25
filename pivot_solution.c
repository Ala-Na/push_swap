/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:17:55 by anadege           #+#    #+#             */
/*   Updated: 2021/07/25 23:47:50 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_costless_move(t_piles *piles, t_operations **ope, int pivot)
{
	int	i;
	int	min_cost;
	int	curr_cost;
	int	min_cost_pos;

	i = piles->size_a;
	min_cost = - 1;
	while (i < piles->size_a + piles->size_b)
	{
		//curr_cost = function to do pour piles->content[i]
		if (curr_cost < min_cost || min_cost == -1)
		{
			min_cost = curr_cost;
			min_cost_pos =  i;
		}
		if (min_cost <= 1) // || (min <= piles->size_a + piles->size_b / 60 && piles->size_a + piles->size_b > 400)
			break ;
	}
	// function où on effectue les mouvements en fonction de min_cost_pos 
}


void	fat_sort(t_piles *piles, t_operations **ope, int pivot)
{
	while (piles->size_b != 0)
	{
		find_costless_move(piles, ope, pivot);
		push_a(piles, ope);
	}
	while (piles->content[0] <= pivot)
		rotate_a(piles, ope);
	while (piles->content[0] != 0)
		push_b(piles, ope);
	push_a(piles, ope);
	while (piles->size_b != 0)
	{
		find_costless_move(piles, ope, pivot);
		push_a(piles, ope);
	}
	while (piles->content[0] != 0)
		rotate_a(piles, ope);
}

void	fat_algo(t_piles *piles, t_operations **ope)
{
	int	pivot;

	pivot = piles->size_a / 2 + 1;
	while (piles->size_b < pivot)
	{
		if (piles->content[0] <= pivot)
			push_b(piles, ope);
		else
			rotate_a(piles, ope);
	}
	push_a(piles, ope);
	fat_sort(piles, ope, pivot);
}
