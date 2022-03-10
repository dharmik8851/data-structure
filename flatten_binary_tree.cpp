#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	
	node(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};

void flatten(node* root){
	if(root==NULL or (root->left==NULL && root->right==NULL)){
		return;
	}
	
	if(root->left!=NULL){
		flatten(root->left);
		node* temp = root->right;
		root->right = root->left;
		root->left = NULL;
		node* t = root->right;

		while(t->right!=NULL){
			t=t->right;
		}
		t->right=temp;
	}
	flatten(root->right);
}

void inorderprint(node* root){
	if(root==NULL) return;
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->right->left = new node(4);
	root->right->right = new node(5);
	/*
			1
		2		3
			   4 5
	*/
	
	flatten(root);
	inorderprint(root);
	return 0;
}