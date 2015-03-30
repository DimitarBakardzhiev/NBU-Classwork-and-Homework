namespace Graphs_Demo
{
    using System;
    using System.Collections.Generic;

    public class MainEntryPoint
    {
        private static string GetMinimumNotvisitedVertex(IDictionary<string, int> distances, ISet<string> set)
        {
            var minimum = new KeyValuePair<string, int>(string.Empty, int.MaxValue);
            foreach (var node in distances)
            {
                if (node.Value < minimum.Value && !set.Contains(node.Key))
                {
                    minimum = node;
                }
            }

            return minimum.Key;
        }

        private static IDictionary<string, int> SetInitialDistances(Graph graph, string start)
        {
            var distances = new Dictionary<string, int>();
            foreach (var node in graph.Nodes)
            {
                if (node.Key != start)
                {
                    distances[node.Key] = int.MaxValue;
                }
                else
                {
                    distances[node.Key] = 0;
                }
            }

            return distances;
        }

        public static int ShortestPathDijkstra(Graph graph, string start, string end)
        {
            var distances = SetInitialDistances(graph, start);

            var visitedNodesSet = new HashSet<string>();

            while (!visitedNodesSet.Contains(end))
            {
                var minVertex = GetMinimumNotvisitedVertex(distances, visitedNodesSet);
                visitedNodesSet.Add(minVertex);

                foreach (var edge in graph.Nodes[minVertex].Edges)
                {
                    if (visitedNodesSet.Contains(edge.Target.Name))
                    {
                        continue;
                    }

                    if (distances[minVertex] + edge.Weight < distances[edge.Target.Name])
                    {
                        distances[edge.Target.Name] = distances[minVertex] + edge.Weight;
                    }
                }
            }

            return distances[end];
        }

        public static void Main()
        {
            var graph = new Graph();

            var sofia = new Node("Sofia");
            var burgas = new Node("Burgas");
            var plovdiv = new Node("Plovdiv");
            var varna = new Node("Varna");
            var ruse = new Node("Ruse");

            sofia.AddConnection(burgas, 400, true);
            sofia.AddConnection(plovdiv, 150, true);
            plovdiv.AddConnection(burgas, 300, true);
            burgas.AddConnection(varna, 200, false);
            varna.AddConnection(sofia, 450, true);
            ruse.AddConnection(varna, 150, true);
            ruse.AddConnection(sofia, 400, false);

            graph.AddNode(sofia);
            graph.AddNode(plovdiv);
            graph.AddNode(burgas);
            graph.AddNode(varna);
            graph.AddNode(ruse);

            Console.WriteLine(ShortestPathDijkstra(graph, sofia.Name, ruse.Name));
        }
    }
}
