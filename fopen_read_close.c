#include "all_system.h"
#include <sys/time.h>



#define KB  (1024)

#define BUFF_SIZE (1*MB)
char buffer[BUFF_SIZE] ; 


double get_time(void)
{
    struct timeval tp;
    struct timezone tzp;

    gettimeofday(&tp,&tzp);
    return((double) tp.tv_sec + .000001 * (double) tp.tv_usec);
}

int main ( int argc, char *argv[] )
{
	if (argc < 3)
	{
		printf("\n") ;
		printf(" Usage: %s <full path> <megabytes to read>\n", argv[0]) ;
		printf("\n") ;
		printf(" Example:") ;
		printf(" %s /tmp/expand/test_1 2\n", argv[0]);
		printf("\n") ;
		return -1 ;
	}	

	FILE *file = fopen(argv[1], "r+");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Aquí puedes leer o escribir en el archivo
    int fd = fileno(file);
    close(fd);  // No olvides cerrar el archivo cuando hayas terminado
    return 0;
}
