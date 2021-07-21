/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:47:06 by anadege           #+#    #+#             */
/*   Updated: 2021/07/21 23:40:58 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pile_until_five_elem(t_piles *piles, t_operations **ope)
{
	int	middle;
	int	order;

	middle = (piles->size_a + piles->size_b) / 2;
	order = is_in_order(piles);
	while (!(order == TRUE_A && piles->size_b == 0))
	{
		if (order == TRUE_AB && piles->size_b > 0)
			push_a(piles, ope);
		if (order != TRUE_AB && ((order != TRUE_A && (piles->size_a == 3 || piles->size_a == 2)) || (order != TRUE_B && (piles->size_b == 3 || piles->size_b == 2))))
			sort_shorts_piles(piles, ope);
		else if (order != TRUE_AB  && order != TRUE_A && piles->size_a > 0 && piles->content[0] < middle)
			push_b(piles, ope);
		else
		{
			sort_top_piles(piles, middle, ope);
			order = is_in_order(piles);
			if (order != TRUE_AB && order != TRUE_A)
				reverse_rotate_a(piles, ope);
			if (order != TRUE_AB && order != TRUE_B)
				reverse_rotate_b(piles, ope);
		}
		order = is_in_order(piles);
	}
}

int	sort_piles(t_piles *piles, t_operations **ope)
{
	int	order;

	order = is_in_order(piles);
	if (order == TRUE_A)
		return (0);
	if (piles->size_a <= 5)
		sort_pile_until_five_elem(piles, ope);
	else 
		bitonic_like_sort(piles, ope);
	return (0);
}
