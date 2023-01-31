#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

class BIG_INT{
private:
    string result;
public:
    string bigfinder(string a, string b){
        if(a.size() < b.size()) swap(a, b);
        string d = b;
        reverse(full(b));
        while(b.size() < a.size()) b.pb('0');
        reverse(full(b));
        int i = 0;
        while(a[i]){
            if(a[i] > b[i]) return a;
            else if(a[i] < b[i]) return d;
            i++;
        }
        return "same";
    }
    llu stringtonumber(string a){
        llu n = 0;
        for(llu i = 0; a[i]; i++) n = ( n*10 ) + (a[i]-48);
        return n;
    }
    string add(string a,string b){
        result.clear();
        reverse(full(a));
        reverse(full(b));
        if(a.size() < b.size()) swap(a, b);
        while(b.size() < a.size()) b.pb('0');
        llu i = 0, carry = 0;
        while(a[i]){
            carry = carry + a[i]-48 + b[i]-48;
            result.pb((carry %10) + 48);
            carry = carry / 10;
            i++;
        }
        while(carry > 9){
            result.pb((carry % 10) + 48);
            carry = carry / 10;
        }
        if(carry != 0) result.pb(carry + 48);
        reverse(full(result));
        return result;
    }
    string subtraction(string a, string b){
        result.clear();
        bool flag = true;
        if(bigfinder(a, b) == b){
            swap(a, b);
            flag = false;
        }
        reverse(full(a));
        reverse(full(b));
        while(b.size() < a.size()) b.pb('0');
        int i = 0, carry = 0, x = 0;
        while(a[i]){
            if(b[i] > a[i]) x = (a[i]-48) + 10;
            else x = a[i]-48;
            carry = x-(carry + (b[i]-48));
            result.pb(carry+48);
            carry = x / 10;
            i++;
        }
        while(result[result.size()-1] == '0' and result.size() > 1) result.erase(result.size()-1, 1);
        if(!flag) result.pb('-');
        reverse(full(result));
        return result;
    }
    string multiplication(string a, string b){
        if(b.size() > a.size()) swap(a, b);
        reverse(full(a));
        reverse(full(b));
        while(a.size() > b.size()) b.pb('0');
        vector < string > x;
        for(llu i = 0; b[i]; i++){
            llu carry = 0;
            string str;
            for(llu j = 0; a[j]; j++){
                str += ((((b[i]-48)*(a[j]-48))+carry)%10)+48;
                carry = (((b[i]-48)*(a[j]-48))+carry)/10;
            }
            if(carry > 0) str += carry + 48;
            reverse(full(str));
            llu zero = i;
            while(zero--){
                str += '0';
            }
            x.pb(str);
        }
        llu len = x.size();
        if(len == 1) result = x[0];
        else{
            for(llu i = 0; i < len-1; i++){
                x[i+1] = add(x[i], x[i+1]);
            }
        }
        result = x[len-1];
        while(result[0] == '0' and result.size() > 1) result.erase(result.begin() + 0);
        return result;
    }
};

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    BIG_INT Int;
    cout << Int.multiplication("656545", "455") << endl;
 
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}