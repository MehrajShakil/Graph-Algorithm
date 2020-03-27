
                                            //BISMILLAHIR RAHMANIR RAHEEM
                                                //ALLAH IS WATCHING ME

//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█


#include<bits/stdc++.h>
using namespace std;

#define ull    unsigned long long
#define ll    long long
#define ios    ios::sync_with_stdio(0);cin.tie(0);
#define ses   "\n"

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const int N=1e6+5;
const int M=(int)1e9+7;


/////////////////////////////////////////////////////////////////////////////
string s[1001];
ll ans[1001][1001];
int n,m,k;

void bfs(int x,int y,int x1,int y1){
ans[x][y]=0;
queue<pair<int,int> > q;
q.push(make_pair(x,y));
map<pair<int,int>,int> mp;
while(!q.empty()){
   ll xx=q.front().first;
   ll yy=q.front().second;
   q.pop();
  // mp[{xx,yy}]=1;
   for(int i=0;i<4;i++){
                ll xxx=xx;
                ll yyy=yy;
                       for(int j=0;j<k;j++){
                                xxx+=dx4[i];
                                yyy+=dy4[i];

                                if(xxx>=n || xxx<0 || yyy>=m || yyy<0 || s[xxx][yyy]=='#')break;
                                // cout<<xxx<<"  out "<<yyy<<" "<<ans[xxx][yyy]<<ses;
                                if(ans[xxx][yyy]>ans[xx][yy]+1){
                                ans[xxx][yyy]=ans[xx][yy]+1;
                               // cout<<xxx<<" "<<yyy<<" "<<ans[xxx][yyy]<<ses;
                                q.push(make_pair(xxx,yyy));
                                if(xxx==x1 && yyy==y1)return;
                                }
                       }
   }
}

}

////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 cin>>n>>m>>k;
 for(int i=0;i<n;i++){
      cin>>s[i];
 }
 for(int i=0;i<1001;i++){
      for(int j=0;j<1001;j++){
      ans[i][j]=1000000000;
 }
 }
 int x,y,x1,y1;
 cin>>x>>y>>x1>>y1;
 x--,y--,x1--,y1--;
 bfs(x,y,x1,y1);
 if(ans[x1][y1]==1000000000)cout<<-1;
 else cout<<ans[x1][y1];

}





//Alhamdulillah
