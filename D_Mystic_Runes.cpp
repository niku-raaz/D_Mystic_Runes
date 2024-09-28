 
  
// JITNA BHI DEKHU, DIL BHAR NA PAAYE 
// KAISA SAMAA HAI, HUM TUM YAHA HAI
// JAAHIR KARU KYA HAI JO, MERE IRAADAY
   
   
#include <bits/stdc++.h>
using namespace std;
   
#define int long long 
#define ll long long 
#define nl cout<<endl; 
#define raaz ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define take(n) int n; cin>>n;
#define takearr(a,n)  int a[n]; for(int i=0; i<n; i++) cin>>a[i];
#define takevec(a,n)  vector<int> a(n); for(int i=0; i<n; i++) cin>>a[i];
#define sortv(v) sort(v.begin(),v.end());
#define sortarr(arr,n) sort(arr,arr+n);
#define show(ds) for(auto it: ds) cout<<it<<" ";cout<<endl;
#define pb push_back
#define pl cout<<endl;
#define ps cout<<" ";
#define pY cout<<"YES"<<endl;
#define pN cout<<"NO"<<endl;
#define py cout<<"Yes"<<endl;
#define pn cout<<"No"<<endl;
#define ff(i,a,n) for(int i = a;i<n;i++)
#define fl(i,a,n) for(int i = n-1;i>=a;i--)
   
   
bool isPrime(int n){
      if(n<=1){
      return false;
      }
   for(int i = 2;i*i<=n;i++){
     if(n%i==0){
     return false;
       }
    }
  return true;
    }
   
   
   
bool sbs(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
   }
   
long long binpow(long long a, long long b, long long m) {
   a %= m;
   long long res = 1;
   while (b > 0) {
        if (b & 1)
          res = res * a % m;
        a = a * a % m;
        b >>= 1;
   }
  return res;
}  
   

void solve(){
    take(n);
    take(m);

    map<char,char> mp;

    int ct=0;
    
    char i='2';
    for(char ch='a';ch<='z';ch++){

        mp[ch]=i;
        ct++;

        if(ct==3){
            i++;
            ct=0;
        }

    }

    mp['s']='7';
    mp['v']='8';
    mp['y']=mp['z']='9';


    vector<string> v(n);

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        string tmp="";
        for(int j=0;j<s.size();j++){
            tmp+=mp[s[j]];

        }

        v[i]=tmp;


    }

    sortv(v);

  //  show(v);

    for(int xy=0;xy<m;xy++){
        string num;
        cin>>num;

        int sz=num.size();


        // binary search for leftmost 
        int a=INT_MAX;

        int lo=0;
        int hi=n-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            // if(v[mid].size()<sz){

            // }

            string zz=v[mid].substr(0,sz);



            if(zz>=num){

                 if(zz==num){
                   a=min(a,mid);
                }

                hi=mid-1;
            }else{

               
                
                lo=mid+1;
                
            }


        }


        // binary search for rightmost
        int b=-1;

        lo=0;
        hi=n-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            string zz=v[mid].substr(0,sz);

            if(zz>num){

             //   cout<<lo<<" "<<hi;pl;
                hi=mid-1;
                

            }else{

              //  cout<<lo<<" "<<hi;pl;
                if(zz==num){
                    b=max(b,mid);
                }
                lo=mid+1;
            }


        }
        
       // cout<<a<<" "<<b;pl;

        if(b==-1 ){
            cout<<0;pl;
        }else{
            cout<<b-a+1;pl;

        }

        



    }


    


        
}
   
   
   
int32_t main(){
        raaz
        int test_case=1; 
      //  cin>>test_case; 
        while(test_case--){
                  solve();
              }
   return 0;
   }
