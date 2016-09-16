/*
 * mapa.c
 *
 *  Created on: 1/9/2016
 *      Author: utnso
 */



#include "libreriaMapa.h"
#include <commons/collections/queue.h>


void mostrarArchivoConfiguracion()
{
	printf("El nombre del Mapa es: %s\n",nombreMapa);
	//printf("El puerto del Mapa es: %d\n", puertoMapa);

	printf("Algoritmo: %s\nBatalla: %d\nIp: %s\nPuerto: %d\nQuantum: %d\nRetardo: %d\nTiempo Chequeo Deadlock: %d\n"
			,config.algoritmo
			,config.batalla
			,config.ip
			,config.puerto
			,config.quantum
			,config.retardo
			,config.tiempoChequeoDeadlock);
}

void procesoPlanificador(char* algoritmo) {

	t_queue cola_Listos, cola_Bloqueados;

}

void escucharEntrenador(void* socketEntrenador)
{
	//Casteo socket_Entrenador
	int socket_Entrenador = (int) socketEntrenador;
	if ((socket_Entrenador) == -1)
	{
		//log_error(logMapa,"Error en el accept()");
		printf("Error en el accept()");
		pthread_exit(NULL);
	}
	char* bufferEntrenador = malloc(200);
	int bytesRecibidos = recv(socket_Entrenador, bufferEntrenador, 23, 0);
	bufferEntrenador[bytesRecibidos] = '\0';

	if(strcmp(bufferEntrenador,"Hola soy un Entrenador") != 0)
	{
		printf("Se conecto un Entrenador\n");

		send(socket_Entrenador,"Bienvenido al Mapa",19,0);
	}

	uint32_t header;
	while(1)
	{
		bytesRecibidos = recv(socket_Entrenador,&header,sizeof(uint32_t),0);
		if(bytesRecibidos <= 0)
		{
			//log_error(logMapa,"Error recv Entrenador");
			printf("Error recv Entrenador\n");
			pthread_exit(NULL);
		}
		if (header != ENTRENADOR)
		{
			//log_error(logMapa, "El Entrenador se ha desconectado o etc");
			printf("El Entrenador se ha desconectado o etc\n");
			pthread_exit(NULL);
		}
		switch(header)
		{
			case MOVER:
			{
				bytesRecibidos = recv(socket_Entrenador,&header,sizeof(uint32_t),0);
				switch(header)
				{
					case ARRIBA:
					{

					}
					break;
					case ABAJO:
					{

					}
					break;
					case IZQUIERDA:
					{

					}
					break;
					case DERECHA:
					{

					}
					break;
				}
				break;

			}
			//case FIN_OBJETIVOS:
			{

			}
			break;
		}
	}

}
