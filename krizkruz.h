#ifndef KRIZKRUZ_H
#define KRIZKRUZ_H

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>//za funkcije vezane za ispitivanje slova

typedef int bool;
#define true 1
#define false 0

int mainKK();
void play();
void ispis_polja(char *polje);
bool krajigre(char *polje);
bool potez(char *polje, int redak, int stupac);
char pobjednik(char *polje);

#endif // KRIZKRUZ_H
