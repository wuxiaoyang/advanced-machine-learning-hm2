#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int D[10][10][2][2];

int abs(int x)
{
    return x>0?x:-x;
}

int main()
{
    freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);

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

        ans=abs(sx-tx)+abs(sy-ty)

        D[sn][tn][0][0]=ans;
        D[sn][tn][1][1]=ans;

        if(sx<tx)
        {
            D[sn][tn][0][1]=ans-1;
            D[sn][tn][1][0]=ans+1;
        }
        else if(sx>tx)
        {
            D[sn][tn][0][1]=ans+1;
            D[sn][tn][1][0]=ans-1;
        }
        else if(sx==tx)
        {
            D[sn][tn][0][1]=ans+1;
            D[sn][tn][1][0]=ans+1;
        }
    }

    cout<<D[6][0][0][0]<<endl;
}
