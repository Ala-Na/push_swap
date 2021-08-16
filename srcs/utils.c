/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:42:53 by anadege           #+#    #+#             */
/*   Updated: 2021/08/16 11:29:07 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	return_value(long int res, long int sign,
		int *check_limit, int cursor)
{
	if (cursor > 10 || ((res < 0 || res > INT_MAX) && sign > 0))
	{
		*check_limit = -1;
		return (-1);
	}
	else if ((res < 0 || res * sign < INT_MIN) && sign < 0)
	{
		*check_limit = -1;
		return (0);
	}
	res *= sign;
	return ((int)res);
}

static void	ft_check_sign(const char *nptr, long int *sign, int *i, int *start)
{
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		*i += 1;
		*start += 1;
	}
}

int	ft_atoi_like(const char *nptr, int *check_limit)
{
	unsigned int	nbr;
	long int		res;
	long int		sign;
	int				i;
	int				start;

	i = 0;
	nbr = 0;
	res = 0;
	sign = 1;
	start = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	ft_check_sign(nptr, &sign, &i, &start);
	while (nptr[start] == '0')
		start++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nptr[i++] - '0';
		res = res * 10 + nbr;
	}
	return ((int)return_value(res, sign, check_limit, i - start));
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
