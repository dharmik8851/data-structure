#include<iostream>
using namespace std;

class Node{
public:
	int data; Node *left,*right;
	Node(int data){
		left=NULL; right=NULL;
		this->data = data;
	}
};

bool isIdentical(Node* root1, Node* root2){
	if(root1 == NULL && root2 == NULL) return true;
	if(root1 == NULL || root2 == NULL) return false;
	else{
		bool con1 = root1->data == root2->data;
		bool con2 = isIdentical(root1->left, root2->left);
		bool con3 = isIdentical(root1->right, root2->right);
		if(con1 && con2 && con3) return true;
		return false;
	}
}

int main(){
	Node* root = new Node(1);
	root->right = new Node(2);
	root->left = new Node(3);

	Node* root1 = new Node(5);
	root1->right = new Node(2);
	root1->left = new Node(3);	
	
	if(isIdentical(root,root1)) cout<<"is Identical";
	else cout<<"not Identical";
	return 0; 
}