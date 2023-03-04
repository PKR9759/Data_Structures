#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node *pre;
	node *next;

	node(int d){
		this->data=d;
		this->pre=nullptr;
		this->next=nullptr;

	}
};
void print(node * &head){
	node *temp=head;
	while(temp!=nullptr){
		cout<<temp->data<<" "<<endl;
		temp=temp->next;
	}
	cout<<endl;
}

int getLength(node * &head){
	node *temp=head;
	int cnt=0;
	while(temp!=nullptr){
		
		temp=temp->next;
		cnt++;
	}
	return cnt;
}


void insAtHead(node* &head,node *&tail,int d){
	node *temp=new node(d);
	//if empty list | head point to null
	if(head==nullptr){
		head=temp;
		tail=temp;
		return;

	}
	
	temp->next=head;
	head->pre=temp;
	head=temp;
}

void insAtTail(node* &head,node* &tail,int d){
	node *temp=new node(d);
	//in case of empty list
	if(tail==nullptr){
		head=temp;;
		tail=temp;
		return;
	}
	
	tail->next=temp;
	temp->pre=tail;
	tail=temp;


}

void insAtPos(node * &head,node* &tail,int pos,int d){
	if(pos==1){
		insAtHead(head,tail,d);
		return;
	}
	node *temp=head;
	node*elem=new node(d);
	int cnt=1;
	while(cnt<pos-1){
		temp=temp->next;
		cnt++;
	}
	//if insert at tail
	if(temp->next==nullptr){
		insAtTail(head,tail,d);
		return;
	}
		node * elemnext=temp->next;
		elem->next=elemnext;
		elemnext->pre=elem;
		elem->pre=temp;
		temp->next=elem;
}


void deleteAt(node* &head,node *&tail,int pos){
	if(pos==1){
		node*temp=head;
		head=head->next;
		head->pre=nullptr;//new head and so pre =null
		temp->next=nullptr;//assign null before delete so that not  pointing to another
		temp->pre=nullptr;
		delete temp;
		return;
	}
	node* temp=head;
	int cnt=1;
	while(cnt<pos){//here we go to pos of that node instead of his prev pos
		cnt++;
		temp=temp->next;
	}
	//delete tail node
	if((temp->next)==nullptr){
		tail=temp->pre;//new tail after delete
		tail->next=nullptr;//that points to null
		
		temp->next=nullptr;//assign to null before delete it
		temp->pre=nullptr;
		delete temp;
		return;

	}
	(temp->next)->pre=temp->pre;
	
	temp->pre->next=temp->next;

	temp->next=nullptr;
	temp->pre=nullptr;


	delete temp;
	
}



int main(){
	node *nodi=new node(10);
	node *head=nullptr;
	node *tail=nullptr;
	insAtHead(head,tail,22);
	insAtHead(head,tail,32);
	insAtHead(head,tail,42);
	insAtTail(head,tail,2); 
	insAtTail(head,tail,72);
	insAtTail(head,tail,92);
	insAtTail(head,tail,82);
	insAtPos(head,tail,8,88);
	deleteAt(head,tail,8);
	cout<<getLength(head)<<endl;
	print(head);
	
	
}
