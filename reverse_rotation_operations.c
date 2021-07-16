/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation_operations.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:39:06 by anadege           #+#    #+#             */
/*   Updated: 2021/07/16 13:39:37 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_piles *lst)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_a > 0)
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
	}
}

void	reverse_rotate_b(t_piles *lst)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_b > 0)
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
	}
}

void	reverse_rotate_r(t_piles *lst)
{
	reverse_rotate_a(lst);
	reverse_rotate_b(lst);
}
