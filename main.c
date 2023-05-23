#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "dataType.h"

int main(void) {
	int uvijet = 1;
	char suplementi;
	FILE* fp = NULL;
	fp = fopen("suplementi.txt", "w");
	if (fp == NULL) {
		perror("Otvaranje");
		exit(EXIT_FAILURE);
	}
	while (uvijet) {
		uvijet = izbornik(suplementi);
	}

	printf("Zavrsetak programa!\n");

	return 0;
}
