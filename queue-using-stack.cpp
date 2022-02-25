#include<iostream>
#include<stack>
using namespace std;

class queue{
	stack<int> s;
	
	public:
		void push(int ele){
			s.push(ele);
		}
		
		int pop(){
			if(s.empty()){
				cout<<"stack underflow";
				return -1;
			}
			
			int x = s.top();
			s.pop();
			
			if(s.empty()){
				return x;
			}
			
			int item = pop();
			s.push(x);
			
			return item;
		}
};

int main(){
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	
	cout<<q.pop()<<endl;
		cout<<q.pop()<<endl;
			cout<<q.pop()<<endl;
				cout<<q.pop()<<endl;
					cout<<q.pop()<<endl;
						cout<<q.pop()<<endl;
	return 0;
}