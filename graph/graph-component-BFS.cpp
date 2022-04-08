#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxN = 30000;
vector<int> g[maxN];
bool check[maxN];
int main(){
	// Goal is to count the number of connected component in graph
	int n,m,u,v;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int count = 0;
	for(int i=0;i<n;i++){
		if(check[i] == false){
			count++;
			queue<int> q;
			q.push(i);
			while(q.empty() == false){
				int u = q.front();
				check[u] = true;
				q.pop();
				for(int v : g[u]){
					if(check[v] == false){
						q.push(v);
					}
				}
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

/*
9 7
0 8
8 4
0 4
4 3
1 7
2 7
6 5
*/