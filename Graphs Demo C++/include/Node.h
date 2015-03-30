#ifndef NODE_H
#define NODE_H

#include <string>
#include <list>
#include <Edge.h>

using namespace std;

class Node
{
    private:
        string name;
        list<Edge> edges;

    public:
        Node(string name);
        virtual ~Node();
        Node(const Node& other);
        Node& operator=(const Node& other);

        void addConnection(Node&, int, bool);

        friend ostream& operator<<(ostream& os, Node&);

        string& getName();
        list<Edge> getEdges() const;
};

#endif // NODE_H
