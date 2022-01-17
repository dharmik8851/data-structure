#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	
	node(){
	}	
	
	node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};

void inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int height(node* root){
	if(root==NULL) return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	return max(lh,rh)+1;
}


//check wheather tree is height balanced or not
//tc = O(n^2);
bool isbalanced(node* root){
	if(root == NULL){
		return true;
	}
	
	if(isbalanced(root->left) == false){
		return false;
	}
	if(isbalanced(root->right) == false){
		return false;
	}
	
	int lh = height(root->left);
	int rh = height(root->right);
	if(abs(lh-rh) <= 1){
		return true;
	}else{
		return false;
	}
}

//tc = O(n^2);
bool isbalanced2(node* root, int* height){
	if(root == NULL){
		return true;
	}
	
	int lh=0,rh=0;
	if(isbalanced2(root->left,&lh) == false){
		return false;
	}
	if(isbalanced2(root->right,&rh) == false){
		return false;
	}
	*height = max(lh,rh)+1;
	
	if(abs(lh-rh) <= 1){
		return true;
	}else{
		return false;
	}
}
int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->left->left = new node(5);
	
	inorder(root);
	//cout<<endl<<height(root);
	int height=0;
	if(isbalanced2(root,&height)) cout<<endl<<"true";
	else cout<<endl<<"false";
	return 0;
}