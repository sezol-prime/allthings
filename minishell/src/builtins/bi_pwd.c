/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:35:11 by mipang            #+#    #+#             */
/*   Updated: 2025/10/29 00:00:05 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_pwd(void)
{
	char	buf[4096];

	if (getcwd(buf, sizeof(buf)) != NULL)
	{
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		return (0);
	}
	perror("pwd");
	return (1);
}
