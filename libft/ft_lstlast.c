/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 18:38:10 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

//#include "stdio.h"

// int main(void)
// {
// 	t_list * l =  NULL;
// 	t_list * lstlast =  NULL;
// 	ft_lstadd_front(&l, ft_lstnew((void*)"test1"));
// 	/* 1 (void*)1*/ 
// 	//printf("first:%s\n",(char*)(l->content));
// 	//printf("count1:%d\n",ft_lstsize(l));
// 	lstlast = ft_lstlast(l);
// 	if (lstlast == NULL)
// 		printf("%s\n","lstlastIsNULL!");
// 	printf("last->test1:%s\n",(char*)lstlast->content);

// 	//0
// 	//printf("%d",l->next);
// 	ft_lstadd_front(&l, ft_lstnew((void*)"test2"));
// 	printf("last->test1:%s\n",(char*)ft_lstlast(l)->content);

// 	//printf("first:%s\n",(char*)(l->content));
// 	//printf("second:%s",(char*)(l->next->content));

// 	return (0);
// }