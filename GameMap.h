// This class is made to generate random maps of different sizes
class GameMap
{
public:
    // Member Variables
    char** map;
    int row;
    int col;
    int crystal_x;
    int crystal_y;

    // Default Constructor
    GameMap()
    {
        row = 0;
        col = 0;
        map = NULL;
        crystal_x = 0;
        crystal_y = 0;
    }

    // Parametrized constructor
    GameMap(int r, int c) : row(r), col(c)
    {
        map = new char* [row];
        for (int i = 0; i < row; ++i)
            map[i] = new char[col];

        // initialize all cells as clear paths
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                map[i][j] = 'C';

        // randomly add obstacles to the map
        for (int i = 0; i < row * col / 4; ++i)
        {
            int randrow = rand() % row;
            int randcol = rand() % col;
            map[randrow][randcol] = '#';
            if (randrow == 0 && randcol == 0)
            {
                map[randrow][randcol] = 'C';
            }
        }

        // randomly add rewards to the map
        for (int i = 0; i < row * col / 4; ++i)
        {
            int randrow = rand() % row;
            int randcol = rand() % col;
            int randitem = rand() % 3;
            if (randitem == 0)
                map[randrow][randcol] = 'J'; // Jewel
            else if (randitem == 1)
                map[randrow][randcol] = 'P'; // Potion
            else
                map[randrow][randcol] = 'W'; // Weapon
        }

        // randomly add enemies to the map
        for (int i = 0; i < row * col / 4; ++i)
        {
            int randrow = rand() % row;
            int randcol = rand() % col;
            int randenemy = rand() % 3;
            if (randenemy == 0)
                map[randrow][randcol] = '@'; // Werewolf
            else if (randenemy == 1)
                map[randrow][randcol] = '$'; // Goblin
            else
                map[randrow][randcol] = '&'; // Dragon
        }

        // randomly add death points to the map
        for (int i = 0; i < 4; ++i)
        {
            int randrow = rand() % row;
            int randcol = rand() % row;
            map[randrow][randcol] = '%';
            if (randrow == 0 && randcol == 0)
            {
                map[randrow][randcol] = 'C';
            }

        }

        // Add crystal points to map 
        for (int i = 0; i < 1; i++)
        {
            int randrow, randcol;
            int attempts = 0;
            do 
            {
                randrow = rand() % row;
                randcol = rand() % col;
                attempts++;
            } while ((map[randrow][randcol] != 'C' && map[randrow][randcol] != '%') && attempts < 10);
            map[randrow][randcol] = '*';
            if (randrow == 0 && randcol)
            {
                map[randrow][randcol] = 'C';
            }
        }

        // Storing Crystal Vertexs 
        int xindex = 0;
        int yindex = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (map[i][j] == '*')
                {
                    xindex = i;
                    yindex = j;
                    break;
                }
            }
        }

        this->crystal_x = xindex;
        this->crystal_y = yindex;
    }

    // Getter and Setters
    int getCrystalX() const
    {
        return crystal_x;
    }

    int getCrystalY() const
    {
        return crystal_y;
    }

    // Function to print the game map
    void printMap() const
    {
        cout << "                                   The Quest for the Crystal Kingdom Map " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }
    // Return the game map array
    char** arr()
    {
        return map;
    }
};