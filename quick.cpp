#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

template <class T>
int part(vector<T>& v, int left, int right){
    int begin = left, end = right;
    T pivot = v[right];
    while(begin < end){
        while(begin < end && v[begin] <= pivot){
            ++begin;
        }
        v[end] = v[begin];
        while(begin < end && v[end] > pivot){
            --end;
        }
        v[begin] = v[end];
    }
    v[begin] = pivot;
    return begin;
}

template <class T>
void quickSort(vector<T>& v, int left, int right){
    if(left >= right){
        return;
    }
    int mid = part(v, left, right);
    quickSort(v, left, mid - 1);
    quickSort(v, mid, right);
}

template <class T>
void quickSortUnrec(vector<T>& v, int size){
    if(size < 2){
        return;
    }
    int left = 0, right = size - 1;
    stack<T> s;
    s.push(right);
    s.push(left);
    while(!s.empty()){
        left = s.top();
        s.pop();
        right = s.top();
        s.pop();
        if(right - left > 1){
            int mid = part(v, left, right);
            s.push(mid - 1);
            s.push(left);

            s.push(right);
            s.push(mid);
        }
    }
}


template <class T>
void Print(vector<T>& v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {2,5,4,3,1,6,7,8,90,23,45,43,18};
    cout << "排序前: ";
    Print(v);
    quickSortUnrec(v, v.size() );
    cout << "排序后： ";
    Print(v);
    return 0;
}