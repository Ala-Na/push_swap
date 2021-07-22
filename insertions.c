/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:52:19 by anadege           #+#    #+#             */
/*   Updated: 2021/07/22 17:15:34 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculate general cost of an operation inside pile a
** from top and bottom. Return the smallest cost.
** If positive : from top. If negative : from bottom.
*/
int		cost_insertion_a_to_a(int value, t_piles *piles)
{
	int	i;
	int	top_insertion_pos;
	int	bottom_insertion_pos;

	i = 1;
	while (i < piles->size_a && value > piles->content[i])
		i++;
	top_insertion_pos = i;
	i = piles->size_a - 1;
	while (i > 0 && value < piles->content[i])
		i--;
	bottom_insertion_pos = i;
	if (top_insertion_pos == 1)
		return (top_insertion_pos);
	if (top_insertion_pos <= piles->size_a - bottom_insertion_pos)
	{
		if (top_insertion_pos == 2)
			return (3);
		return (2 + 2 * top_insertion_pos);
	}
	if (piles->size_a - bottom_insertion_pos == 1)
		return (-2);
	return (-2 * bottom_insertion_pos);
}

int		find_insertion_pos_in_b(int value, t_piles *piles)
{
	int	i;
	int	max_value_pos;
	int	min_value_pos;
	int	insertion_pos;

	i = piles->size_a - 1;
	insertion_pos = -1;
	max_value_pos = piles->size_a;
	min_value_pos = piles->size_a;
	while (++i < piles->size_a + piles->size_b)
	{
		if (piles->content[i] > piles->content[max_value_pos])
			max_value_pos = i;
		if (piles->content[i] < piles->content[min_value_pos])
			min_value_pos = i;
	}
	i = piles->size_a - 1;
	if (value > piles->content[max_value_pos] || value < piles->content[min_value_pos])
		insertion_pos = max_value_pos;
	else if (value > piles->content[piles->size_a]
		&& value < piles->content[piles->size_a + piles->size_b - 1])
		insertion_pos = piles->size_a;
	else
	{
		while (i + 1 < piles->size_a + piles->size_b)
		{
			if (value < piles->content[i] && value > piles->content[i + 1])
				insertion_pos = i + 1;
			i++;
		}
	}
	return (insertion_pos);
}

int		cost_insertion_a_to_b(int value, t_piles *piles)
{
	int	insertion_pos;
	int	middle;
	int	cost;

	middle = (piles->size_b) / 2;
	insertion_pos = find_insertion_pos_in_b(value, piles);
	cost = 0;
	if (insertion_pos == -1 || insertion_pos == piles->size_b)
		return (1);
	else if (insertion_pos < middle)
	{
		while (insertion_pos-- > 0)
			cost++;
		cost++;
	}
	else
	{
		while (insertion_pos++ < piles->size_b)
			cost++;
		cost++;
	}
	return (cost);
}

void	insert_in_b(int value, t_piles *piles, t_operations **ope)
{
	int	insertion_pos;
	int	middle;

	if (piles->size_b == 0)
	{
		push_b(piles, ope);
		return ;
	}
	insertion_pos = find_insertion_pos_in_b(value, piles) - piles->size_a;
	middle = (piles->size_b) / 2;
	if (insertion_pos == -1 || insertion_pos == piles->size_b)
		push_b(piles, ope);
	else if (insertion_pos < middle)
	{
		while (insertion_pos-- > 0)
			rotate_b(piles, ope);
		push_b(piles, ope);
	}
	else
	{
		while (insertion_pos++ < piles->size_b)
			reverse_rotate_b(piles, ope);
		push_b(piles, ope);
	}
	/*int i = 0;
	while (i < piles->size_a + piles->size_b)
	{
		printf("%i ", piles->content[i++]);
		if (i - 1 < piles->size_a)
			printf("in a, ");
		else
			printf("in b, ");
		if (i == piles->size_a + piles->size_b)
			printf("\n");
	}*/
}

void	insert_in_a(int cost, t_piles *piles, t_operations **ope, int top)
{
	int	value;
	int	i;

	value = piles->content[0];
	if (cost <= 2)
	{
		if (top == 0)
			reverse_rotate_a(piles, ope);
		swap_a(piles, ope);
	}
	if (cost == 2)
	{
		if (top == 0)
			reverse_rotate_a(piles, ope);
		else
			rotate_a(piles, ope);
		swap_a(piles,ope);
	}
	else if (cost > 2)
	{
		push_b(piles, ope);
		while (top == 0 && cost-- - 2 > 0)
			reverse_rotate_a(piles, ope);
		while (top == 1 && cost-- - 2 > 0)
			rotate_a(piles, ope);
		push_a(piles, ope);
	}
}

void	choose_costless_option(int value, t_piles *piles, t_operations **ope)
{
	int	a_to_b;
	int	a_to_a;
	int	top;

	top = 0;
	a_to_b = cost_insertion_a_to_b(value, piles);
	a_to_a = cost_insertion_a_to_a(value, piles);
	if (a_to_a > 0)
		top = 1;
	else
		a_to_a *= -1;
	if (a_to_b < a_to_a)
		insert_in_b(value, piles, ope);
	else
		insert_in_a(a_to_a, piles, ope, top);
}
