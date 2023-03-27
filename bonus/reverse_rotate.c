/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:56:02 by amtadevo          #+#    #+#             */
/*   Updated: 2023/03/27 15:06:53 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **top)
{
	t_stack	*tail;
	t_stack	*tmp;

	if (*top == NULL || (*top)->next == NULL)
		return ;
	tail = ft_lstlast(*top);
	tmp = ft_lstseclast(*top);
	tmp->next = NULL;
	tail->next = *top;
	*top = tail;
}

void	rra(t_stack **a, int n)
{
	reverse_rotate(a);
	if (n == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int n)
{
	reverse_rotate(b);
	if (n == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int n)
{
	reverse_rotate(&a);
	reverse_rotate(&b);
	if (n == 1)
		write(1, "rrr\n", 4);
}
