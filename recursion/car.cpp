#include <cstdio>
using namespace std;
const int maxRow = 100, maxCol = 40;
bool mp[maxRow+5][maxCol+5];
int m,n,t;
int answer[maxRow+5];
bool check = false;
void rec(int r,int c){
	if(r == t){
		check = true;
		for(int i=0;i<t;i++){
			printf("%d\n",answer[i]);
		}
	} else if(check == false){
		if(mp[r+1][c] == 1){
			answer[r] = 3;
			rec(r+1,c);
		}
		if(mp[r+1][c-1] == 1){
			answer[r] = 1;
			rec(r+1,c-1);
		}
		if(mp[r+1][c+1] == 1){
			answer[r] = 2;
			rec(r+1,c+1);
		}
	}
}
int main(){
	int x;
	scanf("%d %d %d",&m,&n,&t);
	for(int i=1;i<=t;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&x);
			mp[i][j] = !x;
		}
	}
	rec(0,n);
	return 0;
}
/*
7
5
5
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 1 1 0 0 0 0
1 0 1 1 1 1 1
*/