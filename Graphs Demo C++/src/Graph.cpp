#include "Graph.h"
#include <iostream>
#include <algorithm>

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}

Graph::Graph(const Graph& other)
{
    this->nodes = other.nodes;
}

Graph& Graph::operator=(const Graph& other)
{
    if (this != &other)
    {
        this->nodes = other.nodes;
    }

    return *this;
}

map<string, Node&> Graph::getNodes() const
{
    return this->nodes;
}

void Graph::addNode(Node& obj)
{
    this->nodes.insert(pair<string, Node&>(obj.getName(), obj));
}

void printAllNodes(pair<string, Node&> node)
{
    cout << node.second << endl;
}

ostream& operator<<(ostream& os, const Graph& obj)
{
    for_each(obj.getNodes().begin(), obj.getNodes().end(), printAllNodes);

    return os;
}
