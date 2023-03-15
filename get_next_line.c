/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:09:14 by abez-zir          #+#    #+#             */
/*   Updated: 2023/03/15 00:15:02 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char  *push_line(char *str)
{
	int             i;
	int             j;
	char            *chereen;

	i = ft_count_len_line(str);
	chereen = (char *) malloc ((i + 1) * sizeof(char));
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
	chereen[i] = '\n';
	chereen[i + 1] = '\0';
	return (chereen);
}

static char  *sauvgard_line(char *str)
{
	int                         i;
	int                         j;
	char                    *sauvgard;

	i = ft_count_len_line(str);
	j = ft_strlen(str);
	sauvgard = (char *) malloc ((j - i) +1);
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
	sauvgard[j] = '\0';
	return (sauvgard);
}

static char	*read_line(int fd, char *biit_lkhziin)
{
	char                    *buf;
	int                     i;

	if(biit_lkhziin == NULL)
		biit_lkhziin = ft_strdup("");
	buf = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (NULL == buf)
		return (NULL);
	i = 0;
	while (i >= 0 && !(ft_strchr(biit_lkhziin, '\n')))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if(i <= 0)
		{
			return (NULL);
			break;
		}
		buf[i] = '\0';
	//  printf(" -------->%s\n", buf);
		biit_lkhziin = ft_strjoin(biit_lkhziin, buf);
		// printf("chehaal 9eraat -------->%d\n", i);
	}
	return (biit_lkhziin);
}

char *get_next_line(int fd)
{
	char            *rslt;
	static char     *biit_lkhziin;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	biit_lkhziin = read_line(fd, biit_lkhziin);
	if(!biit_lkhziin)
		return (NULL);
	rslt = push_line(biit_lkhziin);
	biit_lkhziin = sauvgard_line(biit_lkhziin);
	//printf("%s ",rslt);
	return (rslt);
}

// void ff()
// {
//   system("leaks a.out");
// }

int main ()
{
	// atexit(ff);
	int fd;

	fd  = open("check.txt", O_RDWR);
		// printf("%s\n", get_next_line(fd));
		// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
		printf("/|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
		printf("|get_next_line------> /%s \n/", get_next_line(fd));
} 









































































// static char	*push_line(char *str)
// {
// 	int				i;
// 	int				j;
// 	char			*chereen;

// 	i = ft_count_len_line(str);
// 	printf("|count line =>>>>>>%d|\n", i);
// 	chereen = (char *) malloc ((i + 2) * sizeof(char));
// 	if (NULL == chereen)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (str[i] && str[i] != '\n')
// 	{
// 		chereen[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	if (str[i] == '\n'){
// 		chereen[j] = str[i];
// 		chereen[j + 1] = '\0';
// 	}
// 	else
// 		chereen[j] = '\0';
// 	printf("|chereen=>>>>>>> %s|\n", chereen);
// 	return (chereen);
// }

// static char	*sauvgard_line(char *str)
// {
// 	int							i;
// 	int							j;
// 	char					*sauvgard;

// 	i = ft_count_len_line(str);
// 	j = ft_strlen(str);
// 	sauvgard = (char *) malloc ((j - i) + 1);
// 	if (NULL == sauvgard)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 		{
// 			j = 0;
// 			i++;
// 			while (str[i])
// 			{
// 				sauvgard[j] = str[i];
// 				i++;
// 				j++;
// 			}
// 			break;
// 		}
// 		i++;
// 	}
// 	return (sauvgard);
// }

// static char	*read_line(int fd, char *biit_lkhziin)
// {
// 	char					*buf;
// 	int						i;

// 	if(biit_lkhziin == NULL)
// 		biit_lkhziin = ft_strdup("");
// 	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (!buf)
// 		return (free(biit_lkhziin), NULL);
// 	i = 1;

// 	while (i > 0 && !(ft_strchr(biit_lkhziin, '\n')))
// 	{
// 		i = read(fd, buf, BUFFER_SIZE);
// 		if(i == -1)
// 		{
// 			return (NULL);
// 		}
// 		buf[i] = '\0';
// 		biit_lkhziin = ft_strjoin(biit_lkhziin, buf);
// 		printf("|buff =>>>>>>>%s|\n", buf);
// 		printf("|biit =>>>>>>>%s|\n", biit_lkhziin);
// 	}
// 	return (biit_lkhziin);
// }

// char	*get_next_line(int fd)
// {
// 	char			*rslt;
// 	static char		*biit_lkhziin;

// 	if(fd < 0 || BUFFER_SIZE <= 0 )
// 		return (NULL);
// 	biit_lkhziin = read_line(fd, biit_lkhziin);
// 	if(!biit_lkhziin)
// 		return (NULL);
// 	// rslt = push_line(biit_lkhziin);

// 	// biit_lkhziin = sauvgard_line(biit_lkhziin);
// 	return (biit_lkhziin);
// }

// // void	leaks(){system("leaks a.out");}

// int	main ()
// {
// 	int			fd;

// 	fd  = open("check.txt", O_RDWR);
// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// 	// 	printf("|get_next_line    /%s/|", get_next_line(fd));
// }



// //  int main ()
// // {
// 	atexit(leaks);
// 	int fd;

// 	fd  = open("check.txt", O_RDWR);
// 	//get_next_line(fd);
// 	char *str = get_next_line(fd);
// 	printf("%s \n", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s \n", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s \n", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s \n", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s \n", str);
// 	free(str);

// }








































































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
// 	buf = malloc(sizeof(char *) * BUFFER_SIZE +1);
// if (NULL == buf)
// 	return (NULL);
// 	i = 1;
// 	while (i > 0 && !(ft_strchr(biit_lkhziin, '\n')))
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
// static char	*push_line(char *str)
// {
// 	int				i;
// 	int				j;
// 	char			*chereen;

// 	i = ft_count_len_line(str);
// 	chereen = (char *) malloc (i * sizeof(char));
// 	if (NULL == chereen)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (str[i] && str[i] != '\n')
// 	{
// 		chereen[j] = str[i];
// 		i++;
// 		j++;
// 	}
// 	if (str[i] == '\n')
// 		chereen[j++] = str[i];
// 	chereen[i] = '\0';
// 	return (chereen);
// }

// static char	*sauvgard_line(char *str)
// {
// 	int							i;
// 	int							j;
// 	char					*sauvgard;

// 	i = ft_count_len_line(str);
// 	j = ft_strlen(str);
// 	sauvgard = (char *) malloc ((j - i) + 1);
// 	if (NULL == sauvgard)
// 		return (NULL);
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 		{
// 			j = 0;
// 			i++;
// 			while (str[i])
// 			{
// 				sauvgard[j] = str[i];
// 				i++;
// 				j++;
// 			}
// 			break;
// 		}
// 		i++;
// 	}
// 	return (free(str), sauvgard);
// }

// static char	*read_line(int fd, char *biit_lkhziin)
// {
// 	// char				*biit_lkhziin;
// 	char					*buf;
// 	int						i;

// 	if(biit_lkhziin == NULL)
// 		biit_lkhziin = ft_strdup("");
// 	buf = malloc(sizeof(char *) * BUFFER_SIZE +1);
// 	if (NULL == buf)
// 		return (free(biit_lkhziin), NULL);
// 	i = 1;
// 	while (i > 0 && !(ft_strchr(biit_lkhziin, '\n')))
// 	{
// 		i = read(fd, buf, BUFFER_SIZE);
// 		if(i < 0)
// 		{
// 			return (free(biit_lkhziin), free(buf), NULL);
// 		}
// 		buf[i] = '\0';
// 		biit_lkhziin = ft_strjoin(biit_lkhziin, buf);
// 	}
// 	return (free(buf), biit_lkhziin);
// }

// char	*get_next_line(int fd)
// {
// 	char			*rslt;
// 	static char		*biit_lkhziin;

// 	if (fd <= 0 || BUFFER_SIZE <= 0 || !biit_lkhziin)
// 		return (NULL);

// 	biit_lkhziin = read_line(fd, biit_lkhziin);

// 	rslt = push_line(biit_lkhziin);

// 	biit_lkhziin = sauvgard_line(biit_lkhziin);
// 	return (rslt);
// }
