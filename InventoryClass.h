#include<iostream>
using namespace std;
class AVLNode
{
public:
	AVLNode* left;
	AVLNode* right;
	int height;
	int id; //generated randomly
	int reward_score; //score of a particular reward you obtained
	int count; //to avoid duplicate id nodes (maintain count of the id)


	AVLNode()
	{
		left = NULL;
		right = NULL;
		height = 0;
		id = 0;
		reward_score = 0;
		count = 0;
	}
	AVLNode(int sc)
	{
		left = NULL;
		right = NULL;
		height = 0;
		id = 0;
		reward_score = sc;
		count = 0;
	}
};

class AVLTree
{
public:
	AVLNode* root;

	AVLTree()
	{
		root = NULL;
	}
// Helper Functions
	int getHeight(AVLNode* _node)
	{
		if (_node == NULL)
			return 0;
		else
			return _node->height;
	}
	int max(int _left, int _right)
	{
		if (_left > _right)
			return _left;
		else
			return _right;
	}	
// Rotation Functions
	AVLNode* SingleRightRotation(AVLNode*& temp) {
		AVLNode* temp1 = temp->left;
		temp->left = temp1->right;
		temp1->right = temp;

		temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
		temp1->height = 1 + max(getHeight(temp1->left), temp->height);

		return temp1;
	}

	AVLNode* SingleLeftRotation(AVLNode*& temp) {
		AVLNode* temp1 = temp->right;
		temp->right = temp1->left;
		temp1->left = temp;

		temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
		temp1->height = 1 + max(getHeight(temp1->right), temp->height);

		return temp1;
	}

	AVLNode* DoubleRightRotation(AVLNode*& temp) {
		temp->left = SingleLeftRotation(temp->left);
		return SingleRightRotation(temp);
	}

	AVLNode* DoubleLeftRotation(AVLNode*& temp) {
		temp->right = SingleRightRotation(temp->right);
		return SingleLeftRotation(temp);
	}
	// Minimum Node Function
	AVLNode* getMinNode(AVLNode*& temp) //reutrn id of smallest node in the given tree
	{
		AVLNode* curr_node = temp;
		while (curr_node->left != NULL)
			curr_node = curr_node->left;
		return curr_node;
	}
	// Balancing Factor Calculator
	int BalanceFactor(AVLNode* temp)
	{
		if (temp == NULL)
			return 0;
		else
			return ((getHeight(temp->left)) - (getHeight(temp->right)));
	}
	// Inserte Function
	AVLNode* insert(AVLNode*& temp, int val, int scoree)
	{
		if (temp == NULL) 
		{
			temp = new AVLNode;
			temp->id = val;
			temp->reward_score = scoree;
			temp->left = temp->right = NULL;
			temp->height = 1;
		}
		else if (val < temp->id) 
		{
			temp->left = insert(temp->left, val, scoree);
		}
		else if (val > temp->id) 
		{
			temp->right = insert(temp->right, val, scoree);
		}
		else
		{
			// Handle the case when val is equal to temp->id
			// You can choose to update the reward_score or perform any other action here
		}

		// Update the height after the recursive insertions
		temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));

		int bf = BalanceFactor(temp);

		if (bf > 1 && val < temp->left->id) {
			temp = SingleRightRotation(temp);
		}
		else if (bf < -1 && val > temp->right->id) {
			temp = SingleLeftRotation(temp);
		}
		else if (bf > 1 && val > temp->left->id) {
			temp = DoubleRightRotation(temp);
		}
		else if (bf < -1 && val < temp->right->id) {
			temp = DoubleLeftRotation(temp);
		}

		return temp;
	}
	AVLNode* deleteNode(AVLNode*& temp, int val)
	{

		if (temp == NULL)  // Base Case 
		{
			return temp;
		}
		else if (val < temp->id) //go left
		{
			temp->left = deleteNode(temp->left, val);
		}
		else if (val > temp->id) //go right
		{
			temp->right = deleteNode(temp->right,val);
		}
		else //id matches so perform deleteion
		{
			if ((temp->left == NULL) && (temp->right == NULL)) //no child
			{
				AVLNode* tempnode = temp;
				temp = temp->right;
				delete tempnode;
			}
			else if ((temp->left == NULL) && (temp->right != NULL)) //one child on right
			{
				AVLNode* tempnode = temp;
				temp = temp->right;
				delete tempnode;
			}
			else if ((temp->right == NULL) && (temp->left != NULL)) //one child on left
			{
				AVLNode* tempnode = temp;
				temp = temp->left;
				delete tempnode;
			}
			else if ((temp->left != NULL) && (temp->right != NULL))//two children
			{
				AVLNode* tempnode = getMinNode(temp->right);
				temp->id = tempnode->id;
				temp->right = deleteNode(temp->right, tempnode->id);
			}
		}
		if (temp == NULL)
			return temp;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		int bf = BalanceFactor(temp); 
		if ((bf > 1) && (BalanceFactor(temp->left) >= 0)) 
		{
			temp = SingleRightRotation(temp);
		}
		else if ((bf < -1) && (BalanceFactor(temp->right) <= 0))
		{
			temp = SingleLeftRotation(temp);
		}
		else if ((bf < -1) && (BalanceFactor(temp->right) > 0))
		{
			temp = DoubleRightRotation(temp);
		}
		else if ((bf > 1) && (BalanceFactor(temp->left) < 0))
		{
			temp = DoubleLeftRotation(temp);
		}
		return temp;
	}
	void Inorder(AVLNode* temproot)
	{
		if (temproot != NULL)
		{
			Inorder(temproot->left);
			cout << "Id: " << " " << temproot->id << "   " << "Score = " << temproot->reward_score << " " << endl; ;
			Inorder(temproot->right);
		}
	}

};