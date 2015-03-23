#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

const int maxn=10010;

int D[10][10][2][2];
char S[maxn];
int dp[maxn][2];

int abs(int x)
{
    return x>0?x:-x;
}

void load_D()
{

    for(int sn=0;sn<10;++sn)
        for(int tn=0;tn<10;++tn)
    {
        int ans=0;

        int sx=(sn-1)/3;
        int sy=(sn-1)%3;
        int tx=(tn-1)/3;
        int ty=(tn-1)%3;

        if(sn==0)
        {
            sx=3;
            sy=1;
        }

        if(tn==0)
        {
            tx=3;
            ty=1;
        }

        ans=abs(sx-tx)+abs(sy-ty);

        D[sn][tn][0][0]=ans;
        D[sn][tn][1][1]=ans;

        if(sy<ty)
        {
            D[sn][tn][0][1]=ans-1;
            D[sn][tn][1][0]=ans+1;
        }
        else if(sy>ty)
        {
            D[sn][tn][0][1]=ans+1;
            D[sn][tn][1][0]=ans-1;
        }
        else if(sy==ty)
        {
            D[sn][tn][0][1]=ans+1;
            D[sn][tn][1][0]=ans+1;
        }
    }
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);

    load_D();

    int T;
    scanf("%d",&T);

    while(T--)
    {
        memset(S,0,sizeof(S));
        memset(dp,0,sizeof(dp));

        scanf("%s",S+1);
        S[0]='1';

        int n=strlen(S);

        for(int i=1;i<n;++i)
        {
            for(int j=0;j<2;++j)
                dp[i][j]=min( dp[i-1][0]+ D[S[i-1]-'0'][S[i]-'0'][0][j] , dp[i-1][1]+ D[S[i-1]-'0'][S[i]-'0'][1][j]);
        }

        cout<<min( dp[n-1][0],dp[n-1][1])<<endl;
    }
}
