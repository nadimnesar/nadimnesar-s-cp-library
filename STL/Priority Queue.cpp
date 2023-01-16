#include <bits/stdc++.h>
using namespace std;

void showpq1(priority_queue<int> gq) {
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

void showpq2(priority_queue<int, vector<int>, greater<int> > gq) {
    priority_queue<int, vector<int>, greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

void increasing() {
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    cout << "The priority queue pq is : ";
    showpq2(pq);

    cout << "\npq.size() : " << pq.size();
    cout << "\npq.top() : " << pq.top();

    cout << "\npq.pop() : ";
    pq.pop();
    showpq2(pq);
}

void decreasing() {
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    cout << "The priority queue pq is : ";
    showpq1(pq);

    cout << "\npq.size() : " << pq.size();
    cout << "\npq.top() : " << pq.top();

    cout << "\npq.pop() : ";
    pq.pop();
    showpq1(pq);
}

int main()
{
    decreasing();
    increasing();
    return 0;
}
