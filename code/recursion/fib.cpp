// 1,1,2,3,5,8,13,...
#include <cstdio>
using namespace std;
int fib(int n){
	if(n == 1 || n == 2) return 1;
	return fib(n-1) + fib(n-2);
}
int main(){
	int n;
	scanf("%d",&n);
	int ans = fib(n);
	printf("%d\n",ans);
	return 0;
}