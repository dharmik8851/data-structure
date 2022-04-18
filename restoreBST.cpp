#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;

	Node(int data){
		this->data = data;
		left=NULL; right=NULL;
	}
};

void inorder(Node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void swap(int *n1,int *n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void calcPointer(Node *root, Node **first, Node **mid, Node **last, Node **prev){
	if(root==NULL)	return;

	calcPointer(root->left, first,mid,last,prev);

	if(*prev && root->data < (*prev)->data){
		if(!(*first)){
			*first = *prev;
			*mid = root;
		}
		else{
			*last = root;
		}
	}

	*prev = root;

	calcPointer(root->right,first,mid,last,prev);
}

/*
First : previous node where number<prev [8]
Mid : number where num<prev [7]
Last : 2nd node where number<prev [6]
*/
void restoreBST(Node* root){
	Node *first,*mid,*last,*prev;
	first = NULL;
	mid = NULL;
	last = NULL;
	prev = NULL;

	calcPointer(root, &first, &mid, &last, &prev);

	//case 1 : adjcent nodes(last is NULL)
	if(first && last){
		swap(&(first->data),&(last->data));
	}//case 2 : not adjcent nodes(last is not NULL)
	else if(first && mid){
		swap(&(first->data),&(mid->data));
	}

}

int main(){
	/*
			7
		8       6
	5		  		9

	*/

	Node *root = new Node(7);
	root->right = new Node(6);
	root->right->right = new Node(9);
	root->left = new Node(8);
	root->left->left = new Node(5);

	inorder(root);
	restoreBST(root);
	cout<<endl;
	inorder(root);
	
	return 0;
}