#include<iostream>
using namespace std;
#define n 10

class queue{
	int front = -1;
	int back = -1;
	int *arr;
	
	public:
		queue(){
			arr = new int[n];
		}
		void enqueue(int x);
		void dequeue();
		int peek();
		bool empty();
};

//this function will insert data at back end in queue
void queue :: enqueue(int x){
	if(back==n-1){
		cout<<"Queue overflow";
		return;
	}
	back++;
	arr[back] = x;
	if(front == -1) front++;
}

//this function will remove data at front end in queue
void queue :: dequeue(){
	if(front == -1 || front>back){
		cout<<"No element in queue";
		return;
	}
	arr[front]=0;
	front++;
}

//this function will return element at front end
int queue :: peek(){
	if(front == -1 || front>back){
		cout<<"No element in queue";
		return -1;
	}
	return arr[front];
}

//this function will return true if queue is empty otherwise return false		
bool queue :: empty(){
	if(front == -1 || front>back){
		return true;
	}
	return false;
}
	
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