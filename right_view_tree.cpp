#include<iostream>
#include<queue>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(){
		}
		
		node(int data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

void rightView(node* root){
	if(root == NULL){
		return;
	}
	queue<node*> q;
	q.push(root);
	
	while(!q.empty()){
		int n = q.size();
		
		for(int i=0; i<n; i++){
			node* temp = q.front();
			q.pop();
			
			if(i==n-1){
				cout<<temp->data<<" ";
			}
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
		}
	}
}


int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->left->left = new node(4);
	root->right = new node(3);
	root->right->left = new node(5);
	root->right->left->left = new node(7);
	root->right->right = new node(6);
	rightView(root);
	return 0;
}