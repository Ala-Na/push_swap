/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:47:06 by anadege           #+#    #+#             */
/*   Updated: 2021/07/20 22:46:37 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pile_until_ten_elem(t_piles *piles)
{
	int	middle;
	int	order;

	middle = (piles->size_a + piles->size_b) / 2;
	order = is_in_order(piles);
	while (!(order == TRUE_A && piles->size_b == 0))
	{
		if (order == TRUE_AB && piles->size_b > 0)
			push_a(piles);
		if (order != TRUE_AB && ((order != TRUE_A && (piles->size_a == 3 || piles->size_a == 2)) || (order != TRUE_B && (piles->size_b == 3 || piles->size_b == 2))))
			sort_shorts_piles(piles);
		else if (order != TRUE_AB  && order != TRUE_A && piles->size_a > 0 && piles->content[0] < middle)
			push_b(piles);
		else
		{
			sort_top_piles(piles, middle);
			order = is_in_order(piles);
			if (order != TRUE_AB && order != TRUE_A)
				reverse_rotate_a(piles);
			if (order != TRUE_AB && order != TRUE_B)
				reverse_rotate_b(piles);
		}
		order = is_in_order(piles);
	}
}

void	sort_piles(t_piles *piles)
{
	int	order;

	order = is_in_order(piles);
	if (order == TRUE_A)
		return ;
	if (piles->size_a <= 10)
		sort_pile_until_ten_elem(piles);
	else 
		bitonic_like_sort(piles);
	/*int i = 0;
	while (i < piles->size_a + piles->size_b)
	{
		if (i < piles->size_a)
			printf("%i in a, ", piles->content[i]);
		else
			printf("%i in b, ", piles->content[i]);
		i++;
	}
	printf("\n");*/
}
