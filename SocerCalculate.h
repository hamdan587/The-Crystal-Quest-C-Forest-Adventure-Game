class Score_Cal
{
public:
    // This number will always genrate a random id, never a duplicate id will be generated
   int random_number(int id_arr[200], int& counter)
    {
        int val = 0;
        if (counter == 0)
        {
            id_arr[counter] = 100;
            counter++;
            val = 100;
        }
        else
        {
            val = rand() % 200;
            bool found = true;
            while (found)
            {
                found = false;
                for (int i = 0; i < counter; i++)
                {
                    if (id_arr[i] == val)
                    {
                        found = true;
                        val = rand() % 200;
                        break;
                    }
                }
            }
            id_arr[counter] = val;
            counter++;
        }
        return val;
    }
   // This function calculates the Score and inserte and remove in the AVL TREE
    void SocoreCalculation_AVL(char* arr, int count, AVLTree*& tree)
    {
        int total_Score = 0;
        int counter = 0;
        int id_arr[200]{0};
        int JewelArray[50]{0};
        int PotionArray[50]{0};
        int WeaponArray[50]{0};
        int jewel_counter = 0;
        int weapon_counter = 0;
        int potion_counter = 0;

        for (int i = 0; i < 200; i++)
        {
            id_arr[i] = -1;
        }

        for (int i = 0; i < 50; i++)
        {
            JewelArray[i] = -1;
            PotionArray[i] = -1;
            WeaponArray[i] = -1;
        }

        for (int i = 0; i < count; i++)
        {
            if (arr[i] == 'C')
            {
                cout << " Clear Path Move " << endl;
            }
            else if (arr[i] == 'J')
            {
                cout << " You Collected An Jewl " << endl;
                int val = random_number(id_arr, counter);
                JewelArray[jewel_counter] = val;
                tree->insert(tree->root, val, 50);
                total_Score += 50;
                jewel_counter++;
            }
            else if (arr[i] == 'W')
            {
                cout << " You Collected An Weapon " << endl;
                int val = random_number(id_arr, counter);
                WeaponArray[weapon_counter] = val;
                tree->insert(tree->root, val, 30);
                total_Score += 30;
                weapon_counter++;
            }
            else if (arr[i] == 'P')
            {
                cout << " You Collected An Potion " << endl;
                int val = random_number(id_arr, counter);
                cout << val;
                PotionArray[potion_counter] = val;
                tree->insert(tree->root,val,70);
                total_Score += 70;
                potion_counter++;
            }
            else if (arr[i] == '@')
            {
                cout << " You Encountered An WereWolf, 1 Weapon would be removed " << endl;
                if (weapon_counter > 0)
                {
                    weapon_counter--;
                    int id = WeaponArray[weapon_counter];
                    tree->deleteNode(tree->root,id);
                    total_Score -= 30;
                    cout << " Successfully Removed The Weapon " << endl;
                }
                else
                {
                    cout << " Inventory Have No Weapon " << endl;
                }
            }
            else if (arr[i] == '$')
            {
                cout << " You Encountered An Goblin, 1 Potion would be removed " << endl;
                if (potion_counter > 0)
                {
                    potion_counter--;
                    int id = PotionArray[potion_counter];
                    tree->deleteNode(tree->root, id);
                    total_Score -= 70;
                    cout << " Successfully Removed The Potion " << endl;
                }
                else
                {
                    cout << " Inventory Have No Potion " << endl;
                }
            }
            else if (arr[i] == '&')
            {
                cout << " You Encountered An Dragon, 1 Jewel would removed " << endl;
                if (jewel_counter > 0)
                {
                    jewel_counter--;
                    int id = JewelArray[jewel_counter];
                    tree->deleteNode(tree->root, id);
                    total_Score -= 50;
                    cout << " Successfully Removed The Jewel " << endl;
                }
                else
                {
                    cout << " Inventory Have No Jewel " << endl;
                }
            }
            else if (arr[i] == '%')
            {
                cout << " Death Point, Restart " << endl;
                break;
            }
            else if (arr[i] == '*')
            {
                cout << " You Have Reached The Crsytal  " << endl;
            }
        }
        cout << " Total_Score = " << total_Score << endl;
        cout << " In-Order Traversal of Tree " << endl;
        tree->Inorder(tree->root);
    }
};