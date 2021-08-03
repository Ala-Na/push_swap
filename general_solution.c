/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:47:06 by anadege           #+#    #+#             */
/*   Updated: 2021/08/03 11:51:52 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_action	g_values[12] = {SWAP_A, SWAP_B, PUSH_A, PUSH_B, ROTATE_A, ROTATE_B,
	REVERSE_ROTATE_A, REVERSE_ROTATE_B, SS, RR, RRR, NOTHING}; 
char	*g_names[12] = {"sa\n", "sb\n", "pa\n", "pb\n", "ra\n", "rb\n", "rra\n",
		"rrb\n", "ss\n", "rr\n", "rrr\n", NULL};

char	*get_name(t_action act)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (act == (g_values)[i])
			return ((g_names)[i]);
		i++;
	}
	return (NULL);
}

void	print_solution(t_operations **ope)
{
	t_operations	*to_print;
	t_operations	*tmp;
	char	*name;

	simplify_operations(ope);
	to_print = *ope;
	while (to_print)
	{
		name = get_name(to_print->act);
		if (name != NULL)
			ft_putstr_fd(name, 1);
		tmp = to_print;
		to_print = to_print->next;
		free(tmp);
	}
}

int	sort_piles(t_piles *piles, t_operations **ope)
{
	int	order;

	order = is_sorted(piles);
	*ope = NULL;
	if (order == TRUE_A)
		return (0);
	a_half_sort(piles, ope, piles->size_a);
	simplify_operations(ope);
	print_solution(ope);
	if (is_sorted(piles) != TRUE_A || piles->size_b != 0)
		ft_putstr_fd("ERROR\n", 2);
	return (0);
}
