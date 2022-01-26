#include<iostream>
using namespace std;

class node{
	public : 
		int data;
		node *left,*right;
		
		node(int data){
			this->data=data;
			left=NULL; right=NULL;
		}
};

node* insertBST(node* root, int val){
	if(root==NULL){
		return new node(val);
	}
	if(val>root->data){
		root->right = insertBST(root->right,val);
	}else{
		root->left = insertBST(root->left,val);
	}
	return root;
}

void inorderprint(node *root){
	if(root == NULL){
		return;
	}
	inorderprint(root->left);
	cout<<root->data<<" ";
	inorderprint(root->right);
}

node* searchBST(node *root, int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data == key){
		return root;
	}
	if(key > root->data){
		return searchBST(root->right,key);
	}
	return searchBST(root->left,key);
}

node* inorderSucc(node *root){
	node *curr = root;
	while(curr and curr->left != NULL){
		curr = curr->left;
	}
	return curr;
}

node* deleteInBST(node *root, int key){
	if(key > root->data){
		root->right = deleteInBST(root->right, key);
	}else if(key < root->data){
		root->left = deleteInBST(root->left, key);
	}else{
		if(root->left == NULL){
			node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			node *temp = root->left;
			free(root);
			return temp;
		}
		//case 3 : node has two children
		node* temp = inorderSucc(root->right);
		cout<<endl<<"succ->"<<temp->data<<endl;
		root->data = temp->data;
		root->right = deleteInBST(root->right,temp->data);
	}
	return root;
}

int main(){
	int n;
	cin>>n;
	int val;  cin>>val; 
	node* root= new node(val);
	for(int i=1; i<n; i++){
		cin>>val;
		insertBST(root,val);
	}
	inorderprint(root);
	
	//searching in BST
	cout<<endl<<endl<<"Enter value to search->"; cin>>val;
	if(searchBST(root,val) == NULL){
		cout<<"key doesn't exist";
	}else{
		cout<<"key exists";
	}
	
	//deletion in BST
	cout<<endl<<endl<<"Enter value to delete->"; cin>>val;
	root = deleteInBST(root,val);
	inorderprint(root);
	return 0;
}