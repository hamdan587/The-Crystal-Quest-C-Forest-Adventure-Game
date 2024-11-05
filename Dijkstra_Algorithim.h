#include<iostream>
using namespace std;
// This class is made to implement Dijkstra algorithim to find the shortest distnace from source to crystal
class Dijkstar
{
public:
    // Function to calculate shortest distance from vertex zero to crystal_vertex
    int* Dijkstra(int** arr, int rows, int cols, int crystal_x, int crystal_y)
    {
        // Intialization
        int n = rows * cols;
        int* dist = new int[n];
        int* prev = new int[n];
        bool* visited = new bool[n];

        for (int i = 0; i < n; i++)
        {
            dist[i] = INF;
            visited[i] = false;
        }

        // Source vertex can be changed from here
        int source = 0;
        dist[source] = 0;

        queue<int> q;
        q.push(source);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            for (int v = 0; v < n; v++)
            {
                if (arr[u][v] != 0)
                {
                    int alt = dist[u] + arr[u][v];
                    if (alt < dist[v])
                    {
                        dist[v] = alt;
                        prev[v] = u;
                        q.push(v);
                    }
                }
            }
        }

        // To print shortest distance
        int crystal_vertex = crystal_x * cols + crystal_y;
        cout << endl << " Source-Vertex : " << source << "  " << " Destination-Vertex : " << crystal_vertex << "    " << endl;
        cout << "Shortest distance from source to crystal: " << dist[crystal_vertex] << endl;

        // print the shortest path from source to crystal
        int* path = new int[n];
        for (int i = 0; i < n; i++)
        {
            path[i] = -1;
        }
        int current = crystal_vertex;
        int index = 0;
        while (current != source)
        {
            path[index++] = current;
            current = prev[current];
        }
        path[index++] = source;
        cout << "Shortest path from source to crystal: ";
        for (int i = index - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }
        int* traces = new int[n];
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            traces[i] = -1;
        }
        for (int i = index - 1; i >= 0; i--)
        {
            traces[j] = path[i];
            j++;
        }
        cout << endl;
        return traces;
    }

    // Function to calculate shortest distance from custom_vertex to crystal_vertex
    int* Dijkstra(int** arr, int rows, int cols, int src_x, int src_y, int crystal_x, int crystal_y)
    {
        // Initialize arrays to all 
        int n = rows * cols;
        int* dist = new int[n];
        int* prev = new int[n];
        bool* visited = new bool[n];

        for (int i = 0; i < n; i++)
        {
            prev[i] = -2;
            dist[i] = INF;
            visited[i] = false;
        }

        int* path = new int[n];
        int* traces = new int[n];
        for (int i = 0; i < n; i++)
        {
            path[i] = -1;
            traces[i] = -1;
        }

        // Calculate source vertex index
        int source = src_x * cols + src_y;
        dist[source] = 0;

        queue<int> q;
        q.push(source);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            for (int v = 0; v < n; v++)
            {
                if (arr[u][v] != 0)
                {
                    int alt = dist[u] + arr[u][v];
                    if (alt < dist[v])
                    {
                        dist[v] = alt;
                        prev[v] = u;
                        q.push(v);
                    }
                }
            }
        }

        // Prints the shortest distance 
        int crystal_vertex = crystal_x * cols + crystal_y;
        cout << endl << " Source-Vertex : " << source << "  " << " Destination-Vertex : " << crystal_vertex << "    " << endl;
        cout << "Shortest distance from source to crystal: " << dist[crystal_vertex] << endl;

        // Store the vertex of shortest distance
        int index = 0;
        int current = crystal_vertex;
        while (current != -2) // modify the loop condition to stop when the current vertex is the source vertex (-1)
        {
            path[index++] = current;
            current = prev[current];
        }
        cout << "Shortest path from source to crystal: ";
        for (int i = index - 1; i >= 0; i--)
        {
            if (path[i] != -1)
            {
                cout << path[i] << " ";
            }
        }
        for (int i = index - 1, j = 0; i >= 0; i--, j++)
        {
            traces[j] = path[i];
        }
        cout << endl;
        return traces;
    }
};