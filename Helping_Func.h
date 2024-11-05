// Helping Function Class
class Functions
{
public:
    // Function to print menu
    void printMenu()
    {
        cout << setw(50) << "             ****************************************************************" << endl;
        cout << setw(50) << "             |             The Quest for the Crystal Kingdom                | " << endl;
        cout << setw(50) << "             ****************************************************************" << endl;
        cout << setw(50) << "                              **************************" << endl;
        cout << setw(50) << "                              |         MENU           |" << endl;
        cout << setw(50) << "                              **************************" << endl;
        cout << setw(10) << "1. " << setw(50) << "Floyd's algorithm to calculate the shortest path between the default location (0,0) and the crystal" << endl;
        cout << setw(10) << "2. " << setw(50) << "Floyd's algorithm to calculate the shortest path between a custom location and the crystal" << endl;
        cout << setw(10) << "3. " << setw(50) << "Dijkstra's algorithm to find the shortest path between the default location (0,0) and the crystal" << endl;
        cout << setw(10) << "4. " << setw(50) << "Dijkstra's algorithm to calculate the shortest path between a custom location and the crystal" << endl;
        cout << setw(10) << "5. " << setw(50) << "Prim's algorithim to calculate the minimun spanning tree of the game map " << endl;
        cout << setw(10) << "6. " << setw(50) << "Kurskal's algorithim to calculate the minimun spanning tree of the game map " << endl;

    }

    // THis function convert vertexs ti indexs in orignal map and generate 1d dynamic arrya of shortest path
    char* remaping(int* vertex_sp, int ROWS, int COLS, char** orignal_map)
    {
        // Making Charater Array of Shortest path followed by floyad algorithim
        int count = 0;
        for (int i = 0; i < ROWS * COLS; i++)
        {
            if (vertex_sp[i] != -1)
            {
                cout << vertex_sp[i] << "->";
                count++;
            }
        }
        cout << endl;
        int crystalx = 0;
        int crystaly = 0;
        int** elements = new int* [count];
        for (int i = 0; i < count; i++)
        {
            elements[i] = new int[2];
        }
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                elements[i][j] = 0;
            }
        }
        int j = 0;
        for (int i = 0; i < ROWS * COLS; i++)
        {
            if (vertex_sp[i] != -1)
            {
                crystalx = vertex_sp[i] / COLS;
                crystaly = vertex_sp[i] % COLS;
                elements[j][0] = crystalx;
                elements[j][1] = crystaly;
                j++;
            }
        }
        char* shortpath_map = new char[count + 1];
        for (int i = 0; i < count; i++)
        {
            shortpath_map[i] = 0;
        }
        for (int i = 0; i < count; i++)
        {
            shortpath_map[i] = orignal_map[elements[i][0]][elements[i][1]];
        }
        shortpath_map[count] = '\0';
        return shortpath_map;
    }
};