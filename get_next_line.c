/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:09:14 by abez-zir          #+#    #+#             */
/*   Updated: 2023/02/14 00:06:22 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

static char	*push_line(char *str)
{
	int				i;
	int				j;
	char			*chereen;

	i = ft_strlen(str);
	chereen = (char *) malloc (i * sizeof(char));
    if (NULL == chereen)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] || str[i] == '\n')
	{
		chereen[j] = str[i];
		i++;
		j++;
	}
	chereen[i] = '\0';
	return (chereen);
}

static char *sauvgard_line(char *str)
{
	int				i;
	int				j;
	static char *sauvgard;

	i = ft_count_len_line(str);
	sauvgard = (char *) malloc (sizeof(char) * i);
        if (NULL == sauvgard)
            return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j = 0;
			while (str[i])
			{
					sauvgard[j] = str[i];
					i++;
					j++;
			}
			break;
		}
		i++;
	}
	return (sauvgard);
}

char	*read_line(int fd, char *strstr);
{
	char					*buf;
	int						i;

	buf = malloc(sizeof(char *) * BUFFER_SIZE );
	if (NULL == buf)
		return (NULL);
	strstr = ft_strdup("");
	i = 1;
	while (i > 0 && !(ft_strchr(strstr, '\n')))
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		strstr = ft_strjoin(strstr, buf);
	}
	return (strstr);
}

char	*get_next_line(int fd)
{
	char			*rslt;
	static char		*biit_lkhziin;

	a
	biit_lkhziin = read_line(fd, biit_lkhziin);
	rslt = push_line(biit_lkhziin);
	biit_lkhziin = sauvgard_line(biit_lkhziin);
	return (rslt);
}

int main ()
{
	int fd;
	char *strstr;

	fd  = open("check.txt", O_RDWR);
	printf("%s\n", read_line(fd, strstr));
}
