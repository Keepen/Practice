#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void Print(vector<T>& v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}


template <class T>
void adjustDown(vector<T>& v, int pos, int size){
    int parent = pos;
    int left = parent * 2 + 1, right = parent * 2 + 2;
    int max = left;
    while(left < size){
        if(right < size && v[right] > v[left]){
            max = right;
        }
        if(v[max] <= v[parent]){
            return;
        }
        swap(v[max], v[parent]);
        parent = max;
        left = parent * 2 + 1;
        right = parent * 2 + 2;
        max = left;
    }
}

template <class T>
void adjustUp(vector<T>& v, int pos, int size){
    int child = pos, parent = (pos - 1) / 2;
    while(child > 0 && child > parent){
        if(v[child] > v[parent]){
            swap(v[child], v[parent]);
        }
        else{
            break;
        }
        child = parent;
        parent = (parent - 1) / 2;
    }
}


template <class T>
void createHeap(vector<T>& v, int size){
    for(int i = 0;i < size;++i){
        adjustUp(v, i, size);
    }
}

template <class T>
void heapSort(vector<T>& v, int size){
    createHeap(v, size);
    Print(v);
    for(int i = size - 1;i >= 1;--i){
        swap(v[0], v[i]);
        //adjustDown(v, 0, i);
        //adjustUp(v, i - 1, i);
        createHeap(v, i);
    }
}


int main(){
    vector<int> v = {2,5,4,3,1,6,7,8,90,23,45,43,18};
    cout << "排序前: ";
    Print(v);
    heapSort(v, v.size());
    cout << "排序后：";
    Print(v);
    return 0;
}