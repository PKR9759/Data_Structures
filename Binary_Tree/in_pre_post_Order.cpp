
#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	int data;
	node* left,*right;

	node(int d){
		this->data=d;
		this->right=nullptr;
		this->left=nullptr;
	}
};
node* buildTree(node* root){
	int d;
	cout<<"enter data "<<endl;
	cin>>d;

	if(d==-1){
		return nullptr;
	}
	

	root =new node(d);



	cout<<"Enter data of node that you want to insert on left of "<<d<<endl;
	root->left=buildTree(root->left);

	cout<<"Enter data of node that you want to insert on left of "<<d<<endl;
	root->right=buildTree(root->right);

	return root;


}



void Inorder(node *root){
	if(root==nullptr){
		return;
	}
	Inorder(root->left); //		L
	cout<<root->data<<' ';//	N
	Inorder(root->right);//		R

}

void Preorder(node *root){
	if(root==nullptr){
		return;
	}
	
	cout<<root->data<<' ';//		N
	Preorder(root->left); //		L
	Preorder(root->right);//		R

}


void Postorder(node *root){
	if(root==nullptr){
		return;
	}
	
	
	Postorder(root->left); //		L
	Postorder(root->right);//		R
	cout<<root->data<<' ';//		N

}
int main(){
	node * root;
	root=buildTree(root);
	Postorder(root);
}
