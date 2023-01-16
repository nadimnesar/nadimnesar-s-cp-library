#include <bits/stdc++.h>
using namespace std;
 
int n;
int arr[1000001];

void selection_sort(){
    for (int i = 0; i < n-1; i++){
        int min_idx = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}
 

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    selection_sort();
    
    for(int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}