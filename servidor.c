#include <stdio.h>
#include <string.h>

extern acepta_conexion();
extern call_on_sock();

struct PDU
{
	char cabeza;
	char mensaje[100];
};


main()
{
	int dirlisten, conexion;
	struct PDU peticion, respuesta;

	dirlisten=socket_servidor(55055); //Puerto desde el que trabaja

	printf("--------- INICIO DEL SERVIDOR ----------\n");

	while(1)
	{
		while((conexion=acepta_conexion(dirlisten))<0);

		read(conexion, &peticion, sizeof(peticion));
		
		printf("\nDATO RECIBIDO:%s\n",peticion.mensaje);
		printf("Escuchando ....");
		
		//Aqui se elabora la respuesta entregada al cliente
		//peticion.mensaje es un PDU con el mensaje enviado por el cliente
		
		// Consultar a una BDD
		strcpy(respuesta.mensaje,dameLaIp(peticion.mensaje));

		// respuesta.mensaje=dameLaIp(peticion.mensaje);

		//respuesta.mensaje=dameLaIp(peticion.mensaje);
		
		printf("Mensaje recibido\n");
		//strcpy(respuesta.mensaje,"Mensaje recibido");


		write(conexion, &respuesta, sizeof(respuesta));
		close(conexion);
	}
}//Fin main
