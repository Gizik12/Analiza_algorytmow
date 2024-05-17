#pragma once

#include <vector>
#include <cstdint>

using namespace std;

/** 
 * Klasa reprezentująca krawędź grafu. 
 *
 * Klasa opisuje jedną z krawędzi wierzchołka prowadzącą do kolejnego wierzchołka wraz z kosztem przejścia.
 */
class GraphEdge
{
public:
	/**
	 * Konstruktor klasy GraphEdge.
	 * 
	 * @param TargetVertex Wierzchołek, do którego prowadzi krawędź.
	 * @param Weight Koszt przejścia przez krawędź.
	 */
	GraphEdge(const uint32_t TargetVertex, const uint32_t Weight);

	uint32_t GetTargetVertex() const				{ return TargetVertex; }
	void SetTargetVertex(uint32_t NewTargetVertex)	{ TargetVertex = NewTargetVertex; }

	uint32_t GetWeight() const					{ return Weight; }
	void SetTargetWeight(uint32_t NewWeight)	{ Weight = NewWeight; }

private:
	uint32_t TargetVertex;
	uint32_t Weight;
};

/** 
 * Klasa reprezentująca algorytm Dijkstry.
 * 
 * Klasa szukająca najkrótszej ścieżki do każdego wierzchołka w grafie przy pomocy algorytmu Dijkstry.
 */
class ShortestPathFinder
{
public:
	/** 
	 * Konstruktor klasy ShortestPathFinder.
	 * 
	 * Reprezentacja grafu w postaci macierzy sąsiedztwa.
	 * 
	 * @param Graph Graf w postaci macierzy sąsiedztwa.
	 * @param StartingVertex Wierzchołek, dla którego wyznaczane są najkrótsze ścieżki do wszystkich pozostałych wierzchołków.
	 */
	ShortestPathFinder(const vector<vector<uint32_t>>& Graph, const uint32_t StartingVertex);

	/**
	 * Konstruktor klasy ShortestPathFinder.
	 *
	 * Reprezentacja grafu w postaci listy sąsiedztwa.
	 *
	 * @param Graph Graf w postaci listy sąsiedztwa.
	 * @param StartingVertex Wierzchołek, dla którego wyznaczane są najkrótsze ścieżki do wszystkich pozostałych wierzchołków.
	 */
	ShortestPathFinder(const vector<vector<GraphEdge>>& Graph, const uint32_t StartingVertex);

private:
	uint32_t Vertices;
};
