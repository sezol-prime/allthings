/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sitao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:04:41 by sitao             #+#    #+#             */
/*   Updated: 2025/02/28 22:04:44 by sitao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(const char *s1, const char *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s);
char	*gnl_substr(const char *s, unsigned int start, size_t len);
#endif
