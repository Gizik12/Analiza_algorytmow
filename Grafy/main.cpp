#include <iostream>
#include <chrono>
#include <vector>

#include "Dijkstra.hpp"
#include "GraphGenerator.hpp"

using namespace std;

int main() 
{
    vector<uint32_t> numVerticesList = {10, 50, 100, 500, 1000};
    vector<double> densities = {0.25, 0.5, 0.75, 1.0};
    uint16_t repetition = 100;

    chrono::high_resolution_clock::time_point operationStart;
    chrono::high_resolution_clock::time_point operationEnd;

    for (uint32_t numVertices : numVerticesList) {
        for (double density : densities) {
            cout << "Liczba wierzcholkow: " << numVertices << endl;
            cout << "Gestosc grafu: " << density << endl;

            vector<vector<uint32_t>> adjacencyMatrixGraph = GenerateRandomGraph_AdjacencyMatrix(numVertices, density);
            vector<vector<GraphEdge>> adjacencyListGraph = GenerateRandomGraph_AdjacencyList(numVertices, density);

            double summedTimeMatrix = 0.0;
            double summedTimeList = 0.0;

            for (uint16_t i = 0; i < repetition; i++) {
                operationStart = chrono::high_resolution_clock::now();
                ShortestPathFinder(adjacencyMatrixGraph, 0);
                operationEnd = chrono::high_resolution_clock::now();
                summedTimeMatrix += chrono::duration_cast<chrono::microseconds>(operationEnd - operationStart).count();
            }
            cout << "Sredni czas dla macierzy sasiedztwa: " << summedTimeMatrix / repetition << " us" << endl;

            for (uint16_t i = 0; i < repetition; i++) {
                operationStart = chrono::high_resolution_clock::now();
                ShortestPathFinder(adjacencyListGraph, 0);
                operationEnd = chrono::high_resolution_clock::now();
                summedTimeList += chrono::duration_cast<chrono::microseconds>(operationEnd - operationStart).count();
            }
            cout << "Sredni czas dla listy sasiedztwa: " << summedTimeList / repetition << " us" << endl;

            cout << endl;
        }
    }

    return 0;
}
