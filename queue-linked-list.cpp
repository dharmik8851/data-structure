#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int ele){
			data = ele;
			next = NULL;
		}
};

class queue{
	node* front;
	node* back;
	
	public:
		queue(){
			front=NULL;
			back=NULL;
		}
		
		//for insert element
		void enqueue(int ele){
			node* n = new node(ele);
			if(front == NULL){
				front = n;
				back = n;
				return;
			}
			back->next = n;
			back = back->next;
		}
		
		//for delete element
		void dequeue(){
			if(this->empty()){
				cout<<"Queue underflow"<<endl;
				return;
			}
			node* todelete = front;
			front = front->next;
			delete todelete;
		}
		
		//return element which we are deleting in dequeue
		int peek(){
			if(front==NULL) {
				cout<<"No elements in queue"<<endl;
				return -1;
			}
			return front->data;
		}
		
		//check queue empty
		bool empty(){
			if(front == NULL){
				return true;
			}
			return false;
		}
};

int main(){
	queue q;
	
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	
	cout<<q.peek()<<endl;
	q.dequeue();
	cout<<q.peek()<<endl;
	q.dequeue();
	cout<<q.peek()<<endl;
	q.dequeue();
	cout<<q.peek()<<endl;
	q.dequeue();
	
	cout<<q.peek()<<endl;
	q.dequeue();
	
	return 0;
}