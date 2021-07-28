/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:47:06 by anadege           #+#    #+#             */
/*   Updated: 2021/07/28 18:10:43 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_action_name(t_action act)
{
	if (act == SWAP_A)
		return ("sa\n");
	else if (act == SWAP_B)
		return ("sb\n");
	else if (act == PUSH_A)
		return ("pa\n");
	else if (act == PUSH_B)
		return ("pb\n");
	else if (act == ROTATE_A)
		return ("ra\n");
	else if (act == ROTATE_B)
		return ("rb\n");
	else if (act == REVERSE_ROTATE_A)
		return ("rra\n");
	else if (act == REVERSE_ROTATE_B)
		return ("rrb\n");
	else if (act == SS)
		return ("ss\n");
	else if (act == RR)
		return ("rr\n");
	else if (act == RRR)
		return ("rrr\n");
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
		name = get_action_name(to_print->act);
		if (name != NULL)
			ft_putstr_fd(name, 1);
		tmp = to_print;
		to_print = to_print->next;
		free(tmp);
	}
}

void	sort_pile_until_five_elem(t_piles *piles, t_operations **ope)
{
	int	middle;
	int	order;

	middle = (piles->size_a + piles->size_b) / 2;
	order = is_in_order(piles);
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
			order = is_in_order(piles);
			if (order != TRUE_AB && order != TRUE_A)
				reverse_rotate_a(piles, ope);
			if (order != TRUE_AB && order != TRUE_B)
				reverse_rotate_b(piles, ope);
		}
		order = is_in_order(piles);
	}
}

int	sort_piles(t_piles *piles, t_operations **ope)
{
	int	order;

	order = is_in_order(piles);
	*ope = NULL;
	if (order == TRUE_A)
		return (0);
	if (piles->size_a <= 5)
		sort_pile_until_five_elem(piles, ope);
	else
	{
		first_quick_sort(piles, ope, piles->size_a);
		second_quick_sort(piles, ope, piles->size_b);
		while (piles->size_b)
			push_a(piles, ope);
	}
	print_solution(ope);
/*	int	i = 0;
	while (i < piles->size_a + piles->size_b)
	{
		if (i < piles->size_a)
			printf("%i in a, ", piles->content[i]);
		else
			printf("%i in b, ", piles->content[i]);
		i++;
		if (i == piles->size_a + piles->size_b)
			printf("\n");
	}*/
	if (is_in_order(piles) != TRUE_A || piles->size_b != 0)
		printf("ERROR\n");
	return (0);
}
