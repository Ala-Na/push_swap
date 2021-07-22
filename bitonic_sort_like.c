/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitonic_sort_like.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:57:32 by anadege           #+#    #+#             */
/*   Updated: 2021/07/22 18:02:27 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_insert_in_a(int value, t_piles *piles, t_operations **ope)
{
	reverse_rotate_a(piles, ope);
	while (piles->size_b > 0)
	{
/*		int i = 0;
		while (i < piles->size_a + piles->size_b)
		{
			printf("%i ", piles->content[i++]);
			if (i - 1 < piles->size_a)
				printf("in a, ");
			else
				printf("in b, ");
		}
		printf("\n");*/
		if (piles->content[piles->size_a] == piles->content[0] - 1)
			push_a(piles, ope);
		else
			reverse_rotate_a(piles, ope);
	}
	while (piles->content[0] > 0)
		reverse_rotate_a(piles, ope);
}

/*
** Function to get b from bitonic to a monotonic decreasing sequence
*/
void	get_monotonic_b(t_piles *piles, t_operations **ope)
{
	int	i;
	int	max_value;
	int	max_value_pos;

	i = 0;
	max_value_pos = i;
	max_value = piles->content[piles->size_a];
	while (i < piles->size_b)
	{
		if (max_value < piles->content[piles->size_a + i])
		{
			max_value = piles->content[piles->size_a + i];
			max_value_pos = i;
		}
		i++;
	}
	if (max_value_pos < piles->size_b / 2 + 1)
	{
		while (max_value_pos != 0)
		{
			rotate_b(piles, ope);
			max_value_pos--;
		}
		return ;
	}
	while (max_value_pos != piles->size_b)
	{
		reverse_rotate_b(piles, ope);
		max_value_pos++;
	}
}

void	put_non_bitonic_as_first(t_piles *piles, t_operations **ope)
{
	int	i;
	int	j;

	i = 0;
	j = piles->size_a - 1;
	while (i + 1 < piles->size_a && piles->content[i] < piles->content[i + 1])
		i++;
	i += 1;
	while (j - 1 >= 0 && piles->content[j - 1] < piles->content[j])
		j--;
	if (piles->size_a - j < i)
	{
		while (j++ < piles->size_a)
			reverse_rotate_a(piles, ope);
	}
	else
	{
		while (i-- > 0)
			rotate_a(piles, ope);
	}
}

void	init_bitonic_like_sort(t_piles *piles, t_operations **ope)
{
	int	order;
	int	bitonic_a;
	int	change;

	order = is_in_order(piles);
	while (order != TRUE_A && order != TRUE_AB && piles->size_a > 2)
	{
		change = 0;
		bitonic_a = a_is_bitonic(piles);
		printf("here\n");
		while (piles->size_a > 1 && piles->content[0] > piles->content[1])
		{
			change = 1;
			choose_costless_option(piles->content[0], piles, ope);
			bitonic_a = a_is_bitonic(piles);
		}
		if (bitonic_a == 0)
		{
			printf("not bitonic\n");
			put_non_bitonic_as_first(piles, ope);
			if (change == 0 && piles->size_b == 0)
				push_b(piles, ope);
			else if (change == 0)
				choose_costless_option(piles->content[0], piles, ope);
			order = is_in_order(piles);
		}
		else
		{
			printf("bitonic\n");
			order = is_in_order(piles);
			if (order != TRUE_A && order != TRUE_AB)
				get_monotonic_a(piles, ope);
			order = is_in_order(piles);
		}
		int i = 0;
		while (i < piles->size_a + piles->size_b)
		{
			printf("%i ", piles->content[i++]);
			if (i - 1 < piles->size_a)
				printf("in a, ");
			else
				printf("in b, ");
			if (i == piles->size_a + piles->size_b)
				printf("\n");
		}
	}
}

/* 
** Pile a should be in an increasing bitonic order, while pile b should be in a
** decreasing bitonic order. Pile a may be a non bitonic sequence but pile b 
** will be at all times. 
** First we put all non bitonic order element in bitonic order at the end
** of a if possible, if not at their correct position in b. When both b and a are
** in bitonic order, we insert each element of a in their correct position in a
** by reverse rotating a. When b is empty, we continue to reverse rotating or 
** rotating a (dependig which is shortest ) until the first element is on top.
*/
void	bitonic_like_sort(t_piles *piles, t_operations **ope)
{
	init_bitonic_like_sort(piles, ope);
/*	int i = 0;
	while (i < piles->size_a + piles->size_b)
	{
		printf("%i ", piles->content[i++]);
		if (i - 1 < piles->size_a)
			printf("in a, ");
		else
			printf("in b, ");
	}
	printf("\n");*/
	get_monotonic_b(piles, ope);
	while (piles->size_b > 0)
		final_insert_in_a(piles->content[piles->size_a], piles, ope);
	if (is_in_order(piles) != TRUE_A)
		printf("ERROR !!!\n");
}
