#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool ispossible( string s, string t )
{
    int n = s.size();
    for( int i =0; i<n; i++ ){
        if( s[i] =='#' and t[i] =='#' )return false;
    }
    return true;
}
void solve(){
    string s,t;
     cin >> s >> t;
    if( !ispossible(s,t)){
        cout<<"No\n";
        return ;
    }
    int n = s.size();
    string arr[2];
    arr[0] = s;
    arr[1] =t;

    int ihashf = n;
    int ihashs = n;

    for( int i =0; i<n; i++ ){
        if( s[i] =='#' ){
            ihashf = i;
            break;
        }
    }

    for( int i =0; i<n; i++ ){
        if( t[i] =='#' ) {
            ihashs = i;
            break;
        }
    }

    if( ihashf == n || ihashs == n ){
        cout<<"Yes\n";
        cout<<0<<endl;
        return;
    }

    if( ihashf > ihashs ){
        int lane = 0;
        int ans =0 ;
        for( int i =0; i<n; i++ ){
            if( arr[lane][i] == '#' ){
                ans++;
                lane ^=1;
            }
        }
        cout<<"Yes\n";
        cout<<ans<<endl;
        return;
    }

    int lane = 1;
    int ans =0;
    for( int i =0; i<n; i++ ){
        if( arr[lane][i] == '#' ){
            ans++;
            lane ^=1;
        }
    }

    cout<<"Yes\n";
    cout<<ans<<endl;

}
int main() {
    ll t; cin >> t ;
    while(t--){
       solve();
    }
    return 0;
}
