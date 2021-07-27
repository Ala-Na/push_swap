/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:42:47 by anadege           #+#    #+#             */
/*   Updated: 2021/07/27 14:20:47 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partial_order(t_piles *piles, int is_b, int len)
{
	int start;
	int	i;

	i = 0;
	if (is_b == 0)
		start = 0;
	else
		start = piles->size_a;
	while (i + 1 < len)
	{
		if (is_b == 0 && piles->content[start + i] > piles->content[start + i + 1])
			return (0);
		else if (is_b == 1 && piles->content[start + i] < piles->content[start + i + 1])
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
