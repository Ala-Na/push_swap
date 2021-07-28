/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:59:15 by anadege           #+#    #+#             */
/*   Updated: 2021/07/29 00:00:43 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// POUR LES TESTS SEULEMENT :
# include <stdio.h>

/*
** Enum to define the return value of is_in_order function.
*/
typedef enum e_order
{
	FALSE,
	TRUE_A,
	TRUE_B,
	TRUE_AB
}	t_order;

/*
** Enum to simplify identification of actions/operations
** performed inside the structure t_operations.
*/
typedef enum e_action
{
	SWAP_A,
	SWAP_B,
	ROTATE_A,
	ROTATE_B,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	PUSH_A,
	PUSH_B,
	SS,
	RR,
	RRR,
	NOTHING
}	t_action;

/*
** Structure contening piles with tag values.
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
** Structure to tag values.
** Values are stocked and sorted inside *values thanks to a merge_sort.
** For each value, a tag corresponding to their position in the original
** non-sorted array is assigned from 0 to size - 1.
** (For example : For the array "42 6 9 1", ->values is "1 6 9 42"
** and ->tags is "3 1 2 0").
** Tagged values are more convenient to use than real values.
*/
typedef struct s_tags
{
	int	*values;
	int	*tags;
	int	size;
}	t_tags;

/*
** Structure to keep in memory all operations before writing them.
*/
typedef struct s_operations
{
	t_action	act;
	struct s_operations	*next;
}	t_operations;

/*
** 
*/
int		sort_piles(t_piles *piles, t_operations **ope);
char	*get_action_name(t_action act);
void	print_solution(t_operations **ope);

void	sort_until_five(t_piles *piles, t_operations **ope);

/*
** Operations functions.
** When one is performed, the information is stocked inside a
** t_operations structure.
*/
void	swap_a(t_piles *lst, t_operations **ope);
void	swap_b(t_piles *lst, t_operations **ope);
void	push_a(t_piles *lst, t_operations **ope);
void	push_b(t_piles *lst, t_operations **ope);
void	rotate_a(t_piles *lst, t_operations **ope);
void	rotate_b(t_piles *lst, t_operations **ope);
void	reverse_rotate_a(t_piles *lst, t_operations **ope);
void	reverse_rotate_b(t_piles *lst, t_operations **ope);

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
