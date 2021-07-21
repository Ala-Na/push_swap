/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:56:07 by anadege           #+#    #+#             */
/*   Updated: 2021/07/21 23:39:56 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_operations	*ope;
	t_piles		*piles;
	int			*list_a;
	int			size_a;

	if (argc < 2)
		return (1);
	if (check_and_extract_list(argc, argv, &list_a, &size_a) == -1 || !list_a)
	{
		if (list_a)
			free(list_a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (size_a == 1 && list_a)
	{
		free(list_a);
		return (0);
	}
	piles = tag_values(list_a, size_a);
	if (piles == NULL || sort_piles(piles, &ope) == -1)
	{
		free(list_a);
		if (piles->content)
			free(piles->content);
		if (piles)
			free(piles);
		if (ope)
			free(ope);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	free(piles->content);
	free(piles);
	free(ope);
	return (0);
}
