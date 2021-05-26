#include <stdlib.h>
#include <stdio.h>
#include "../include/graph.h"

graph createGraph(int size) {
    graph newGraph;
    newGraph = malloc(sizeof(*newGraph));
    newGraph->size = size;
    newGraph->matrix = (int **)malloc(size*sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        newGraph->matrix[i] = (int *)malloc(size*sizeof(int));
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            newGraph->matrix[i][j] = 0;
        }
    }
    return newGraph;
}

void deinitializeMatrix(int **graph, int size) {
    for(int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);
}

void addEdge(int vertex1, int vertex2, graph currentGraph) {
    if ((vertex2 < currentGraph->size) && (vertex1 < currentGraph->size)) {
        currentGraph->matrix[vertex1][vertex2] = 1;
        currentGraph->matrix[vertex2][vertex1] = 1;
    }
}

void removeEdge(int vertex1, int vertex2, graph currentGraph) {
    if ((vertex2 < currentGraph->size) && (vertex1 < currentGraph->size)) {
        currentGraph->matrix[vertex1][vertex2] = 0;
        currentGraph->matrix[vertex2][vertex1] = 0;
    }
}

void addVertex(graph currentGraph) {
    int size = currentGraph->size + 1;
    int **array = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        array[i] = (int *)malloc(size*sizeof(int));
    }


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((j == size - 1) || (i == size - 1)) array[i][j] = 0;
            else array[i][j] = currentGraph->matrix[i][j];
        }
    }


    deinitializeMatrix(currentGraph->matrix, currentGraph->size);
    currentGraph->matrix = array;
    currentGraph->size = size;
}

void removeVertex(graph currentGraph, int vertex) {
    int size = currentGraph->size - 1;
    int **array = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        array[i] = (int *)malloc(size*sizeof(int));
    }

    int offsetI = 0;
    for (int i = 0; i < size; i++)
    {
        if (i >= vertex) offsetI = 1;
        for (int j = 0; j < size; j++)
        {

            if (j >= vertex) {
                array[i][j] = currentGraph->matrix[i + offsetI][j + 1];
            }
            else array[i][j] = currentGraph->matrix[i + offsetI][j];

        }
    }

    deinitializeMatrix(currentGraph->matrix, currentGraph->size);
    currentGraph->matrix = array;
    currentGraph->size = size;
}

void printGraphFile(graph currentGraph, FILE *outFile) {
    fprintf(outFile, "size %d: ", currentGraph->size);
    fprintf(outFile,"\n");
    for (int i = 0; i < currentGraph->size; i++)
    {
        for (int j = 0; j < currentGraph->size; j++)
        {
            fprintf(outFile, " %d ", currentGraph->matrix[i][j]);
        }
        fprintf(outFile,"\n");
    }
}

int getSize(graph currentGraph){
    return currentGraph->size;
}

int** getMatrix(graph currentGraph) {
    return  currentGraph->matrix;
}

void deinitializeGraph(graph currentGraph) {
    deinitializeMatrix(currentGraph->matrix, currentGraph->size);
    free(currentGraph);
}