/*
 * libreriaEntrenador.c
 *
 *  Created on: 8/9/2016
 *      Author: utnso
 */

#include "libreriaEntrenador.h"

void mostrarArchivoConfiguracion()
{
	printf("ELnombre del Entrenador es: %s\n", participante.nombreEntrenador);
	printf("El simbolo del Entrenador es: %s\n",participante.simboloEntrenador);
	printf("La cantidad de vidas que tiene es de: %d\n",participante.cantidadVidas);
	printf("Su hoja de ruta es: %s\n",participante.hojaDeViaje);
	printf("El puerto del Entrenador es: %d\n", puertoEntrenador);
	printf("El puerto del Mapa es: %d\n", puertoMapa);
	printf("El IP del Mapa es: %s\n", ipMapa);
}

void recorrerMapa(void* socketMapa)
{
	//Casteo socket Mapa
	int socket_Mapa = (int) socketMapa;
	send(socket_Mapa, "Hola, soy un Entrenador", 24, 0);
/*
	char* bufferMapa;
	while(1)
	{
		int bytesRecibidos = recv(socket_Mapa,bufferMapa,50,0);
		bufferMapa[bytesRecibidos] = '\0';
		if(strcmp(bufferMapa,"Bienvenido al Mapa") == 0)
		{
			printf("Entre al Mapa\n");

		}
	}
*/
}
