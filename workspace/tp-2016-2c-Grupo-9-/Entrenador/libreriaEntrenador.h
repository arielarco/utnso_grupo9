/*
 * entrenador.h
 *
 *  Created on: 1/9/2016
 *      Author: utnso
 */

#ifndef LIBRERIAENTRENADOR_H_
#define LIBRERIAENTRENADOR_H_

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

int puertoEntrenador;
int puertoMapa;
char* ipMapa;

typedef struct
{
char* nombreEntrenador;
char* simboloEntrenador;
int cantidadVidas;
char* hojaDeViaje;
} entrenador;

entrenador participante;

void mostrarArchivoConfiguracion();

void recorrerMapa(void* socketServidor);

#endif /* LIBRERIAENTRENADOR_H_ */
