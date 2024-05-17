#pragma once

#include <limits>
#include <stdint.h>
#include <vector>
#include <cstdint>

using namespace std;

const uint32_t MinGeneratedNumber = 1;
const uint32_t MaxGeneratedNumber = 10;

class GraphEdge;

/**
 * Generuje losowe liczby ca³kowite z zakresu [FirstGeneratedNumber, LastGeneratedNumber].
 * 
 * @return Losowa liczba ca³kowita z zakresu [FirstGeneratedNumber, LastGeneratedNumber].
 */
uint32_t GenerateRandomNumber();

/**
 * Generuje losowy graf o okreœlonej gêstoœci reprezentowany w postaci macierzy s¹siedztwa.
 * 
 * @param Verticies Liczba wierzcho³ków generowanego grafu.
 * @param Density Gêstoœæ generowanego grafu.
 * @return Graf reprezentowany w postaci macierzy s¹siedztwa.
 */
vector<vector<uint32_t>> GenerateRandomGraph_AdjacencyMatrix(uint32_t Vertices, double Density);

/**
 * Generuje losowy graf o okreœlonej gêstoœci reprezentowany w postaci listy s¹siedztwa.
 * 
 * @param Verticies Liczba wierzcho³ków generowanego grafu.
 * @param Density Gêstoœæ generowanego grafu.
 * @return Graf reprezentowany w postaci listy s¹siedztwa.
 */
vector<vector<GraphEdge>> GenerateRandomGraph_AdjacencyList(uint32_t Vertices, double Density);