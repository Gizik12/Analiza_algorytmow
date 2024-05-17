#include "Dijkstra.hpp"
#include "GraphGenerator.hpp"

#include <limits>
#include <queue>
#include <iostream>
#include <cstdint>

#define INF std::numeric_limits<uint32_t>::max()

GraphEdge::GraphEdge(const uint32_t Weight, const uint32_t TargetVertex)
{
    this->TargetVertex = TargetVertex;
    this->Weight = Weight;
}

ShortestPathFinder::ShortestPathFinder(const std::vector<std::vector<uint32_t>>& Graph, const uint32_t StartingVertex)
{
    Vertices = static_cast<uint32_t>(Graph.size());

    std::vector<uint32_t> DistanceToTheVertex(Vertices, INF);
    std::vector<bool> bHasTheVertexBeenVisited(Vertices, false);

    std::priority_queue<std::pair<uint32_t, uint32_t>, std::vector<std::pair<uint32_t, uint32_t>>, std::greater<std::pair<uint32_t, uint32_t>>> VertexQueue;

    DistanceToTheVertex[StartingVertex] = 0;
    VertexQueue.push({0, StartingVertex});

    while (!VertexQueue.empty())
    {
        uint32_t CurrentVertex = VertexQueue.top().second;
        VertexQueue.pop();

        if (bHasTheVertexBeenVisited[CurrentVertex])
        {
            continue;
        }

        bHasTheVertexBeenVisited[CurrentVertex] = true;

        for (uint32_t NextVertex = 0; NextVertex < Vertices; NextVertex++)
        {
            if (Graph[CurrentVertex][NextVertex] != 0 && !bHasTheVertexBeenVisited[NextVertex])
            {
                uint32_t DistanceToNextVertex = DistanceToTheVertex[CurrentVertex] + Graph[CurrentVertex][NextVertex];
                if (DistanceToNextVertex < DistanceToTheVertex[NextVertex])
                {
                    DistanceToTheVertex[NextVertex] = DistanceToNextVertex;
                    VertexQueue.push({DistanceToTheVertex[NextVertex], NextVertex});
                }
            }
        }
    }
}

ShortestPathFinder::ShortestPathFinder(const std::vector<std::vector<GraphEdge>>& Graph, const uint32_t StartingVertex)
{
    Vertices = static_cast<uint32_t>(Graph.size());

    std::vector<uint32_t> DistanceToTheVertex(Vertices, INF);
    std::vector<bool> bHasTheVertexBeenVisited(Vertices, false);

    std::priority_queue<std::pair<uint32_t, uint32_t>, std::vector<std::pair<uint32_t, uint32_t>>, std::greater<std::pair<uint32_t, uint32_t>>> VertexQueue;

    DistanceToTheVertex[StartingVertex] = 0;
    VertexQueue.push({0, StartingVertex});

    while (!VertexQueue.empty())
    {
        uint32_t CurrentVertex = VertexQueue.top().second;
        VertexQueue.pop();

        if (bHasTheVertexBeenVisited[CurrentVertex])
        {
            continue;
        }

        bHasTheVertexBeenVisited[CurrentVertex] = true;

        for (const GraphEdge& GraphEdge : Graph[CurrentVertex])
        {
            uint32_t NextVertex = GraphEdge.GetTargetVertex();
            uint32_t Weight = GraphEdge.GetWeight();

            if (!bHasTheVertexBeenVisited[NextVertex])
            {
                uint32_t DistanceToNextVertex = DistanceToTheVertex[CurrentVertex] + Weight;
                if (DistanceToNextVertex < DistanceToTheVertex[NextVertex])
                {
                    DistanceToTheVertex[NextVertex] = DistanceToNextVertex;
                    VertexQueue.push({DistanceToTheVertex[NextVertex], NextVertex});
                }
            }
        }
    }
}
