#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "dataType.h"
#include "functions.h"
int izbornik(const char* const);
void kreiranjeDatoteke(const char* const);
void dodajSuplement(const char* const);
void* ucitavanjeSuplementa(const char* const);
void ispisivanjeSuplementa(const SUPLEMENT* const);
void* pretrazivanjeSuplementa(SUPLEMENT* const);
int izlazIzPrograma(SUPLEMENT*);
#endif //FUNCTIONS_H