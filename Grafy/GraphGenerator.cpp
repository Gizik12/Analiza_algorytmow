#include "GraphGenerator.hpp"
#include "Dijkstra.hpp"

#include <random>
#include <cmath>
#include <cstdint>

uint32_t GenerateRandomNumber()
{
    random_device RandomDevice;
    mt19937 Generator(RandomDevice());
    uniform_int_distribution<uint32_t> Distribution(MinGeneratedNumber, MaxGeneratedNumber);

    return Distribution(Generator);
}

vector<vector<uint32_t>> GenerateRandomGraph_AdjacencyMatrix(uint32_t Vertices, double Density)
{
    vector<vector<uint32_t>> Graph(Vertices, vector<uint32_t>(Vertices, 0));
    uint32_t Edges = static_cast<uint32_t>(ceil(Vertices * Density));
    
    uint32_t NumberOfEdges = 0;
    while (NumberOfEdges < Edges)
    {
        for (uint32_t i = 0; i < Vertices; i++)
        {
            for (uint32_t j = i + 1; j < Vertices; j++)
            {
                if (Density < 1.0)
                {
                    if (NumberOfEdges >= Edges)
                    {
                        break;
                    }
                    if (GenerateRandomNumber() % 10 == 0)
                    {
                        if (Graph[i][j] <= 0)
                        {
                            Graph[i][j] = GenerateRandomNumber();
                            Graph[j][i] = Graph[i][j];
                            NumberOfEdges++;
                        }
                    }
                }
                else
                {
                    if (Graph[i][j] <= 0)
                    {
                        Graph[i][j] = GenerateRandomNumber();
                        Graph[j][i] = Graph[i][j];
                        NumberOfEdges++;
                    }
                }
            }
        }
    }

    return Graph;
}

vector<vector<GraphEdge>> GenerateRandomGraph_AdjacencyList(uint32_t Vertices, double Density)
{
    vector<vector<GraphEdge>> Graph(Vertices);
    uint32_t Edges = static_cast<uint32_t>(ceil(Vertices * Density));

    uint32_t NumberOfEdges = 0;
    while (NumberOfEdges < Edges)
    {
        for (uint32_t i = 0; i < Vertices; i++)
        {
            for (uint32_t j = i + 1; j < Vertices; j++)
            {
                if (Density < 1.0)
                {
                    if (NumberOfEdges >= Edges)
                    {
                        break;
                    }
                    if (GenerateRandomNumber() % 10 == 0)
                    {
                        for (const GraphEdge& GraphEdge : Graph[i])
                        {
                            if (GraphEdge.GetTargetVertex() == j)
                            {
                                continue;
                            }
                        }
                        uint32_t Weight = GenerateRandomNumber();
                        Graph[i].push_back(GraphEdge(Weight, j));
                        Graph[j].push_back(GraphEdge(Weight, i));
                        NumberOfEdges++;
                    }
                }
                else
                {
                    uint32_t Weight = GenerateRandomNumber();
                    Graph[i].push_back(GraphEdge(Weight, j));
                    Graph[j].push_back(GraphEdge(Weight, i));
                    NumberOfEdges++;
                }
            }
        }
    }

    return Graph;
}