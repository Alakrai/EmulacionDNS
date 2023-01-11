#include <stdio.h>
extern socket_cliente();

struct PDU
{
    char cabeza;
    char mensaje[100];
};

main()
{
    char dato[25];
    int conexion;
    struct PDU peticion, respuesta;

    printf("--------- INICIO DE CLIENTE --------\n");
    printf("Ingrese dato a enviar:");

    scanf("%s",dato);
    conexion=socket_cliente("server",55055); //Puerto desde el que trabaja

    strcpy(peticion.mensaje,dato);
    write(conexion,&peticion,sizeof(peticion));
    read(conexion, &respuesta, sizeof(respuesta));

    printf("RESPUESTA DE SERVIDOR: %s\n", respuesta.mensaje);

    close(conexion);
}
