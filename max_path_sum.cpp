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

int maxSumPathUtil(node* root, int &ans){
	if(root==NULL){
		return 0;
	}
	int left = maxSumPathUtil(root->left,ans);
	int right = maxSumPathUtil(root->right,ans);
	
	int nodeMax = max(max(root->data,root->data+left+right),
						max(root->data+left,root->data+right));
	ans = max(ans,nodeMax);
	int siglePathSum = max(root->data, max(root->data+left, root->data+right));
	return siglePathSum;
							
}

int maxSumPath(node* root){
	int ans = INT_MIN;
	maxSumPathUtil(root,ans);
	return ans;
}

int main(){
	node *root = new node(1);
	root->left = new node(2);
	root->left->left = new node(4);
	root->right = new node(3);
	root->right->left = new node(5);
	root->right->right = new node(6);
	root->right->left->left = new node(7);
	
	cout<<maxSumPath(root);
	return 0;	
}