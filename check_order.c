/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:42:47 by anadege           #+#    #+#             */
/*   Updated: 2021/07/25 17:32:55 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_monotonic_a(t_piles *piles, t_operations **ope)
{
	int	i;
	int	min_value_pos;

	i = 0;
	min_value_pos = i;
	while (i < piles->size_a)
	{
		if (piles->content[min_value_pos] > piles->content[i])
			min_value_pos = i;
		i++;
	}
	if (min_value_pos < piles->size_a / 2 + 1)
	{
		while (min_value_pos != 0)
		{
			rotate_a(piles, ope);
			min_value_pos--;
		}
		return ;
	}
	while (min_value_pos != piles->size_a)
	{
		reverse_rotate_a(piles, ope);
		min_value_pos++;
	}
}

int	a_is_bitonic(t_piles *lst)
{
	int	i;
	int	max_value_pos;
	int min_value_pos;

	i = 0;
	max_value_pos = 0;
	min_value_pos = 0;
	if (lst->size_a <= 2)
		return (1);
	while (i < lst->size_a)
	{
		if (lst->content[i] > lst->content[max_value_pos])
			max_value_pos = i;
		if (lst->content[i] < lst->content[min_value_pos])
			min_value_pos = i;
		i++;
	}
	i = 0;
	while (i + 1 < lst->size_a)
	{
		if (i != max_value_pos && lst->content[i] > lst->content[i + 1])
			return (0);
		else if (i == max_value_pos && lst->content[i + 1] != lst->content[min_value_pos])
			return (0);
		i++;
	}
	return (1);
}

/*
** Function to check if pile a is in increasing order, and if pile b is in
** decreasing order. A value corresponding to the enum t_inorder is returned.
*/
t_order	is_in_order(t_piles *lst)
{
	int	i;
	int	true_a;
	int	true_b;

	i = 0;
	true_a = 1;
	while (i + 1 < lst->size_a)
	{
		if (lst->content[i] > lst->content[i+ 1])
			true_a = 0;
		i++;
	}
	i = lst->size_a;
	true_b = 1;
	while (i + 1 < lst->size_a + lst->size_b)
	{
		if (lst->content[i] < lst->content[i+ 1])
			true_b = 0;
		i++;
	}
	if (lst->size_a != 0 && lst->size_b != 0 && true_a && true_b)
		return (TRUE_AB);
	else if (lst->size_a != 0 && true_a)
		return (TRUE_A);
	else if (lst->size_b != 0 && true_b)
		return (TRUE_B);
	return (FALSE);
}
