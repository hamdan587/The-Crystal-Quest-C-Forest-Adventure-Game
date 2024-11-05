// This class is made to implement the Kurskal Algorithim
class Kurskal
{
public:
    // Function find the minimum spanning tree using Kurkals algorithim
    void Kruskals_Algo(int** adj, int ROWS, int COLS)
    {
        // Create array to store edges
        int** edges = new int* [ROWS * COLS];
        for (int i = 0; i < ROWS * COLS ; i++)
        {
            edges[i] = new int[3];
        }
        int count = 0;

        // Add all edges to the array
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = i + 1; j < COLS; j++)
            {
                if (adj[i][j] != 0)
                {
                    edges[count][0] = adj[i][j];
                    edges[count][1] = i;
                    edges[count][2] = j;
                    count++;
                }
            }
        }

        // Sort the edges in ascending order of weight
        sortEdges(edges, count);

        // Create a parent array for disjoint sets
        int* parent = new int[ROWS];
        for (int i = 0; i < ROWS; i++)
        {
            parent[i] = i;
        }

        // Create an array to store the edges in the MST
        int** mst_edges = new int* [ROWS - 1];
        for (int i = 0; i < ROWS - 1; i++)
        {
            mst_edges[i] = new int[2];
        } 
        int mst_count = 0;

        // Loop through all edges and add them to the MST if they do not form a cycle
        for (int i = 0; i < count; i++)
        {
            int u = edges[i][1];
            int v = edges[i][2];

            int set_u = findSet(parent, u);
            int set_v = findSet(parent, v);

            if (set_u != set_v)
            {
                mst_edges[mst_count][0] = u;
                mst_edges[mst_count][1] = v;
                mst_count++;
                unionSet(parent, set_u, set_v);
            }
        }

        // Print the edges of the MST
        cout << "Minimum Spanning Tree:\n";
        for (int i = 0; i < mst_count; i++)
        {
            cout << mst_edges[i][0] << " - " << mst_edges[i][1] << "   " << adj[mst_edges[i][0]][mst_edges[i][1]] << endl;
        }
    }

private:
    void sortEdges(int**edges, int count)
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (edges[i][0] > edges[j][0])
                {
                    int temp1 = edges[i][0];
                    int temp2 = edges[i][1];
                    int temp3 = edges[i][2];
                    edges[i][0] = edges[j][0];
                    edges[i][1] = edges[j][1];
                    edges[i][2] = edges[j][2];
                    edges[j][0] = temp1;
                    edges[j][1] = temp2;
                    edges[j][2] = temp3;
                }
            }
        }
    }

    int findSet(int* parent, int vertex)
    {
        if (parent[vertex] != vertex)
        {
            parent[vertex] = findSet(parent, parent[vertex]);
        }

        return parent[vertex];
    }

    void unionSet(int* parent, int set_u, int set_v)
    {
        parent[set_u] = set_v;
    }
};