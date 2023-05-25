#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "dataType.h"
int izbornik(const char* const);
void kreiranjeDatoteke(const char* const);
void dodajSuplement(const char* const);
void* ucitavanjeSuplementa(const char* const);
void ispisivanjeSuplementa(const SUPLEMENT* const);
void* pretrazivanjeSuplementa(SUPLEMENT* const);
void brisanjeSuplementa(SUPLEMENT** const, const SUPLEMENT* const, const char* const);
void promjenaImenaDatoteci(const char*);
void brisanjeDatoteke(const char*);
int izlazIzPrograma(SUPLEMENT*);
#endif //FUNCTIONS_H