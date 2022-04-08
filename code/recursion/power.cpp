// Find a^b (a,b are positive integers)
#include <cstdio>
using namespace std;
int power(int a,int b){
	if(b == 0) return 1;
	return power(a,b-1)*a;
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int ans = power(a,b);
	printf("%d\n",ans);
	return 0;
}