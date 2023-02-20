/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:40:55 by abez-zir          #+#    #+#             */
/*   Updated: 2023/02/14 23:41:03 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static char	*diir_chii_fchiii(char *one, char *two, char *swap)
{
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	while (one[i])
	{
		swap[i] = one[i];
		i++;
	}
	while (two[j])
	{
		swap[j + i] = two[j];
		j++;
	}
	swap[i + j] = '\0';
	return (swap);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char					*ptr;
	size_t					totalenergie;
	int						i;
	int						j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	totalenergie = (i + j);
	ptr = (char *) malloc ((totalenergie + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	return (diir_chii_fchiii((char *)s1, (char *)s2, ptr));
}

size_t	ft_strlen(const char *s)
{
	size_t				i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_lkhedma(char *buf, int *ret)
{
    int         i;
    char        *dest;

    i = 0;
    while (buf && buf[i] != '\n')
        i++;
    dest = malloc(i + 1);
    if (!dest)
        return (NULL);
    if (ft_strchr(buf, '\n') != 0)
        *ret = 1;
    i = 0;
    while (buf && buf[i] && buf[i] != '\n')
    {
        dest[i] = buf[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}// hena diiir strdup o noooood naaayed  

char    *ft_lkhedaamaa(char *buf)
{
    int             i;
    int             j;
    char            *dest;

    i = 0;
    while (buf && buf[i] && buf[i] != '\n')
    i++;
    dest = malloc(sizeof(*dest) * (ft_strlen(buf) - i + 1));
    if (!dest)
        return (NULL);
    j = 0;
    while (buf && buf[++i])
        dest[j++] = buf[++i];
    dest[j] = 0;
    return (dest);
}	
