#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
	node(int val){
		this->data = val;
		this->next = NULL;
	}
};

//this function will insert val to the end of the linked list
void insertAtTail(node* &head, int val){
	node* temp = head;
	
	if(head == NULL){
		node* n = new node(val);
		head = n;
		return;
	}
	while(temp->next != NULL){
		temp=temp->next;
	}
	node* n = new node(val);
	temp->next = n;
}

//this function will print the elelments of the list
void display(node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

//this function will insert val to start of the linked list
void insertAtHead(node* &head, int val){
	node* n = new node(val);
	n->next = head;
	head = n;
}

//this function will search an element in the list
bool search(node* head, int key){
	while(head!=NULL){
		if(head->data==key) return true;
		head=head->next;
	}
	return false;
}

//this function will delete an val
void deletion(node* &head, int val){
	if(head->data == val){
		node* todelete = head;
		head = head->next;
		delete todelete;
		if(head==NULL) cout<<"your linked list is empty"<<endl;
		return;
	}
	if(head->next == NULL){
		cout<<"element not found"<<endl; 
		return;
	}
	node* temp = head;
	
	while(temp->next->data != val){
		if(temp->next->next == NULL){
			cout<<"element not found "<<endl; return;
		}
		temp=temp->next;
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

//this function will reverse the list
void reverse(node* &head){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;
	
	while(currptr != NULL){
		nextptr = currptr->next;
		currptr->next = prevptr;
		
		prevptr = currptr;
		currptr = nextptr;
	}
	
	head = prevptr;
}

//this function will reverse the list using recursion
node* reverse_recursive(node* head){
	if(head == NULL || head->next==NULL){
		return head;
	}
	node* newhead = reverse_recursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return newhead;
}

//this function will reverse k nodes in the list
node* reverse_k_nodes(node* &head, int k){
	node* prevptr = NULL;
	node* currptr = head;
	node* nextptr;
	
	int count = 0;
	while(currptr!=NULL && count<k){
		nextptr = currptr->next;
		currptr->next = prevptr;
		prevptr = currptr;
		currptr = nextptr;
		count++;
	}
	if(nextptr!=NULL){
			head->next = reverse_k_nodes(currptr,k);		
	}
	return prevptr;

}

//this function will detect cycle in the list
bool detectCycle(node* head){
	node* fast = head;
	node* slow = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(fast==slow){
			return true;
		}
	}
	return false;
}

//this function will make cycle at pos
void makeCycle(node* head, int pos){
	int count=1;
	node* temp = head;
	node* startnode;
	while(temp->next != NULL){
		if(count == pos){
			startnode=temp;
		}
		temp=temp->next;
		count++;
	}
	temp->next=startnode;
}

//this function will remove cycle if found
void removeCycle(node* head){
	node* fast = head;
	node* slow = head;
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(fast==slow){
			break;
		}
	}
	fast = head;
	while(fast->next != slow->next){
		fast=fast->next;
		slow=slow->next;
	}
	slow->next = NULL;
}

//this function will return length of the list
int length(node* head){
	int l=0;
	while(head!=NULL){
		l++;
		head=head->next;
	}
	return l;
}

//this function will append last k nodes to first
node* appendk(node* head, int k){
	int l = length(head);
	node* newtail;
	node* newhead;
	node* tail = head;
	int count=0;
	while(tail->next != NULL){
		count++;
		if(l-k == count){
			newtail = tail;
		}		
		if(l-k+1 == count){
			newhead = tail;
		}
		tail=tail->next;
	}
	tail->next=head;
	newtail->next=NULL;
	return newhead;
}

//this function will return first intersection elemetn between two list
int intersection(node* head1, node* head2){
	int len1 = length(head1);
	int len2 = length(head2);
	int k;
	node* ptr;
	if(len1 > len2){
		k = len1 - len2;
		while(k--){
			head1 = head1->next;
		}
	}else{
		k = len2 - len1;
		while(k--){
			head2 = head2->next;
		}
	}
	
	while(head1 != NULL || head2 != NULL){
		if(head1->data == head2->data) return head1->data;
		head1=head1->next;
		head2=head2->next;
	}
	return -1;
}

//this function will add intersection in two linked list
void makeIntersection(node* head1, node* head2,int pos){
	node* temp = head1;
	node* temp2 = head2;
	while(--pos){
		temp=temp->next;
	}
	while(temp2->next != NULL){
		temp2 = temp2->next;
	}
	temp2->next = temp->next;
}

//merge two sorted linked list 
node* mergeList(node* &head1, node* &head2){
	node* ptr1 = head1;
	node* ptr2 = head2;
	node* dummy = new node(-1);
	node* ptr3 = dummy;
	
	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1->data < ptr2->data){
			ptr3->next = ptr1;
			ptr1=ptr1->next;
		}
		else{
			ptr3->next = ptr2;
			ptr2 = ptr2->next;
		}
		ptr3=ptr3->next;
	}
	
	while(ptr1 != NULL){
		ptr3->next = ptr1;
		ptr1 = ptr1->next;
		ptr3 = ptr3->next;
	}
	
	while(ptr2 != NULL){
		ptr3->next = ptr2;
		ptr2 = ptr2->next;
		ptr3 = ptr3->next;
	}
	
	return dummy->next;
}

//merge two sorted linked list using recursion
node* mergeRecursive(node* &head1, node* &head2){
	node* result;
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;
	if(head1->data < head2->data){
		result = head1;
		result->next = mergeRecursive(head1->next,head2);
	}
	else{
		result = head2;
		result->next = mergeRecursive(head1,head2->next);
	}
	return result;
}

//put even position nodes after odd position nodes
void putEvenAfterOdd(node* &head){
	node* odd = head;
	node* even = head->next;
	node* evenStart = even;
	
	while(odd->next != NULL && even->next != NULL){
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next=evenStart;
	
}

int main(){
	node* head = NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	insertAtTail(head,6);
	insertAtTail(head,7);
	display(head);
	putEvenAfterOdd(head);
	display(head);
	
	
	return 0;
}