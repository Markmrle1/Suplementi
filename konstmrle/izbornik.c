#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "functions.h"

int izbornik(const char* const imeDatoteke) {
printf("====================");
printf("Odaberite jednu od ponudenih opcija:");
printf("====================\n");
printf("\t\t\tOpcija 1: kreiranje datoteke!\n");
printf("\t\t\tOpcija 2: dodavanje suplementa!\n");
printf("\t\t\tOpcija 3: ucitavanje suplementa!\n");
printf("\t\t\tOpcija 4: ispisivanje suplementa!\n");
printf("\t\t\tOpcija 5: pretrazivanje suplementa!\n");
printf("\t\t\tOpcija 6: brisanje suplementa!\n");
printf("\t\t\tOpcija 7: promjena imena datoteci!\n");
printf("\t\t\tOpcija 8: brisanje datoteke!\n");
printf("\t\t\tOpcija 9: izlaz iz programa!\n");
printf("======================================\
======================================\n");
	int uvijet = 0;
	static SUPLEMENT* poljeSuplementa = NULL;
	static SUPLEMENT* pronadeniSuplement = NULL;
	scanf("%d", &uvijet);
	switch (uvijet) {
	case 1:
		kreiranjeDatoteke(imeDatoteke);
		break;
	case 2:
		dodajSuplement(imeDatoteke);
		break;
	case 3:
		if (poljeSuplementa != NULL) {
			free(poljeSuplementa);
			poljeSuplementa = NULL;
		}
		poljeSuplementa = (SUPLEMENT*)ucitavanjeSuplementa(imeDatoteke);
		if (poljeSuplementa == NULL) {
			exit(EXIT_FAILURE);
		}
		break;
	case 4:
		ispisivanjeStudenata(poljeSuplementa);
		break;
	case 5:
		pronadeniSuplement = (SUPLEMENT*)pretrazivanjeSuplementa(poljeSuplementa);
		break;
	case 6:
		brisanjeSuplementa(&pronadeniSuplement, poljeSuplementa, imeDatoteke);
		break;
	case 7:
		promjenaImenaDatoteci(imeDatoteke);
		break;
	case 8:
		brisanjeDatoteke(imeDatoteke);
		break;
	case 9:
		uvijet = izlazIzPrograma(poljeSuplementa);
		break;
	default:
		uvijet = 0;
	}
	return uvijet;
}