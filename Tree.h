/*
* a. insert
* b. search
* c. count nodes
* d. determine tree height
*/
typedef struct TreeNode* link;

typedef struct TreeNode{
	int number;
	link pLeft;
	link pRight;
}TREENODE;

link root;

TREENODE* newNode(int value);

TREENODE* Insert(link root, int value);

TREENODE* Search(link root, int value);

int CountNodes(link root);

int TreeHeight(link root);


void printTree(link root);