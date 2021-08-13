/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadege <anadege@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 10:53:52 by anadege           #+#    #+#             */
/*   Updated: 2021/08/07 16:04:36 by anadege          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_order
{
	FALSE,
	TRUE_A,
	TRUE_B,
	TRUE_AB
}	t_order;

typedef struct s_piles
{
	int	*content;
	int	size_a;
	int	size_b;
}	t_piles;

t_order	is_sorted(t_piles *lst);
void	init_piles(t_piles *piles, int *list_a, int size_a);
void	free_piles(t_piles *piles, int *list_a);
int		error(int i);

int		read_instructions(char *buffer, t_piles *piles);
void	fill_full_buffer(char *buffer, char **full_buffer);
int		get_instructions(t_piles *piles);
int		check_buffer(char *buffer, int start);
int		comp_to_op(char *buffer);
int		find_op(char *buffer, t_piles *piles);

int		ft_atoi_like(const char *nptr, int *check_limit);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		check_pa(t_piles *lst);
int		check_pb(t_piles *lst);
int		check_sa(t_piles *lst);
int		check_sb(t_piles *lst);
int		check_ss(t_piles *lst);
int		check_ra(t_piles *lst);
int		check_rb(t_piles *lst);
int		check_rr(t_piles *lst);
int		check_rra(t_piles *lst);
int		check_rrb(t_piles *lst);
int		check_rrr(t_piles *lst);

int		check_duplicate(int *list_a, int size_a);
int		get_list_from_mult_strings(char **arr_str,
			int **list_a, int *size_a, int *check_limit);
int		get_list_size_from_string(char *str);
int		get_list_from_single_string(char *str, int **list_a,
			int *size_a, int *check_limit);
int		check_and_extract_list(int argc, char **argv, int **list_a,
			int *size_a);

#endif
