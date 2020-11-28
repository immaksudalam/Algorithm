/*
    we just want to calculate a^n;
    if we illustrate n in binary value
    let n = 13, its binary is 1101
      so n =               1* 2^3 +1* 2^2+ 0* 2^1+ 1* 2^0
    Now, let a=3 and n = 13;
    then a^n = 3^13 = 3^(1101) = 3^(1*8 + 1*4 + 0*2 + 1 * 1)
                    = 3^8 + 3^4 + 3^0 + 3^1

*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll binpow1(ll a, ll n)
{
    ll result =1;
    while(n>0){
        if(n&1){
            result = result * a;
        }
        a = a*a;  // current value is the square of left one.
        n>>=1;
    }
    return result;
}
ll binpow2(ll a, ll n, ll m)
{
    ll result =1;
    while(n>0){
        if(n&1){
            result = result *a;
            result%=m; // find mod value.
        }
        a*=a;
        a%=m; // find mod value;
        n = n>>1;
    }
    return result;
}
// Binary exponensiation using tree logic;
/*
     let a = 3 and n = 9;

              3^9
            /  \  \
          3^4  3^4  3^1
         /  \
        3^2  3^2
       /   \
       3^1  3^1
     now lets try to calculate it recursively.

*/

ll binpow3(ll a, ll n)
{
    if(n==1) return a;
    ll result = binpow3(a, n/2);
    if(n%2==0) return result * result;
    else return result * result *a;

}
ll binpow4(ll a, ll n, ll m)
{
    if(n==1)return a;
    ll result = binpow4(a, n/2, m);
    if(n%2 == 0) return ((result *result) % m);
    else return ((result * result * a) %m);
}
int main()
{
   int t;
   cin>>t;
   while(t--){
       ll a, n, m;
       cin>>a>>n>>m;
       cout<< binpow4(a, n, m)<<endl;
   }
   cin>>t;


}
