#include <bits/stdc++.h>
using namespace std;

class SLL{
private:
    typedef struct node{
        int data;
        struct node *next;
    } node;
    node *head = (node*)malloc(sizeof(node));
    node *tail = head;
    node *current;
    int isize = 0;
public:
    void insert_back(int value){
        tail -> data = value;
        tail -> next = (node*)malloc(sizeof(node));
        tail = tail -> next;
        isize++;
        //O(1)
    }
    void insert_at(int value, int position){
        node *new_node = (node*)malloc(sizeof(node));
        new_node -> data = value;
        if(position == 1){ new_node -> next = head; head = new_node; isize++; return; }
        node *prenode;
        current = head;
        int counter = 1;
        while(current != tail){
            counter++;
            prenode = current;
            current = current -> next;
            if(counter == position) break;
        }
        if(current == tail){
            cout << "Wrong Position." << endl;
            return;
        }
        new_node -> next = current;
        prenode -> next = new_node;
        isize++;
        //O(n)
    }
    int size(){ return isize; /*O(1)*/ }
    void print(){
        current = head;
        while(current != tail){
            cout << current -> data << endl;
            current = current -> next;
        }
        //O(n)
    }
    void clear(){ head = NULL; tail = head; isize = 0; /*O(1)*/ }
    void delete_at(int position){
        current = head;
        if(position == 1){ head = head -> next; free(current); isize--; return; }
        node *prenode;
        int counter = 1;
        while(counter != position){
            prenode = current;
            current = current -> next;
            counter++;
        }
        if(current == tail){ cout << "Wrong Position." << endl; return; }
        prenode -> next = current -> next;
        free(current);
        isize--;
        //O(n)
    }
    int search(int value){
        int counnter = 1;
        current = head;
        while(current != tail){
            if((current -> data) == value) return counnter;
            current = current -> next;
            counnter++;
        }
        return -1;
        //O(n)
    }
    void reverse_all(){
        node *prenode = tail;
        current = head;
        node *temp;
        while(current != tail){
            temp = current -> next;
            current -> next = prenode;
            prenode = current;
            current = temp;
        }
        head = prenode;
        //O(n)
    }
    void sorting(){
        node *currentI = head;
        node *currentJ;
        while(currentI != tail){
            currentJ = currentI -> next;
            while(currentJ != tail){
                if((currentI -> data) > (currentJ -> data)) swap(currentI -> data, currentJ -> data);
                currentJ = currentJ -> next;
            }
            currentI = currentI -> next;
        }
        //O(n*n)
    }
    void delete_all(int value){
        while(head -> data == value){
            node *temp = head;
            head = head -> next;
            free(temp);
            isize--;
        }
        current = head;
        node *prenode;
        while(current != tail){
            if(current -> data == value){
                prenode -> next = current -> next;
                node *temp = current;
                current = current -> next;
                free(temp);
                isize--;
                continue;
            }
            prenode = current;
            current = current -> next;
        }
        //O(n)
    }
};

int main(){
    SLL nesar;
    nesar.insert_back(5);
    nesar.insert_back(6);
    nesar.insert_at(7, 1);
    nesar.insert_back(7);
    nesar.sorting();
    nesar.reverse_all();
    nesar.delete_all(7);
    nesar.print();
}
