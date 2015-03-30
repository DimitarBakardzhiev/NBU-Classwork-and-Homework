namespace Graphs_Demo
{
    using System;
    using System.Collections.Generic;

    public class Node
    {
        private string name;
        private IList<Edge> edges;

        public Node(string name)
        {
            this.Name = name;
            this.edges = new List<Edge>();
        }

        public string Name
        {
            get
            {
                return this.name;
            }

            private set
            {
                if (string.IsNullOrEmpty(value))
                {
                    throw new ArgumentException("Name cannot be an empty string!");
                }

                this.name = value;
            }
        }

        public IList<Edge> Edges
        {
            get
            {
                return this.edges;
            }
        }

        public void AddConnection(Node target, int weight, bool isTwoWay)
        {
            if (this == target)
            {
                throw new ArgumentException("Cannot add a connection to the same node!");
            }

            var edge = new Edge(target, weight);
            this.edges.Add(edge);

            if (isTwoWay)
            {
                var oppositeEdge = new Edge(this, weight);
                target.edges.Add(oppositeEdge);
            }
        }
    }
}
