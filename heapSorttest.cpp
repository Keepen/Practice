#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(vector<int>&v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}
//建立大堆，排升序
template <class T>
void adjustDown(vector<T>& v, int pos, int size){
    int parent = pos;
    int left = parent * 2 + 1, right = parent * 2 + 2;
     int max = left;
    while(left < size){ 
        if(right < size && v[left] < v[right]){
            max = right;
        }
        if(v[max] <= v[parent]){
            return;
        }
        swap(v[parent], v[max]);
        parent = max;
        left = parent * 2 + 1;
        right = parent * 2 + 2;
        max = left;
    }
}

template <class T>
void createHeap(vector<T>&v){
    int size = v.size();
    for(int i = size / 2;i >=0;--i){
        adjustDown(v, i, size);
    }
}

template <class T>
void heapSort(vector<T>& v){
    int size = v.size();
    createHeap(v);
    cout << "建堆：";
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
    for(int i = size - 1;i >= 1;--i){
        swap(v[0], v[i]);
        adjustDown(v, 0, i);
    }
}

int main(){
    vector<int> v = {5,1,2,3,9,8,6,7,10,2};
    //vector<int> v = {10,11,22,7,3,5,9,0,1,3,4,2,6};
    cout << "排序前：";
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
    heapSort(v);
    cout << "排序后：";
        for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}