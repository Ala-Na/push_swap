/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:59:36 by anadege           #+#    #+#             */
/*   Updated: 2021/08/04 23:19:38 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	find_op(char *buffer, t_piles *piles)
{
	if (!ft_strncmp(buffer, "pa\n", 3))
		return (check_pa(piles));
	else if (!ft_strncmp(buffer, "pb\n", 3))
		return (check_pb(piles));
	else if (!ft_strncmp(buffer, "sa\n", 3))
		return (check_sa(piles));
	else if (!ft_strncmp(buffer, "sb\n", 3))
		return (check_sb(piles));
	else if (!ft_strncmp(buffer, "ss\n", 3))
		return (check_ss(piles));
	else if (!ft_strncmp(buffer, "ra\n", 3))
		return (check_ra(piles));
	else if (!ft_strncmp(buffer, "rb\n", 3))
		return (check_rb(piles));
	else if (!ft_strncmp(buffer, "rr\n", 3))
		return (check_rr(piles));
	else if (!ft_strncmp(buffer, "rra\n", 4))
		return (check_rra(piles));
	else if (!ft_strncmp(buffer, "rrb\n", 4))
		return (check_rrb(piles));
	else if (!ft_strncmp(buffer, "rrr\n", 4))
		return (check_rrr(piles));
	else if (!ft_strncmp(buffer, "\n", 1))
		return (0);
	return (-1);
}

int	read_instructions(char *buffer, t_piles *piles)
{
	int	i;

	i = 0;
	if (buffer == NULL && is_sorted(piles) == TRUE_A && piles->size_b == 0)
		return (1);
	while (buffer[i] != '\0' && find_op(&(buffer[i]), piles) == 1)
	{
		while (buffer[i] != '\n' && buffer[i] != '\0')
			i++;
		if (buffer[i] != '\0')
			i++;
	}
	if (buffer[i] == '\0' || find_op(&(buffer[i]), piles) == 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		if (is_sorted(piles) == TRUE_A && piles->size_b == 0)
			return (1);
	}
	if (buffer)
		free(buffer);
	return (0);
}

int	comp_to_op(char *buffer)
{
	int			i;
	const char	*ope[11] = {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	i = 0;
	while (i < 11)
	{
		if (i < 8 && !ft_strncmp(buffer, ope[i], 3))
			return (3);
		else if (i >= 8 && !ft_strncmp(buffer, ope[i], 4))
			return (4);
		i++;
	}
	return (0);
}

int	check_buffer(char *buffer)
{
	int	i;
	int	y;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (comp_to_op(buffer) == 3)
			i += 3;
		else if (comp_to_op(buffer) == 4)
			i += 4;
		else
		{
			y = i;
			while (buffer[y] != '\0')
				y++;
			if (y - i < 4 || (y - i < 5 && buffer[i] == 'r'
					&& buffer[i + 1] == 'r'))
				return (1);
			else
				return (-1);
		}
	}
	return (1);
}

int	get_instructions(t_piles *piles)
{
	char			buffer[1024];
	int				red;
	char			*full_buffer;
	char			*tmp;

	full_buffer = NULL;
	red = read(0, buffer, 1023);
	while (red > 0)
	{
		buffer[red] = '\0';
		if (full_buffer == NULL)
			full_buffer = ft_strdup(buffer);
		else
		{
			tmp = full_buffer;
			full_buffer = ft_strjoin(full_buffer, buffer);
			free(tmp);
		}
		if (full_buffer == NULL || check_buffer(full_buffer) == -1)
			return (-1);
		red = read(0, buffer, 1023);
	}
	return (read_instructions(full_buffer, piles));
}
