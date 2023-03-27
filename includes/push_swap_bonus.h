/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:58:33 by amtadevo          #+#    #+#             */
/*   Updated: 2023/03/27 15:35:14 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include "../libft/libft.h"

void	fake_atoi(char *str);
void	check_duplicates(char **str, int len);
t_stack	*fill_stack(char **str);
void	swap(t_stack *top);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **top);
void	ra(t_stack **a, int n);
void	rb(t_stack **b, int n);
void	rr(t_stack *a, t_stack *b, int n);
void	rra(t_stack **a, int n);
void	rrb(t_stack **b, int n);
void	rrr(t_stack *a, t_stack *b, int n);
void	ss(t_stack *a, t_stack *b, int n);
void	sa(t_stack *a, int n);
void	sb(t_stack *b, int n);
void	pa(t_stack **a, t_stack **b, int n);
void	pb(t_stack **a, t_stack **b, int n);
void	print_error(void);
void	zeros_validation(char **str, int len);
int		num_len(int num);
int		is_sorted(t_stack *top);
void	sort3(t_stack **a);
void	sort4(t_stack **a, t_stack **b);
void	sort5(t_stack **a, t_stack **b);
int		max_pos(t_stack *a);
int		min_pos(t_stack *a);
char	**argv_parsing(int argc, char **argv);
void	butterfly(t_stack **a, t_stack **b);
int		*str_to_arr(t_stack *a);
int		*bubble_sort(t_stack *a);
void	indexing(t_stack *a);
void	a_to_b(t_stack **a, t_stack **b, int n);
void	b_to_a(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
void	free_str(char **str);
void	sort2(t_stack **a);
int		place_in_stack(t_stack **a, int data);
int		largest_element(t_stack *head);
void	del(int data);

#endif
