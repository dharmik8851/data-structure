#include<iostream>
#include<queue>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	
	public:
	node(){}	
	
	node(int data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};

void inorder(node* root){
	if(root==NULL) return;
	cout<<" "<<root->data;
	inorder(root->left);
	inorder(root->right);
}

void levelOrder(node* root){
	if(root==NULL) return;
	queue<node*> qu;
	qu.push(root);
	qu.push(NULL);
	
	while(!qu.empty()){
		node* n = qu.front();
		qu.pop();
		if(n!=NULL){
			cout<<" "<<n->data;
			if(n->left!=NULL){
				qu.push(n->left);
			}
			if(n->right!=NULL){
				qu.push(n->right);
			}
		}
		else if(!qu.empty()){
			qu.push(NULL);
		}
	}
}

//sum of nodes at kth level
int sumAtk(node* root, int k){
	if(root==NULL) return -1;
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	int sum=0;
	int level=0;
	while(!q.empty()){
		node* n = q.front();
		q.pop();
		if(n!=NULL){
			if(level==k) sum+=n->data;
			if(n->left) q.push(n->left);
			if(n->right) q.push(n->right);
		}
		else if(!q.empty()){
			level++;
			q.push(NULL);
		}
	}
	return sum;
}

//count total no of nodes 
int count(node* root){
	if(root==NULL) return 0;
	return count(root->left)+count(root->right)+1;
}

//sum of all nodes
int sumAll(node* root){
	if(root==NULL) return 0;
	return sumAll(root->left)+sumAll(root->right)+root->data;
}

//calculate height of given binary tree
//TC = O(n);
int calcHeight(node* root){
	if(root==NULL) return 0;
	int leftH = calcHeight(root->left);
	int rightH = calcHeight(root->right);
	return max(leftH,rightH)+1;
}

//calculate diameter of given binary tree
//TC = O(n^2);
int calcDiameter(node* root){
	if(root==NULL) return 0;
	int lHeight = calcHeight(root->left);
	int rHeight = calcHeight(root->right);
	int currDia = lHeight+rHeight+1;
	return max(currDia,max(calcDiameter(root->left),calcDiameter(root->right)));
}

//calculate diameter of given binary tree
//optimized TC = O(n);
int calcDiameter2(node* root, int* height){
	if(root == NULL){
		*height = 0;
		return 0;
	}
	int lh=0,rh=0;
	int lDiameter = calcDiameter2(root->left,&lh);
	int rDiameter = calcDiameter2(root->right,&rh);
	
	int currDiameter = lh + rh + 1;
	*height = max(lh , rh) + 1;
	
	return max(currDiameter, max(lDiameter,rDiameter));
}

//sum replacement in a binary tree
//TC = O(n);
void sumReplace(node* root){
	if(root==NULL) return;
	sumReplace(root->left);
	sumReplace(root->right);
	int currSum;
	if(root->left) root->data+=root->left->data;
	if(root->right) root->data+=root->right->data;
}

/* 
		1
	   / \
	  2  3
	 /\  /\
	4 5 6 7
*/
int main(){
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);
	levelOrder(root);
	cout<<endl<<" sum at 1th level"<<sumAtk(root,1);
	cout<<endl<<" total no of -> "<<count(root);
	cout<<endl<<" total sum -> "<<sumAll(root);
	cout<<endl<<" height of tree -> "<<calcHeight(root);
	cout<<endl<<" diameter of tree -> "<<calcDiameter(root);
	int height = 0;
	cout<<endl<<" diameter of tree optimized-> "<<calcDiameter2(root, &height);
	cout<<endl;
	inorder(root);
	sumReplace(root);
	cout<<endl;
	inorder(root);
	return 0;
}
