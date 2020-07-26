#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

template <class T>
void Print(vector<T>& v){
    for(auto& i:v){
        cout << i << " ";
    }
    cout << endl;
}

//此处用挖坑法来分割区间
template <class T>
int Div(vector<T>& v, int left, int right){
    int begin = left, end = right;
    int piv = v[right];
    while(begin < end){
        while(begin < end && v[begin] <= piv){
            ++begin;
        }
        v[end] = v[begin];
        while(begin < end && v[end] >= piv){
            --end;
        }
        v[begin] = v[end];
    }
    v[begin] = piv;
    return begin;
}

template <class T>
void quickSort(vector<T>& v, int size){
    stack<T> s;     //保存区间的边界
    int left = 0, right = size - 1;
    s.push(right);
    s.push(left);
    while(!s.empty()){
        left = s.top();
        s.pop();
        right = s.top();
        s.pop();
        if(right - left > 1){
            int mid = Div(v, left, right);
            s.push(mid - 1);
            s.push(left);

            s.push(right);
            s.push(mid);
        }
    }
}

int main(){
    //vector<int> v = {5,1,2,3,9,8,6,7,10,2};
    vector<int> v = {9, 3, 7, 6, 8, 2, 10, 4, 5};
    cout << "排序前：";
    Print(v);
    quickSort(v, v.size());
    cout << "排序后：";
    Print(v);
    return 0;
}

