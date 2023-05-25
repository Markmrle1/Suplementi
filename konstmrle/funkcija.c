#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "dataType.h"

static int brojSuplementa = 0;

void ispisivanjeStudenata() {}
void* ucitavanjeSuplementa (const char* const izbornik) {}
void ispisivanjeSuplementa(const SUPLEMENT* const suplement) {}
void* pretrazivanjeSuplementa(SUPLEMENT* const poljeSuplementa) {
	if (poljeSuplementa == NULL) {
		printf("Polje suplementa je prazno!\n");
		return NULL;
	}
	int i;
	char trazenoIme[30] = { '\0' };
	printf("Unesite trazeni kriterij za pronalazak studenta.\n");
	getchar();
	scanf("%19[^\n]", trazenoIme);
	for (i = 0; i < brojSuplementa; i++)
	{
		if (!strcmp(trazenoIme, (poljeSuplementa + i)->ime)) {
			printf("Suplement je pronaden!\n");
			return (poljeSuplementa + i);
		}
	}
	return NULL;
}
void promjenaImenaDatoteci(const char* staroImeDatoteke) {
	char novoImeDatoteke[20] = { '\0' };
	printf("Unesite novi naziv datoteke!\n");
	getchar();
	scanf("%19[^\n]", novoImeDatoteke);
	printf("Zelite li uistinu promijeniti ime datoteci?\n");
	printf("Utipkajte \"da\" ako uistinu želite promijeniti ime datoteke u suprotno utipkajte\"ne\"!\n");
	char potvrda[3] = { '\0' };
	scanf("%2s", potvrda);
	if (!strcmp("da", potvrda)) {
		rename(staroImeDatoteke, novoImeDatoteke) == 0 ?
			printf("Uspjesno promijenjeno ime datoteci!\n") :
			printf("Neuspjesno promijenjeno ime datoteci!\n");
	}
}
void brisanjeSuplementa(SUPLEMENT** const trazeniSuplement, const SUPLEMENT* const poljeSuplementa,
	const char* const imeDatoteke) {
	FILE* pF = fopen(imeDatoteke, "wb");
	if (pF == NULL) {
		perror("Brisanje studenta iz datoteke suplementi.txt");
		exit(EXIT_FAILURE);
	}
	fseek(pF, sizeof(int), SEEK_SET);
	int i;
	int noviBrojacSuplementa = 0;
	for (i = 0; i < poljeSuplementa; i++)
	{
		if (*trazeniSuplement != (poljeSuplementa + i)) {
			fwrite((poljeSuplementa + i), sizeof(SUPLEMENT), 1, pF);
			noviBrojacSuplementa++;
		}
	}
	rewind(pF);
	fwrite(&noviBrojacSuplementa, sizeof(int), 1, pF);
	fclose(pF);
	printf("Student je uspjesno obrisan!\n");
	*trazeniSuplement = NULL;
}
void brisanjeDatoteke(const char* imeDatoteke) {
	printf("Zelite li uistinu obrisati datoteku %s?\n", imeDatoteke);
	printf("Utipkajte \"da\" ako uistinu želite obrisati datoteku u suprotno utipkajte\
\"ne\"!\n");
	char potvrda[3] = { '\0' };
	scanf("%2s", potvrda);
	if (!strcmp("da", potvrda)) {
		remove(imeDatoteke) == 0 ? printf("Uspjesno obrisana datoteka %s!\n",
			imeDatoteke) : printf("Neuspjesno brisanje datoteke %s!\n", imeDatoteke);
	}
}
int izlazIzPrograma(SUPLEMENT* poljeSuplementa) {
	free(poljeSuplementa);
	return 0;
}

void kreiranjeDatoteke(const char* const imeDatoteke) {
	FILE* pF = fopen(imeDatoteke, "wb");
	if (pF == NULL) {
		perror("Kreiranje datoteke suplementi.txt");
		exit(EXIT_FAILURE);
	}
	fwrite(&brojSuplementa, sizeof(int), 1, pF);
	fclose(pF);
}
void dodajSuplement(const char* const imeDatoteke) {
	FILE* pF = fopen(imeDatoteke, "rb+");
	if (pF == NULL) {
		perror("Dodavanje studenta u datoteke suplementi.txt");
		exit(EXIT_FAILURE);
	}
	fread(&brojSuplementa, sizeof(int), 1, pF);
	printf("brojStudenata: %d\n", brojSuplementa);
	SUPLEMENT temp = { 0 };
	temp.id = brojSuplementa;
	getchar();
	printf("Unesite ime suplementa!\n");
	scanf("%19[^\n]", temp.ime);
	fseek(pF, sizeof(SUPLEMENT) * brojSuplementa, SEEK_CUR);
	fwrite(&temp, sizeof(SUPLEMENT), 1, pF);
	rewind(pF);
	brojSuplementa++;
	fwrite(&brojSuplementa, sizeof(int), 1, pF);
	fclose(pF);
}