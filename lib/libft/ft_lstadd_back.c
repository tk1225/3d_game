/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumasaokamoto <takumasaokamoto@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/01 17:18:15 by takumasaoka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	return ;
}

// #include "stdio.h"

// int main(void)
// {
// 	t_list * l =  NULL;
// 	// ft_lstadd_back(&l, ft_lstnew((void*)"test1"));
// 	// /* 1 (void*)1*/ 
// 	// printf("first:%s\n",(char*)(l->content));
// 	// //0
// 	// //printf("%d",l->next);
// 	// ft_lstadd_back(&l, ft_lstnew((void*)"test2"));

// 	// printf("first->test1:%s\n",(char*)(l->content));

// 	// printf("second->test2:%s\n",(char*)(l->next->content));
// 	// ft_lstadd_back(&l, ft_lstnew((void*)"test3"));
// 	// printf("first->test1:%s\n",(char*)(l->content));
// 	// printf("second->test2:%s\n",(char*)(l->next->content));
// 	// printf("second->test3:%s\n",(char*)(l->next->next->content));
// 	printf("%p\n",l);
// 	ft_lstadd_back(&l, ft_lstnew((void*)"test1"));
// 	printf("%p\n",l);
// 	ft_lstadd_back(&l, ft_lstnew((void*)"test2"));
// 	printf("%p\n",l);
// 	ft_lstadd_back(&l, ft_lstnew((void*)"test3"));
// 	printf("%p\n",l);
// 	ft_lstadd_back(&l, ft_lstnew((void*)"test3"));
// 	printf("%p\n",l);

// 	return (0);
// }