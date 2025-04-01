#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	 int data;
	 Node* next;
	 
	 Node(int value) {
        data = value;
        next = NULL;
    }
};

void print(Node* head){
	while(head!=NULL){
		cout<<head->data<<endl;
		head= head->next;
	}
}

void inserthead(Node* head){
	Node* temp = new Node(40);
	temp->next=head;
	head=temp;
	print(head);
}

void inserttail(Node* &tail,Node* &head){
	Node* temp1 = new Node(90);
	tail->next=temp1;
	tail=temp1;
	while(head!=NULL){
		cout<<head->data<<endl;
		head= head->next;
	}
}

void insertPos(Node* head,Node* tail, int pos){
	Node* temp2 = new Node(89);
	Node* prev = NULL;
	Node* curr = head;
	while(pos!=0){
		prev=curr;
		curr=curr->next;
		pos--;
	}
	prev->next=temp2;
	temp2->next=curr;
	print(head);
}

void deletehead(Node* head){
	Node* temp3 = head;
	head = head->next;
	temp3->next= NULL;
	delete temp3;
	print(head);	
}

void deletetail(Node* head,Node* tail){
	Node* temp4 = head;
	while(temp4->next!=tail){
		temp4=temp4->next;
	}
	temp4->next = NULL;
	delete tail;
	tail= temp4;		
	print(head);
}
 
void deletePos(Node* head,Node* tail,int pos){
	Node* prev = NULL;
	Node* curr = head;
	while(pos!=0){
		prev=curr;
		curr=curr->next;
		pos--;
	}
	prev->next = curr->next;
	curr->next=NULL;
	delete curr;
	print(head);	
}  

Node* reverseLL(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	
	while(curr!=NULL){
		Node *temp = curr->next;
		curr->next = prev;
		prev=curr;
		curr=temp;
	}
	return prev;
} 

Node* midnode(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;	
}

bool compareLL(Node*head1,Node* head2){
    while(head1!=NULL && head2!=NULL){
        if (head1->data!=head2->data)
            return false;
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

bool isPalindrome(Node* head){
	if(!head || !head->next){
		return true;
	}
	Node* mid = midnode(head);
	Node* secHead=reverseLL(mid);
	bool result=compareLL(head,secHead);
	return result;
}

bool cyclePresent(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;		
		if(slow==fast) return true;
	}
	return false;	
}

void startPtOfcycle(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
				
		if(slow==fast){
			slow=head;
			while(slow!=fast){
				slow=slow->next;
				fast=fast->next;
			}
			cout<<slow->data;
			return;
		} 				
	}		
}

void removecycle(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
				
		if(slow==fast){
			slow=head;
			
			Node* prev = NULL;			
			while(slow!=fast){
				prev=fast;
				slow=slow->next;
				fast=fast->next;
			}
			prev->next=NULL;
			print(head);
			return;
		} 				
	}		
}

Node* Add1toLL(Node* head){
	Node* rev=reverseLL(head);
	Node* temp=rev;
	
	int carry=1;
	Node* prev=NULL;
	while(temp!=NULL){
		temp->data += carry;
		carry=temp->data/10;
		temp->data %= 10;
		
		prev=temp;
		temp=temp->next;
	}	
	if(carry){
		prev->next=new Node(carry);
	}
	Node* hd =reverseLL(rev);
	print(hd);		
}

void remDuplicateFromSortedLL(Node* head){
	if(head->next==NULL){
		cout<<head->data;
	}
	
	Node* temp=head;
	while(temp!=NULL){
		Node* temp1=temp->next;
		if(temp->next!=NULL && temp->data==temp1->data){
			temp->next=temp1->next;
			temp1->next=NULL;
			delete temp1;
		}
		else{
			temp=temp->next;			
		}
	}
	print(head);	
}

int main(){
	int n; cin>>n;
	Node *f = new Node(1);
	Node *s = new Node(2);
	Node *t = new Node(2);
	Node* fr = new Node(2);
	
	f->next = s;
	s->next = t;
	t->next = fr;
	
	
	int pos=2;
	//inserthead(f);
	//inserttail(t,f);
	//insertPos(f,t,pos);
	//deletehead(f);
	//deletetail(f,t);
	//deletePos(f,t,pos);
	//reverseLL(f);
	//midnode(f);
	//bool y = isPalindrome(f);
	//bool y = cyclePresent(f);
	//startPtOfcycle(f);
	//cout<<y;
	//removecycle(f);
	//Add1toLL(f);
	//reverseKGroup(f,pos);
	remDuplicateFromSortedLL(f);
	
	return 0;
	
	
	
}