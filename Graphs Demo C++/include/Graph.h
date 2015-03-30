#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <Node.h>

class Graph
{
    private:
        map<string, Node&> nodes;

    public:
        Graph();
        virtual ~Graph();
        Graph(const Graph& other);
        Graph& operator=(const Graph& other);

        map<string, Node&> getNodes() const;
        void addNode(Node&);

        friend ostream& operator<<(ostream&, const Graph&);
};

#endif // GRAPH_H
