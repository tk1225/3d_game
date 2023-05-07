/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:59:36 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/04 15:57:15 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	strloc;
	size_t	j;

	if ((to_find != NULL && len == 0 && str == NULL) || \
	(to_find[0] == 0 && str != NULL))
		return ((char *)str);
	strloc = 0;
	while ((str[strloc] != 0) && (len > 0))
	{
		if (str[strloc] == to_find[0])
		{
			j = 0;
			while (to_find[j] != 0 && ((len - j) > 0))
			{
				if (str[strloc + j] != to_find[j])
					break ;
				j++;
			}
			if (j == ft_strlen(to_find))
				return ((char *)&str[strloc]);
		}
		strloc++;
		len --;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     // char text1[] = "0123456789";
//     // char text2[] = "";
//     // char pat1[] = "012";
//     // char pat2[] = "54";
//     // char pat3[] = "012345679";
//     // char pat4[] = "";
//     // char pat5[] = "89";
//     // char pat6[] = "1";

//     // printf("%p\n",strnstr(text1, pat1, 3));
//     // printf("%p\n",strnstr(text1, pat2, 2));
//     // printf("%p\n",strnstr(text1, pat3, 10));
//     // printf("%p\n",strnstr(text1, pat4, 0));
//     // printf("%p\n",strnstr(text2, pat1, 3));
//     // printf("%p\n",strnstr(text1, pat5, 9));
//     // printf("%p\n",strnstr(text1, pat6, 2));
//     // printf("\n");
//     // printf("%p\n",ft_strnstr(text1, pat1, 3));
//     // printf("%p\n",ft_strnstr(text1, pat2, 2));
//     // printf("%p\n",ft_strnstr(text1, pat3, 10));
//     // printf("%p\n",ft_strnstr(text1, pat4, 0));
//     // printf("%p\n",ft_strnstr(text2, pat1, 3));
//     // printf("%p\n",ft_strnstr(text1, pat5, 9));
//     // printf("%p\n",ft_strnstr(text1, pat6, 2));
// 	char haystack[30] = "aaabcabcd";
//     printf("%s\n",ft_strnstr(haystack, "cd", 8));
// }