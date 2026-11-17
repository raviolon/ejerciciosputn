#include <iostream>
#include <cstdio>
using namespace std;

struct infraccion{
int codigo;
int fecha;
char patente[8];
};
struct nodoinf{
    infraccion dato;
    nodoinf* sig;
};



int insertarordenado(nodoinf*& p , infraccion data){
FILE* archivo = fopen("infracciones.dat","rb");
nodoinf* nuevo = new nodoinf();
nuevo->dato = data;
nuevo-> sig = NULL;
nodoinf* aux = p;
nodoinf* anterior=NULL;

while(aux!= NULL && aux->dato.codigo < data.codigo){
    anterior = aux;
    aux=aux->sig;

}
if (anterior==NULL){
 nuevo->sig =p;
    p=nuevo;
}else{
    nuevo->sig =aux;
    anterior->sig=nuevo;
}

}
void procesarinfracciones(FILE* f, nodoinf*& p){
    infraccion data;
    while (fread(&data , sizeof(infraccion),1,f)==1){
        insertarordenado(p,data);
        }
    }


void mostrar_patentes_por_infraccion(nodoinf* p, int c){
    nodoinf* aux = p;
    while(aux!= NULL && aux->dato.codigo!=c){
        aux = aux->sig;
    }
    cout<<aux->dato.patente;

}
int main(){


    return 0;
}