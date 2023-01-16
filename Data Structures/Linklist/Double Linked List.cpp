#include <bits/stdc++.h>
using namespace std;

class DLL{
private:
    typedef struct node{
        struct node *left;
        int data;
        struct node *right;
    } node;
    node *head = NULL;
public:
    void print(){

    }
    void insert_back(int value){
        if(head == NULL){
            head = (node*)malloc(sizeof(node));
            head -> data = value;
            head -> left = NULL;
            head -> right = NULL;
            return;
        }
        /*node *temp = (node*)malloc(sizeof(node));
        temp -> data = value;
        temp -> left = tail -> right;
        tail = temp;*/
    }
    /*void insert_front(int value){
        if(head == NULL){


            return;
        }
        node *temp = (node*)malloc(sizeof(node));
        temp -> data = value;
        temp -> left = tail -> right;
        tail = temp;
    }*/
};

int main(){
    DLL nesar;
    nesar.insert_back(5);

}
