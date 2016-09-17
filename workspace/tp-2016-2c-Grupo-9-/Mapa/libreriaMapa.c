/*
 * mapa.c
 *
 *  Created on: 1/9/2016
 *      Author: utnso
 */



#include "libreriaMapa.h"
#include <commons/collections/queue.h>

void iniciarMapa () {
	items = list_create();
	nivel_gui_inicializar();
	nivel_gui_get_area_nivel(&rows, &cols);

	//CrearPersonaje(items, '#', x, y);???

	//CrearEnemigo(items, '1', ex1, ey1);???

	// Corresponden a los pokemones/recursos del mapa
	CrearCaja(items, 'P', 26, 10, 5);
	CrearCaja(items, 'B', 11, 20, 2);
	CrearCaja(items, 'C', 5, 26, 3);

	//t_list* items = list_create();

	//MoverPersonaje(items, '1', ex1, ey1 );

	//nivel_gui_dibujar(items, "Test Chamber 04");

	//BorrarItem(items, 'H');
	//nivel_gui_terminar();

}





void cargarArchivoConfiguracion(tConfig config, char* ruta) {

	//CREAMOS EL ARCHIVO DE CONFIGURACION
	t_config* configuracion = config_create(ruta);

	nombreMapa = config_get_string_value(configuracion,"NOMBRE_MAPA");
	//puertoMapa = config_get_int_value(configuracion, "PUERTO_MAPA");

	config.algoritmo = config_get_string_value(configuracion,"ALGORITMO");
	config.batalla = config_get_int_value(configuracion,"BATALLA");
	config.ip = config_get_string_value(configuracion,"IP");
	config.puerto = config_get_int_value(configuracion,"PUERTO");
	config.quantum = config_get_int_value(configuracion,"QUANTUM");
	config.retardo = config_get_int_value(configuracion,"RETARDO");
	config.tiempoChequeoDeadlock = config_get_int_value(configuracion,"TIEMPOCHEQUEODEADLOCK");
}

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
	close(pipeMaE[1]);
	close(pipeEaM[0]);

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
