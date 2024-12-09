#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//Str nodului arborelui
typedef struct nod
{
    int valoare;
    struct nod* stanga;
    struct nod* dreapta;
}Nod;

//Creeaza un nod nou
Nod* creeazaNod(int val){
    Nod* nod_N=(Nod*)malloc(sizeof(Nod));
    nod_N->valoare=val;
    nod_N->stanga=NULL;
    nod_N->dreapta=NULL;
    return nod_N;
}

//inseram un nod in arbore
Nod* insereaza(Nod* radacina, int val){
if(radacina==NULL){
    return creeazaNod(val);
}
if(val<radacina->valoare){
    radacina->stanga=insereaza(radacina->stanga,val);
}else{
    radacina->dreapta=insereaza(radacina->dreapta,val);
}
return radacina;
}


 
//Traversare in PreOrdine
Nod* preOrdine(Nod* radacina){

if(radacina!=NULL){
    printf("%d ", radacina->valoare);
    preOrdine(radacina->stanga);
    preOrdine(radacina->dreapta);
}

}
//Traversare in InOrdine
void inOrdine(Nod* radacina) {
    if (radacina != NULL) {
        inOrdine(radacina->stanga);
        printf("%d ", radacina->valoare);
        inOrdine(radacina->dreapta);
    }
}

//Traversare in PostOrdine
void postOrdine(Nod* radacina) {
    if (radacina != NULL) {
        postOrdine(radacina->stanga);
        postOrdine(radacina->dreapta);
        printf("%d ", radacina->valoare);
    }
}
//Traversare pe Niveluri
void peNiveluri(Nod* radacina) {
    if (radacina == NULL) return;

    Nod* coada[100];
    int inceput = 0, sfarsit = 0;

    coada[sfarsit++] = radacina;

    while (inceput < sfarsit) {
        Nod* curent = coada[inceput++];
        printf("%d ", curent->valoare);

        if (curent->stanga != NULL) coada[sfarsit++] = curent->stanga;
        if (curent->dreapta != NULL) coada[sfarsit++] = curent->dreapta;
    }
}

int main(){
   Nod* radacina = NULL;
    int n = 10; 
    int val_Max = 100; 

    srand(time(NULL));
    
    //Adaugare de valori random in radacina
    for (int i = 0; i < n; i++) {
        int valoareAleatoare = rand() % val_Max;
        radacina = insereaza(radacina, valoareAleatoare);
    }

//Printare rezultate traversari
    printf("Arbore binar:\n");
    printf("Pre-Ordine: ");
    preOrdine(radacina);
    printf("\n");

    printf("In-Ordine: ");
    inOrdine(radacina);
    printf("\n");

    printf("Post-Ordine: ");
    postOrdine(radacina);
    printf("\n");

    printf("Pe Niveluri: ");
    peNiveluri(radacina);
    printf("\n");
    
    printf("Merge bine!");

    return 0;
}