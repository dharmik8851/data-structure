#include<iostream>
using namespace std;

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
	
	node* makeTree(int postorder[],int inorder[],int st,int end);
	int search(int inorder[],int st, int end,int curr);
	void inorder(node* root);
};

int node::search(int inorder[],int st, int end,int curr){
	for(int i=0; i<=end; i++){
		if(inorder[i] == curr) return i;
	}
	return -1;
}

node* node::makeTree(int postorder[],int inorder[],int st,int end){
	if(st>end) return NULL;
	static int idx = end;
	int curr = postorder[idx];
	node* root = new node(curr);
	idx--;
	if(st==end) return root;
	int pos = search(inorder,st,end,curr);
	root->right = makeTree(postorder,inorder,pos+1,end);
	root->left = makeTree(postorder,inorder,st,pos-1);
	return root;
}

void node::inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);
}

int main(){
	int postorder[] = {4,2,5,3,1};
	int inorder2[] = {4,2,1,5,3};
	node ob;
	node* root = ob.makeTree(postorder,inorder2,0,4);
	ob.inorder(root);
	return 0;
}