#include <bits/stdc++.h>
using namespace std;

#define llu                 long long unsigned int
#define ll                  long long int

#define max                 (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define base                (ll)(69)

ll hashTable[max];
ll basePow[max];

void init(){
    basePow[0] = 1;
    for(ll i = 1; i < max; i++){
        basePow[i] = (basePow[i-1]*base)%mod;
    }
}

ll get_hashValue(string &str){
    ll res = 0;
    for(ll i = 0; str[i]; i++){
        res *= base;
        res %= mod;
        res += (str[i] - 'a' + 1);
    }
    return res;
}

void build_hashTable(string &str){
    hashTable[0] = (str[0] - 'a' + 1);
    for(ll i = 1; str[i]; i++){
        hashTable[i] = ((hashTable[i-1]*base)%mod + (str[i] - 'a' + 1))%mod;
    }
}

ll get_subHash(ll left, ll right){
    return (ll)((hashTable[right]+mod) - ((hashTable[left-1]*basePow[right-left+1])%mod))%mod;
}

int main(){

    init();
    ll n;
    string sub, str;

    while(cin >> n){
        cin >> sub >> str;

        build_hashTable(str);
        ll value = get_hashValue(sub);

        ll len = str.size();
        bool ok = false;
        for(int i = 0; i < len-(n-1); i++){
            if(get_subHash(i, i+(n-1)) == value){
                cout << i << endl;
                ok = true;
            }
        }
        if(!ok) cout << endl;
    }
}