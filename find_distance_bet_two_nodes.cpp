#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	
	node()	{
	}
	
	node(int data){
		this->data = data;
		left=NULL;
		right=NULL;
	}
};

node* lca(node* root,int n1, int n2){
	if(root == NULL){
		return NULL;
	}
	if(root->data == n1 || root->data == n2){
		return root;
	}
	node* left = lca(root->left, n1, n2);
	node* right = lca(root->right, n1, n2);
	
	if(left!=NULL && right!=NULL){
		return root;
	}
	if(left==NULL && right==NULL){
		return NULL;
	}
	if(left!=NULL){
		return left;
	}
	return right;
}

int findDis(node* root, int k, int dis){
	if(root==NULL){
		return -1;
	}
	if(root->data == k){
		return dis;
	}
	int left = findDis(root->left, k, dis+1);
	if(left != -1){
		return left;
	}
	return findDis(root->right, k, dis+1);
}

int distBtnNodes(node *root, int n1, int n2){
	node* a = lca(root,n1,n2);
	int d1 = findDis(a,n1,0);
	int d2 = findDis(a,n2,0);
	return d1+d2;
}

int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->right->right = new node(5);
	
	cout<<distBtnNodes(root,2,1);
	return 0;
}