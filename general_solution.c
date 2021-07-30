/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:47:06 by anadege           #+#    #+#             */
/*   Updated: 2021/07/30 15:58:55 by anadege          ###   ########.fr       */
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

	//simplify_operations(ope);
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

void	sort_until_five(t_piles *piles, t_operations **ope)
{
	int	middle;
	int	order;

	middle = (piles->size_a + piles->size_b) / 2;
	order = is_sorted(piles);
	while (!(order == TRUE_A && piles->size_b == 0))
	{
		if (order == TRUE_AB && piles->size_b > 0)
			push_a(piles, ope);
		if (order != TRUE_AB && ((order != TRUE_A && (piles->size_a == 3 || piles->size_a == 2)) || (order != TRUE_B && (piles->size_b == 3 || piles->size_b == 2))))
			sort_shorts_piles(piles, ope);
		else if (order != TRUE_AB  && order != TRUE_A && piles->size_a > 0 && piles->content[0] < middle)
			push_b(piles, ope);
		else
		{
			sort_top_piles(piles, middle, ope, -1);
			order = is_sorted(piles);
			if (order != TRUE_AB && order != TRUE_A)
				reverse_rotate_a(piles, ope);
			if (order != TRUE_AB && order != TRUE_B)
				reverse_rotate_b(piles, ope);
		}
		order = is_sorted(piles);
	}
}

int	sort_piles(t_piles *piles, t_operations **ope)
{
	int	order;

	order = is_sorted(piles);
	*ope = NULL;
	if (order == TRUE_A)
		return (0);
	if (piles->size_a <= 5)
		sort_until_five(piles, ope);
	else
		first_quick_sort(piles, ope, piles->size_a);
	simplify_operations(ope);
	print_solution(ope);
	if (is_sorted(piles) != TRUE_A || piles->size_b != 0)
		printf("ERROR\n");
	return (0);
}
