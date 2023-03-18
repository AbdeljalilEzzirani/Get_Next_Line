/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:54:54 by abez-zir          #+#    #+#             */
/*   Updated: 2023/03/17 20:54:56 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	leaks(){system("leaks a.out");}

void	my_free(void *s)
{
	if (!s)
		return ;
	free(s);
	s = NULL;
}

static char  *push_line(char *str)
{
	int             i;
	int             j;
	char            *chereen;

	i = ft_count_len_line(str);
	if (ft_find_slash_n(str) == 0)
		i++;
	else
		i+=2;
	chereen = (char *) malloc (i * sizeof(char));
	if (NULL == chereen)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		chereen[j] = str[i];
		i++;
		j++;
	}
	if (str[i] == '\n')
		chereen[j++] = '\n';
	chereen[j] = '\0';
	return (chereen);
}

static char  *sauvgard_line(char *str)
{
	int                         i;
	int                         j;
	char                    *sauvgard;

	i = ft_count_len_line(str);
	if (ft_find_slash_n(str) == 1)
		i++;
	j = ft_strlen(str);
	sauvgard = (char *) malloc ((j - i) + 1);
	if (NULL == sauvgard)
		return (my_free(str) ,my_free(sauvgard), NULL);

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			while (str[i])
				sauvgard[j++] = str[i++];
			break;
		}
		i++;
	}
	if (j == 0)
		return (free(str), free(sauvgard), NULL);
	sauvgard[j] = '\0';
	return (my_free(str), sauvgard);
}

int	ft_find_slash_n(char *str)
{
	if (!str)
		return (0);
	int i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

static char	*read_line(int fd, char *biit_lkhziin)
{
	char                    *buf;
	int                     i;

	// if (!biit_lkhziin)
	// 	ft_strdup("");
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == buf)
		return (my_free(buf), my_free(biit_lkhziin), NULL);
	i = 1;
	while (ft_find_slash_n(biit_lkhziin) == 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if(i < 0)
			return (my_free(buf), my_free(biit_lkhziin), NULL);
		buf[i] = '\0';
		if (i == 0)
			return (my_free(buf), biit_lkhziin);
		biit_lkhziin = ft_strjoin(biit_lkhziin, buf);
	}
	return (my_free(buf), biit_lkhziin);
}

char *get_next_line(int fd)
{
	char            *rslt;
	static char     *biit_lkhziin[];

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, &rslt, 0) < 0)
	{
		if(biit_lkhziin)
		{
			free(biit_lkhziin);
			biit_lkhziin=NULL;
		}
		return (NULL);
		
	}
	biit_lkhziin = read_line(fd, biit_lkhziin);
	if(!biit_lkhziin)
		return (NULL);
	rslt = push_line(biit_lkhziin);
	if(!rslt)
		return (NULL);
	biit_lkhziin = sauvgard_line(biit_lkhziin);
	// leaks();
	return (rslt);
}



int main()
{
	int fd = open("check.txt", O_RDWR);
	char *str;
	int fd1 = open("tst.txt", O_RDWR);
	char *str1;

	str = get_next_line(fd);
	str1 = get_next_line(fd1);
	while (1)
	{
		printf("%s\n", str1);
		printf("%s\n", str);
		my_free(str);
		str = get_next_line(fd);
		str1 = get_next_line(fd1);
		if (!str)
			break;
	}
}
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));
// // 	// printf("||%s|| \n", get_next_line(fd));

// }
