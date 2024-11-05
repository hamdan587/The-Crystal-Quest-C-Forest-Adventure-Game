// This class is responsible of making adjency matrix of the map
class Graph
{
public:
    int** GraphMaker(char** mat, int n, int m)
    {
        // Dynamic Memory Allocation to Store Connected Componenets( Meaning  Neigbours)
        int** connected = new int* [n * m];
        for (int i = 0; i < n * m; i++)
        {
            connected[i] = new int[4];
        }
        int** count = new int* [m];
        for (int i = 0; i < n; i++)
        {
            count[i] = new int[m] {0};
        }
        // Loop to store up,down,right,left vertexs
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > 0)
                    connected[i * m + j][count[i][j]++] = (i - 1) * m + j;
                if (i < n - 1)
                    connected[i * m + j][count[i][j]++] = (i + 1) * m + j;
                if (j > 0)
                    connected[i * m + j][count[i][j]++] = i * m + j - 1;
                if (j < m - 1)
                    connected[i * m + j][count[i][j]++] = i * m + j + 1;
            }
        }
        // Make the adjency Matrix all have weight of 1 and connection with # have weigth 100
        int** adj = new int* [n * m];
        for (int i = 0; i < n * m; i++)
        {
            adj[i] = new int[n * m] {0};
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < count[i][j]; k++)
                {
                    int v = connected[i * m + j][k];
                    if (mat[i][j] == '#' || mat[v / m][v % m] == '#')
                    {
                        adj[i * m + j][v] = 100;
                    }
                    else
                    {
                        adj[i * m + j][v] = 1;
                    }
                }
            }
        }
        return adj;
    }
};