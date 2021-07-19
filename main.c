/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:56:07 by anadege           #+#    #+#             */
/*   Updated: 2021/07/19 23:59:21 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_piles *piles;
	int	*list_a;
	int	size_a;

	if (argc < 2)
		return (1);
	if (check_and_extract_list(argc, argv, &list_a, &size_a) == -1 || !list_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	/*int i = 0;
	while (i < size_a)
	{
		printf("%i\n", list_a[i]);
		i++;
	}*/
	if (size_a == 1 && list_a)
	{
		free(list_a);
		return (0);
	}
	piles = tag_values(list_a, size_a);
	if (piles == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);

	}
	sort_piles(piles);
	/*i = 0;
	while (i < piles->size_a)
	{
		printf("%i\n", piles->content[i]);
		i++;
	}*/
	free(piles->content);
	free(piles);
	return (0);
}
