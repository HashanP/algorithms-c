#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	int value;
	struct Node *left;
	struct Node *right;
};

typedef struct {
	struct Node *root;
} BinarySearchTree;

BinarySearchTree *BinarySearchTreeCreate() {
	BinarySearchTree *k = malloc(sizeof(BinarySearchTree));
	k->root = NULL;
	return k;
}

struct Node *NodeCreate(int key, int value) {
	struct Node *node = malloc(sizeof(struct Node));
	node->key = key;
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void BinarySearchTreeAdd(BinarySearchTree *k, int key, int value) {
	if(k->root == NULL) {
		k->root = NodeCreate(key, value);
	} else {
		struct Node *node = k->root;
		while(1) {
			if(node->key == key) {
				node->value = value;
				break;
			} else if(node->key > key) {
				if(node->left == NULL) {
					node->left = NodeCreate(key, value);
					break;
				} else {
					node = node->left;
				}
			} else {
				if(node->right == NULL) {
					node->right = NodeCreate(key, value);
					break;
				} else {
					node = node->right;
				}
			}
		}
	}
}

int BinarySearchTreeGet(BinarySearchTree *k, int key) {
	struct Node *node = k->root;
	while(node->key != key) {
		if(node->key > key) {
			node = node->left;
		} else {
			node = node->right;
		}
	}
	return node->value;
}

void NodeDelete(struct Node *node) {
	if(node->left) {
		NodeDelete(node->left);
	}
	if(node->right) {
		NodeDelete(node->right);
	}
	free(node);
}

void BinarySearchTreeDelete(BinarySearchTree *k) {
	NodeDelete(k->root);
	free(k);
}

int main() {
	BinarySearchTree *k = BinarySearchTreeCreate();
	BinarySearchTreeAdd(k, 5, 9);
	BinarySearchTreeAdd(k, 4, 111);
	BinarySearchTreeAdd(k, 55, 55);
	BinarySearchTreeAdd(k, 53, 53);
	printf("%i\n", BinarySearchTreeGet(k, 55));
	printf("%i\n", BinarySearchTreeGet(k, 53));
	BinarySearchTreeDelete(k);
	return 0;
}
