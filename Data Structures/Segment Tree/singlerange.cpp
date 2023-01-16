#include <stdio.h>

#define MAX              (int)(1e5+7)

int n, q, temp, i, v, j;
char type;
int arr[MAX];
int segTree[MAX * 4];

void build_segTree(int index, int left, int right){
    if(left == right){
        segTree[index] = arr[left];
        return;
    }

    int mid = (left+right) >> 1;
    build_segTree((index << 1), left, mid);
    build_segTree((index << 1)+1, mid+1, right);

    segTree[index] = (segTree[(index << 1)] * segTree[(index << 1)+1]);
}

void single_quary(int index, int left, int right){
    if(right < i or left > i) return;
    if(left == i and right == i){
        segTree[index] = v;
        return;
    }

    int mid = (left+right) >> 1;
    single_quary((index << 1), left, mid);
    single_quary((index << 1)+1, mid+1, right);

    segTree[index] = (segTree[(index << 1)] * segTree[(index << 1)+1]);
}

int range_quary(int index, int left, int right){
    if(right < i or left > j) return 1;
    if(left >= i and right <= j) return segTree[index];

    int mid = (left+right) >> 1;
    int left_product = range_quary((index << 1), left, mid);
    int right_product = range_quary((index << 1)+1, mid+1, right);

    return (left_product*right_product);
}

void solve(){
    while(~scanf("%d %d", &n, &q)){
        for(int k = 1; k <= n; k++){
            scanf("%d", &temp);
            (temp < 0) ? arr[k] = -1: (temp == 0) ? arr[k] = 0: arr[k] = 1; 
        }
        getchar();
        build_segTree(1, 1, n);

        while(q--){
            scanf("%c", &type);
            if(type == 'C'){
                scanf("%d %d", &i, &v);
                getchar();
                (v < 0) ? v = -1: (v == 0) ? v = 0: v = 1;
                single_quary(1, 1, n);
            }
            else{
                scanf("%d %d", &i, &j);
                getchar();
                int res = range_quary(1, 1, n);
                char newres; (res < 0) ? newres = '-': (res == 0) ? newres = '0': newres = '+';
                printf("%c", newres); 
            }
        }
        printf("\n");
    }
}

int main(){

    // int t; scanf("%d", &t);
    // int cn = 0;
    // while(t--){
        // printf("Case %d:\n", ++cn);
        solve();
    // }
 
}
