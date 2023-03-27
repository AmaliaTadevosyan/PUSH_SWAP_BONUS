/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:56:24 by amtadevo          #+#    #+#             */
/*   Updated: 2023/03/27 15:34:25 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *top)
{
	int	tmp;

	if (top == NULL || top->next == NULL)
		return ;
	tmp = top->data;
	top->data = top->next->data;
	top->next->data = tmp;
	tmp = top->pos;
	top->pos = top->next->pos;
	top->next->pos = tmp;
}

void	ss(t_stack *a, t_stack *b, int n)
{
	swap(a);
	swap(b);
	if (n == 1)
		write(1, "ss\n", 3);
}

void	sa(t_stack *a, int n)
{
	swap(a);
	if (n == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int n)
{
	swap(b);
	if (n == 1)
		write(1, "sb\n", 3);
}
