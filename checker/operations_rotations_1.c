/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:55:10 by anadege           #+#    #+#             */
/*   Updated: 2021/08/04 18:17:43 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_ra(t_piles *lst)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_a <= 1)
		return (1);
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
	return (1);
}

int	check_rb(t_piles *lst)
{
	int	i;
	int	tmp_1;
	int	tmp_2;

	if (lst->size_b <= 1)
		return (1);
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
	return (1);
}

int	check_rr(t_piles *piles)
{
	return (check_ra(piles) && check_rb(piles));
}

int	check_rra(t_piles *lst)
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
	}
	return (1);
}

int	check_rrb(t_piles *lst)
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
	}
	return (1);
}
