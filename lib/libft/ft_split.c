/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:06 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/02 18:03:23 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freetab(char **tab, size_t loc)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL && i < loc)
	{
		free(tab[i]);
		i ++;
	}
	free(tab);
}

static int	cnt_split(char const *s, char c)
{
	size_t	i;

	if (!s || ft_strlen(s) == 0)
		return (1);
	i = 0;
	while (*s != '\0')
	{
		while ((*s != '\0') && (*s != c))
		{
			s ++;
			if (*s == c || *s == '\0')
			{
				i ++;
				break ;
			}
		}
		if (*s != '\0')
			s++;
	}
	return (i);
}

static void	ft_make_strtrim(char const *s1, char *res, size_t sp, size_t ep)
{
	size_t	loc;

	loc = 0;
	if (!(sp == 0 && ep == 0))
	{
		while (sp <= ep)
		{
			res[loc] = s1[sp];
			sp ++;
			loc ++;
		}
	}
	res[loc] = '\0';
}

static char	**ft_helper(char **res, char const *s, char c, t_index_list in)
{
	while (s[in.s_loc] != '\0')
	{
		while ((s[in.s_loc] != '\0') && (s[in.s_loc] != c))
		{
			in.s_loc ++;
			in.w_len ++;
			if (s[in.s_loc] == c || s[in.s_loc] == '\0')
			{
				res[in.tab_loc] = (char *)malloc(sizeof(char) * in.w_len + 1);
				if (res[in.tab_loc] == NULL)
				{
					freetab(res, in.tab_loc);
					return (NULL);
				}
				ft_make_strtrim(s, res[in.tab_loc], \
				in.s_loc - in.w_len, in.s_loc - 1);
				in.tab_loc ++;
				in.w_len = 0;
			}
		}
		if (s[in.s_loc] != '\0')
			in.s_loc++;
	}
	res[in.tab_loc] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	t_index_list	in;

	res = (char **)malloc(sizeof(char *) * (cnt_split(s, c) + 1));
	if (res == NULL)
		return (NULL);
	if (!s || ft_strlen(s) == 0)
	{
		res[0] = NULL;
		return (res);
	}
	if (!c || ft_strlen(&c) == 0)
	{
		res[0] = ft_strdup(s);
		res[1] = NULL;
		return (res);
	}
	in.s_loc = 0;
	in.tab_loc = 0;
	in.w_len = 0;
	return (ft_helper(res, s, c, in));
}

// void freeTab(char * * tab)
// {
// 	if (tab == NULL)
// 	{
// 		free(tab);
// 		return ;
// 	}
// 	for (int i = 0; tab[i] != NULL; ++i)
// 		free(tab[i]);
// 	free(tab);
// }

// # include <stdio.h>
// #include <string.h>
// int main (void)
// {
//     char *test1;
//     char test2;
// 	char **res;
// 	test1 = "abc   def   i";
// 	test2 = ' ';

// 	char *test3 = "bcdefghf";
// 	char test4 = 0;

// 	//printf("%s", ft_make_strtrim(test3, 3, 5));
// 	// printf("cnt = %d\n", cnt_split(test1,test2));
//     // printf("cnt = %d\n", cnt_split(test3,test4));

// 	//char * invalidReadCheck = new char;
// 	// char *invalidReadCheck = 0;
// 	// char *test5 = 0;
// 	// char test6 = ' 'cnt_split(s, c)
// 	// res = ft_split(test1,test2);
//     // printf("1 = %s\n", res[0]);
//     // printf("2 = %s\n", res[1]);
//     // printf("3 = %s\n", res[2]);
//     // printf("4 = %s\n", res[3]);
//     // printf("isNull = %d\n", res[0] == NULL);
//     // printf("true = %d\n", 1 == 1);
//     // printf("test = %s\n", res[2]);
//     // printf("test = %s\n", res[3]);
// 	//freeTab(res);
// 	//res = ft_split(test1, test2);

// 	//freeTab(res);
//     //printf("free = %s\n", res[3]);

//     return (0);
// }