/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:34:11 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/27 15:38:53 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

// t_stack	*ft_create_stack(int content)
// {
// 	t_stack	*top;

// 	top = (t_stack *)malloc(sizeof(t_stack));
// 	if (!top)
// 		return (NULL);
// 	top->data = content;
// 	top -> index = -1;
// 	top -> next = NULL;
// 	return (top);
// }

t_stack	*ft_lstlast(t_stack *top)
{
	if (!top)
		return (NULL);
	while (top -> next)
		top = top -> next;
	return (top);
}

int	ft_lstsize(t_stack *top)
{
	int	size;

	size = 0;
	while (top)
	{
		top = top -> next;
		size++;
	}
	return (size);
}

void	ft_lstadd_front(t_stack **stack, t_stack *top)
{
	if (!top)
		return ;
	top -> next = *stack;
	*stack = top;
}

void	ft_lstadd_back(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!node)
		return ;
	if (*stack)
	{
		tmp = ft_lstlast(*stack);
		tmp -> next = node;
	}
	else
		*stack = node;
}
