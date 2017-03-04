#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
int n,p;
int search(int i,long long x){
        if(a[n-1]<=x) return n;
	int left=i+1,right=n-1,mid;
	while(left<right){
		mid=(left+right)/2;
		if(a[mid]>x){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	return left;
}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans=1;
	for(int i=0;i<n;i++){
		long long x=a[i]*p;
		int j=search(i,x);
		ans=max(ans,j-i);
	}
	printf("%d\n",ans);
	return 0;
}
