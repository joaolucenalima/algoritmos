#include <iostream>
#include <list>
using namespace std;

#define INT_MAX 99999

struct edge
{
	int orig;
	int dest;
	int weigth;
};

void show_shortest_path(int parent[], int end)
{
	if (parent[end] == -1)
	{
		cout << end;
		return;
	}
	show_shortest_path(parent, parent[end]);
	cout << " " << parent[end];
}

void shortest_path_dijkstra(list<edge> adj[], int vertices, int start, int end)
{
	bool visited[vertices];
	int distance[vertices], parent[vertices];

	for (int u = 0; u < vertices; u++)
	{
		visited[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
	distance[start] = 0;

	int v = start;
	while (visited[end] == false)
	{
		visited[v] = true;
		list<edge>::iterator p;
		for (p = adj[v].begin(); p != adj[v].end(); p++)
		{
			int dest = p->dest;
			int weight = p->weigth;
			if (distance[dest] > distance[v] + weight)
			{
				distance[dest] = distance[v] + weight;
				parent[dest] = v;
			}
		}
		v = start;
		int dist = INT_MAX;
		for (int u = 0; u < vertices; u++)
		{
			if (visited[u] == false && dist > distance[u])
			{
				dist = distance[u];
				v = u;
			}
		}
	}

	cout << "Menor caminho:";
	show_shortest_path(parent, end);

	cout << "\nCusto: " << distance[end] << endl;
}

int main()
{
	int vertices, directed;
	cin >> vertices >> directed;

	int start, end;
	cin >> start >> end;

	list<edge> adj[vertices];

	int v1, v2, w;
	while (cin >> v1 >> v2 >> w && v1 != -1 && v2 != -1 && w != -1)
	{
		adj[v1].push_back({v1, v2, w});
		if (directed == 0)
			adj[v2].push_back({v2, v1, w});
	}

	shortest_path_dijkstra(adj, vertices, start, end);
}