/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:40:55 by abez-zir          #+#    #+#             */
/*   Updated: 2023/0 2/14 23:41:03 by abez-zir         ###   ########.fr       */
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
        free(one);
        one = NULL;
        return (swap);
}

char    *ft_strjoin(char *s1, char *s2)
{
        char                                    *ptr;
        size_t                                  totalenergie;
        int                                             i;
        int                                             j;

        // if (s1 == NULL)
        //         s1 = ft_strdup("");
        // if (s2 == NULL)
        //         return (free(s1), NULL);
        if (!s1 && !s2)
                return (NULL);
        if (s1 == NULL)
                return(ft_strdup(s2));
        if (s2 == NULL)
                return (ft_strdup(s1));
        i = ft_strlen(s1);
        j = ft_strlen(s2);
        totalenergie = (i + j);
        ptr = (char *) malloc ((totalenergie + 1) * sizeof(char));
        if (ptr == NULL)
                return (free(s1), NULL);
        return (join(s1, s2, ptr));
}

char    *ft_strdup(const char *s1)
{
        char                    *p;
        int                             size;
        size = ft_strlen(s1);
        p = (char *) malloc (sizeof(char) * size + 1);
        if (p == NULL)
                return ( NULL);
        int i = 0;
        while (s1[i])
        {
                p[i] = s1[i];
                i++;
        }
        p[i] = '\0';
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

size_t  ft_count_len_line(const char *s)
{
        size_t                          i;

        i = 0;
        while (s[i] && s[i] != '\n')
                i++;
        return (i);
}
