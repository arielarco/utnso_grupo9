#include "libreriaEntrenador.h"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		printf("Igrese la ruta del archivo por linea de comando");
		return -1;
	}
	if (argc != 2)
	{
		printf("Numero incorrecto de Argumentos");
	}

	//CREAMOS EL ARCHIVO DE CONFIGURACION DEL ENTRENADOR

	t_config* configuracion = config_create(argv[1]);
	participante.nombreEntrenador = config_get_string_value(configuracion,"NOMBRE");
	participante.simboloEntrenador = config_get_string_value(configuracion,"SIMBOLO");
	participante.cantidadVidas = config_get_int_value(configuracion,"CANTIDAD_VIDAS");
	participante.hojaDeViaje = config_get_string_value(configuracion,"HOJA_VIAJE");
	puertoEntrenador = config_get_int_value(configuracion, "PUERTO_ENTRENADOR");
	puertoMapa = config_get_int_value(configuracion, "PUERTO_MAPA");
	ipMapa = config_get_string_value(configuracion, "IP_MAPA");


	//MOSTRAMOS POR PANTALLA/LOG EN ARCHIVO DE CONFIGURACION
	mostrarArchivoConfiguracion();

	int socketMapa = conectarAServidor(ipMapa,puertoMapa);

	//escucharMapa((void*) socketMapa);
	char* bufferHandshakeMapa = malloc(200);

	int bytesRecibidosMapa = recv(socketMapa, bufferHandshakeMapa, 50, 0);
	bufferHandshakeMapa[bytesRecibidosMapa] = '\0';

	printf("Me conecté al Mapa y recibí %d bytes con el mensaje: %s", bytesRecibidosMapa, bufferHandshakeMapa);

	recorrerMapa((void*) socketMapa);

	return 0;
}
