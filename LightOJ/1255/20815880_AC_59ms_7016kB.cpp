#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e6 + 10;

char a[maxn], b[maxn];
int nex[maxn];

void getNext(char *str)
{
	int n = strlen(str), i = 0, j = -1;
	nex[i] = j;
	while(i < n)
	{
		if(j == -1 || str[i] == str[j]) nex[++ i] = ++j;
		else j = nex[j];
	}
}

int KMP()
{
	int n = strlen(a), m = strlen(b);
	getNext(b);
	int i = 0, j = 0, ans = 0;
	while(i < n && j < m)
	{
		if(j == -1 || a[i] == b[j]) i ++, j ++;
		else j = nex[j];
		if(j == m) j = nex[j], ans ++;
	}
	return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int _ = 1; _ <= t; _ ++)
    {
        scanf("%s%s", a, b);
        printf("Case %d: %d\n", _, KMP());
    }
    return 0;
}
