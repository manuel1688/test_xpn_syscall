#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

double get_time(void)
{
    struct timeval tp;
    struct timezone tzp;

    gettimeofday(&tp,&tzp);
    return((double) tp.tv_sec + .000001 * (double) tp.tv_usec);
}

int main(int argc, char *argv[]) {

	double t_bc,t_ac;

    t_bc = get_time();
   
    printf("argv[2]: %d\n", argv[2]);
    int fd = creat(argv[1], 0644);
    if(fd < 0) {
        printf("%d = creat('%s', %o)\n", fd, argv[1], 0644);
        return -1;
    }

    long mb = atoi(argv[2]);
    printf("File descriptor: %d\n", fd);
    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }
    close(fd);

    t_ac = get_time() - t_bc;

	printf("Bytes (KiB); Total time (ms); Read time (ms)\n") ;
	printf("%f;%f;%f\n", ((double)mb * (double)BUFF_SIZE) / ((double)KB), t_ac * 1000, t_aw * 1000);

    return 0; 
}
//gcc prueba_create.c -o prueba_creat



