#include<iostream>
#include "bits/stdc++.h"


class node{
	int data;
	node* left;
	node* right;
	
	public:
	node(){}
	
	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	
	node* makeTree();
	void inorder(node* root);
	void preorder(node* root);
	void postorder(node* root);
};

void node :: inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	std::cout<<" "<<root->data;
	inorder(root->right);
}

void node :: preorder(node* root){
	if(root==NULL) return;
	std::cout<<" "<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void node :: postorder(node* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	std::cout<<" "<<root->data;
}
node* node :: makeTree(){
	/*
			1
		   / \
		  2   3
		 /\   /\
		4 5	 6  7
	*/
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	return root;
}


int main(){
	node ob;
	node* root = ob.makeTree();
	ob.inorder(root);
	std::cout<<std::endl;
	ob.preorder(root);
	std::cout<<std::endl;
	ob.postorder(root);
	return 0;
}