/*
a.	Inserts a random number of integers (from 5 to 10 integers, inclusive) into the tree. Each integer can range from 1 to 100.
b.	Print out the all the numbers inserted into the tree, in sorted order from smallest to largest.
c.	Print the number of nodes in the tree.
d.	Print the tree height.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"

int main(int argc, char* argv[])
{
	int genRandomNum;
	int num;
	num = atoi(argv[1]);
	srand(time(0));

	int heightofTree;
	int numberofNodes;
	
		TREENODE* Newnode;
		Newnode = malloc(sizeof(TREENODE));
		Newnode->pLeft = NULL;
		Newnode->pRight = NULL;
	
	//Loop through to insert the random numbers into the tree
	for (int i = 0; i < num; i++)
	{		
		genRandomNum = rand() % 100;
		if (i == 0)
		{
			Newnode->number = genRandomNum;			
		}		
		else
		{
			Insert(Newnode, genRandomNum);
		}
		printf("Inserted Number - %d\n", genRandomNum);
	}

	printf("\n");
	//calling the function to print the inserted value in the tree
	printTree(Newnode);

	//Getting the height of the tree
	heightofTree = TreeHeight(Newnode);

	printf(" Height of tree = %d\n", heightofTree);

	//Printing the number of nodes in the tree
	numberofNodes = CountNodes(Newnode);
	printf(" Number of nodes = %d\n", numberofNodes);

	free(Newnode);
}