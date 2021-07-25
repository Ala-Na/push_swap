/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:12:59 by anadege           #+#    #+#             */
/*   Updated: 2021/07/25 18:03:38 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_action(t_operations **curr, t_operations **seek, t_action action)
{
	t_operations	*to_replace;
	t_operations	*to_delete;
	t_operations	*parent_of_to_del;

	if (!*curr || !*seek || !(*curr)->next || !(*seek)->next)
		return ;
	to_replace = *curr;
	to_replace->act = action;
	parent_of_to_del = *seek;
	to_delete = parent_of_to_del->next;
	if (to_delete->next != NULL)
		parent_of_to_del->next = to_delete->next;
	else
		parent_of_to_del->next = NULL;
	free(to_delete);
	to_replace = to_replace->next;
	curr = &to_replace;
	seek = &(to_replace->next);
}

void	delete_unecessary_operations(t_operations **ope)
{
	t_operations	*curr;
	t_operations	*seek;

	curr = *ope;
	seek = curr->next;
	while (curr->next)
	{
		if (((curr->act == ROTATE_A || curr->act == REVERSE_ROTATE_A)
			&& (seek->act == PUSH_A || seek->act == SWAP_A || seek->act == PUSH_B))
			|| ((curr->act == ROTATE_B || curr->act == REVERSE_ROTATE_B)
			&& (seek->act == PUSH_B || seek->act == PUSH_A || seek->act == SWAP_B))
			|| seek->next == NULL)
		{
			curr = curr->next;
			seek = curr->next;
		}
		else if (curr->act == ROTATE_A && seek->act == REVERSE_ROTATE_A)
			replace_action(&curr, &seek, NOTHING);
		else if (curr->act == ROTATE_B && seek->act == REVERSE_ROTATE_B)
			replace_action(&curr, &seek, NOTHING);
		else if (seek->act == ROTATE_A && curr->act == REVERSE_ROTATE_A)
			replace_action(&curr, &seek, NOTHING);
		else if (seek->act == ROTATE_B && curr->act == REVERSE_ROTATE_B)
			replace_action(&curr, &seek, NOTHING);
	}
}

void	simplify_operations(t_operations **ope)
{
	t_operations	*curr;
	t_operations	*seek;

	curr = *ope;
	seek = curr->next;
	while (curr->next)
	{
		if (curr->act == PUSH_A || curr->act == PUSH_B
			|| seek->act == PUSH_A || seek->act == PUSH_B || seek->next == NULL
			|| (curr->act == SWAP_A && (seek->act == ROTATE_A || seek->act == REVERSE_ROTATE_A))
			|| (curr->act == SWAP_B && (seek->act == ROTATE_B || seek->act == REVERSE_ROTATE_B))
			|| (seek->act == SWAP_A && (curr->act == ROTATE_A || curr->act == REVERSE_ROTATE_A))
			|| (seek->act == SWAP_B && (curr->act == ROTATE_B || curr->act == REVERSE_ROTATE_B)))
		{
			curr = curr->next;
			seek = curr->next;
		}
		else if ((curr->act == SWAP_A && seek->next->act == SWAP_B)
			|| (curr->act == SWAP_B && seek->next->act == SWAP_A))
			replace_action(&curr, &seek, SS);
		else if ((curr->act == ROTATE_A && seek->next->act == ROTATE_B)
			|| (curr->act == ROTATE_B && seek->next->act == ROTATE_A))
			replace_action(&curr, &seek, RR);
		else if ((curr->act == REVERSE_ROTATE_A && seek->next->act == REVERSE_ROTATE_B)
			|| (curr->act == REVERSE_ROTATE_B && seek->next->act == REVERSE_ROTATE_A))
			replace_action(&curr, &seek, RRR);
		else
			seek = seek->next;
	}
}

t_operations	*new_op(t_action action)
{
	t_operations	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->act = action;
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
