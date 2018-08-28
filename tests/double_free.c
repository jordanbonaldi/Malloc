/*
** EPITECH PROJECT, 2018
** Tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include "project.h"

void test_double_free(void)
{
	char *test = malloc(12);

	free(test);
	free(test);
}

Test(misc, double_free, .signal = SIGABRT)
{
	test_double_free();
}
