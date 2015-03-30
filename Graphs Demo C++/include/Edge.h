#ifndef EDGE_H
#define EDGE_H

class Node;

class Edge
{
    private:
        Node& target;
        int weight;

    public:
        Edge(Node&, int);
        virtual ~Edge();
        Edge(const Edge& other);
        Edge& operator=(const Edge& other);

        Node& getTarget() const;
        int getWeight() const;
};

#endif // EDGE_H
