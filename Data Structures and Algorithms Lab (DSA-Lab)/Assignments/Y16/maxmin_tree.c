  // C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
int min,max=0;
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
struct node *findmin(struct node *node)
{
    if(node==NULL)
    {
        printf("minimum is %d",min);
        return;
    }
    min=node->key;
    findmin(node->left);

}
struct node *findmax(struct node *node)
{
    if(node==NULL)
    {
        printf("maximum is %d",max);
        return;
    }
    max=node->key;
    findmax (node->right);

}
// A utility function to do inorder traversal of BST
void preorder(struct node * root)
{
	if (root == NULL)
	 return;
	 
		preorder(root->left);
printf("%d \n", root->key);
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
    findmin(root);
    findmax(root);
}









// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key99
    return search(root->left, key);
}











/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */

