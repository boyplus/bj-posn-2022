#include <cstdio>
using namespace std;
const int maxK = 100;
char answer[maxK*2+5] = "";
void rec(int k,int a,int b,int index){
	if(a == k || b == k){
		for(int i=0;i<index;i++){
			printf("%c ",answer[i]);
		}
		printf("\n");
	} else {
		answer[index] = 'W';
		rec(k,a+1,b,index+1);
		answer[index] = 'L';
		rec(k,a,b+1,index+1);
	}
}
int main(){
	int k,a,b;
	scanf("%d %d %d",&k,&a,&b);
	rec(k,a,b,0);
	return 0;
}