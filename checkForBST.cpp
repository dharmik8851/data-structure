#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *left,*right;
		
		node(int data){
			this->data=data;
			left=NULL;
			right=NULL;
		}
};

bool checkForBST(node* root, node* min, node* max){
	if(root==NULL){
		return true;
	}
	if(min != NULL && root->data <= min->data){
		return false;
	}
	if(max != NULL && root->data >= max->data){
		return false;
	}
	bool leftValid = checkForBST(root->left, min, root);
	bool rightValid = checkForBST(root->right, root, max);
	return leftValid && rightValid;
}

int main(){
	node* root = new node(7);
	root->left = new node(6);
	root->right = new node(9);
	
	if(checkForBST(root,NULL,NULL)){
		cout<<"valid BST";
	}else cout<<"invalid BST";
	return 0;
}				