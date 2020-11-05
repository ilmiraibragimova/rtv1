

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *al;
	t_list *temp;

	al = *alst;
	while (al)
	{
		temp = al->next;
		del(al->content, al->content_size);
		free(al);
		al = temp;
	}
	*alst = NULL;
}
