#include <cstdio>
using namespace std;
const int maxRow = 1000, maxCol = 1000;
char mp[maxRow][maxCol];
bool check[maxRow][maxCol];
int n,m;
void dfs(int r,int c){
	check[r][c] = true;
	if(r-1 >= 0 && check[r-1][c] == false && mp[r-1][c] == '#'){
		dfs(r-1,c);
	}
	if(r+1 < n && check[r+1][c] == false && mp[r+1][c] == '#'){
		dfs(r+1,c);
	}
	if(c-1 >= 0 && check[r][c-1] == false && mp[r][c-1] == '#'){
		dfs(r,c-1);
	}
	if(c+1 < m && check[r][c+1] == false && mp[r][c+1] == '#'){
		dfs(r,c+1);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",mp[i]);
	}
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mp[i][j] == '#' && check[i][j] == false){
				count++;
				dfs(i,j);
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
/*
5 4
..#.
.##.
..#.
.#.#
#.##
*/