/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:59:15 by anadege           #+#    #+#             */
/*   Updated: 2021/07/15 22:30:40 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// POUR LES TESTS SEULEMENT :
# include <stdio.h>

/*
** Structure contening piles.
** All values are stocked inside one unique array of int named content. 
** Int size_a and size_b respectively represent the size of pile a and pile b. 
** If a is full and b empty, all values inside content belongs to pile a.
** If b is full and a empty, it's the contrary. 
** If both are filled, then the first size_a-nth values belongs to pile a,
** and the last size_b-nth belongs to pile b. 
*/
typedef struct s_piles
{
	int	*content;
	int	size_a;
	int	size_b;
}	t_piles;

/*
** Parsing functions
*/
int		check_duplicate(int *list_a, int size_a);
int		get_list_from_mult_strings(char **arr_str, int **list_a, int *size_a);
int		get_list_size_from_string(char *str);
int		get_list_from_single_string(char *str, int **list_a, int *size_a);
int		check_and_extract_list(int argc, char **argv, int **list_a,
			int *size_a);

/*
** Utilitary functions
*/
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);

#endif
