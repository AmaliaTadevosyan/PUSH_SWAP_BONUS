/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:58:33 by amtadevo          #+#    #+#             */
/*   Updated: 2023/03/27 15:53:59 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sign_error(char *str, int *i, int *sign)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		if (str[*i] == '-' && ft_issign(str[*i + 1]))
			print_error();
		if (ft_issign(str[*i]) && !str[*i + 1])
			print_error();
		if (ft_issign(str[*i]) && !ft_isdigit(str[*i + 1]))
			print_error();
		(*i)++;
	}
	if (ft_isdigit(str[*i]) && ft_issign(str[*i + 1]))
		print_error();
}

void	num_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && !ft_isdigit(str[i + 1]))
			print_error();
		i++;
	}
}

void	fake_atoi(char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	sign_error(str, &i, &sign);
	if (ft_isdigit(str[i]))
	{
		num_error(str);
		while (str[i] && ft_isdigit(str[i]))
		{
			num = (num * 10) + (str[i] - '0');
			if (num * sign > 2147483647)
				print_error();
			else if (num * sign < -2147483648)
				print_error();
			i++;
		}
	}
	else
		print_error();
}

void	check_duplicates(char **str, int len)
{
	int	i;
	int	j;
	int	*nums;

	i = 0;
	nums = malloc(sizeof(int) * len);
	while (str[i])
	{
		nums[i] = ft_atoi(str[i]);
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] == nums[j])
				print_error();
			j++;
		}
		i++;
	}
	free(nums);
}

int	is_sorted(t_stack *top)
{
	if (top == NULL || top->next == NULL)
		return (1);
	return (top->data < top->next->data && is_sorted(top->next));
}
