/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:39:29 by sitao             #+#    #+#             */
/*   Updated: 2025/05/30 20:39:31 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static char	**get_args(int argc, char **argv, bool *should_free_args)
{
	char	**args;

	*should_free_args = false;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			exit(1);
		*should_free_args = true;
	}
	else
		args = &argv[1];
	return (args);
}

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	bool			should_free_args;

	a = NULL;
	b = NULL;
	args = get_args(argc, argv, &should_free_args);
	init_stack_a(&a, args);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	if (b)
		free_stack(&b);
	if (should_free_args)
		free_args(args);
	return (0);
}
