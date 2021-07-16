/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 15:45:36 by anadege           #+#    #+#             */
/*   Updated: 2021/07/16 13:42:18 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_piles *lst)
{
	int	tmp;

	if (lst->size_a > 1)
	{
		tmp = lst->content[0];
		lst->content[0] = lst->content[1];
		lst->content[1] = tmp;
	}
}

void	swap_b(t_piles *lst)
{
	int	tmp;

	if (lst->size_b > 1)
	{
		tmp = lst->content[(lst->size_a)];
		lst->content[lst->size_a] = lst->content[(lst->size_a) + 1];
		lst->content[(lst->size_a) + 1] = tmp;
	}
}

void	swap_s(t_piles *lst)
{
	swap_a(lst);
	swap_b(lst);
}

void	push_a(t_piles *lst)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_b > 0)
	{
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
	}
}

void	push_b(t_piles *lst)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_a > 0)
	{
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
	}
}
