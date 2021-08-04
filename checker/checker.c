/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:05:57 by anadege           #+#    #+#             */
/*   Updated: 2021/08/04 18:18:44 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_order	is_sorted(t_piles *lst)
{
	int	i;
	int	true_a;
	int	true_b;

	i = -1;
	true_a = 1;
	while (++i + 1 < lst->size_a)
		if (lst->content[i] > lst->content[i + 1])
			true_a = 0;
	i = lst->size_a - 1;
	true_b = 1;
	while (++i + 1 < lst->size_a + lst->size_b)
		if (lst->content[i] < lst->content[i + 1])
			true_b = 0;
	if (lst->size_a != 0 && lst->size_b != 0 && true_a && true_b)
		return (TRUE_AB);
	else if (lst->size_a != 0 && true_a)
		return (TRUE_A);
	else if (lst->size_b != 0 && true_b)
		return (TRUE_B);
	return (FALSE);
}

void	init_piles(t_piles *piles, int *list_a, int size_a)
{
	piles->content = list_a;
	piles->size_a = size_a;
	piles->size_b = 0;
}

void	free_piles(t_piles *piles, int *list_a)
{
	if (list_a)
		free(list_a);
	if (piles)
		free(piles);
}

int	error(void)
{
	ft_putstr_fd("KO\n", 2);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_piles	*piles;
	int		*list_a;
	int		size_a;
	int		res;

	list_a = NULL;
	piles = NULL;
	if (argc < 2)
		return (0);
	piles = malloc(sizeof(*piles));
	if (check_and_extract_list(argc, argv, &list_a, &size_a) == -1 || !piles)
	{
		free_piles(piles, list_a);
		return (error());
	}
	init_piles(piles, list_a, size_a);
	res = get_instructions(piles);
	free_piles(piles, list_a);
	if (res != 1)
		return (error());
	ft_putstr_fd("OK\n", 1);
	return (0);
}
