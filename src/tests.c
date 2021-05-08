#include <assert.h>
#include <stdio.h>
#include "../include/graph.h"


void testBuildGraph() {
    int size = 4;
    graph newGraph = createGraph(size);
    assert(getSize(newGraph) == size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            assert(newGraph->matrix[i][j] == 0);
        }

    }
    deinitializeGraph(newGraph);
}

void testAddEdge() {
    int size = 4;
    graph newGraph = createGraph(size);
    addEdge(0, 1, newGraph);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (((i == 0) && (j == 1)) || ((i == 1) && (j == 0))) assert(newGraph->matrix[i][j] == 1);
            else assert(newGraph->matrix[i][j] == 0);
        }

    }
    addEdge(1, 2, newGraph);
    addEdge(1, 3, newGraph);
    assert(newGraph->matrix[1][2] == 1);
    assert(newGraph->matrix[2][1] == 1);
    assert(newGraph->matrix[1][3] == 1);
    assert(newGraph->matrix[3][1] == 1);

    deinitializeGraph(newGraph);
}

void testRemoveEdge() {
    int size = 4;
    graph newGraph = createGraph(size);
    addEdge(0, 1, newGraph);
    addEdge(1, 2, newGraph);
    addEdge(1, 3, newGraph);
    removeEdge(0, 1, newGraph);
    //int **test;
    //test = getMatrix(newGraph);
    assert(newGraph->matrix[0][1] == 0);
    assert(newGraph->matrix[1][0] == 0);
    assert(newGraph->matrix[1][2] == 1);
    assert(newGraph->matrix[2][1] == 1);
    assert(newGraph->matrix[1][3] == 1);
    assert(newGraph->matrix[3][1] == 1);

    deinitializeGraph(newGraph);
}

void testAddVertex() {
    int size = 4;
    graph newGraph = createGraph(size);


    addEdge(0, 1, newGraph);
    addEdge(1, 2, newGraph);
    addEdge(1, 3, newGraph);
    addVertex(newGraph);
    addEdge(2, 4, newGraph);
    //int **test;
    //test = getMatrix(newGraph);
    assert(getSize(newGraph) == 5);
    assert(newGraph->matrix[1][4] == 0);
    assert(newGraph->matrix[4][1] == 0);
    assert(newGraph->matrix[2][4] == 1);
    assert(newGraph->matrix[4][2] == 1);

    deinitializeGraph(newGraph);
}

void testRemoveVertex() {
    int size = 4;
    graph newGraph = createGraph(size);



    addEdge(0, 1, newGraph);
    addEdge(0, 3, newGraph);
    addEdge(1, 2, newGraph);
    addEdge(2, 3, newGraph);
    removeVertex(newGraph, 2);
    //int **test;
    //test = getMatrix(newGraph);
    assert(getSize(newGraph) == 3);
    assert(newGraph->matrix[0][2] == 1);
    assert(newGraph->matrix[2][0] == 1);
    assert(newGraph->matrix[1][2] == 0);
    assert(newGraph->matrix[2][1] == 0);

    deinitializeGraph(newGraph);
}

int runAllTests()
{
    testBuildGraph();
    testAddEdge();
    testRemoveEdge();
    testAddVertex();
    testRemoveVertex();
    return 0;
}

