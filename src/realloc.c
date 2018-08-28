/*
** EPITECH PROJECT, 2018
** Main
** File description:
** Main
*/

#include "project.h"

void *realloc(void *ptr, size_t size)
{
	block_t *header;
	void *ret;

	if (!ptr || !size)
		return malloc(size);
	header = (block_t*)ptr - METADATA_SIZE;
	if (header->size >= size)
		return (ptr);
	ret = malloc(size);
	if (ret) {
		memcpy(ret, ptr, header->size);
		free(ptr);
	}
	return (ret);
}
