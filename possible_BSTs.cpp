#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
	int data;
	Node *left,*right;

	Node(int data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
};

void printPreorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

vector<Node*> constructTrees(int start,int end){
	vector<Node*> trees;

	if(start>end){
		trees.push_back(NULL);
		return trees;
	}

	for(int i=start; i<=end; i++){
		vector<Node*> leftSubtrees = constructTrees(start,i-1);
		vector<Node*> rightSubtrees = constructTrees(i+1,end);
		for(int j=0; j<leftSubtrees.size(); j++){
			Node* left = leftSubtrees[j];
			for(int k=0; k<rightSubtrees.size(); k++){
				Node* right = rightSubtrees[k];
				Node* node = new Node(i);
				node->left = left;
				node->right = right;
				trees.push_back(node);
			}
		}
	}
	return trees;
}



int main(){

	vector<Node*> arr = constructTrees(1,3);

	for(int i=0; i<arr.size(); i++){
		cout<<i+1<<" : ";
		printPreorder(arr[i]);
		cout<<endl;
	}
	return 0;
}