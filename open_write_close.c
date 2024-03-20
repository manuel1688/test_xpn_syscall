#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include "all_system.h"

// KB es una constante que se define como 1024
#define KB  (1024)

// BUFF_SIZE es una constante que se define como 1*MB
#define BUFF_SIZE (1*MB)

//Se define un arreglo de caracteres llamado buffer de tamaño BUFF_SIZE
char buffer[BUFF_SIZE] ; 

double get_time(void)
{
    struct timeval tp;
    struct timezone tzp;

    gettimeofday(&tp,&tzp);
    return((double) tp.tv_sec + .000001 * (double) tp.tv_usec);
}

int main(int argc, char *argv[]) {

	double t_bc,t_ac,t_bw,t_aw;

    /*
        Se llena el buffer con el caracter 'a'
        se llena hasta el tamaño BUFF_SIZE
    */
    memset(buffer, 'a', BUFF_SIZE);

    t_bc = get_time();
   
    int fd = creat(argv[1], 0644);
    if(fd < 0) {
        printf("%d = creat('%s', %o)\n", fd, argv[1], 0644);
        return -1;
    }
    t_bw = get_time();

    /* 
        Se convierte el segundo argumento a un entero
        el cual respresenta la cantidad de megabytes que 
        se van a escribir.
    */
    long mb = atoi(argv[2]);
    
    /*
        Se escribe 1MB de texto con caracteres 'a' n veces
        Según se defina en el segundo argumento
    */
    for (int i = 0; i < mb; i++)
	{
		ret = write(fd, buffer, BUFF_SIZE);
	}

    t_aW = get_time() - t_aw;

    close(fd);

    t_ac = get_time() - t_bc;

	printf("Bytes (KiB); Total time (ms); Read time (ms)\n") ;
	printf("%f;%f;%f\n", ((double)mb * (double)BUFF_SIZE) / ((double)KB), t_ac * 1000, t_aw * 1000);

    return 0; 
}
//gcc prueba_create.c -o prueba_creat



