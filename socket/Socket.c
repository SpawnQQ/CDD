// Ficheros de cabecera
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/errno.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define PORT 5000 
int main(int argc, char **argv){
 
	 
		//Primer paso, definir variables
		extern int errno;
		int fd,fd2,longitud_cliente;

		//Se necesitan dos estructuras del tipo sockaddr
		//La primera guarda info del server
		//La segunda del cliente
		 struct sockaddr_in server;
		 struct sockaddr_in client;
		 
		//Configuracion del servidor
		 server.sin_family= AF_INET; //Familia TCP/IP
		 server.sin_port = htons((short) PORT); //Puerto
		 server.sin_addr.s_addr = INADDR_ANY; //Cualquier cliente puede conectarse
		 bzero(&(server.sin_zero),sizeof(server)); //Funcion que rellena con 0's
		 
		 //Paso 2, definicion de socket
		 if (( fd=socket(AF_INET,SOCK_STREAM,0) )<0){
			 perror("Error de apertura de socket");
			 exit(-1);
		 }
		 
		 //Paso 3, avisar al sistema que se creo un socket
		 if(bind(fd,(struct sockaddr*)&server, sizeof(server))) {
			 printf("error en bind() \n");
			 exit(-1);
		 }
		 
		 //Paso 4, establecer el socket en modo escucha
		if(listen(fd,5) < 0) {
			 printf("error en listen()\n", PORT, strerror(errno));
			 exit(-1);
		 }
		 
		 //Paso5, aceptar conexiones
		 while(1) {
			 longitud_cliente= sizeof(struct sockaddr_in);
			 /* A continuaciÃ³n la llamada a accept() */
			 if ((fd2 = accept(fd,(struct sockaddr *)&client,&longitud_cliente))==-1) {
				 printf("error en accept()\n");
				 exit(-1);
			 }
			 
			send(fd2,"Bienvenido a mi servidor.\n",26,0);
			 
			close(fd2); /* cierra fd2 */
		 }

		close(fd);
	

		//printf("NO se ingreso el puerto por parametro\n");
	
	 
	return 0;
 
}
