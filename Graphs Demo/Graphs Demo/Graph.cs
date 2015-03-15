namespace Graphs_Demo
{
    using System.Collections.Generic;

    public class Graph
    {
        public Graph()
        {
            this.Nodes = new Dictionary<string, Node>();
        }

        public IDictionary<string, Node> Nodes { get; private set; }

        public void AddNode(Node node)
        {
            this.Nodes[node.Name] = node;
        }
    }
}
