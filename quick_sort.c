/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 16:42:50 by anadege           #+#    #+#             */
/*   Updated: 2021/07/28 18:08:53 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_piles(t_piles *piles)
{
	int	i = 0;
	while (i < piles->size_a + piles->size_b)
	{
		if (i < piles->size_a)
			printf("%i in a, ", piles->content[i]);
		else
			printf("%i in b, ", piles->content[i]);
		i++;
		if (i == piles->size_a + piles->size_b)
			printf("\n");
	}
}

int	get_pivot(t_piles *piles, int start, int end)
{
	int		i;
	double	pivot;
	int		approx;

	i = start;
	pivot = 0;
	while (i < end)
		pivot += piles->content[i++];
	pivot /= (end - start);
	approx = pivot;
	pivot += 0.5;
	if (approx < (int)pivot)
		return ((int)pivot);
	return (approx);
}

int	second_quick_sort(t_piles *piles, t_operations **ope, int size)
{
	int	pivot;
	int	nb_elem;
	int	deplaced_elems;
	int	res;

//	printf("enter second with size %i\n", size);
//	print_piles(piles);
	nb_elem = size;
	deplaced_elems = 0;
	if (size > 1 &&  partial_order(piles, 1, size) == 1)
	{
		while (size--)
			push_a(piles, ope);
		if (size < 0)
			return (1);
	}
	if (size <= 3)
	{
		sort_top_b(piles, ope, size);
		while (size--)
			push_a(piles, ope);
//		print_piles(piles);
//		printf("end of second with size %i\n", nb_elem);
		return (1);
	}
	pivot = get_pivot(piles, piles->size_a, piles->size_a + size);
//	printf("pivot is %i and size is %i\n", pivot, size);
	while (size != nb_elem / 2)
	{
		if (piles->content[piles->size_a] >= pivot && size--)
			push_a(piles, ope);
		else if (++deplaced_elems)
			rotate_b(piles, ope);
	}
//	print_piles(piles);
	while (nb_elem / 2 != piles->size_b && deplaced_elems--)
		reverse_rotate_b(piles, ope);
	return (first_quick_sort(piles, ope, nb_elem / 2 + nb_elem % 2)
		&& second_quick_sort(piles, ope, nb_elem / 2));
}

int	first_quick_sort(t_piles *piles, t_operations **ope, int size)
{
	int	pivot;
	int	nb_elem;
	int	deplaced_elems;
	int	res;

//	printf("enter first with size %i\n", size);
//	print_piles(piles);
	deplaced_elems = 0;
	if (partial_order(piles, 0, size) == 1 || size <= 1)
	{
//		print_piles(piles);
//		printf("end of first with size %i\n", size);
		return (1);
	}
	nb_elem = size;
	if (size <= 3)
	{
		sort_top_a(piles, ope, size);
//		print_piles(piles);
//		printf("end of first with size %i\n", size);
		return (1);
	}
	pivot = get_pivot(piles, 0, size);
//	printf("pivot is %i with size %i\n", pivot, size);
	while (size != nb_elem / 2 + nb_elem % 2)
	{
		if (piles->content[0] < pivot && (size--))
			push_b(piles, ope);
		else if ((++deplaced_elems))
			rotate_a(piles, ope);
	}
//	print_piles(piles);
	while (piles->size_a != nb_elem / 2 + nb_elem % 2 && deplaced_elems--)
		reverse_rotate_a(piles, ope);
	return (first_quick_sort(piles, ope, nb_elem / 2 + nb_elem % 2)
		&& second_quick_sort(piles, ope, nb_elem / 2));
}
