/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipang <mipang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:19:41 by mipang            #+#    #+#             */
/*   Updated: 2025/11/02 23:19:45 by mipang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

void	ms_setup_signals_interactive(void);
void	ms_setup_signals_child(void);
void	ms_setup_signals_heredoc(void);

#endif
