/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:40:30 by sitao             #+#    #+#             */
/*   Updated: 2025/05/30 20:40:35 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min_val;
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_val = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min_val)
		{
			min_val = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max_val;
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_val = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max_val)
		{
			max_val = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
