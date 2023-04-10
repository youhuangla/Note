#include <stdio.h>
const int N=1e5+10;
int n,a[N],f[N],g[N],ans=0x3f3f3f3f;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        f[i]=g[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);
            if(a[j]>a[i]) g[i]=max(g[i],g[j]+1);
        }
    }
    for(int i=1;i<=n;i++) ans=min(ans,n-f[i]+1),ans=min(ans,n-g[i]+1);
    printf("%d\n",ans);
    return 0;
}