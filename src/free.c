/*
** EPITECH PROJECT, 2018
** Main
** File description:
** Main
*/

#include "project.h"

block_t *get_adress(void *ptr)
{
	char *tmp = ptr;

	return (ptr = tmp -= BLOCK_SIZE);
}

mybool can_be_free(void *ptr)
{
	if (!head)
		return (FALSE);
	if (ptr > (void *)head && ptr < sbrk(0))
		return (ptr == (get_adress(ptr))->ptr);
	return (FALSE);
}

block_t *fusion_blocks(block_t *block)
{
	if (block->next && block->next->isFree) {
		block->size += block->next->size + BLOCK_SIZE;
		block->next = block->next->next;
		if (block->next)
			block->next->prev = block;
	}
	return (block);
}

void free(void *ptr)
{
	block_t *block = get_adress(ptr);

	if (!ptr)
		return;
	if (!can_be_free(ptr))
		raise(SIGABRT);
	pthread_mutex_lock(&locker);
	block->isFree = TRUE;
	if (block->prev && block->prev->isFree)
		block = fusion_blocks(block->prev);
	if (block->next)
		block = fusion_blocks(block);
	else {
		if (block->prev)
			block->prev->next = NULL;
		else
			head = NULL;
		brk(block);
	}
	pthread_mutex_unlock(&locker);
}
