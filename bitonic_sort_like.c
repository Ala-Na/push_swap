/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitonic_sort_like.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:57:32 by anadege           #+#    #+#             */
/*   Updated: 2021/07/21 23:45:19 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	insert_in_b(int value, t_piles *piles, t_operations **ope)
{
	int	insertion_pos;
	int	middle;

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
	int	change;

	order = is_in_order(piles);
	while (order != TRUE_A && order != TRUE_AB && piles->size_a > 2)
	{
		change = 0;
		while (piles->size_a > 1 && piles->content[0] > piles->content[1])
		{
			change = 1;
			if (piles->size_a > 2 && piles->content[0] < piles->content[2])
				swap_a(piles, ope);
			else if (piles->content[0] > piles->content[piles->size_a - 1])
				rotate_a(piles, ope);
			else if (piles->content[0] < piles->content[piles->size_a - 1]
				&& piles->content[0] > piles->content[piles->size_a - 2])
			{
				reverse_rotate_a(piles, ope);
				swap_a(piles, ope);
			}
			else if (piles->content[0] < piles->content[piles->size_a - 1]
				&& piles->content[0] < piles->content[piles->size_a - 2]
				&& piles->content[0] > piles->content[piles->size_a - 3])
			{
				reverse_rotate_a(piles, ope);
				swap_a(piles, ope);
				reverse_rotate_a(piles, ope);
				swap_a(piles, ope);
			}
			else if (piles->size_b == 0)
				push_b(piles, ope);
			else
				insert_in_b(piles->content[0], piles, ope);
		}
		order = is_in_order(piles);
		if (order != TRUE_AB && order != TRUE_A)
		{
			put_non_bitonic_as_first(piles, ope);
			if (change == 0 && piles->size_b == 0)
				push_b(piles, ope);
			else if (change == 0)
				insert_in_b(piles->content[0], piles, ope);
		}
		/*int i = 0;
		while (i < piles->size_a + piles->size_b && piles->size_b != 4)
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
}

void	insert_in_a(int value, t_piles *piles, t_operations **ope)
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
		insert_in_a(piles->content[piles->size_a], piles, ope);
	if (is_in_order(piles) != TRUE_A)
		printf("ERROR !!!\n");
}
