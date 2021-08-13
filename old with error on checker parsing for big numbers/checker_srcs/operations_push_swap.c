/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:49:57 by anadege           #+#    #+#             */
/*   Updated: 2021/08/04 18:16:56 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sa(t_piles *lst)
{
	int	tmp;

	if (lst->size_a > 1)
	{
		tmp = lst->content[0];
		lst->content[0] = lst->content[1];
		lst->content[1] = tmp;
	}
	return (1);
}

int	check_sb(t_piles *lst)
{
	int	tmp;

	if (lst->size_b > 1)
	{
		tmp = lst->content[(lst->size_a)];
		lst->content[lst->size_a] = lst->content[(lst->size_a) + 1];
		lst->content[(lst->size_a) + 1] = tmp;
	}
	return (1);
}

int	check_ss(t_piles *lst)
{
	return (check_sa(lst) && check_sb(lst));
}

int	check_pa(t_piles *lst)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_b == 0)
		return (1);
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
	return (1);
}

int	check_pb(t_piles *lst)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_a == 0)
		return (1);
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
	return (1);
}
