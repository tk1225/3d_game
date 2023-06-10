/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/10/31 18:38:22 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// #include "stdio.h"

// int main(void)
// {
// 	t_list * l =  NULL;
// 	ft_lstadd_front(&l, ft_lstnew((void*)"test1"));
// 	/* 1 (void*)1*/ 
// 	//printf("first:%s\n",(char*)(l->content));
// 	printf("count1:%d\n",ft_lstsize(l));
// 	//0
// 	//printf("%d",l->next);
// 	ft_lstadd_front(&l, ft_lstnew((void*)"test2"));
// 	printf("count2:%d\n",ft_lstsize(l));

// 	//printf("first:%s\n",(char*)(l->content));
// 	//printf("second:%s",(char*)(l->next->content));

// 	return (0);
// }