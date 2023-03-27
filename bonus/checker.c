/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:26:10 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/03/27 15:45:19 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap_bonus.h"

void	errors(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*result;
// 	char	*str;
// 	char	*arr_to_free;

// 	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (!s2 || !result)
// 		return (0);
// 	arr_to_free = s1;
// 	str = result;
// 	while (*s1)
// 	{
// 		*str = *s1;
// 		s1++;
// 		str++;
// 	}
// 	while (*s2)
// 		*str++ = *s2++;
// 	*str = '\0';
// 	free(arr_to_free);
// 	return (result);
// }

int	ft_is_stack_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	gnl(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		compare(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (!ft_is_stack_sorted(*a) || *b != NULL)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

// static void	ft_fill_stack(t_stack **stack, int c, char **v)
// {
// 	t_stack	*node;
// 	char	**arr;
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	str = ft_strdup("");
// 	while (++i < c)
// 	{
// 		str = ft_strjoin(str, v[i]);
// 		str = ft_strjoin(str, " ");
// 	}
// 	i = -1;
// 	arr = ft_split(str, ' ');
// 	while (arr[++i])
// 	{
// 		node = ft_create_stack(ft_atoi(arr[i]));
// 		ft_lstadd_back(stack, node);
// 	}
// 	ft_free_arr(arr);
// 	free(str);
// }

int	main(int c, char **v)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (c < 2)
		return (0);
	if (v[1][0] == '\0')
		errors();
	ft_chek_arg(c, v);
	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	ft_fill_stack(stack_a, c, v);
	if (*stack_a == NULL || ft_is_stack_sorted(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	gnl(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
