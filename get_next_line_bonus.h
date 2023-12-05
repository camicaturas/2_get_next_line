/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:41:15 by cberneri          #+#    #+#             */
/*   Updated: 2023/11/30 18:15:52 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_readed_line(char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_move_start(char *start);
char	*ft_strjoin(char *s1, char *s2);
#endif