/*
** EPITECH PROJECT, 2018
** reallocf
** File description:
** reallocf
*/

#include "project.h"

void *reallocf(void *ptr, size_t size)
{
	void *ret;

	ret = realloc(ptr, size);
	if (!ret)
		free(ptr);
	return (ret);
}
