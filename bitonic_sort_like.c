/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitonic_sort_like.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 10:57:32 by anadege           #+#    #+#             */
/*   Updated: 2021/07/21 12:03:05 by anadege          ###   ########.fr       */
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
/*
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
	else if (distance > 1 && distance != piles->size_a + piles->size_b - 1)
	{
		while (distance > 1 && distance < piles->size_b)
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
}*/

/*
** On recommence mais sans remettre la sequence en bitonique a chaque fois. 
** Pour ça, on va comparer la value aux élements de b en faisant attention à la
** position de la valeur max où le rapport risque de s'inverser.
** Plusieurs cas figures :
** - Value > valeur max ou < valeur min => insérer avant valeur max
** - Value entre dessus de la pile et valeur max ou entre dessous pile et
** valeur max.
** Toujours faire attention à réaliser le moins de mouvement possible selon
** la position d'insertion par rapport au centre de pile b.
*/
int		find_insertion_pos_in_b(int value, t_piles *piles)
{
	int	i;
	int	max_value_pos;
	int	insertion_pos;

	i = piles->size_a - 1;
	insertion_pos = -1;
	max_value_pos = piles->content[piles->size_a];
	while (++i < piles->size_a + piles->size_b)
	{
		if (piles->content[i] > piles->content[max_value_pos])
		{
			max_value_pos = i;
			printf("case 1\n");
		}
	}
	i = piles->size_a - 1;
	while (++i + 1 < piles->size_a + piles->size_b)
	{
		if (i + 1 != max_value_pos && value < piles->content[i] && value > piles->content[i + 1])
		{
			insertion_pos = i + 1;
			printf("case 2\n");
		 }
	}
	if (value < piles->content[i + 1] && value > piles->content[piles->size_a])
	{
		insertion_pos = piles->size_a;
		printf("case 3\n");
	}
	else if (value > piles->content[max_value_pos])
	{
		insertion_pos = max_value_pos;
		printf("case 4\n");
	}
	return (insertion_pos);
}

void	insert_in_b(int value, t_piles *piles)
{
	int	insertion_pos;
	int	middle;

	insertion_pos = find_insertion_pos_in_b(value, piles);
	printf("insertion is %i\n", insertion_pos);
	middle = (piles->size_a + piles->size_b) / 2;
	if (insertion_pos == piles->size_a || insertion_pos == piles->size_a + piles->size_b - 1)
		push_b(piles);
	else if (insertion_pos < middle)
	{
		while (--insertion_pos > piles->size_a)
			rotate_b(piles);
		push_b(piles);
	}
	else
	{
		while (++insertion_pos < piles->size_a + piles->size_b)
			reverse_rotate_b(piles);
		push_b(piles);
	}
}

void	put_non_bitonic_as_first(t_piles *piles)
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
			reverse_rotate_a(piles);
	}
	else
	{
		while (i-- > 0)
			rotate_a(piles);
	}
}

void	init_bitonic_like_sort(t_piles *piles)
{
	int	order;
	int	change;

	order = is_in_order(piles);
	while (order != TRUE_AB && piles->size_a > 2)
	{
		change = 0;
		while (piles->size_a > 1 && piles->content[0] > piles->content[1])
		{
			change = 1;
			if (piles->size_a > 2 && piles->content[0] < piles->content[2])
				swap_a(piles);
			else if (piles->content[0] > piles->content[piles->size_a - 1])
				rotate_a(piles);
			else if (piles->size_b == 0)
				push_b(piles);
			else
				insert_in_b(piles->content[0], piles);
		}
		order = is_in_order(piles);
		if (order != TRUE_AB && order != TRUE_A)
		{
			put_non_bitonic_as_first(piles);
			if (change == 0)
				insert_in_b(piles->content[0], piles);
		}
		int i = 0;
		while (i < piles->size_a + piles->size_b && piles->size_b != 6)
		{
			printf("%i ", piles->content[i++]);
			if (i - 1 < piles->size_a)
				printf("in a, ");
			else
				printf("in b, ");
		}
		if (piles->size_b != 6)
			printf("\n");
	}
}

void	insert_in_a(int value, t_piles *piles)
{
	reverse_rotate_a(piles);
	while (piles->size_b > 0)
	{
		if (piles->content[piles->size_a] == piles->content[0] - 1)
			push_a(piles);
		else
			reverse_rotate_a(piles);
	}
	while (piles->content[0] > 0)
		reverse_rotate_a(piles);
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
void	bitonic_like_sort(t_piles *piles)
{
	init_bitonic_like_sort(piles);
	int i = 0;
	while (i < piles->size_a + piles->size_b)
	{
		printf("%i ", piles->content[i++]);
		if (i - 1 < piles->size_a)
			printf("in a, ");
		else
			printf("in b, ");
	}
	printf("\n");
	keep_bitonic_b(piles);
	while (piles->size_b > 0)
		insert_in_a(piles->content[piles->size_a], piles);
	if (is_in_order(piles) != TRUE_A)
		printf("ERROR !!!\n");
}

/*int	main()
{
	int size = 8;
	int *array = malloc(sizeof(*array) * size);
	array[0] = 3;
	array[1] = 4;
	array[2] = 2;
	array[3] = 8;
	array[4] = 5;
	array[5] = 6;
	array[6] = 1;
	array[7] = 7;
	t_piles *piles = malloc(sizeof(*piles));
	piles->content = array;
	piles->size_a = size;
	piles->size_b = 0;
	int i = 0;
	while (i < size)
		printf("%i ", piles->content[i++]);
	printf("\n");
	bitonic_like_sort(piles);
	i = 0;
	while (i < piles->size_a + piles->size_b)
	{
		printf("%i ", piles->content[i++]);
		if (i - 1 < piles->size_a)
			printf("in a, ");
		else
			printf("in b, ");
	}
	printf("\n");
}*/
