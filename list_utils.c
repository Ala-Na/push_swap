/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:12:59 by anadege           #+#    #+#             */
/*   Updated: 2021/07/21 23:52:40 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operations	*new_op(char *name_op)
{
	t_operations	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->operation = name_op;
	new->next = NULL;
	return (new);
}

void	add_op(t_operations **ope, t_operations *new)
{
	t_operations	*last_op;

	if (new == NULL)
		return ;
	else if (*ope == NULL)
	{
		*ope = new;
		return ;
	}
	last_op = *ope;
	while (last_op->next != NULL)
		last_op = last_op->next;
	last_op->next = new;
}

