/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:59:15 by anadege           #+#    #+#             */
/*   Updated: 2021/07/30 17:20:12 by anadege          ###   ########.fr       */
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

void	sort_top_a(t_piles *piles, t_operations **ope, int size);
void	sort_top_b(t_piles *piles, t_operations **ope, int size);

void	sort_top_piles(t_piles *piles, int middle, t_operations **ope, int define_case);
void	sort_shorts_piles(t_piles *piles, t_operations **ope);

int		first_quick_sort(t_piles *piles, t_operations **ope, int size);
int		second_quick_sort(t_piles *piles, t_operations **ope, int size);
int		get_pivot(t_piles *piles, int start, int end);

/*
** Functions to check if order inside a pile is strictly ascending (for a),
** or descending (for b).
** Function is_sorted check order in whole pile for both piles.
** Function is_part_sorted check order in either a or b (depending if is_b
** value is either 0 or 1) for the len first elements.
** Both returns a t_order enum value.
*/
t_order	is_sorted(t_piles *lst);
t_order	is_part_sorted(t_piles *lst, int is_b, int len);

/*
** Functions to transform values to tags value from 0 to number
** of elements. A merge sort is used.
*/
t_piles	*tag_values(int *lst, int size);
void	transform_valus_to_tags(t_tags *tags);
int		merge_sort(int *lst, int start, int end);
int		merge(int *lst, int start, int center, int end);
int		*init_sub_arrays(int *lst, int *tmp, int start, int end);
int		free_sub_arrays(int *tmp_1, int *tmp_2);
int		*copy_array(int *lst, int size);

/*
** Operations functions.
** When one is performed, its name is stocked inside a
** t_operations structure and changed are applied to a t_piles
** structure.
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
** Functions for manipulation of t_operations structure.
*/
t_operations	*new_op(t_action action);
void	add_op(t_operations **ope, t_operations *new);
void	simplify_operations(t_operations **ope);
void	simplify_rotations(t_operations *curr, t_operations *seek);
void	replace_action(t_operations **curr, t_operations **seek, t_action action);

/*
** Utilitary functions
*/
int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);

#endif
