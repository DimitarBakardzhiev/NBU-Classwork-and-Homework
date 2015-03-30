#include <iostream>
#include <Node.h>
#include <Graph.h>
#include <map>
#include <algorithm>

using namespace std;

void setDistances(pair<string, Node&> node, map<string, int> dists)
{
    dists.insert(pair<string, int>(node.first, 12345));
}

int shortestPathDijkstra(const Graph& graph, string start, string end)
{
    map<string, int> distances;
    for_each(graph.getNodes().begin(), graph.getNodes().end(), setDistances);
}

int main()
{
    Node sofia("Sofia"), burgas("Burgas"), varna("Varna");

    sofia.addConnection(burgas, 400, true);
    burgas.addConnection(varna, 200, false);
    varna.addConnection(sofia, 450, true);

    Graph graph;
    graph.addNode(sofia);
    graph.addNode(burgas);
    graph.addNode(varna);

    cout << graph << endl;
    cout << "pesho" << endl;

    return 0;
}
