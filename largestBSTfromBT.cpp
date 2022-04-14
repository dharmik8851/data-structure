#include <iostream>
#include <climits>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;

	Node(int data){
		this->data=data;
		left=NULL; right=NULL;
	}
};

struct Info
{
	int min;
	int max;
	int size;
	int ans;
	bool isBST;
};

Info largestBST(Node* root){
	if(root==NULL){
		return {INT_MAX, INT_MIN, 0, 0, true};
	}
	if(root->left==NULL && root->right==NULL){
		return {root->data, root->data, 1, 1, true};
	}
	Info leftInfo = largestBST(root->left);
	Info rightInfo = largestBST(root->right);

	Info curr;
	curr.size = 1+leftInfo.size+rightInfo.size;
	curr.min = min(leftInfo.min, min(root->data,rightInfo.min));
	curr.max = max(leftInfo.max, max(root->data,rightInfo.max));
	if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min>root->data){
		curr.isBST=true;
		curr.ans=curr.size;	
		return curr;
	}
	curr.ans = max(leftInfo.ans, rightInfo.ans);
	curr.isBST=false;
	return curr;
}

int main(){
	/*
			5
		3		6
	  2   4       1
	*/
	Node* root = new Node(5);
	root->right = new Node(6);
	root->right->right = new Node(1);
	root->left = new Node(3);
	root->left->left = new Node(2);
	root->left->right = new Node(4);
	
	cout<<"largest BST is -> "<<largestBST(root).ans;
	return 0;
}