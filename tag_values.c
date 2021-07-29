/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:00:59 by anadege           #+#    #+#             */
/*   Updated: 2021/07/29 11:17:25 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Transform values to their tags equivalents thanks to
** their sorted order.
*/
void	transform_values_to_tags(t_tags *tags)
{
	int	i;
	int	j;

	i = 0;
	while (i < tags->size)
	{
		j = 0;
		while (j < tags->size)
		{
			if (tags->tags[i] == tags->values[j])
			{
				tags->tags[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

/*
** Function to transform the received list of int to
** a t_piles structure with values from 0 to number of elements.
** A t_tags structure is made and elements are sorted to
** obtain each tag corresponding to each value. 
** The non-ordered array of 0 to number of elements
** is the future t_piles->content.
*/
t_piles	*tag_values(int *lst, int size)
{
	t_piles	*piles;
	t_tags	*tags;

	tags = malloc(sizeof(*tags));
	if (!tags)
		return (NULL);
	tags->tags = copy_array(lst, size);
	tags->size = size;
	if (!tags->tags || merge_sort(lst, 0, size - 1) == -1)
		return (NULL);
	tags->values = lst;
	transform_values_to_tags(tags);
	piles = malloc(sizeof(*piles));
	if (!piles)
		return (NULL);
	piles->content = tags->tags;
	piles->size_a = tags->size;
	piles->size_b = 0;
	free(tags->values);
	free(tags);
	return (piles);
}
