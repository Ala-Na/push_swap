/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:45:36 by anadege           #+#    #+#             */
/*   Updated: 2021/07/29 10:55:30 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *lst, t_operations **ope)
{
	int	tmp;

	if (lst->size_a > 1)
	{
		tmp = lst->content[0];
		lst->content[0] = lst->content[1];
		lst->content[1] = tmp;
		add_op(ope, new_op(SWAP_A));
	}
}

void	swap_b(t_piles *lst, t_operations **ope)
{
	int	tmp;

	if (lst->size_b > 1)
	{
		tmp = lst->content[(lst->size_a)];
		lst->content[lst->size_a] = lst->content[(lst->size_a) + 1];
		lst->content[(lst->size_a) + 1] = tmp;
		add_op(ope, new_op(SWAP_B));
	}
}

void	push_a(t_piles *lst, t_operations **ope)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_b == 0)
		return ;
	i = 0;
	tmp_1 = lst->content[i];
	while ((i + 1) <= (lst->size_a))
	{
		tmp_2 = lst->content[i + 1];
		lst->content[i + 1] = tmp_1;
		tmp_1 = tmp_2;
		i++;
	}
	lst->content[0] = tmp_1;
	lst->size_a += 1;
	lst->size_b -= 1;
	add_op(ope, new_op(PUSH_A));
}

void	push_b(t_piles *lst, t_operations **ope)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_a == 0)
		return ;
	i = lst->size_a - 1;
	tmp_1 = lst->content[0];
	while (i >= 0)
	{
		tmp_2 = lst->content[i];
		lst->content[i] = tmp_1;
		tmp_1 = tmp_2;
		i--;
	}
	lst->content[lst->size_a - 1] = tmp_1;
	lst->size_a -= 1;
	lst->size_b += 1;
	add_op(ope, new_op(PUSH_B));
}
