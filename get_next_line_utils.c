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

# include "get_next_line.h"

static char     *join(char *one, char *two, char *swap)
{
        size_t                          i;
        size_t                          j;

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

char    *ft_strjoin(char const *s1, char const *s2)
{
        char                                    *ptr;
        size_t                                  totalenergie;
        int                                             i;
        int                                             j;

        if (s1 == NULL || s2 == NULL)
                return (NULL);
        i = ft_strlen(s1);
        j = ft_strlen(s2);
        totalenergie = (i + j);
        ptr = (char *) malloc ((totalenergie + 1) * sizeof(char));
        if (ptr == NULL)
                return (NULL);
        return (join((char *)s1, (char *)s2, ptr));
}

void    *ft_memcpy(void *dst, const void *src,  size_t n)
{
        size_t                                  i;
        char                                    *d;
        const char                              *s;

        i = 0;
        s = src;
        d = dst;
        if (s == NULL && d == NULL)
                return (NULL);
        while (i < n)
        {
                d[i] = s[i];
                i++;
        }
        return (d);
}

char    *ft_strdup(const char *s1)
{
        char                    *p;
        int                             size;

        size = ft_strlen(s1);
        p = (char *) malloc (sizeof(char) * size + 1);
        if (p == NULL)
                return (NULL);
        ft_memcpy(p, s1, size);
        p[size] = '\0';
        return (p);
}

size_t  ft_strlen(const char *s)
{
        size_t                          i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

char    *ft_strchr(const char *s, int c)
{
        int             i;

        if (s == NULL)
                return (NULL);
        i = 0;
        while (s[i])
        {
                if ((char )c == s[i])
                        return ((char *)&s[i]);
                i++;
        }
        if (s[i] == (char )c)
                return ((char *)&s[i]);
        return (NULL);
}


size_t  ft_count_len_line(const char *s)
{
        size_t                          i;

        i = 0;
        // while (s[i] && s[i] != '\n')
        //         i++; 
        while (s[i] && s[i] != '\n')
                i++;
        i++;
        return (i);
}
