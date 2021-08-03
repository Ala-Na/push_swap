/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:42:47 by anadege           #+#    #+#             */
/*   Updated: 2021/08/02 17:40:26 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function to check if pile a is in increasing order, and if pile b is in
** decreasing order. A value corresponding to the enum t_inorder is returned.
*/
t_order	is_sorted(t_piles *lst)
{
	int	i;
	int	true_a;
	int	true_b;

	i = -1;
	true_a = 1;
	while (++i + 1 < lst->size_a)
		if (lst->content[i] > lst->content[i + 1])
			true_a = 0;
	i = lst->size_a - 1;
	true_b = 1;
	while (++i + 1 < lst->size_a + lst->size_b)
		if (lst->content[i] < lst->content[i + 1])
			true_b = 0;
	if (lst->size_a != 0 && lst->size_b != 0 && true_a && true_b)
		return (TRUE_AB);
	else if (lst->size_a != 0 && true_a)
		return (TRUE_A);
	else if (lst->size_b != 0 && true_b)
		return (TRUE_B);
	return (FALSE);
}

/*
** Function to check either if pile a is in increasing order (is_b == 0),
** or if pile b is in decreasing order (is_b ==1) for the len first elements. 
** A value corresponding to the enum t_inorder is returned.
*/
t_order	is_part_sorted(t_piles *lst, int is_b, int len)
{
	int	start;
	int	i;

	i = 0;
	if (is_b == 0)
		start = 0;
	else
		start = lst->size_a;
	while (i + 1 < len)
	{
		if (is_b == 0 && lst->content[start + i] > lst->content[start + i + 1])
			return (FALSE);
		else if (is_b == 1
			&& lst->content[start + i] < lst->content[start + i + 1])
			return (FALSE);
		i++;
	}
	if (is_b == 0)
		return (TRUE_A);
	return (TRUE_B);
}
