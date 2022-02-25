#include<iostream>
#include<vector>
using namespace std;

class node{
	public:
		int data;
		node *left,*right;
		node(int data){
			this->data = data;
			left=NULL;
			right=NULL;
		}
};

node* balancedBST(vector<int> arr, int start, int end){
	if(start>end) return NULL;
	int mid = (start+end)/2;
	node* root = new node(arr[mid]);
	
	root->left = balancedBST(arr, start, mid-1);
	root->right = balancedBST(arr, mid+1, end);
	return root;
}

void printInorder(node* root){
	if(root==NULL) return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8};
	node* root = balancedBST(arr, 0, arr.size()-1);
	printInorder(root);
	//for(auto ele : arr) cout<<ele<<" ";
	return 0;
}