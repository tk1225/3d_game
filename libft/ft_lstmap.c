/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takuokam <takuokam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:57:20 by takuokam          #+#    #+#             */
/*   Updated: 2022/11/04 15:52:15 by takuokam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;

	if (lst == NULL || f == NULL || del == NULL)
		return (lst);
	else
	{
		head = NULL;
		while (lst != NULL)
		{
			new_node = ft_lstnew(f(lst->content));
			if (new_node == NULL)
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, new_node);
			lst = lst->next;
		}
	}
	return (head);
}

// #include "stdio.h"
// #include "string.h"
// #include "ctype.h"

// static void *str_toupper(void *p)
// {
//     char *str = ft_strdup((char *)p);
//     char *tmp = str;
//     while (*tmp)
//     {
//         *tmp = toupper(*tmp);
//         tmp++;
//     }
//     return (str);
// }

// int main(void)
// {
// 		t_list  *lst = ft_lstnew(ft_strdup("Hello"));
// 		ft_lstadd_back(&lst, ft_lstnew(strdup(" World")));
// 		ft_lstadd_back(&lst, ft_lstnew(strdup(" 42")));
// 		ft_lstadd_back(&lst, ft_lstnew(strdup(" Tokyo!")));
// 		ft_lstadd_back(&lst, ft_lstnew(strdup("")));

// 		t_list *newlst = ft_lstmap(lst, str_toupper, free);

// 		printf("%s\n", newlst->content);
// 		printf("%s\n", newlst->next->content);
// 		printf("%s\n", newlst->next->next->content);
// 		printf("%s\n", newlst->next->next->next->content);
// 		printf("%p\n", newlst->next);
// 		printf("%p\n", newlst->next->next);
// 	return (0);
// }
