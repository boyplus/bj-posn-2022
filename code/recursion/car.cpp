#include <cstdio>
using namespace std;
const int maxRow = 100, maxCol = 40;
int m,n,t;
bool A[maxRow+5][maxCol+5];
int answer[maxRow+5];
void rec(int r,int c){
	// Reach goal
	if(r == t){
		for(int i=0;i<t;i++){
			printf("%d\n",answer[i]);
		}
	} else {
		if(A[r+1][c-1]){
			answer[r] = 1;
			rec(r+1,c-1);
		}
		if(A[r+1][c]){
			answer[r] = 3;
			rec(r+1,c);
		}
		if(A[r+1][c+1]){
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
			A[i][j] = !x;
		}
	}
	rec(0,n);
	return 0;
}

/*

0 = ไม่มีสิ่งกีดขวาง
1 = มีสิ่งกีดขวาง
7 (m = จำนวนคอลัมน์)
5 (n = ตอนนี้อยู่ที่คอลัมน์ไหน)
5 (t = จำนวนแถว)

-------------
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 1 1 0 0 0 0
1 0 1 1 1 1 1


1 1 1 1 2


5
2
3
0 0 0 1 0
0 1 1 0 0
1 1 1 0 1


R R S
2 2 3

L = 1
R = 2
S = 3
*/