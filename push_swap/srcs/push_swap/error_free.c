/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:38:50 by sitao             #+#    #+#             */
/*   Updated: 2025/05/30 20:38:52 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	error_syntax(char *s)
{
	int	i;

	i = 1;
	if (s == NULL || s[0] == '\0')
		return (1);
	if (s[0] == '+')
		return (1);
	if (!(s[0] == '-' || (s[0] >= '0' && s[0] <= '9')))
		return (1);
	if (s[0] == '-' && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_range(long long val)
{
	if (val > INT_MAX || val < INT_MIN)
		return (1);
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}
