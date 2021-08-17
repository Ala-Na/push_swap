/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:59:53 by anadege           #+#    #+#             */
/*   Updated: 2021/08/17 10:50:43 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_get_list_from_single_string(char *str, int **list_a,
		int *list_i, int *size_a)
{
	*list_i = 0;
	*size_a = get_list_size_from_string(str);
	if (*size_a == -1)
		return (-1);
	*list_a = malloc(sizeof(**list_a) * (*size_a));
	if (!*list_a)
		return (-1);
	return (0);
}

int	return_value_get_list_from_single_string(int i)
{
	if (i == 0)
		return (-1);
	return (0);
}

void	modify_check_and_begin_number(int *check, int *begin_number, int i)
{
	if (*check == 0)
		*check = i;
	*begin_number = 0;
}
