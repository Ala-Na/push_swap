/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:00:59 by anadege           #+#    #+#             */
/*   Updated: 2021/07/19 21:24:07 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_piles	*tag_values(int *list, int size)
{
	t_piles	*piles;
	t_tags	*tags;

	tags = malloc(sizeof(*tags));
	if (!tags)
		return (NULL);
	tags->tags = copy_array(list, size);
	tags->size = size;
	if (!tags->tags || merge_sort(list, 0, size - 1) == -1)
		return (NULL);
	tags->values = list;
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
