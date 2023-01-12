#include <stdio.h>
#include <mysql/mysql.h>

int maint(int argc, char* argv[]){
        SAConection con;
        try{
                con.Connect("dns",
                                "dns",
                                "IntroARedes_1@",
                                SA_Oracle_Client);
                printf("Conectado");
                con.Disconnect();
                printf("Desconectado");
        }
        catch(SAException & x){

                try{
                }
                catch(SAExeption &){
                }
                printf("Error");
        }
        return 0;
}
