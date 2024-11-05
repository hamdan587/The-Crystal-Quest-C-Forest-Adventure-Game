// Thhis class is made to implement the Prims Algorithim
class Prims
{
public:
    // Function find the minimum spanning tree using Prims algorithim
    void Prims_Algo(int** adj, int ROWS, int COLS)
    {
        int* parent = new int[ROWS];
        int* key = new int[ROWS];
        bool* inMST_Array = new bool[ROWS];

        for (int i = 0; i < ROWS; i++)
        {
            parent[i] = -1;
            key[i] = INT_MAX;
            inMST_Array[i] = false;
        }

        for (int i = 0; i < ROWS*COLS; i++)
        {
            for (int j = 0; j < ROWS*COLS; j++)
            {
                if (adj[i][j] == 0 && i != j)
                {
                    adj[i][j] = INF;
                }
            }
        }

        key[0] = 0;

        for (int i = 0; i < ROWS - 1; i++)
        {
            int minKey = INT_MAX, u;

            // Find the vertex with the minimum key value that is not in the MST
            for (int v = 0; v < ROWS; v++)
            {
                if (!inMST_Array[v] && key[v] < minKey)
                {
                    minKey = key[v];
                    u = v;
                }
            }

            inMST_Array[u] = true;

            // Update the key values and parent pointers of adjacent vertices 
            for (int v = 0; v < ROWS; v++)
            {
                if (adj[u][v] && !inMST_Array[v] && adj[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = adj[u][v];
                }
            }
        }

        cout << "Minimum Spanning Tree:\n";
        for (int i = 1; i < ROWS; i++)
        {
            cout << parent[i] << " -> " << i << "   " << adj[i][parent[i]] << endl;
        }
    }
};