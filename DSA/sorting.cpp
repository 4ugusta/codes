#include <bits/stdc++.h>
using namespace std;

//Sorting array and vector of n size
void vectorandarr(){
        int arr[] = {1, 3, 6, 8, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.emplace_back(9);
    v.insert(v.begin(),3);

    for(auto it : v){
        cout<<it<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end());
    for(auto it : v){
        cout<<it<<" ";
    }
}
//Sorting in my way
bool comp(pair<int,int>p1, pair<int,int>p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    //they are same
    if(p1.first>p2.first) return true;
    return false;
}
void myway(){
    //sort it according to the second element
    //if second element is same, then sort
    //it according to first element but 
    //in descending
    pair<int,int> a[] = {{1,5} ,{2,1}, {4,1}};
    sort(a, a+3,comp);
    for(int i=0;i<3;i++){
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
}
//Selection Sort
void selection_sort(int arr[],int n){
    for(int i=0; i<=n-2; i++){
        int mini = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
        //swap(arr[mini],arr[i]);
    }
}
//Bubble Sort
void bubble_sort(int arr[],int n){
    for(int i=n-1;i>=1;i--){
        int didSwap = 0;
        for(int j=0; j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap==0){
            break;
        }
    }
}
//Insertion Sort
void insertion_sort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
//Merge Sort
void merge(int arr[],int low,int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i - low];
    }
}
void merge_sort(int arr[],int low,int high){
    if(low == high) return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
//Quick Sort
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        quick_sort(arr,low,pIndex-1);
        quick_sort(arr,pIndex+1,high);
    }
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    selection_sort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
