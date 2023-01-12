#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

//Codigo que trabaja con la base de datos

int main(int argc, char **argv)
{
    MYSQL *conn;

    conn = mysql_init(NULL);

    //Caso error de inicializacion
    if (conn == NULL) 
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    //Caso error de conexion
    if (mysql_real_connect(conn, "190.161.106.202", "dns", "IntroARedes_1@", 
          "dns", 0, NULL, 0) == NULL) 
    {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    else
    {
        printf("Conexión exitosa a la base de datos\n");
    }

    // codigo para interactuar con la base de datos aqui

    mysql_close(conn);
    return 0;
}
