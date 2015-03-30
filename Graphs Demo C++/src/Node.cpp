#include "Node.h"
#include <Edge.h>
#include <algorithm>
#include <iostream>

Node::Node(string name)
{
    this->name = name;
}

Node::~Node()
{
}

Node::Node(const Node& other)
{
    this->name = other.name;
    this->edges = other.edges;
}

Node& Node::operator=(const Node& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->edges = other.edges;
    }

    return *this;
}

void Node::addConnection(Node& other, int weight, bool isTwoWay)
{
    Edge connection(other, weight);
    this->edges.push_back(connection);

    if (isTwoWay)
    {
        Edge reversedConnection(*this, weight);
        other.edges.push_back(reversedConnection);
    }
}

void printEdges(Edge& edge)
{
    cout << edge.getTarget().getName() << " ";
}

ostream& operator<<(ostream& os, Node& obj)
{
    os << obj.name;
    cout << " -> ";
    for_each(obj.edges.begin(), obj.edges.end(), printEdges);

    return os;
}

string& Node::getName()
{
    return this->name;
}

list<Edge> Node::getEdges() const
{
    return this->edges;
}
