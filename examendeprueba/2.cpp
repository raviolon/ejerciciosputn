#include <iostream>
#include <cstdio>
using namespace std;

struct tinfo{
int codigo;
char patente[9];
int fecha;
};

struct nodoinf{
    tinfo data;
    nodoinf* sig;
};

nodoinf* insertarordenado(nodoinf*& p ,tinfo info){
    nodoinf* aux=p;
    nodoinf* nuevo = new nodoinf();
    nuevo->data = info;
    nuevo->sig=NULL;
    nodoinf* anterior = NULL;
    while (aux != NULL && aux->data.codigo < info.codigo){
        anterior = aux;
        aux = aux->sig;


    }
    if (anterior == NULL){
        nuevo->sig = p;
        p=nuevo;
    }else{
        nuevo->sig = aux;
        anterior->sig=nuevo;
    }

return nuevo;
}

void procesarinfracciones(FILE* f, nodoinf*& p){
    tinfo info;
    while (fread(&info, sizeof(tinfo),1,f) == 1){
        insertarordenado(p, info);

    }
}

int main(){

    FILE* archivo=fopen("archivoinfracciones.dat","rb");

    return 0;
}
