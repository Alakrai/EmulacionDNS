#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

struct PDU 
{
    char cabeza;
    char mensaje[100];
};

char* dameLaIp(struct PDU pdu) 
{
    MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "190.161.106.202", "dns", "IntroARedes_1@",
          NULL, 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }
  else
  {
    printf("Conexion exitosa\n");
  }

    /*
  if (mysql_query(con, "CREATE DATABASE testdb"))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }
    */

    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    char *ip;

    conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        return NULL;
    }

    //creamos la consulta SQL
    char query[256];
    sprintf(query, "SELECT IP FROM sitios WHERE Dominio = '%s'", pdu.mensaje);
    if (mysql_query(conn, query)) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    result = mysql_use_result(conn);
    if (result == NULL) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    //recogemos el resultado
    row = mysql_fetch_row(result);

    if (row == NULL) //Si el resultado == NULL
    {
        printf("No se encontró el dominio en la base de datos\n");
        mysql_free_result(result);
        mysql_close(conn);
        return NULL;
    }
    
    //sino asignamos la IP encontrada a una variable  IP||
    ip = row[0];
    mysql_free_result(result);
    mysql_close(conn);
    
    return ip;

    mysql_close(con);
  exit(0);
}//Fin dameLaIp



