#include<iostream>
#include<vector>
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

bool getpath(node* root, int n,vector<int> &path){
	if(root==NULL){
		return false;
	}
	path.push_back(root->data);
	if(root->data==n){
		return true;
	}
	if(getpath(root->left,n,path) || getpath(root->right,n,path)){
		return true;
	}
	path.pop_back();
	return false;
}

int LCA(node* root, int n1, int n2){
	vector<int> path1,path2;
	
	if(!getpath(root,n1,path1) || !getpath(root,n2,path2)){
		return -1;
	}
	
	int pc=0; 
	for(pc=0; pc<path1.size() && path2.size(); pc++){
		if(path1[pc] != path2[pc]) break;
	}
	
	return path1[pc-1];
	
}

node* LCA2(node* root, int n1, int n2){
	if(root==NULL){
		return NULL;
	}
	if(root->data==n1 || root->data==n2){
		return root;
	}
	
	node* leftlca = LCA2(root->left,n1,n2);
	node* rightlca = LCA2(root->right,n1,n2);
	
	if(leftlca && rightlca){
		return root;
	}
	if(leftlca != NULL){
		return leftlca;
	}
	return rightlca;
}

int main(){
	node *root= new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->right->left = new node(5);
	root->right->right = new node(6);
	root->right->left->left = new node(7);
	
	cout<<LCA2(root,7,6)->data;
	
	return 0;
}