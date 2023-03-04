#include<bits/stdc++.h>
using namespace std;



class node{
public:
	int data;
	node* next;
//constr...
	node(int d){
		this->data=d;
		this->next=nullptr;
	}
};


void insAtHead(node* &head,node* &tail,int d){
	node *temp=new node(d);
	//if empty list | head point to null
	if(head==nullptr){
		head=temp;
		tail=temp;
		return;

	}
	temp->next=head;
	head=temp;
}
void insAtTail(node* &head,node* &tail,int d){
	node *temp=new node(d);
	//if empty list | tail or head point to null
	if(head==nullptr){
		head=temp;
		tail=temp;
		return;

	}
	tail->next=temp;
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
		elem->next=temp->next;
		temp->next=elem;
}


void deleteAt(node* &head,node *&tail,int pos){
	if(pos==1){
		node*temp=head;
		head=head->next;
		temp->next=nullptr;//assign null before delete so that not  pointing to another
		delete temp;
		return;
	}
	node* temp=head;
	int cnt=1;
	while(cnt<pos-1){
		cnt++;
		temp=temp->next;
	}
	//delete tail node
	if((temp->next)->next==nullptr){
		node *temp2=temp->next;
		temp->next=nullptr;
		tail=temp;
		temp2->next=nullptr;//assign to null before delete it
		delete temp2;
		return;

	}
	node *current=temp->next;
	temp->next=current->next;
	current->next=nullptr;
	delete current;
	
}


void print(node * &head){
	node *temp=head;
	while(temp!=nullptr){
		cout<<temp->data<<" "<<endl;
		temp=temp->next;
	}
	cout<<endl;



}
int main(){
	node *nodi=new node(10);
	node* head=nullptr;
	node* tail=nullptr;
	insAtTail(head,tail,78);
	insAtTail(head,tail,7);
	insAtTail(head,tail,8);
	insAtPos(head,tail,2,99);
	
	insAtPos(head,tail,5,777);
	deleteAt(head,tail,4);
cout<<endl;

	print(head);
	cout<<head->data<<endl;
	cout<<tail->data<<endl;


	
}
