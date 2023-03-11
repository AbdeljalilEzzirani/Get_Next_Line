/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:13:53 by abez-zir          #+#    #+#             */
/*   Updated: 2023/02/13 21:39:56 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_h
# define get_next_line_h

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>        //for size_t
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>



char		    *get_next_line(int fd);
char		    *ft_strchr(const char *s, int c);
char		    *ft_strdup(const char *s1);
size_t		    ft_strlen(const char *s);
char            *ft_strjoin(char const *s1, char const *s2);
size_t          ft_count_len_line(const char *s);
static char     *sauvgard_line(char *str);
static char     *push_line(char *str);
static char     *read_line(int fd, char *strstr);

#endif
