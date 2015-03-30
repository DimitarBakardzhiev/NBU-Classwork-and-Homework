#include "Edge.h"

Edge::Edge(Node& target, int weight) : target(target)
{
    this->weight = weight;
}

Edge::~Edge()
{
}

Edge::Edge(const Edge& other) : target(other.target)
{
    this->weight = other.weight;
}

Edge& Edge::operator=(const Edge& other)
{
    if (this == &other)
    {
        //this->target = other.target;
    }

    return *this;
}

Node& Edge::getTarget() const
{
    return this->target;
}

int Edge::getWeight() const
{
    return this->weight;
}
