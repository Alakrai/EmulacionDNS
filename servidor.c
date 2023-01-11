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
		
		strcpy(respuesta.mensaje,"Mensaje recibido");
		write(conexion, &respuesta, sizeof(respuesta));
		close(conexion);
	}
}
