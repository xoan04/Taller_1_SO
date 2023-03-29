#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *file;
    file = fopen("test2.in", "r");
    if (file == NULL)
    {
        printf("Error al abrir archivo");
        return 1;
    }
    int size;
    int *array=NULL;
    fscanf(file, "%d", &size);
    array = (int *)malloc(sizeof(int) * size);
    if (array == NULL)
    {
        printf("Error al alocar memoria");
        exit (1);
    }
    double timespent=0.0;
    long int sum=0;
    int frequencia=0;
    int maxfreq=0;
    int maxnum=0;
    clock_t begin =clock();
    for (int i=0; i<size; i++)
    {
        frequencia=1;
        fscanf(file, "%d", &array[i]);
        sum += array[i];
     
    }
    clock_t end =clock();
    timespent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("La suma de los elementos es: %ld\n", sum);
    printf("Tiempo: %f\n",timespent);
    fclose(file);
    free(array);

    return 0;
}