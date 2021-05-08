#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "../test/tests.h"

/*Демонстрационная программа создаёт граф размера N (задается первым аргументом конмадной строки)
 * затем прочтём K (второй аргумент) пар переходов между вершинами из файла edges.txt (3 аргумент)
 * и после этого заполним матрицу смежности. Напечатаем содержимое графа в файл out.txt (4 аргумет)
 */
int main(int argc, char *argv[]) {
    runAllTests();
    if (argc != 5) {
        printf("\nWrong command line arguments\n");
        return -1;
    }
    int N = *argv[1] - '0';
    int K = *argv[2] - '0';
    K *= 2;

    int *numbers = (int *)malloc(K*sizeof(int *));
    FILE *edgesFile;
    FILE *outFile;

    edgesFile = fopen(argv[3], "r");
    for (int i = 0; !feof(edgesFile); i++) {
        fscanf(edgesFile, "%d", &numbers[i]);
    }
    graph currentGraph = createGraph(N);
    for (int k = 0; k < K; k += 2) {
        addEdge(numbers[k], numbers[k+1], currentGraph);
    }
    free(numbers);
    fclose(edgesFile);

    outFile = fopen(argv[4], "w");
    printGraphFile(currentGraph, outFile);
    fclose(outFile);

    deinitializeGraph(currentGraph);
    return 0;
}