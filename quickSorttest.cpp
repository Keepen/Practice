#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <class T>
void Print(vector<T>& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}


template <class T>
int part(vector<T>& v, int left, int right) {
    int begin = left, end = right;
    int pivot = v[right];
    while (begin < end) {
        while (begin < end && v[begin] <= pivot) {
            ++begin;
        }
        v[end] = v[begin];
        while (begin < end && v[end] >= pivot) {
            --end;
        }
        v[begin] = v[end];
    }
    v[begin] = pivot;
    return begin;
}

//非递归
template <class T>
void quickSort(vector<T>& v, int size) {
    int left = 0, right = size - 1;
    stack<T> s;
    s.push(right);
    s.push(left);
    while (!s.empty()) {
        left = s.top();
        s.pop();
        right = s.top();
        s.pop();
        if (right - left > 1) {
            int mid = part(v, left, right);
            s.push(mid - 1);
            s.push(left);

            s.push(right);
            s.push(mid);
        }
    }
}

//递归
template <class T>
void quickSort_R(vector<T>&v, int left, int right){
    if(left >= right || right - left == 1){
        return;
    }
    int mid = part(v, left, right);
    quickSort_R(v, left, mid - 1);
    quickSort_R(v, mid, right);
}

template <class T>
void quickSort2(vector<T>&v, int size){ 
    quickSort_R(v, 0, size - 1);
}
int main() {
    vector<int> v = {9, 3, 7, 6, 8, 2, 10, 4, 5};
    cout << "排序前：";
    Print(v);
    quickSort2(v, v.size());
    Print(v);
    return 0;
}
