#include <stddef.h>

struct graphStruct {
    int** matrix; //матрица смежности размером size * size, меняется динамически
    int size; //размер нашей матрицы == количеству вершин
};

typedef struct graphStruct *graph;


graph createGraph(int size); //создание графа с количеством вершин и размером size
void addEdge(int vertex1, int vertex2, graph currentGraph); //добавление ребра между 2 вершинами
void removeEdge(int vertex1, int vertex2, graph currentGraph); //удаление ребра между 2 вершинами
void addVertex(graph currentGraph); //добавление вершины в граф
void removeVertex(graph currentGraph, int vertex); //удаление вершины из графа
void printGraphFile(graph currentGraph, FILE *outFile); //печать содержимого графа в файл
int getSize(graph currentGraph); //получение размера(количества вершин) графа
int** getMatrix(graph currentGraph); //получение матрицы смежности графа
void deinitializeGraph(graph currentGraph); //освобождение памяти