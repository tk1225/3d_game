/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 21:41:06 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	else
	{
		while (lst != NULL)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
	return ;
}

// #include "stdio.h"

// void addOne(void * p)
// {
// 	printf("%s","func");
// 	*(int*)p += 1;
// }

// int main(void)
// {
// 	int tab[] = {1, 1, 2, 3};
// 	t_list * l =  ft_lstnew(tab);
// 	for (int i = 0; i < 10; ++i)
// 		ft_lstadd_front(&l, ft_lstnew(tab));
// 	ft_lstiter(l,addOne);

// 	printf("first:%s\n",(char*)(l->content));

// 	// printf("second:%d\n",(int*)(l->next->content)[0]);

// 	// printf("third:%d\n",(int*)(l->next->next->next->content)[0]);
// 	return (0);
// }