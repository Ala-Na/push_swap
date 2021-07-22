/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:39:06 by anadege           #+#    #+#             */
/*   Updated: 2021/07/22 16:46:32 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_piles *lst, t_operations **ope)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_a > 1)
	{
		i = 0;
		tmp_1 = lst->content[i];
		while ((i + 1) < lst->size_a)
		{
			tmp_2 = lst->content[i + 1];
			lst->content[i + 1] = tmp_1;
			tmp_1 = tmp_2;
			i++;
		}
		lst->content[0] = tmp_1;
		add_op(ope, new_op(REVERSE_ROTATE_A));
		printf("rra\n");
	}
}

void	reverse_rotate_b(t_piles *lst, t_operations **ope)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_b > 1)
	{
		i = lst->size_a;
		tmp_1 = lst->content[i];
		while ((i + 1) < (lst->size_a + lst->size_b))
		{
			tmp_2 = lst->content[i + 1];
			lst->content[i + 1] = tmp_1;
			tmp_1 = tmp_2;
			i++;
		}
		lst->content[lst->size_a] = tmp_1;
		add_op(ope, new_op(REVERSE_ROTATE_B));
		printf("rrb\n");
	}
}
