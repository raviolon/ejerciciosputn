#include <iostream>

using namespace std;

struct nodo{
    int numero;
    nodo* sig;
};

nodo* insertarordenado(nodo*& p,int v){
nodo* nuevo = new nodo();
nuevo->numero = v;
nuevo->sig = NULL;
nodo* aux = p;
nodo* anterior=NULL;
while (aux!=NULL && aux->numero <= v)
{
    anterior=aux;
    aux = aux->sig;
}
if (anterior== NULL){
    p = nuevo;
}
else{
    anterior->sig = nuevo;
}
 nuevo->sig = aux;
return nuevo;
}
nodo* buscar(nodo*& p, int v){
    nodo* aux=p;
    while (aux!=NULL && aux->numero != v){
        aux=aux->sig;
    }
    return aux;
}


void mostrar(nodo* p){
nodo* aux=p;
while (aux!=NULL)
{
    cout<<'-'<< aux->numero<<endl;
    aux=aux->sig;
}
}

void borrarnum (nodo*& p, int v){
    nodo* aux = p;
    nodo* anterior=NULL;
    while (aux!=NULL && aux->numero!=v){
        anterior=aux;
        aux=aux->sig;
    }
    if (anterior!=NULL){
        anterior->sig = aux->sig;

    }else{
        p=aux->sig;
    }
    
    delete aux;
}

int main() {
nodo* Lista=NULL;
insertarordenado(Lista,8);
insertarordenado(Lista,10);
insertarordenado(Lista,2);
insertarordenado(Lista,3);
mostrar(Lista);
    return 0; 
}