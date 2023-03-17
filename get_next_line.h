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
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
// # include <stddef.h>        //for size_t
// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h>



char		    *get_next_line(int fd);
char            *ft_strchr(const char *s, int c);
char		    *ft_strdup(const char *s1);
size_t          ft_strlen(const char *s);
char            *ft_strjoin(char  *s1, char *s2);
size_t          ft_count_len_line(const char *s);
int         	ft_find_slash_n(char *str);

#endif

// char		    *ft_strchr(const char *s, int c);
// static char     *join(char *one, char *two, char *swap);
// size_t	        ft_findchar(const char *stash, char s);
// static char     *diir_chii_fchiii(char *one, char *two, char *swap);
// static char     *read_line(int fd, char *biit_lkhziin);