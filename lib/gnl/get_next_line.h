/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:11:44 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/14 13:15:57 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

long long int	ft_strchr_len(const char *s, int c);
char			*ft_strdup(const char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
char			*ft_strjoin_bf_newline(char const *s1, char const *s2);
size_t			ft_strlen(const char *target);
char			*get_next_line(int fd);
char			*ft_strjoin(char const *s1, char const *s2);

#endif