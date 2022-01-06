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
	
	node* makeTree(int preorder[],int inorder[],int st,int end);
	int search(int inorder[],int st, int end,int curr);
	void inorder(node* root);
};

void node :: inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	std::cout<<" "<<root->data;
	inorder(root->right);
}

int node :: search(int inorder[],int st, int end, int curr){
	for(int i=st; i<=end; i++){
		if(inorder[i] == curr) return i;
	}
	return -1;
}

node* node :: makeTree(int preorder[],int inorder[],int st,int end){
	if(st>end){
		return NULL;
	}
	static int idx = 0;
	int curr = preorder[idx];
	idx++;
	node* root = new node(curr);
	if(st==end) {
		return root;
	}
	int pos = search(inorder,st,end,curr);
	root->left = makeTree(preorder,inorder,st,pos-1);
	root->right = makeTree(preorder,inorder,pos+1,end);
	return root;
}



int main(){
	int preorder[] = {1,2,4,3,5};
	int inorder2[] = {4,2,1,5,3};
	node ob;
	node* root = ob.makeTree(preorder,inorder2,0,4);
	ob.inorder(root);
	
	return 0;
}