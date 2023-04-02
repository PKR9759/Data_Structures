#include<bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define	lcm(a,b) __gcd(a,b)/a*b
#define loop(k,n) for(int i=k;i<n;i++)
#define vi(v) vector<int> v
#define vc(v) vector<char> v
#define vs(v) vector<string> v
#define mci(v) map<char,int> v
#define mii(v) map<int ,int> v
#define mis(v) map<int,string> v
#define msi(v) map<string,int> v
#define mic(v) map<int,char> v
#define umii(v) unordered_map<int ,int> v
#define umis(v) unordered_map<int,string> v
#define umsi(v) unordered_map<string,int> v
#define umic(v) unordered_map<int,char> v
#define umci(v) unordered_map<char,int> v
#define al(i,j) for(auto i:j)
#define _n <<"\n"
#define si(v) set<int> v
#define usi(v) unordered_set<int> v
#define ss(v) set<string> v
#define uss(v) unordered_set<string> v
#define sc(v) set<char> v
#define usc(v) unordered_set<char> v
#define pb push_back
#define sum(a,n,k) accumulate(a, a + n, k)
#define tinp(n) int q=0;while(q--);int b;cin>>b;{q+=b}


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

void ReverselevelOrderTra(node * root){

	stack<node*> s;
	queue<node *>q;
	q.push(root);
	q.push(nullptr);

	while(!q.empty()){
		node *temp=q.front();	
		q.pop();
		

		if(temp==nullptr){//this is for pyramid -->we are ading sepetaretor 
			cout<<endl;    //run one timr all clear OK !!
			if(!q.empty()){
				q.push(nullptr);
				s.push(nullptr);
			}
		}
		else{
			s.push(temp);
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
	while(!s.empty()){
		if(s.top()==nullptr){
			cout<<endl;
			s.pop();
		}

		cout<<s.top()->data<<' ';
		s.pop();

	}
}

void levelOrderTra(node * root){

	queue<node*> q;
	q.push(root);
	q.push(nullptr);

	while(!q.empty()){
		node *temp=q.front();	
		q.pop();

		if(temp==nullptr){//this is for pyramid -->we are ading sepetaretor 
			cout<<endl;    //run one timr all clear OK !!
			if(!q.empty()){
				q.push(nullptr);
				

			}
		}
		else{
			cout<<temp->data<<' ';
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}


int main(){
	node * root;
	root=buildTree(root);
	ReverselevelOrderTra( root);
}
