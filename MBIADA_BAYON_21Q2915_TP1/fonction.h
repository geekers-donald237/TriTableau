#ifndef __FONCTION_H__
#define __FONCTION_H__
#include "fonction.h"

int* alloue_espace(int n);

int* genere(int * tab,int n);

int*  fill_tab(int n, int* tab);

void print_tab(int n,int*tab);

void recherche_sequentielle(int*tab,int n,int x);

void recherche_dichotomique(int*tab,int n,int x);

void tri_selection(int *T,int n);

void tri_bulle(int *tab ,int n);

void tri_insertion(int*tab,int n);

void permuter(int *a, int *b);

void triRapid(int *tab, int first, int last);

void triFusion(int i, int j, int* tab, int *tmp);

void tri_bitonnique(int * tab,int n);

int premiere_occurence(int* tab,int n,int x);

int derniere_occurences( int* tab,int n,int x);

int nbre_occurences(int* tab,int n,int x);



#endif