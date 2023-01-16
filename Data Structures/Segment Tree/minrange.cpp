#include <stdio.h>

#define MAX              (int)(1e5+7)

int n, q, s, e;
int arr[MAX];
int segTree[(MAX << 1)];

void build_segTree(int index, int left, int right){
    if(left == right){
        segTree[index] = arr[left];
        return;
    }
    int mid = (left+right) >> 1;
    build_segTree((index << 1), left, mid);
    build_segTree((index << 1)+1, mid+1, right);

    segTree[index] = (segTree[(index << 1)] > segTree[(index << 1)+1]) ? segTree[(index << 1)+1]: segTree[(index << 1)];
}

int range_quary(int index, int left, int right){
    if(right < s or left > e) return MAX;
    if(left >= s and right <= e) return segTree[index];

    int mid = (left+right) >> 1;
    int left_min = range_quary((index << 1), left, mid);
    int right_min = range_quary((index << 1)+1, mid+1, right);

    return (left_min > right_min) ? right_min: left_min;
}

void solve(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    build_segTree(1, 1, n);
    while(q--){
        scanf("%d %d", &s, &e);
        printf("%d\n", range_quary(1, 1, n));
    }
}

int main(){

    int t; scanf("%d", &t);
    int cn = 0;
    while(t--){
        printf("Case %d:\n", ++cn);
        solve();
    }
 
}
