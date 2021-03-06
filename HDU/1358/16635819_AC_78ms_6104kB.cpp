#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e6+10;

char a[maxn];
int nex[maxn];

void getNext(int n)
{
	int i=0,j=-1;
	nex[0]=-1;
	while(i<n)
	{
		if(j==-1||a[i]==a[j]) nex[++i]=++j;
		else j=nex[j];
	}
}

int main()
{
	int n,_=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		scanf("%s",a);
		getNext(n);
		printf("Test case #%d\n",++_);
		for(int i=1;i<=n;i++)
			if(i%(i-nex[i])==0&&i/(i-nex[i])>1)
				printf("%d %d\n",i,i/(i-nex[i]));
		printf("\n");
	}
	return 0;
}

