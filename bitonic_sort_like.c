/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitonic_sort_like.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:57:32 by anadege           #+#    #+#             */
/*   Updated: 2021/07/20 12:47:39 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_bitonic_b(t_piles *piles)
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
			rotate_b(piles);
			max_value_pos--;
		}
		return ;
	}
	while (max_value_pos != piles->size_b)
	{
		reverse_rotate_b(piles);
		max_value_pos++;
	}
}

void	insert_in_b(int value, t_piles *piles)
{
	int	distance;
	int	pos_low_adj_value;

	distance = 0;
	while (value < piles->content[piles->size_a + distance]
			&& piles->size_a + distance < piles->size_a + piles->size_b)
		distance++;
	pos_low_adj_value = piles->size_a + distance;
	if (distance <= 1 || distance == piles->size_a + piles->size_b - 1)
		push_b(piles);
	if (piles->size_b > 2 && distance == piles->size_a + piles->size_b - 1)
		rotate_b(piles);
	else if (distance == 1)
		swap_b(piles);
	else if (distance > 1)
	{
		while (distance > 0 && distance < piles->size_b)
		{
			if (pos_low_adj_value < (piles->size_b / 2))
			{
				rotate_b(piles);
				distance--;
			}
			else
			{
				reverse_rotate_b(piles);
				distance++;
			}
		}
		push_b(piles);
		if (pos_low_adj_value < piles->size_b / 2)
			swap_b(piles);
	}
	keep_bitonic_b(piles);
}

void	init_bitonic_like_sort(t_piles *piles)
{
	int first;

	first = 1;
	while (piles->size_a > 1 && content[0] > content[1])
	{
		if (first == 1)
		{
			if (content[0] > content[piles->size_a - 1])
				rotate_a(piles);
			else
			{
				push_b(piles);
				first = 0;
			}
		}

	}
}

int	main()
{
	int *array = malloc(sizeof(*array) * 5);
	array[0] = 9;
	array[1] = 8;
	array[2] = 6;
	array[3] = 4;
	array[4] = 2;
	t_piles *piles = malloc(sizeof(*piles));
	piles->content = array;
	piles->size_a = 1;
	piles->size_b = 4;
	int i = 0;
	while (i < 5)
		printf("%i ", piles->content[i++]);
	printf("\n");
	insert_in_b(piles->content[0], piles);
	i = 0;
	while (i < 5)
		printf("%i ", piles->content[i++]);
	printf("\n");
}

*/
/* Pile a should be in an increasing bitonic order, while pile b should be in a
** decreasing bitonic order. Pile a may be a non bitonic sequence but pile b 
** will be at all times. 
** First we put all non bitonic order element in bitonic order at the end
** of a if possible, if not at their correct position in b. When both b and a are
** in bitonic order, we insert each element of a in their correct position in a
** by reverse rotating a. When b is empty, we continue to reverse rotating or 
** rotating a (dependig which is shortest ) until the first element is on top.
*/
/*
void	bitonic_like_sort(t_piles *piles)
{
	
}
*/
