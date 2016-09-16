/*
 * mapa.h
 *
 *  Created on: 1/9/2016
 *      Author: utnso
 */

#ifndef LIBRERIAMAPA_H_
#define LIBRERIAMAPA_H_


#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <errno.h>
#include <arpa/inet.h>
#include <commons/config.h>
#include <commons/string.h>
#include <commons/collections/queue.h>
#include <commons/log.h>
#include <commons/process.h>
#include "/home/utnso/workspace/tp-2016-2c-Grupo-9-/biblioteca/socket.h"
#include "/home/utnso/workspace/tp-2016-2c-Grupo-9-/biblioteca/enum.h"


typedef struct {
	int tiempoChequeoDeadlock;
	int batalla;
	char* algoritmo;
	int quantum;
	int retardo;
	char* ip;
	int puerto;
} tConfig;

tConfig config;

int puertoMapa;
char* nombreMapa;

void mostrarArchivoConfiguracion();

void procesoPlanificador(char* algoritmo);

void escucharEntrenador(void* socketCliente);

#endif /* LIBRERIAMAPA_H_ */
