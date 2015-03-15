namespace Graphs_Demo
{
    using System;

    public class Edge
    {
        private Node target;

        public Edge(Node target, int weight)
        {
            this.Target = target;
            this.Weight = weight;
        }

        public Node Target
        {
            get
            {
                return this.target;
            }

            private set
            {
                if (value == null)
                {
                    throw new ArgumentNullException("Target cannot be set to null!");
                }

                this.target = value;
            }
        }

        public int Weight { get; private set; }
    }
}
