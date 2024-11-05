#include<iostream>
using namespace std;
// This class is made to implement floyads algorithim to find the shortest distnace from source to crystal
const int INF = 100;
class Floyad_Algo
{
public:
    // Function to calculate shortest distance from vertex zero to crystal_vertex
    int* FloydsAlgorithim(int** adj, int row, int col, int crystal_x, int crystal_y)
    {
        // Intialization
        int n = row * col;
        int** dist = new int* [n];
        int** prev = new int* [n];
        for (int i = 0; i < n; i++)
        {
            dist[i] = new int[n];
            prev[i] = new int[n];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = adj[i][j];
                prev[i][j] = -1;
                if (adj[i][j] == 0 && i != j)
                {
                    dist[i][j] = INF;
                }
            }
        }

        // Floyads Algorithm
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        prev[i][j] = k;
                    }
                }
            }
        }

        // Prints the shortest distance
        int default_x = 0;
        int default_y = 0;
        int crystal_vertex = crystal_x * col + crystal_y;
        int default_vertex = default_x * col + default_y;
        cout << endl << " Source-Vertex : " << default_vertex << "  " << " Destination-Vertex : " << crystal_vertex << "    " << endl;
        cout << "Shortest distance from default location to crystal: " << dist[default_vertex][crystal_vertex] << endl;

        // This loop store the vertexs of shortest path and return 
        int* path = new int[n];
        int curr_vertex = crystal_vertex;
        int* traces = new int[n];
        for (int i = 0; i < n; i++)
        {
            traces[i] = -1;
        }
        int i = n - 1;
        while (curr_vertex != default_vertex && curr_vertex > 0)
        {
            path[i] = curr_vertex;
            traces[i] = curr_vertex;
            int prev_vertex = prev[default_vertex][curr_vertex];
            curr_vertex = prev_vertex;
            i--;
        }
        traces[i] = default_vertex;
        i--;
        path[i] = default_vertex;
        delete[] path;
        return traces;
    }

    // Function to calculate shortest distance from custom_vertex to crystal_vertex
    int* FloydsAlgorithim(int** adj, int row, int col, int src_x, int src_y, int crystal_x, int crystal_y)
    {
        // Intializing
        int n = row * col;
        int** dist = new int* [n];
        int** prev = new int* [n];
        for (int i = 0; i < n; i++)
        {
            dist[i] = new int[n];
            prev[i] = new int[n];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = adj[i][j];
                prev[i][j] = -1;
                if (adj[i][j] == 0 && i != j)
                {
                    dist[i][j] = INF;
                }
            }
        }

        // Floyads Algorithim
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        prev[i][j] = k;
                    }
                }
            }
        }

        // Prints the shortest distance
        int default_x = src_x;
        int default_y = src_y;
        int crystal_vertex = crystal_x * col + crystal_y;
        int default_vertex = default_x * col + default_y;
        cout << endl << " Source-Vertex : " << default_vertex << "  " << " Destination-Vertex : " << crystal_vertex << "    " << endl;
        cout << "Shortest distance from default location to crystal: " << dist[default_vertex][crystal_vertex] << endl;

        // This loop store the vertexs of shortest path and return 
        int* path = new int[n];
        int curr_vertex = crystal_vertex;
        int* traces = new int[n];
        for (int i = 0; i < n; i++)
        {
            traces[i] = -1;
        }
        int i = n - 1;
        while (curr_vertex != default_vertex && curr_vertex > 0)
        {
            path[i] = curr_vertex;
            traces[i] = curr_vertex;
            int prev_vertex = prev[default_vertex][curr_vertex];
            curr_vertex = prev_vertex;
            i--;
        }
        traces[i] = default_vertex;
        i--;
        path[i] = default_vertex;
        delete[] path;
        return traces;
    }
};