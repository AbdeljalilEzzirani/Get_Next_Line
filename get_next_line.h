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
# define BUFFER_SIZE
#endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


char		*get_next_line(int fd);


#endif
