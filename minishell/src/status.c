/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:54:16 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 21:54:22 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_status(t_ms *ms, int code)
{
	ms->last_status = code;
}

int	get_status(t_ms *ms)
{
	return (ms->last_status);
}
