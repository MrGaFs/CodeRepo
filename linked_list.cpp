#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WAENINGS
#define print(x) cout << (x) << endl;
#define fill(x) cin >> (x);
#define pb push_back
#define ff first
#define ss second
#define dance ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define repi(n) for(ll i = 0;i<(n);++i)
#define repj(n) for(ll j = 0;j<(n);++j)
#define repi1(n) for(ll i = 1;i<(n);++i)
#define repj1(n) for(ll j = 1;j<(n);++j)
#define all(v) 			((v).begin()), ((v).end())
#define sz(v) 			((int)((v).size()))
#define lns length()
#define py printf("Yes\n")
#define pn printf("No\n")
typedef long long ll;
typedef long double ld;
using namespace std;
/*------------------------------------------------------*/


//My fanctions
bool isprime(ll n){
if( n ==2) return true;
if(n<2||n%2 == 0) return false;
for (ll r=3;r*r<=n;r+=2)
{
     if(n%r==0){
     return false;
     }
}
return true;
}

void arrprint(char arr[],ll n,char x){
repi(n){
cout<<arr[i]<<x;
}
}

void arrfill(char arr[],ll n){
repi(n){
cin>>arr[i];
}
}
bool ispal(string str){
string str_1=str;
reverse(all(str));
if (str==str_1)return 1;
else return 0;
}
ll fact(ll num){
ll n=1;
repi1(num+1){
n*=i;
}
return n;
}

bool isStr(string str_1, string str){
   int j = 0;
   for (int i=0; i<sz(str_1)&&j<sz(str); i++)
       if (str[j] == str_1[i])
         j++;
   return (j==sz(str));
}

ll gcd(ll l,ll r){
  ll a,b,c=0;
a=max(l,r);
b=min(l,r);
for(;b!=0;){
c=b;
b=a%b;
a=c;
}
return abs(a);
}

/*
       ||==========||
       ||          ||
       ||          ||
       ||          ||
       ||          ||
       ||          ||
 \\=====|          |=====//
  \\                    //
   \\                  //
    \\                //
     \\              //
      \\            //
       \\          //
        \\        //
         \\      //
          \\    //
           \\  //
           \\//

*/
//Code start here
//priority_queue<int,vector<int>,greater<int> > mypq;
//cout<< fixed << setprecision(x)<< variable << endl
struct node{
          ll num;
          node* link;
};
node* head;
void addl(ll n){
  node* temp;
  temp=new node;
  temp->link=head;
  temp->num=n;
  head=temp;
}
void pop(){
node* temp=head;
  cout<<head->num;

  head=head->link;

  delete temp;

}
void erase (ll n){
node* nu=head;
node* temp=head;
node* s=head;
  do{
     if (nu->num==n&&nu!=head){
       temp->link=nu->link;
       s=nu;
       nu = nu -> link ;
          delete s;
     }
     else if (nu->num==n&&nu==head){
       s=head;
       head=head->link;
       delete s;
     }
     temp = nu;
     nu = nu -> link ;
} while(nu->link!=NULL);

}

int main(){
      dance;
       node* nu;
       head = new node ;
       ll n,t;
       cin >>t;
       head->num=0;
       head->link=NULL;
            repi (t){
                cin>>n;
              addl(n);
             }
           erase(3);
           nu=head;
              do{
                 cout<<nu->num<<" ";
                 nu=nu->link;
            } while(nu->link!=NULL);
    }
