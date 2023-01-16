#include <bits/stdc++.h>
using namespace std;
 
int n;
int arr[1000001];

void bubble_sort(){
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubble_sort();
    
    for(int i = 0; i < n; i++)
        printf("%d\n", arr[i]);

    return 0;
}