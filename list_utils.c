/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:12:59 by anadege           #+#    #+#             */
/*   Updated: 2021/07/30 18:16:03 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function to create a new t_operations structure with the last
** action made as ->act.
*/
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

/*
** Function to add a new t_operations stucture at the end of a linked list.
*/
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

/*
** Function to reduce number of operations.
** It replace or delete operations. 
** For example, if rra and rrb are consecutive, the first will be replace by rrr
** and the second by nothing.
** Another example, if rra and ra are consecutive, both will be 
** replaced by NOTHING.
*/
void	simplify_operations(t_operations **ope)
{
	t_operations	*curr;
	t_operations	*seek;

	curr = *ope;
	while (curr->next)
	{
		seek = curr->next;
		if ((curr->act == SWAP_A && seek->act == SWAP_B)
			|| (curr->act == SWAP_B && seek->act == SWAP_A))
			replace_action(&curr, &seek, SS);
		else if (curr->act == ROTATE_A || curr->act == ROTATE_B
			|| curr->act == REVERSE_ROTATE_A || curr->act == REVERSE_ROTATE_B)
			simplify_rotations(curr, seek);
		else if ((curr->act == ROTATE_A && seek->act == REVERSE_ROTATE_A)
			|| (curr->act == ROTATE_B && seek->act == REVERSE_ROTATE_B)
			|| (seek->act == ROTATE_A && curr->act == REVERSE_ROTATE_A)
			|| (seek->act == ROTATE_B && curr->act == REVERSE_ROTATE_B)
			|| (seek->act == PUSH_A && curr->act == PUSH_B)
			|| (seek->act == PUSH_B && curr->act == PUSH_A))
			replace_action(&curr, &seek, NOTHING);
		curr = curr->next;
	}
}

/*
** Sub-function of simplify_operations for rotations and reverse rotations.
*/
void	simplify_rotations(t_operations *curr, t_operations *seek)
{
	if (curr->act == ROTATE_A || curr->act == ROTATE_B)
	{
		while (seek->act == curr->act || seek->act == RR)
			seek = seek->next;
		if ((curr->act != seek->act && seek->act == ROTATE_B)
			|| (curr->act != seek->act && seek->act == ROTATE_A))
			replace_action(&curr, &seek, RR);
	}
	else if (curr->act == REVERSE_ROTATE_A || curr->act == REVERSE_ROTATE_B)
	{
		while (seek->act == curr->act || seek->act == RRR)
			seek = seek->next;
		if ((curr->act != seek->act && seek->act == REVERSE_ROTATE_B)
			|| (curr->act != seek->act && seek->act == REVERSE_ROTATE_A))
			replace_action(&curr, &seek, RRR);
	}
}

/*
** Sub-function of simplify_operations which replace one action by another.
*/
void	replace_action(t_operations **curr, t_operations **seek,
		t_action action)
{
	if (!*curr || !*seek || !(*curr)->next)
		return ;
	(*curr)->act = action;
	(*seek)->act = NOTHING;
}
