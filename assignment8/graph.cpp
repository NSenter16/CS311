#include "graph.h"

// @brief Construct a Graph with the given number of vertices.
// @param nV The number of vertices in the graph.
Graph::Graph(int nV)
{
    // TODO: Add your code here
}

// @brief destructor
Graph::~Graph()
{
    // TODO: Add your code here
}

// @brief add a vertex to the graph
void Graph::addVertex(Vertex v)
{
    // TODO: Add a vertex to the vertex vector
    // TODO: Add an empty list to the adjacency list
}

// @brief add a directed edge v1->v2 to the graph
void Graph::addDirectedEdge(int v1, int v2, float weight)
{
    // TODO: Add an edge to the adjacency list of v1
}

// @brief add an undirected edge to the graph
void Graph::addUndirectedEdge(int v1, int v2, float weight)
{
    // TODO: Add edge v1->v2
    // TODO: Add edge v2->v1
}

// @brief the number of outgoing edges from a vertex
int Graph::outDegree(int v)
{
    // TODO: Add code here
    return 0;
}

// @brief depth first search from vertex v
vector<int> Graph::DepthFirstSearch(int v)
{
    // TODO: Implement the depth first search algorithm
    // Add the vertex ID to a vector when it is visited
}

// @brief breadth first search from a vertex
vector<int> Graph::BreadthFirstSearch(int v)
{
    // TODO: Implement the breadth first search algorithm
    // Add the vertex ID to a vector when it is visited
}

/**
 * @brief Check if the graph has cycles
 * @return true if the graph has cycles
 */
bool Graph::checkCycle()
{
    // TODO: Implement the algorithm to check if the graph has cycles
    // Assume an undirected graph
    return false;
}

// @brief print the graph
void Graph::printGraph()
{
    cout << "Graph:" << endl;
    for (int i = 0; i < numVerts; i++)
    {
        cout << i << ": ";
        for(auto j = adjList[i].begin(); j != adjList[i].end(); ++j)
        {
            cout << (*j).to_vertex << " " ;
        }
        cout << endl;
    }
    cout << endl;
}
