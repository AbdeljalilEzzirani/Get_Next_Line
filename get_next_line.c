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

static size_t  ft_newlen(const char *s)
{
        size_t                          i;

        i = 0;
        while (s[i] && s[i] != '\n')
                i++;
        return (i);
}

static char *return_line(char *str)
{
	int i = 0;
	char *tmp;

	tmp = malloc(ft_newlen(str));
	while(str[i] != '\0')
	{
		if(str[i] == '\n')
			break;
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char *shyata_d_lbuffer(char *str)
{
	int i = 0;
	int j = 0;
	char *tmp;


	while(str[j] && str[j] != '\n')
		j++;
	j++;
	tmp = malloc(ft_strlen(str) - ft_newlen(str) +1);
	while(str[i] != '\0')
	{
		if(str[i] == '\n')
			break;
		tmp[i] = str[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static int  ft_is_nline(char *s)
{
        int	i;

        i = 0;
		if (!s)
			return (1);
        while (s[i] && s[i] != '\n')
		{
                if(s[i] && s[i] == '\n')
					return (0);
				i++;
		}
		return (1);
}


char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	ssize_t		bytes;
	char		*returned_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE +1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && ft_is_nline(temp) == 1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(temp), temp = NULL, NULL);
		buffer[bytes] = 0;
		temp = ft_strjoin(temp, buffer);
	}
	returned_line = return_line(temp);
	temp = shyata_d_lbuffer(temp);
	free(buffer);
	return (returned_line);
}


int main ()
{
	int fd;

	fd  = open("check.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

}























































































// char *get_next_line(int fd)
// {
// 	char			**line;
// 	char			buf[BUFFER_SIZE + 1];
// 	int				ret;
// 	static char		*str = NULL;
// 	char			*tmp;

// 	ret = BUFFER_SIZE;
// 	if (fd < 0 || fd > 1023 || !line || BUFFER_SIZE <= 0)
// 		return (-1);
// 	while (ret > 0)
// 	{
// 		ret = read(fd, buf, BUFFER_SIZE);
// 		if (ret == -1)
// 			return (-1);
// 		buf[ret] = 0;
// 		temp = str;
// 		str = strjoin(temp, buf);
// 		free(temp);
// 		if (ft_strchr(str, '\n'))
// 			break;
// 	}
// 	*line = ft_select(str, &ret);
// 	temp = str;
// 	str = ft_select(temp);
// 	free(temp);
// 	if (ret == 0 && (*str)[0] == 0)
// 	{
// 		free(*str);
// 		*str = NULL;
//    	}
// 	return (ret);
// }

// int	main ()
// {
// 	int			fd;
// 	char		*line;
// 	int			ret;

// 	*line = NULL;
// 	fd  = open("hello world", O_RDONLY);
// 	ret = get_next_line(fd, &line);

// 	while (ret != 0)
// 	{
// 		printf("%s", line);
// 		ret = get_next_line(fd, &line);
// 	}
// }

// int main ()
// {
// 	int			fd;
// 	char		buffer[8000];
// 	char		msg[2000] = "is a not working";

// 	fd = open ("check.txt", O_RDWR);
// 	//printf ("fd = %d", fd);
// 	if (fd != -1)
// 	{
// 		//printf ("\n check.txt opened with read write access my bitch \n");
// 		write (fd, msg, sizeof(msg));
// 	//	lseek (fd, 0, SEEK_SET);
// 		read (fd, buffer, sizeof(msg));
// 		//printf ("\n %s was written to my fie \n", buffer);
// 		close (fd);
// 	}
// 	return (0);
// }
