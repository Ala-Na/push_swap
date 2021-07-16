/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:00:59 by anadege           #+#    #+#             */
/*   Updated: 2021/07/16 16:06:41 by anadege          ###   ########.fr       */
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

t_tags	*tag_values(int *list, int size)
{
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
	return (tags);
}
