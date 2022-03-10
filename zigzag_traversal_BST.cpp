#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class Node{
public:
	int data;
	Node *left,*right;
	Node(int data){
		this->left = NULL;
		this->right = NULL;
		this->data = data;
	}
};

void zigzagTraversal(Node* root){
	if(root == NULL) return;

	stack<Node*> currLevel;
	stack<Node*> nextLevel;
	currLevel.push(root);
	bool leftToright = true;

	while(!currLevel.empty()){
		Node* temp = currLevel.top();
		currLevel.pop();

		if(temp){
		cout<<temp->data<<" ";

			if(leftToright){
				if(temp->left){
					nextLevel.push(temp->left);
				}
				if(temp->right){
					nextLevel.push(temp->right);
				}
			}
			else{
				if(temp->right){
					nextLevel.push(temp->right);
				}
				if(temp->left){
					nextLevel.push(temp->left);
				}
			}
		}
		if(currLevel.empty()){
				leftToright = !leftToright;
			swap(currLevel,nextLevel);			
		}
	}
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->right = new Node(5);
	root->left->right = new Node(4);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(7);

	zigzagTraversal(root);
	/*
				1
			2		3
			  4	  	  5
			6   7
	*/
	return 0;
}