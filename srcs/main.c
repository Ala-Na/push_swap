/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 11:56:07 by anadege           #+#    #+#             */
/*   Updated: 2021/08/16 11:38:12 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function to get the name of an operation, according it's t_action value.
*/
char	*get_name(t_action act)
{
	int				i;
	const t_action	values[12] = {SWAP_A, SWAP_B, PUSH_A, PUSH_B, ROTATE_A,
		ROTATE_B, REVERSE_ROTATE_A, REVERSE_ROTATE_B, SS, RR, RRR, NOTHING};
	const char		*names[12] = {"sa\n", "sb\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rra\n", "rrb\n", "ss\n", "rr\n", "rrr\n", NULL};

	i = 0;
	while (i < 12)
	{
		if (act == (values)[i])
			return ((char *)(names)[i]);
		i++;
	}
	return (NULL);
}

/*
** Function to print every operations used to sort elements.
** It browse a t_operations structure, print the corresponding name
** and free it in the same time.
** It can also be used to strictly free the structure without printing if
** print is set to 0.
*/
void	browse_solution(t_operations **ope, int print)
{
	t_operations	*to_print;
	t_operations	*tmp;
	char			*name;

	simplify_operations(ope);
	to_print = *ope;
	while (to_print)
	{
		if (print)
		{
			name = get_name(to_print->act);
			if (name != NULL)
				ft_putstr_fd(name, 1);
		}
		tmp = to_print;
		to_print = to_print->next;
		free(tmp);
	}
	*ope = NULL;
}

/*
** Function to nicely free every malloc objects. 
** If error == 1, an error message is displayed on stderr.
*/
int	free_cleaning(t_piles *piles, t_operations **ope, int *list,
		int return_value)
{
	if (list)
		free(list);
	if (piles)
	{
		if (piles->content)
			free(piles->content);
		free(piles);
	}
	if (ope)
		browse_solution(ope, 0);
	if (return_value == -1)
		ft_putstr_fd("Error\n", 2);
	return (return_value);
}

/*
** Function to start the sort algorithm and print the solution
** once it's done.
*/
int	sort_piles(t_piles *piles, t_operations **ope)
{
	int				order;
	int				success;

	order = is_sorted(piles);
	*ope = NULL;
	if (order == TRUE_A)
		return (0);
	a_half_sort(piles, ope, piles->size_a);
	if (piles->size_b != 0)
		success = FALSE;
	else
		success = is_sorted(piles);
	if (success != TRUE_A || ope == NULL)
		return (-1);
	simplify_operations(ope);
	browse_solution(ope, 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_operations	*ope;
	t_piles			*piles;
	int				res;
	int				*list_a;
	int				size_a;

	list_a = NULL;
	size_a = 0;
	if (argc < 2)
		return (0);
	res = check_and_extract_list(argc, argv, &list_a, &size_a);
	if (res == -1 || !list_a || (size_a == 1 && list_a))
	{
		free_cleaning(NULL, NULL, list_a, res);
		if (size_a == 1 && res != -1)
			return (0);
		return (1);
	}
	piles = tag_values(list_a, size_a);
	free(list_a);
	if (piles == NULL)
		return (1);
	if (sort_piles(piles, &ope) == -1)
		return (free_cleaning(piles, &ope, NULL, 1));
	return (free_cleaning(piles, NULL, NULL, 0));
}
