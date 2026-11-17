#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct escuela{
	int c_estudiantes;
	int c_escuela;
	int c_muni;
};
void recorrer(FILE* f, escuela datos[9]);

int main(){
  escuela datos[9] = {
    {1901, 5568, 198},
    {1901, 5571, 250},
    {1901, 5506, 312},
    {1655, 2499, 356},
    {1655, 2415, 320},
    {1519, 1254, 230},
    {1519, 1298, 195},
    {1519, 1245, 350},
    {1519, 1236, 218}
};
  FILE* f= fopen("ESCUELAS.DAT", "wb+");
  recorrer(f, datos);
  
  
}

void recorrer(FILE* f, escuela datos[9]){
	
    fwrite(datos,sizeof(escuela),9,f);
    
}

