#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *left,*right;
		node(int data){
			this->data=data;
			left=NULL; right=NULL;
		}
};

node* constructBST(int preorder[], int *idx, int key, int min, int max, int n){
	if(*idx >= n){
		return NULL;
	}
	node* root = NULL;
	if(key > min && key < max){
		root = new node(key);
		*idx = *idx + 1;
		if(*idx<n){
			root->left=constructBST(preorder,idx,preorder[*idx],min,key,n);
		}
		if(*idx<n){
			root->right=constructBST(preorder,idx,preorder[*idx],key,max,n);
		}
	}
	return root;
}

void printPreorder(node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

int main(){
	int preorder_arr[] = {7,5,4,6,8,9};
	int idx=0;
	node* root = constructBST(preorder_arr,&idx,7,INT_MIN,INT_MAX,6);
	printPreorder(root);
	return 0;
}

