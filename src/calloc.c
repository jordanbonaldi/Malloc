/*
** EPITECH PROJECT, 2018
** Main
** File description:
** Main
*/

#include "project.h"

void *calloc(size_t ptr, size_t size)
{
	void *tab;

	tab = malloc(ptr * size);
	if (!tab)
		return (NULL);
	memset(tab, 0, ptr * size);
	return (tab);
}
