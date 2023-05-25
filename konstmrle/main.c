#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "dataType.h"

int main(void) {
	int uvijet = 1;
	char suplementi[20] = { '\0' };
	printf("Unesite ime datoteke s kojom se treba raditi!\n");
	scanf("%19[^\n]", suplementi);
	while (uvijet) {
		uvijet = izbornik(suplementi);
	}
	printf("Zavrsetak programa!\n");
	return 0;
}

