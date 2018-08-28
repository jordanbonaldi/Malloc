/*
** EPITECH PROJECT, 2018
** malloc
** File description:
** show_alloc_mem
*/

#include "project.h"

void show_alloc_mem(void)
{
	size_t breakpg = (size_t)sbrk(0);
	block_t *tmp;

	printf("break : 0x%lX\n", breakpg);
	tmp = head;
	while (tmp && tmp->next != head)
	{
		if (!tmp->isFree)
			printf("0x%lX - 0x%lX : %lu bytes\n",
				(size_t)tmp + BLOCK_SIZE,
				(size_t)tmp + BLOCK_SIZE + tmp->size,
				tmp->size);
		tmp = tmp->next;
	}
}
