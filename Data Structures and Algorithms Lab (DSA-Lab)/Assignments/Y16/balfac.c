#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int i=0;
 
struct node
{
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
 
 
// A utility function to do inorder traversal of BST
void preorder(struct node * root)
{
	if (root == NULL)
	 return;
	 printf("%d \n", root->key);
		preorder(root->left);

		preorder(root->right);

}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	else if (key < node->key)
		node->left = insert(node->left, key);
	else if  (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}


int findheight(struct node *node)
{
	if (node == NULL) return -1;

return 1+ fmax(findheight(node->left),findheight(node->right));
}


struct node *balfac(struct node *node)
{	i++;
	if (node == NULL) return;
 
	printf("%d %d\n",i,findheight(node->left)-findheight(node->right));
	//balfac(node->left);
	//balfac(node->right);
}


// Driver Program to test above functions
void main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 20);
	insert(root, 30);
	 insert(root, 40);
	 insert(root, 70);
	 insert(root, 60);
	 insert(root, 80);

	// print inoder traversal of the BST
	preorder(root);
   // findmin(root);
    //findmax(root);
	balfac(root);
}

