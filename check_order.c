/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:42:47 by anadege           #+#    #+#             */
/*   Updated: 2021/07/16 16:00:32 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (lst->content[i] > lst->content[i++ + 1])
			true_a = 0;
	}
	i = lst->size_a;
	true_b = 1;
	while (i + 1 < lst->size_a + lst->size_b)
	{
		if (lst->content[i] < lst->content[i++ + 1])
			true_b = 0;
	}
	if (true_a && true_b)
		return (TRUE_AB);
	else if (true_a)
		return (TRUE_A);
	else if (true_b)
		return (TRUE_B);
	return (FALSE);
}
