#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];

void marge(int left, int mid, int right){
    int leftsize = (mid-left)+1;
    int rightsize = (right-mid);

    int leftarray[leftsize], rightarray[rightsize];
    for(int i = 0; i < leftsize; i++) leftarray[i] = arr[left+i];
    for(int i = 0; i < rightsize; i++) rightarray[i] = arr[mid+i+1];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < leftsize and j < rightsize){
        if(leftarray[i] <= rightarray[j]){
            arr[k] = leftarray[i];
            k++;
            i++;
        }
        else{
            arr[k] = rightarray[j];
            k++;
            j++;
        }
    }

    while(i < leftsize){
        arr[k] = leftarray[i];
        i++;
        k++;
    }

    while(j < rightsize){
        arr[k] = rightarray[j];
        k++;
        j++;
    }
}

void margesorting(int left, int right){
    if(left >= right) return;
    int mid = left + (right-left)/2;
    margesorting(left, mid);
    margesorting(mid+1, right);
    marge(left, mid, right);
}

voi

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    margesorting(0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}