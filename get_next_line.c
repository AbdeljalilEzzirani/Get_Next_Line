/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:09:14 by abez-zir          #+#    #+#             */
/*   Updated: 2023/03/12 17:30:52 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*push_line(char *str)
{
	int				i;
	int				j;
	char			*chereen;

	i = ft_count_len_line(str);
	chereen = (char *) malloc (i * sizeof(char));
	if (NULL == chereen)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
	{
		chereen[j] = str[i];
		i++;
		j++;
	}
	if (str[i] == '\n')
		chereen[j] = str[i];
	chereen[i] = '\0';
	return (chereen);
}

static char	*sauvgard_line(char *str)
{
	int							i;
	int							j;
	char					*sauvgard;

	i = ft_count_len_line(str);
	j = ft_strlen(str);
	sauvgard = (char *) malloc ((j - i) + 1);
	if (NULL == sauvgard)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			j = 0;
			i++;
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
	return (free(str), sauvgard);
}

static char	*read_line(int fd, char *biit_lkhziin)
{
	// char				*biit_lkhziin;
	char					*buf;
	int						i;

	if(biit_lkhziin == NULL)
		biit_lkhziin = ft_strdup("");
	buf = malloc(sizeof(char *) * BUFFER_SIZE +1);
	if (NULL == buf)
		return (free(biit_lkhziin), NULL);
	i = 1;
	while (i > 0 && !(ft_strchr(biit_lkhziin, '\n')))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if(i < 0)
		{
			return (free(biit_lkhziin), free(buf), NULL);
		}
		buf[i] = '\0';
		biit_lkhziin = ft_strjoin(biit_lkhziin, buf);
	}
	return (free(buf), biit_lkhziin);
}

char	*get_next_line(int fd)
{
	char			*rslt;
	static char		*biit_lkhziin;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	biit_lkhziin = read_line(fd, biit_lkhziin);

	rslt = push_line(biit_lkhziin);
	
	biit_lkhziin = sauvgard_line(biit_lkhziin);
	return (rslt);
}

void ff()
{
	system("leaks a.out");
}

int main ()
{
	atexit(ff);
	int fd;

	fd  = open("check.txt", O_RDWR);
	printf("%s \n", 	 get_next_line(fd));
	printf("%s \n", 	 get_next_line(fd));
	printf("%s \n", 	 get_next_line(fd));
}








// char	*get_next_line(int fd)
// {
// 	char			*rslt;
// 	static char		*biit_lkhziin;
// 	char					*buf;
// 	// char					*tmp;
// 	int						i;


// 	if(fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if(biit_lkhziin == NULL)
// 		biit_lkhziin = ft_strdup("");
// 	buf = malloc(sizeof(char *) * BUFFER_SIZE +1);
// 	if (NULL == buf)
// 		return (NULL);
// 	i = 1;
// 	while (i > 0 && !(ft_strchr(biit_lkhziin, '\n')))
// 	{
// 		i = read(fd, buf, BUFFER_SIZE);
// 		if(i < 0)
// 			break;
// 		buf[i] = '\0';
// 		biit_lkhziin = ft_strjoin(biit_lkhziin, buf);
// 		// tmp = biit_lkhziin;
// 		// free(tmp);
// 	}
// 	// free(buf);
// 	rslt = push_line(biit_lkhziin);
// 	biit_lkhziin = sauvgard_line(biit_lkhziin);
// 	return (rslt);
// }









	// if(biit_lkhziin == NULL)
	// 	biit_lkhziin = ft_strdup("");
	// buf = malloc(sizeof(char *) * BUFFER_SIZE +1);
	// if (NULL == buf)
	// 	return (NULL);
	// i = 1;
	// while (i > 0 && !(ft_strchr(biit_lkhziin, '\n')))
	// {
	// 	i = read(fd, buf, BUFFER_SIZE);
	// 	if(i < 0)
	// 		break;
	// 	buf[i] = '\0';
	// 	biit_lkhziin = ft_strjoin(biit_lkhziin, buf);
	// 	// tmp = biit_lkhziin;
	// 	// free(tmp);
	// }
	// // free(buf);