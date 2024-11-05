#include<iostream>
using namespace std;
#include<cstdlib>
#include <climits>
#include<queue>
#include"iomanip"
#include"GameMap.h"
#include"Graph.h"
#include"Floyads_Algorithim.h"
#include"Dijkstra_Algorithim.h"
#include"Prims_Algorithim.h"
#include"Kurskal_Algorithim.h"
#include"InventoryClass.h"
#include"Helping_Func.h"
#include"SocerCalculate.h"

int main()
{

    // Game Map Generation Steps
    const int ROWS = 20, COLS = 20;
    int choice = 0, print = 0;
    GameMap game(ROWS, COLS);
    char** mat = game.arr();
    int c_x = game.getCrystalX();
    int c_y = game.getCrystalY();
    cout << " GAME_MAP : " << endl;
    game.printMap();
    // Graph Adjency Matrix Generation Steps
    const int n = ROWS, m = ROWS;
    Graph g;
    int** adj = g.GraphMaker(mat, n, m);
    cout << "Press1: If you want to print Adjency Matrix and Crystal Points : " << endl;
    cout << " If Not Press Zero To Continue : " << endl;
    cin >> print;
    if (print == 1)
    {
        for (int i = 0; i < n * m; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < n * m; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << " Crystal X-Coordinate : " << c_x << " " << "\n" << " Crystal Y-Coordinate : " << c_y << endl;
        cout << endl << endl;
    }
    // Function-Call To Print Menu
    Functions func;
    func.printMenu();
    cout << " Enter The Choice : " << endl;
    cin >> choice;
    if (choice == 1)
    {
        //Floyads Algorithim Function Call
        Floyad_Algo obj;
        int* vertex_sp = obj.FloydsAlgorithim(adj, ROWS, COLS, c_x, c_y);          // Function to find the shortest path using floyads alogrithm using (0,0) as default
        cout << endl;
        char* arr = func.remaping(vertex_sp, ROWS, COLS, mat);
        int i = 0;
        while (arr[i] != '\0')
        {
            cout << arr[i] << "->";
            i++;
        }
        cout << endl;
        AVLTree* tree = new AVLTree();
        Score_Cal score;
        score.SocoreCalculation_AVL(arr, i, tree);
    }
    if (choice == 2)
    {
        //Floyads Algorithim Function Call
        Floyad_Algo obj;
        int* vertex_sp = obj.FloydsAlgorithim(adj, ROWS, COLS, 2, 3, c_x, c_y);          // Function to find the shortest path using floyads alogrithm using custom as default
        cout << endl;
        char* arr = func.remaping(vertex_sp, ROWS, COLS, mat);
        int i = 0;
        while (arr[i] != '\0')
        {
            cout << arr[i] << "->";
            i++;
        }
        cout << endl;
        AVLTree* tree = new AVLTree();
        Score_Cal score;
        score.SocoreCalculation_AVL(arr, i, tree);
    }
    if (choice == 3)
    {
        //Dijastra Algorithim function call
        Dijkstar dj;
        int* dj_vetex = dj.Dijkstra(adj, ROWS, COLS, c_x, c_y);
        cout << endl;
        for (int i = 0; i < ROWS * COLS; i++)
        {
            if (dj_vetex[i] != -1)
                cout << dj_vetex[i] << "->";
        }
        char* arr2 = func.remaping(dj_vetex, ROWS, COLS, mat);
        int i2 = 0;
        while (arr2[i2] != '\0')
        {
            cout << arr2[i2] << "->";
            i2++;
        }
        AVLTree* tree = new AVLTree();
        Score_Cal score;
        score.SocoreCalculation_AVL(arr2, i2, tree);
    }
    if (choice == 4)
    {
        //Dijastra Algorithim function call
        Dijkstar dj;
        int* dj_vetex = new int[ROWS * COLS];
        for (int i = 0; i < ROWS * COLS; i++)
        {
            dj_vetex[i] = -1;
        }
        dj_vetex = dj.Dijkstra(adj, ROWS, COLS, 3, 3, c_x, c_y);
        cout << endl;
        for (int i = 0; i < ROWS * COLS; i++)
        {
            if (dj_vetex[i] != -1)
            {
                cout << dj_vetex[i] << "->";
            }
            else
            {
                break;
            }
        }
        cout << endl;
        char* arr2 = func.remaping(dj_vetex, ROWS, COLS, mat);
        int i2 = 0;
        while (arr2[i2] != '\0')
        {
            cout << arr2[i2] << "->";
            i2++;
        }
        cout << endl;
        AVLTree* tree = new AVLTree();
        Score_Cal score;
        score.SocoreCalculation_AVL(arr2, i2, tree);
    }
    if (choice == 5)
    {
        Prims pm;
        pm.Prims_Algo(adj, ROWS, COLS);
    }
    if (choice == 6)
    {
        Kurskal k;
        k.Kruskals_Algo(adj, ROWS, COLS);
    }
}