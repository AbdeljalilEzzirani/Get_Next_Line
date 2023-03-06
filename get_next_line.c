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

# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
	int			buffer;
	char		*pointer;

	buffer = 100;
	if (buffer > 1024)
		return (NULL);
	while (buffer > 0)
	{
		read(fd, pointer, 100);
		buffer++;
	}
	return (pointer);
}


int main ()
{
	int fd;
	int counting;
	char	sort;
	fd  = open("hello world !!!!!?", O_RDWR);
	// sort = get_next_line(fd);
	// while (sort != '\0')
	// {
		printf ("%s \n",get_next_line(fd));
	// 	sort++;
	// }
	close(fd);
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
