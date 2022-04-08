#include <cstdio>
using namespace std;
const int maxRow = 1000, maxCol = 1000;
char mp[maxRow][maxCol];
bool check[maxRow][maxCol];
int n,m,s = 0,mx = 0;
// ให้ทำการ print ด้วยว่าขนาดของ component ที่ไปเจอมีกี่ช่อง
void dfs(int r,int c){
	s++;
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
				s = 0;
				dfs(i,j);
				if(s > mx){
					mx = s;
				}
				printf("size is %d\n",s);
			}
		}
	}
	printf("%d\n",count);
	printf("max size is %d\n",mx);
	return 0;
}
/*
5 4
..#.
.##.
..#.
.#.#
#.##

4 1 3 1
*/