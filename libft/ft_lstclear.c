/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 21:40:51 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	while (lst[0] != NULL)
	{
		tmp = lst[0]->next;
		ft_lstdelone(lst[0], del);
		lst[0] = tmp;
	}
	*lst = NULL;
	return ;
}

// #include "stdio.h"

// int main(void)
// {
// 	t_list * l =  ft_lstnew(malloc(1));
// 	for (int i = 0; i < 10; ++i)
// 		ft_lstadd_front(&l, ft_lstnew(malloc(1)));
// 	ft_lstclear(&l, free);
// 	return (0);
// }