#include <bits/stdc++.h>
using namespace std;
 
int n;
int arr[1000001];

void insertion_sort(){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    insertion_sort();
    
    for(int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}