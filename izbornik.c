#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "functions.h"

int izbornik(const char* const suplementi) {
	printf("====================");
	printf("Odaberite jednu od ponudenih opcija:");
	printf("====================\n");
	printf("\t\t\tOpcija 1: dodavanje vrste suplemenata!\n");
	printf("\t\t\tOpcija 2: popis suplemenata!\n");
	printf("\t\t\tOpcija 3: ispisivanje podataka o suplementima!\n");
	printf("\t\t\tOpcija 4: pretrazivanje suplementa!\n");
	printf("\t\t\tOpcija 5: izlaz iz programa\n");
	printf("================================================================\n");

	int uvijet = 0;
	static SUPLEMENT* poljeSuplement = NULL;
	static SUPLEMENT* pronadeniSuplement = NULL;
	scanf("%d", &uvijet);


	switch (uvijet) {
	case 1:
		dodajSuplement(suplementi);
		break;
	case 2:
		if (poljeSuplement != NULL) {
			free(poljeSuplement);
			poljeSuplement = NULL;
		}
		poljeSuplement = (SUPLEMENT*)ucitavanjeSuplementa(suplementi);
		if (poljeSuplement == NULL) {
			exit(EXIT_FAILURE);
		}
		break;

	case 3:
		ispisivanjeSuplementa(poljeSuplement);
		break;
	case 4:
		pronadeniSuplement = (SUPLEMENT*)pretrazivanjeSuplementa(poljeSuplement);
		break;
	case 5:
		uvijet = izlazIzPrograma(poljeSuplement);
		break;

	default:
		uvijet = 0;
	}
	return uvijet;
}