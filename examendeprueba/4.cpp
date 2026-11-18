#include <iostream>
#include <cstdio>

struct proyecto{
int tipo;
int fecha;
float costo;
}

struct nodoproyecto{
    proyecto data;
    nodoproyecto* sig;
}


void procesarproyectos(nodoproyecto*& p, FILE* f){
    proyecto protectos;
    while (fread(proyectos,sizeof(proyecto),1,f)==1){
        push(p,proyecto);
    }
}

void escribirarchivo(nodoproyecto*& p, FILE* f){
    while(p!=NULL){
        proyecto proyectos =pop(p);
        write(&p,sizeof(proyecto),1,f);
    }
}
int main(){
//    new proyecto();       VER LINEA
    Nodo* pila = NULL;
    FILE* archivoleido= fopen("proyectos.dat","wb+");
    procesarproyectos(pila,archivoleido);
    escribirarchivo(pila,archivoleido);
    return 0;
}