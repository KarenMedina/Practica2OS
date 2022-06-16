//#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

//void welcome(int sourceId, int dstId, int hod) {

struct datosBusqueda{
	int origen;
	int destino;
	int hora;
};
int revisarDatos(struct datosBusqueda data, int aux){
if(data.origen==-1){
	printf("No ha ingresado el ID del origen \n");
	aux = -1;
}
if(data.destino==-1){
	printf("No ha ingresado el ID del destino \n");
	aux = -1;
}
if(data.hora==-1){
	printf("No ha ingresado la hora del viaje \n ");
	aux = -1;
}
return aux;
}
int main(){

	int select = 0;
	int aux = 0;
	struct datosBusqueda d1 = {-1,-1,-1};
	startover:
	do {
    printf("Bienvenide al menu principal\n");
	printf("1. Ingresar origen \n");
	printf("2. Ingresar destino \n");
	printf("3. Ingresar hora\n");
	printf("4. Buscar tiempo de viaje medio \n");
	printf("5. Salir \n");
	printf("Seleccione una opción (1-5) \n");
	scanf("%d", &select);
	}
    while((select < 1) && (select > 4));
 
    switch(select)
    {
        case 1:
             printf("Origen\n");
             scanf("%d", &d1.origen);
                goto startover;
        case 2:
             printf("Destino \n");
             scanf("%d",&d1.destino);
             goto startover;
        case 3:
             printf("Hora\n");
             scanf("%d", &d1.hora);
             goto startover;
        case 4:
             printf("Buscando...\n");
             printf ("Origen = %d, Destino = %d, Hora = %d \n", d1.origen, d1.destino, d1.hora);
             if(revisarDatos(d1, aux)==-1)
		printf("Ingrese los datos completos \n");
	     goto startover;	
        case 5:
       	     printf("Saliendo...\n");
             exit(0);
             //return 0;
        default:
             printf("Por favor selecione una opción válida\n");
             goto startover;
    }
 return 0;   
}



//}
