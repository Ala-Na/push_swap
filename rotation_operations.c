/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:37:56 by anadege           #+#    #+#             */
/*   Updated: 2021/07/22 11:41:55 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_piles *lst, t_operations **ope)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_a <= 1)
		return ;
	i = lst->size_a - 1;
	tmp_1 = lst->content[i];
	while ((i - 1) >= 0)
	{
		tmp_2 = lst->content[i - 1];
		lst->content[i - 1] = tmp_1;
		tmp_1 = tmp_2;
		i--;
	}
	lst->content[lst->size_a - 1] = tmp_1;
	add_op(ope, new_op(ROTATE_A));
}

void	rotate_b(t_piles *lst, t_operations **ope)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_b <= 1)
		return ;
	i = lst->size_a + lst->size_b - 1;
	tmp_1 = lst->content[i];
	while ((i - 1) >= lst->size_a)
	{
		tmp_2 = lst->content[i - 1];
		lst->content[i - 1] = tmp_1;
		tmp_1 = tmp_2;
		i--;
	}
	lst->content[lst->size_a + lst->size_b - 1] = tmp_1;
	add_op(ope, new_op(ROTATE_B));
}
