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

//case 1 print nodes on subtress at distance k
void printSubtreenodes(node* root, int k){
	if(root==NULL || k<0){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printSubtreenodes(root->left,k-1);
	printSubtreenodes(root->right,k-1);
}

//case 2 print ancestors at distance k
int printnodesAtk(node* root, node* target, int k){
	if(root==NULL){
		return -1;
	}
	if(root==target){
		printSubtreenodes(root,k);
		return 0;
	}
	
	int dl = printnodesAtk(root->left, target, k);
	if(dl!=-1){
		if(dl+1 == k){
			cout<<root->data<<" ";
		}else{
			printSubtreenodes(root->right,k-dl-2);
		}
		return dl+1;
	}
	
	int dr = printnodesAtk(root->right, target, k);
	if(dl!=-1){
		if(dl+1 == k){
			cout<<root->data<<" ";
		}else{
			printSubtreenodes(root->left,k-dl-2);
		}
		return dl+1;
	}
	return -1;
}

int main(){
	
//	node* root = new node(1);
//	root->left = new node(2);
//	root->right = new node(3);
//	root->left->left = new node(4);
	
	node* root = new node(1);
	root->left = new node(5);
	root->right = new node(2);
	
	root->right->left = new node(3);
	root->right->right = new node(4);
	
	root->left->left = new node(6);
	root->left->left->right = new node(7);
	root->left->left->right->left = new node(8);
	root->left->left->right->right = new node(9);

	printnodesAtk(root, root->left, 3);
	return 0;
}