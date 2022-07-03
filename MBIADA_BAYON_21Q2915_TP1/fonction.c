#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <time.h>

int* alloue_espace( int n)
{
	int* tab;
	tab=(int*)malloc(sizeof(int)*n);
	return tab;
} 
int* genere(int* tab,int n)
{
	int i;
	srand(time(NULL));
	for (i=0 ; i<n ; i++)
	{
		tab[i]=rand ()%20;
	}
	return tab;
}

int* fill_tab(int n, int* tab)
{ int i;
	for(i=0;i<n;i++){
	printf("element %d:",i+1);
	scanf("%d", &tab[i]);
	}

	return tab;
}

void print_tab(int n,int*tab)
{
	int i;
	printf("le tableau est\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",tab[i]);
	}
	printf("\n");
}

void recherche_sequentielle(int*tab,int n,int x)
{
	int i=0;
	int flag=0;
	while(i<=n && flag == 0)
	{
		if(tab[i]==x)
		{
			flag=i;
		}
		i=i+1;
	}

	if(flag == 0)
	{
		printf("elements pas trouve\n");
	}
	else{
		printf("elments trouve il s'agit de %d qui est a la position %d\n",x,flag);
	}
}


void recherche_dichotomique(int*tab,int n,int x)
{
	int inf=0;
	int sup=n-1;
	int mil;
	int pos=-1;

	while((inf<=sup) && (pos==-1))
	{
		mil=(sup+inf)/2;
		if(x<tab[mil])
		{
			sup=mil-1;
		}
		else if(x>tab[mil])
		{
			inf=mil+1;
		}
		else
		{
			pos=mil;
		}
	}

	if(pos==-1)
	{
		printf("valeur non trouvé\n");
	}
	else
	{
		printf("Element trouve il s'agit de %d qui est la position %d\n",x,pos);
	}
}

void tri_insertion(int*tab,int n)
{
    int i,j,t,m;
    for(i=1;i<n;i++)
    {
	    t=tab[i];
	    j=i-1;
	    while((j>=0) && (tab[j]>t))
	    {
		    m=tab[j+1];
		    tab[j+1]=tab[j];
		    tab[j]=m;
		    j=j-1;
	    }
	}
}

void tri_selection(int *T,int n)
{
	int i,j,t,min;
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<=n;j++)
		{
			if(T[j]<T[min])
			{
				min=j;
			}
		}
		t=T[i];
		T[i]=T[min];
		T[min]=t;
	}
}	

void tri_bulle(int *tab ,int n)
{	
	int i, r,p=0;
	i=n;
        while(p==0)
	    {
		    p=1;
		    for(i=n-1;i>0;i--)
		    {
			    if(tab[i-1]>tab[i])
			    {
				    p=0;
				    r=tab[i-1];
				    tab[i-1]=tab[i];
				    tab[i]=r;
			    }
		    }
	    }
}	


void permuter(int *a, int *b) 
{
    int tmp;   
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void triRapid(int *tab, int first, int last)
{
    int pivot, i, j;
    if(first < last) {
        pivot = first;
        i = first;
        j = last;
        while (i < j) {
            while(tab[i] <= tab[pivot] && i < last)
                i++;
            while(tab[j] > tab[pivot])
                j--;
            if(i < j) {
                permuter(&tab[i], &tab[j]);
            }
        }
        permuter(&tab[pivot], &tab[j]);
        triRapid(tab, first, j - 1);
        triRapid(tab, j + 1, last);
    }
}

void triFusion(int i, int j, int* tab, int *tmp) 
{

    if(j <= i){ 
		return;
	}
    int m = (i + j) / 2;
    
    triFusion(i, m, tab, tmp);     
    triFusion(m + 1, j, tab, tmp); 
    int pg = i;     //pg pointe au début du sous-tableau de gauche
    int pd = m + 1; //pd pointe au début du sous-tableau de droite
    int c;          //compteur
	// on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for(c = i; c <= j; c++) {  //copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
}


void tri_bitonnique(int * tab,int n)
{
	int i,tmp,test=0;

	do
	{
		test=0;
		for(i=0 ;i <=n-2 ; i=i+2){
			if(tab[i] > tab[i+1]){ 
				tmp=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=tmp;
				test=1;
			}	
		}
		for(i=1 ;i <=n-2 ; i=i+2){
			if(tab[i] > tab[i+1]){ 
			tmp=tab[i];
			tab[i]=tab[i+1];
			tab[i+1]=tmp;
			test=1;
			}	
		}

	}while(test == 1);
}	

int premiere_occurence(int* tab,int n,int x)
{
	int i=0;
	int flag=0;
	while(i<=n && flag == 0)
	{
		if(tab[i]==x)
		{
			flag=i;
		}
		i=i+1;
	}
	if(flag == 0){
		printf("valeurs non trouve\n");
	}else {
		printf("la premiere occurence  de %d est %d\n",x,flag);

	}
		return flag;

}

int derniere_occurences( int* tab,int n,int x)
{
	int i=n;
	int flag=-1;
	while(i>=n && flag == -1)
	{
		if(tab[i]==x)
		{
			flag=i;
		}
		i=i-1;
	}

	if(flag == -1){
		printf("valeurs non trouve\n");
	}else{
		printf("la derniere occurence de %d est %d\n",x,flag);

	}
		return flag;

}

int nbre_occurences(int* tab,int n,int x)
{	
	int i=n;
	int flag=0;
	while(i>=1)
	{
		if(tab[i]==x)
		{
			flag=flag+1;
		}
		i=i-1;
	}
	if(flag == 0){
		printf("valeurs non trouve\n");
	}else{
		printf("le nombre d'occurence  de %d est %d dans le tableau\n",x,flag);

	}
	return flag;

}


