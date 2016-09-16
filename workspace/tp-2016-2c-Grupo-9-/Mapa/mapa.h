/*
 * mapa.h
 *
 *  Created on: 1/9/2016
 *      Author: utnso
 */

#ifndef MAPA_H_
#define MAPA_H_

void procesoPlanificador(int pipMaP[2], int pipPaM[2]){
	/* Definicion de log*/
		t_log* plInfo  = log_create("planificador.log", "mapa", true, LOG_LEVEL_INFO);
		t_log* plTrace = log_create("planificador.trc", "mapa", true, LOG_LEVEL_TRACE);
		t_log* plDebug = log_create("planificador.dbg", "mapa", true, LOG_LEVEL_TRACE);

	/***/

	log_info(plInfo, "Inicio");
	close(pipMaP[1]); // Cierra el pipe no usado
	close(pipPaM[0]); // Cierra el pipe no usado

	/***/
		log_info(plTrace, "Creacion de colas");
		t_queue *listos     = queue_create(); //Cola de listos
		t_queue *bloqueados = queue_create(); //Cola de Bloqueados

	/***/

		log_info(plTrace, "Bucle Principal");
		while(1) {

			sleep(1);

		}

	/**/

	log_info(plInfo, "Fin");

}

void hiloEntrenador(int socNuevo,int pipMaHe[2],int pipHeaM[2]) {
	/* Definicion de log*/
		char *archivo;
		sprintf(archivo, "hEntrenador_%d.log",socNuevo);
		t_log* heInfo  = log_create(archivo, "mapa", true, LOG_LEVEL_INFO);
		sprintf(archivo, "hEntrenador_%d.trc",socNuevo);
		t_log* heTrace = log_create(archivo, "mapa", true, LOG_LEVEL_TRACE);
		sprintf(archivo, "hEntrenador_%d.dbg",socNuevo);
		t_log* heDebug = log_create(archivo, "mapa", true, LOG_LEVEL_TRACE);

	/***/

	log_info(heInfo, "Inicio");
	close(pipMaHe[1]); // Cierra el pipe no usado
	close(pipHeaM[0]); // Cierra el pipe no usado

	/***/


	/***/
		log_info(heTrace, "Bucle Principal");
		while(1) {

			sleep(1);

		}

	/**/

	log_info(heInfo, "Fin");
}

#endif /* MAPA_H_ */
