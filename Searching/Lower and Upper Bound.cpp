/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define eps       1e-9
#define MAX       100000
#define PI        acos(-1.0) //3.1415926535897932
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int upperbound(vector < int > x, int q){
    int right = x.size()-1;
    int left = 0;
    int up = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if(x[mid] > q){
            up = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return up;
}

int lowerbound(vector <int > x, int q){
    int right = x.size()-1;
    int left = 0;
    int low = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if (x[mid] == q){
            low = mid;
            right = mid -1;
        }
        else if(x[mid] > q){
            low = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return low;
}

int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    int n, q;
    cin >> n >> q;
    vector < int > x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    cout << upperbound(x, q) << endl;
    cout << lowerbound(x, q) << endl;
 
    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}