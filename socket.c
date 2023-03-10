#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <ctype.h>

#define NOBLOCK
extern int errno;

int socket_servidor(side)
int side;
{//Esto de aqui no se como funciona, pero lo hace, parece declarar socket_servidor(side)	NO TOCAR
	struct sockaddr_in server;
	
	int sock, x, flags;
	sock= socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
	{
		perror ("NO SE PUEDE CREAR SOCKET");
		exit (1);
	}
	
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(side);
	x = bind(sock, &server, sizeof(server));

	if (x<0)
	{
		close(sock);
		perror("NO SE PUEDE ENLAZAR");
		exit(1);
	}

	if (listen(sock, 5) < 0)
	{
		perror ("NO ESCUCHA");
		exit (1);
	}

	return sock;
}

int sock;
int acepta_conexion(sock)
{ struct sockaddr_in server;
	int adrl, x, flags;
	adrl = sizeof (struct sockaddr_in);
	x = accept (sock, &server, &adrl);
	return x;
}

/*********** cliente ***********************/

int socket_cliente(host, port)
char *host;
int port;
{
	int csock;
	struct sockaddr_in client;
	struct hostent *hp, *gethostbyname();
	bzero(&client, sizeof(client));
	client.sin_family = AF_INET;
	client.sin_port = htons(port);
	if (isdigit(host[0]))
		client.sin_addr.s_addr = inet_addr(host);
	else
	{
		hp = gethostbyname(host);
		if (hp == NULL)
		{ perror (" ¿A QUE HOST QUIERO CONECTAR? ");
			exit (1);
		}
		bcopy(hp->h_addr, &client.sin_addr, hp->h_length);
	}
	csock = socket(AF_INET, SOCK_STREAM, 0);
	if (csock < 0)
	{ perror ("NO SE PUEDE CREAR EL SOCKET");
		exit (1);
	}
	connect(csock, &client, sizeof(client));
	return csock;
}
