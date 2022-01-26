#include<iostream>
using namespace std;

class node{
	public : 
		int data;
		node *left,*right;
		
		node(int data){
			this->data=data;
			left=NULL; right=NULL;
		}
};

node* insertBST(node* root, int val){
	if(root==NULL){
		return new node(val);
	}
	if(val > root->data){
		root->right = insertBST(root->right, val);
	}
	else{
		root->left = insertBST(root->left, val);
	}
	return root;
}

void inorderprint(node *root){
	if(root == NULL){
		return;
	}
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}

int main(){
	node *root = new node(5);
	insertBST(root,32);
	insertBST(root,43);
	insertBST(root,3);
	insertBST(root,1);
	insertBST(root,98);
	insertBST(root,44);
	insertBST(root,476);
	insertBST(root,2);
	
	inorderprint(root);
	return 0;
}