#include <algorithm>
#include <iostream>
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
void Merge(vector<T>& v, int left, int mid, int right) {
    vector<int> begin(v.begin() + left, v.begin() + mid + 1);
    vector<int> end(v.begin() + mid + 1, v.begin() + right + 1);
    int lsize = begin.size(), rsize = end.size();
    int k = left, i = 0, j = 0;
    while (i < lsize && j < rsize) {
        if (begin[i] <= end[j]) {
            v[k++] = begin[i++];
        } else {
            v[k++] = end[j++];
        }
    }

    while (i < lsize) {
        v[k++] = begin[i++];
    }
    while (j < rsize) {
        v[k++] = end[j++];
    }
    //Print(v);
}

template <class T>
void mergeSort(vector<T>& v, int left, int right) {
    if (left >= right) {
        return;
    }
    //cout << "进来了！！！" << endl;
    int mid = (left + right) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    Merge(v, left, mid, right);
}

//非递归
template <class T>
void mergeSort_Unrec(vector<T>& v, int size) {
    if (size < 2) {
        return;
    }
    int sz = 1;
    while (sz < size) {
        int begin = 0, mid = 0, end = 0;
        while (end < size) {
            end = begin + sz;
            mid = (begin + end) / 2;
            if (end >= size) {
                end = size - 1;
            }
            if (mid >= size) {
                mid = (begin + end) / 2;
            }
            Merge(v, begin, mid, end);
            begin = end + 1;
        }
        sz *= 2;  //步幅每次扩大两倍
    }  
}

int main() {
    vector<int> v = {3,4,5,6,2,1,9,8,20,10};
    //vector<int> v = {9, 3, 7, 6, 8, 2, 10, 4, 5};
    cout << "排序前：";
    Print(v);
    mergeSort_Unrec(v, v.size() - 1);
    cout << "排序后：";
    Print(v);
    return 0;
}