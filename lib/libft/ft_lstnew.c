/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 17:18:43 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (res == NULL)
	{
		return (NULL);
	}
	res->content = content;
	res->next = NULL;
	return (res);
}

// #include "stdio.h"

// int main(void)
// {
// 	t_list * l =  ft_lstnew((void*)42);
// 	printf("%p",(l->content));
// 	t_list * ls =  ft_lstnew("test");
// 	printf("%s",(char*)(ls->content));
// 	return (0);
// }