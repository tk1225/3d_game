/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 18:37:52 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp_next;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp_next = *lst;
		*lst = new;
		lst[0]->next = tmp_next;
	}
	return ;
}

// #include "stdio.h"

// int main(void)
// {
// 	t_list * l =  NULL;
// 	ft_lstadd_front(&l, ft_lstnew((void*)"test1"));
// 	/* 1 (void*)1*/ 
// 	printf("first:%s\n",(char*)(l->content));
// 	//0
// 	//printf("%d",l->next);
// 	ft_lstadd_front(&l, ft_lstnew((void*)"test2"));

// 	printf("first:%s\n",(char*)(l->content));

// 	printf("second:%s",(char*)(l->next->content));

// 	return (0);
// }