
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

map<pair<ll,ll> ,ll > mp;  // use STL map for visited or not ...

string s[21];
ll ans=1;      // initially ans=1 because answer contain prince location also

ll BFS(ll x,ll y,ll w,ll h){
 mp.clear();       // at first clear the map..because i use several test case.
ans=1;
queue<pair<ll,ll> > q;   // queue using pair for store x and y
q.push(make_pair(x,y));   // initially i push the princes initial location....

while(!q.empty()){       //while queue size greater than 0.
     ll xx=q.front().first;  // here i store x-axis index
     ll yy=q.front().second; // y-axis index
     q.pop();   // delete those index from the queue
     mp[{xx,yy}]=1;  // mark index as visited
     for(ll i=0;i<4;i++){    // here i use 4-direction array for searching land
                ll xxx = xx+dx4[i];
                ll yyy = yy+dy4[i];
                if(xxx>=h || yyy>=w ||  xxx<0 || yyy<0 || s[xxx][yyy]=='#' || mp[{xxx,yyy}])continue;
                else{
                        q.push(make_pair(xxx,yyy));
                        ans++;
                        mp[{xxx,yyy}]=1;
                }
     }
     //if(has==4)return ans;
}
return ans;   // finally return the answer.
}

////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main(){
ll t,tc=0;
cin>>t; //test case
while(t--){
ll w,h,x,y; // h is the number of line and w is represented containing of character of each line
cin>>w>>h;
for(ll i=0;i<h;i++){
cin>>s[i];    // input the string
for(ll j=0;j<w;j++){
                if(s[i][j]=='@'){       // find the location of initial position of prince
                                x=i;    // x for row
                                y=j;    // y  for column
                }
}
}
cout<<"Case "<<++tc<<": "<<BFS(x,y,w,h)<<ses; // BFS function containing with 4 parameter
}

}





//Alhamdulillah
