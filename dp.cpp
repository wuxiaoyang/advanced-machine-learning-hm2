#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
const int INF = 50000000;
int dp[10010][2];
int dist(int from,int to){
    if(from>to){
        swap(from,to);
    }

    int rf = (from-1)/3;
    int rt = (to-1)/3;
    int cf = (from-1)%3;
    int ct = (to-1)%3;

    int res = abs(rf-rt)+abs(cf-ct);
    return res;
}
int act_pos(int key, int off){
    return key+off;
}
int solve(char* seq){
    dp[0][0] = 0;
    dp[0][1] = 0;

    int len = strlen(seq);
    for(int i=1;i<len;++i){
        int target = seq[i]-'0';
        if(target==0){
            target = 11;
        }
        seq[i] = char(target);
        int x1,x2;
        if(target==2 || target==5 || target==8 || target==11){
            x1 = dp[i-1][0] + dist(act_pos(seq[i-1], 0), act_pos(seq[i],0));
            x2 = dp[i-1][1] + dist(act_pos(seq[i-1], 1), act_pos(seq[i],0));
            dp[i][0] = min(x1,x2);
            x1 = dp[i-1][0] + dist(act_pos(seq[i-1], 0), act_pos(seq[i],1));
            x2 = dp[i-1][1] + dist(act_pos(seq[i-1], 1), act_pos(seq[i],1));
            dp[i][1] = min(x1,x2);
        } else if(target == 1 || target==4 || target==7){
            dp[i][0] = INF;

            x1 = dp[i-1][0] + dist(act_pos(seq[i-1], 0), act_pos(seq[i],1));
            x2 = dp[i-1][1] + dist(act_pos(seq[i-1], 1), act_pos(seq[i],1));
            dp[i][1] = min(x1,x2);
        } else {
            dp[i][1] = INF;
            x1 = dp[i-1][0] + dist(act_pos(seq[i-1], 0), act_pos(seq[i], 0));
            x2 = dp[i-1][1] + dist(act_pos(seq[i-1], 1), act_pos(seq[i], 0));
            dp[i][0] = min(x1,x2);
        }
    }
    return min(dp[len-1][0], dp[len-1][1]);
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int ncase;
    cin>>ncase;
    char line[10010];
    line[0] = 1;
    while(ncase>0){
        --ncase;
        cin>>(line+1);
        cout<<solve(line)<<endl;
    }
}
