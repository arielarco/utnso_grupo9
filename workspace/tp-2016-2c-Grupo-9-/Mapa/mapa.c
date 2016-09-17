#include "libreriaMapa.h"
#include <pthread.h>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("Igrese la ruta del archivo por linea de comando");
		return -1;
	}
	if (argc != 2) {
		printf("Numero incorrecto de Argumentos");
	}

	//CARGAMOS EL ARCHIVO DE CONFIGURACION
	cargarArchivoConfiguracion(config, argv[1]);

	//MOSTRAMOS POR PANTALLA/LOG EN ARCHIVO DE CONFIGURACION
	mostrarArchivoConfiguracion();

	/* HILO PLANIFICADOR */
	//Atributo Detached
	pthread_attr_t atributo;
	pthread_attr_init(&atributo);
	pthread_attr_setdetachstate(&atributo, PTHREAD_CREATE_DETACHED);
	int falloP_thread;
	//Creo el hilo planificador
	pthread_t* hiloPlanificador = malloc(sizeof(pthread_t));
	falloP_thread = pthread_create(hiloPlanificador, &atributo,
			(void*) procesoPlanificador, config.algoritmo);
	if (falloP_thread < 0) {
		//log_error(logMapa, "Error Hilo Planificador");
		printf("Error Hilo Planificador\n");
		abort();
	}
	/***/

	//Creo un socket de escucha, acepto a un entrenador y realizo handshake
	int socketMapa = crearSocketDeEscucha(config.puerto);
	/*Atributo Detached
	 pthread_attr_t atributo;
	 pthread_attr_init(&atributo);
	 pthread_attr_setdetachstate(&atributo, PTHREAD_CREATE_DETACHED);
	 int falloP_thread;*/
	//int socketEntrenador = aceptarCliente(socketMapa);
	//escucharEntrenador((void*) socketEntrenador);

	/**********************************************************************/

	iniciarMapa ();
	nivel_gui_dibujar(items, "Test Chamber 04");

	/** Bucle Principal **/
	while (1) {
		int socketCliente = aceptarCliente(socketMapa);
		//escucharEntrenador((void*) socketEntrenador);
		if ((socketCliente) == -1) {
			printf("Error en el accept()\n");
			//log_error(logMapa, "Error en el accept()");
			abort();
		}

		send(socketCliente, "Hola quien sos?", 16, 0);

		char* bufferCliente = malloc(200);
		int bytesRecibidosBufferCliente = recv(socketCliente, bufferCliente,
				bytesRecibidosBufferCliente, 0);
		bufferCliente[bytesRecibidosBufferCliente] = '\0';

		if (strcmp("Hola, soy un Entrenador", bufferCliente) == 0) {
			pthread_t* hiloEntrenador = malloc(sizeof(pthread_t));

			pipe(pipeMaE);

			falloP_thread = pthread_create(hiloEntrenador, &atributo,
					(void*) escucharEntrenador, (void*) socketCliente);
			if (falloP_thread < 0) {
				//log_error(logMapa, "Error Hilo Entrenador");
				printf("Error Hilo Entrenador\n");
				abort();
			}
			close(pipeMaE[0]);
			close(pipeEaM[1]);
		}

		sleep(config.retardo);

		nivel_gui_dibujar(items, "Test Chamber 04");

	}

	nivel_gui_terminar();

	return 0;
}
