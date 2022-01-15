#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"


/// <summary>
/// Teh function to create a new node
/// </summary>
/// <param name="value"></param>
/// <returns>the Tree Newnode</returns>
TREENODE* newNode(int value)
{
	TREENODE* Newnode;

	Newnode = malloc(sizeof(TREENODE));
	Newnode->number = value;
	Newnode->pLeft = NULL;
	Newnode->pRight = NULL;
}

/// <summary>
/// Function to insert values into the tree nodes
/// </summary>
/// <param name="root"></param>
/// <param name="value"></param>
/// <returns>TREENODE</returns>
TREENODE* Insert(link root, int value)
{
	if (root == NULL)
	{
		return newNode(value);
	}
	else if(value > root->number)
	{
		root->pRight = Insert(root->pRight, value);
		return root;
	}
	else
	{
		root->pLeft = Insert(root->pLeft, value);
		return root;
	}
}

/// <summary>
/// Function to search the tree
/// </summary>
/// <param name="root"></param>
/// <param name="value"></param>
/// <returns>Searched TreeNode</returns>
TREENODE* Search(link root, int value)
{
	if (root == NULL || root->number == value)
	{
		return root;
	}
	else if(value > root->number)
	{
		return Search(root->pRight, value);
	}
	else
	{
		return Search(root->pLeft, value);
	}
}

/// <summary>
/// Function to count the number the tree nodes
/// </summary>
/// <param name="root"></param>
/// <returns>The number of tree nodes</returns>
int CountNodes(link root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return (CountNodes(root->pLeft) + CountNodes(root->pRight) + 1);
	}
}

/// <summary>
/// Function to calculate the height of the tree
/// </summary>
/// <param name="root"></param>
/// <returns>The value of the tree height</returns>
int TreeHeight(link root)
{
	int leftHeight;
	int rightHeight;

	if (root == NULL)
	
		return -1;

	leftHeight = TreeHeight(root->pLeft);
	rightHeight = TreeHeight(root->pRight);

	if (leftHeight > rightHeight)
	{
		return (leftHeight + 1);
	}
	else
	{
		return (rightHeight + 1);
	}
	
}

/// <summary>
/// Function to print the tree
/// </summary>
/// <param name="root"></param>
void printTree(link root)
{
	if (root != NULL)
	{
		printTree(root->pLeft);
		printf(" %d\n", root->number);
		printTree(root->pRight);
	}
}