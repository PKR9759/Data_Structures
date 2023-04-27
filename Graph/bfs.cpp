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






//BFS travesel
int main(){
	int m,n;cin>>m>>n;//n==node; m==edges
	vector<int> adj[n+1];

	loop(0,m){
		int u,v;cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
// for(int i=0;i<n+1;i++){
// 	cout<<i<<":";
// 	for(int j=0;j<adj[i].size();j++){
// 		cout<<adj[i][j]<<' ';
// 	}
// 	cout<<endl;
// }

//visited array
	int visited[n+1]={0};
	visited[0]=1;//root element

	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		cout<<node<<" ";

		//adding neighbours

		for(auto it:adj[node]){
			if(!visited[it]){
				visited[it]=1;
				q.push(it);
			}
		}


	}
	
	
}
