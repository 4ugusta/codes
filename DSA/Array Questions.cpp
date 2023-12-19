#include<bits/stdc++.h>
using namespace std;
//largest element in an array
void largest_ele(int arr[],int n){
    int largest = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    cout<<largest;
}
//second largest element in an array
void slargest_ele(int arr[],int n){
    int largest = arr[0];
    int slargest = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    cout<<slargest;
}
//check if array is sorted
int check_arr(int arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){
            
        }
        else{
            return false;
        }
    }
    return true;
}
//Remove duplicates in place from sorted array
void removeDup(int arr[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    cout<<i+1;
}
//Left rotate the array by one place
void rotateArray(int arr[],int n){
    int temp = arr[0];
    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1]=temp;
}
//Left rotate the array by D place
void leftRotate(int arr[],int n,int d){
    // d = d%n;
    // int temp[d];
    // for (int i=0; i<d; i++){
    //     temp[i]=arr[i];
    // }
    // for(int i=d;i<n;i++){
    //     arr[i-d]=arr[i];
    // }
    // for(int i=n-d;i<n;i++){
    //     arr[i] = temp[i-(n-d)];
    // }
    //or (optimal solution)
    // reverse(arr,arr+d);
    // reverse(arr+d,arr+n);
    // reverse(arr,arr+n);
    //Or
    vector<int> ret; 
	for (int i = 0; i < n; i++) {
		ret.push_back(arr[(i + d)%n]);
	}
	for (int i = 0; i < ret.size(); i++) {
		cout<<ret[i]<<" ";
	} 
}
//move zeros to the end of the array
void move_zeros(int arr[],int n){
    // vector<int> v;
    // for(int i=0;i<n;i++){
    //     if(arr[i] != 0){
    //         v.push_back(arr[i]);
    //     }
    // }
    // for(int i=0;i<v.size();i++){
    //     arr[i] = v[i];
    // }
    // for(int i=v.size();i<n;i++) arr[i] = 0;
    //Or (optimal solution)
    int j = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
//search an element in array
void linearSearch(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==6)/*if num is 6*/{
            cout<< i;
            return;
        }
    }
    cout<< -1;
}
//union of arrays
void Union(){
    vector<int> a = {1,2,3,5,7,9};
    vector<int> b = {1,2,2,2,3,4,9};
    int n1=a.size();
    int n2=b.size();
    //set<int> st;
    // for(int i=0;i<n1;i++){
    //     st.insert(a[i]);
    // }
    // for(int i=0;i<n2;i++){
    //     st.insert(b[i]);
    // }
    // vector<int> temp;
    // for(auto it : st){
    //     temp.push_back(it);
    // }
    // for(int i=0;i<temp.size();i++){
    //     cout<<temp[i]<<" ";
    // }
    //Or (optimal solution)
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size() == 0 ||
            unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else {
            if(unionArr.size() == 0 ||
            unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(unionArr.size() == 0 ||
            unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
    }
    while(i<n1){
        if(unionArr.size() == 0 ||
            unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
    }
    for(int i=0;i<unionArr.size();i++){
         cout<<unionArr[i]<<" ";
    }
    cout<<endl;
    //Intersection Array
    int p=0;
    int q=0;
    vector<int> intersecArr;
    while(p<n1 && q<n2){
        if(a[p]<b[q]){
            p++;
        }
        else if(b[q]<a[p]){
            q++;
        }
        else{
            intersecArr.push_back(a[p]);
            p++;
            q++;
        }
    }
    for(int i=0;i<intersecArr.size();i++){
         cout<<intersecArr[i]<<" ";
    }

}
//finding missing number in an array
void missingNum(){
    vector<int> v = {1,2,3,5,6,7};
    int xor1 = 0, xor2 = 0;
    for(int i=0;i<v.size();i++){
        xor2 = xor2^v[i];
        xor1 = xor1^(i+1);
    }
    xor1 = xor1^(v.size()+1);
    cout<<(xor1^xor2);

}
//longest subarray with sum d
void lsubarr(int arr[],int n,int d){
    //(brute force)
    // int len=0;
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         // int sum =0;
    //         // for(int k=i;k<=j;k++){
    //         //     sum += arr[k];
    //         // }
    //         sum += arr[j];
    //         if(sum==d) len = max(len,j-i+1);
    //     }
    // }
    // cout<<len;
    //(better solution //optimal if array has positive zeros and negatives)
    // map<int,int> preSumMap;
    // int sum = 0;
    // int maxLen = 0;
    // for(int i=0;i<n;i++){
    //     sum += arr[i];
    //     if(sum==d){
    //         maxLen = max(maxLen, i+1);
    //     }
    //     int rem = sum - d;
    //     if(preSumMap.find(rem) != preSumMap.end()){
    //         int len = i - preSumMap[rem];
    //         maxLen = max(maxLen,len);
    //     }
    //     if(preSumMap.find(sum) == preSumMap.end()){
    //         preSumMap[sum] = i;
    //     }
    // } 
    // cout<<maxLen;
    //(optimal solution for arrays with positives and zeros)
    int left = 0, right = 0;
    int sum = arr[0];
    int maxLen = 0;
    while(right<n){
        while(left<=right && sum>d){
            sum -= arr[left];
            left++;
        }
        if(sum==d){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right<n) sum += arr[right];
    }
    cout<<maxLen;
}
//two sum target problem
void twoSum(int arr[],int n,int target){
    //(brute force)
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i] + arr[j] == target){
    //         cout<<"true";
    //         return;
    //         }
    //     }
    // }
    // cout<<"false";
    //(better solution)
    // map<int,int> mpp;
    // for(int i=0;i<n;i++){
    //     int a = arr[i];
    //     int more = target - a;
    //     if(mpp.find(more) != mpp.end()){
    //         cout<<"true";
    //         return;
    //     }
    //     mpp[a] = i;
    // }
    // cout<<"false";
    //(optimal solution)
    int left = 0, right = n-1;
    sort(arr,arr+n);
    while(left<right){
        int sum = arr[left] + arr[right];
        if(sum==target){
            cout<<"true";
            return;
        }
        else if(sum<target) left++;
        else right--;
    }
    cout<<"false";

}
//sorting an array of 0s, 1s and 2s
void sortArray(int arr[],int n){
    //(brute force)
    // merge sort but TC is O(nlogn) and SC of O(n)
    //(better solution)
    // int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    // for(int i=0;i<n;i++){
    //     if(arr[i]==0) cnt0++;
    //     else if(arr[i]==1) cnt1++;
    //     else cnt2++;
    // }
    // for(int i=0;i<cnt0;i++) arr[i]=0;
    // for(int i=cnt0;i<cnt0+cnt1;i++) arr[i]=1;
    // for(int i=cnt0+cnt1;i<n;i++) arr[i]=2;
    //TC is O(2n)
    //(optimal Solution) Dutch National Flag Algorithm
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    //TC is O(n) and SC is O(1)
}
//majority element in an array
void majorityEle(int arr[],int n){
    //(brute force) TC -> O(n^2)
    // for(int i=0;i<n;i++){
    //     int cnt=0;
    //     for(int j=0;j<n;j++){
    //         if(arr[j]==arr[i]) cnt++;
    //     }
    //     if(cnt>n/2){
    //         cout<<arr[i];
    //         return;
    //     }
    // }
    //(better solution) SC->O(n)
    // map<int,int>mpp;
    // //O(nlogn)
    // for(int i=0;i<n;i++){
    //     mpp[arr[i]]++;
    // }
    // //O(n)
    // for(auto it : mpp){
    //     if(it.second>n/2){
    //         cout<<it.first;
    //     }
    // }
    //(optimal Solution)Moore's Voting Algorithm
    //TC -> O(n)
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else cnt--;
    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el) cnt1++;
    }
    if(cnt1>n/2) cout<<el;
}
//Maximum Subarray Sum
void subarrSum(int arr[],int n){
//(brute force) TC -> O(n^3)
//(better solution) TC -> O(n^2)
// int maxS = INT_MIN;
// for(int i=0;i<n;i++){
//     int sum=0;
//     for(int j=i;j<n;j++){
//         // int sum =0;
//         // for(int k=i; k<=j; k++){
//         //     sum += arr[k];
//         // }
//         sum += arr[j];
//         maxS = max(sum,maxS);
//     }
// }
// cout<<maxS;
//(Optimal Solution) kadane's Algorithm
    int sum = 0, maxS = INT_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum>maxS) maxS = sum;

        if(sum<0) sum = 0;
    }
    cout<<maxS;
}
//Best time to buy and sell stocks
void stonks(int arr[],int n){
    int mini = arr[0];
    int maxProfit = 0;
    for(int i=1;i<n;i++){
        int cost = arr[i] - mini;
        maxProfit = max(maxProfit,cost);
        mini = min(mini,arr[i]);
    }
    cout<<maxProfit;
}
//Rearrange array elements by sign
void rearrangeArr(int arr[],int n){
    vector<int> pos,neg;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else {
         for(int i=0;i<pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            arr[index] = neg[i];
            index++;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
//Next permutation
void nxtPer(int arr[],int n){
    //(better solution)
    // next_permutation(arr, arr+n);
    //(optimal soltution)
    int ind = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(arr,arr+n);
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    }
    for(int i=n-1;i>ind;i--){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr+ind+1,arr+n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
//Leaders in an Array
void leaders(int arr[],int n){
    // (brute force)
    // vector<int>v;
    // for(int i=0;i<n;i++){
    //     int leader = 1;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[j]>arr[i]){
    //             leader = 0;
    //             break;
    //         }
    //     }
    //     if(leader==1) v.push_back(arr[i]);
    // }
    // for(auto it : v) cout<<it<<" ";
    //(optimal solution)
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }
    for(auto it : ans) cout<<it<<" ";
}
//Longest Consecutive Sequence
bool ls(int arr[],int num,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==num) return true;
    }
    return false;
}
void Lconseq(int arr[],int n){
    //(brute force)
    // int longest = 1;
    // for(int i=0;i<n;i++){
    //     int x = arr[i];
    //     int cnt = 1;
    //     while(ls(arr,x+1,n)==true){
    //         x = x+1;
    //         cnt++;
    //     }
    //     longest = max(longest,cnt);
    // }
    // cout<<longest;
    //(better solution)
    // sort(arr,arr+n);
    // int lastsmaller = INT_MIN;
    // int cnt = 0;
    // int longest = 1;
    // for(int i=0;i<n;i++){
    //     if(arr[i]-1 == lastsmaller){
    //         cnt++;
    //         lastsmaller = arr[i];
    //     }
    //     else if(lastsmaller != arr[i]){
    //         cnt = 1;
    //         lastsmaller = arr[i];
    //     }
    //     longest = max(longest,cnt);
    // }
    // cout<<longest;
    //(optimal solution)
    int longest = 1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x += 1;
                cnt++;
            }
            longest = max(longest,cnt);
        }
    }
    cout<<longest;
}
//Set Matrix Zeros
void markRow(int i,vector<vector<int>>& a){
    int n = a.size();
    for(int j=0;j<n;j++){
        if(a[i][j] != 0) a[i][j] = -1;
    }
}
void markCol(int j,vector<vector<int>>& a){
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i][j] != 0) a[i][j] = -1;
    }
}
void zeroMatrix(vector<vector<int>>& a) {
    //(brute force) TC -> O(n^3) SC -> O(1)
    // int n = a.size();
    // int m = a[0].size();
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(a[i][j]==0){
    //             markRow(i,a);
    //             markCol(j,a);
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(a[i][j] == -1) a[i][j] = 0;
    //     }
    // }
    //(better solution) TC -> O(n*m) SC -> O(n+m)
    // int n = a.size();
    // int m = a[0].size();
    // int col[m] = {0}, row[n] = {0};
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(a[i][j]==0){
    //             row[i]=1;
    //             col[j]=1;
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(row[i] || col[j]){
    //             a[i][j] = 0;
    //         }
    //     }
    // }
    //(optimal solution) TC -> O(n*m) SC -> O(1)
    int n = a.size();
    int m = a[0].size();
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                a[i][0]=0;
                if(j != 0) a[0][j]=0;
                else col0 = 0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j] != 0){
                if(a[0][j]==0 || a[i][0]==0){
                a[i][j] = 0;
                }
            }
        }
    }
    if(a[0][0] == 0){
        for(int j=0;j<n;j++){
            a[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<n;i++){
            a[i][0] = 0;
        }
    }
}
//Rotate matrix/Image by 90 degrees
void rotateMatrix(vector<vector<int>>& a){
    //(brute force) TC -> O(n^2) SC -> O(n^2)
    int n = a.size();
    // int ans[n][n];
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         ans[j][n-i-1] = a[i][j];
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //(optimal solution) TC -> O(n/2*n/2) + O(n/2) SC -> O(1)
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(a[i][j],a[j][i]);
        }
    }
    //O(n/2)
    for(int i=0;i<n;i++){
        reverse(a[i].begin(),a[i].end());
    }
}
//Spiral Traversal of a Matrix
void spiralMatrix(vector<vector<int>>& a){
    int n = a.size();
    int m = a[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while(top<=bottom && left<=right){
    //right
    for(int i=left;i<=right;i++){
        ans.push_back(a[top][i]);
    }
    top++;
    //bottom
    for(int i=top;i<=bottom;i++){
        ans.push_back(a[i][right]);
    }
    right--;
    //left
    if(top<=bottom){
    for(int i=right;i>=left;i--){
        ans.push_back(a[bottom][i]);
    }
    bottom--;
    }
    //top
    if(left<=right){
    for(int i=bottom;i>=top;i--){
        ans.push_back(a[i][left]);
    }
    left++;
    }
    }
    for(auto it : ans) cout<<it<<" ";
    cout<<endl;
}
//count subarray sum equals k
void subarrSum(int a[],int n,int k){
    //(brute force) TC -> O(n^3) SC -> O(1)
    //(better solution) TC -> O(n^2) SC -> O(1)
    // int cnt = 0;
    // for(int i=0;i<n;i++){
    //     int sum = 0;
    //     for(int j=i;j<n;j++){
    //         // int sum = 0;
    //         // for(int k=i;k<=j;k++){
    //         //     sum += a[k];
    //         // }
    //         sum += a[j];
    //         if(sum==k) cnt++;
    //     }
    // }
    // cout<<cnt;
    //(optimal solution) TC -> O(nlogn) SC -> O(n)
    map<int,int>mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i=0;i<n;i++){
        preSum += a[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    cout<<cnt;
}
//pascal triangle 
//To find element at row R annd col C in pascal triangle
//put (R-1,C-1) as parameters in nCr function
int nCr(int n,int r){
    int res = 1;
    for(int i=0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}
//Print the Nth row of Pascle Triangle
void Row(int n){
    //(brute force) TC -> O(n*r)
    // for(int c=1;c<=n;c++){
    //     cout<<nCr(n-1,c-1)<<" ";
    // }
    //(optimal solution) TC -> O(n) ans SC -> O(1)
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++){
        ans = ans*(n-i);
        ans = ans/i;
        cout<<ans<<" ";
    }
}
//Print Pascal Triangle
vector<int> generateRow(int row){
    int ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans = ans*(row-col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
void pascalTriangle(int n){
    //(brute force)
    // vector<vector<int>> ans;
    // for(int row=1;row<=n;row++){
    //     vector<int> temp;
    //     for(int col=1;col<=row;col++){
    //         temp.push_back(nCr(row-1,col-1));
    //     }
    //     ans.push_back(temp);
    // }
    // int a = ans.size();
    // for(int i=0;i<a;i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //(optimal solution)
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        ans.push_back(generateRow(i));
    }
    int a = ans.size();
    for(int i=0;i<a;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


}
//Majority element part 2 (>n/3 times)
void majorityEle2(int arr[],int n){
    //(brute force) TC -> O(n^2) SC -> O(1)
    // vector<int> ls;
    // for(int i=0;i<n;i++){
    //     if(ls.size()==0 || ls[0] != arr[i]){
    //         int cnt = 0;
    //         for(int j=0;j<n;j++){
    //             if(arr[j] == arr[i]) cnt++;
    //         }
    //         if(cnt>n/3) ls.push_back(arr[i]);
    //     }
    //     if(ls.size()==2) break;
    // }
    // for(auto ele : ls) cout<<ele<<" ";
    //(better solution) TC -> O(nlogn) SC -> O(n)
    // vector<int> v;
    // map<int,int>mpp;
    // int min = n/3 + 1;
    // for(int i=0;i<n;i++){
    //     mpp[arr[i]]++;
    //     if(mpp[arr[i]] == min){
    //      v.push_back(arr[i]);
    //     }
    // }
    // for(auto ele : v) cout<<ele<<" ";
    //(optimal solution) O(n) SC -> O(1)
    int cnt1=0, cnt2=0;
    int el1, el2;
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i] != el2){
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && arr[i] != el1){
            cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1){
            cnt1++;
        }
        else if(arr[i]==el2){
            cnt2++;
        }
        else cnt1--,cnt2--;
    }
    int cnt3=0, cnt4=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el1) cnt3++;
        if(arr[i]==el2) cnt4++;
    }
    if(cnt3>n/3 && cnt4>n/3) cout<<el1<<" "<<el2;
}
//3Sum
void ThreeSum(int arr[],int n){
//(brute force) TC -> O(n^3*log(no of unique triplets)) SC-> 2*O(no of unique triplets)
// set<vector<int>> st;
// for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         for(int k=j+1;k<n;k++){
//             if(arr[i]+arr[j]+arr[k]==0){
//                 vector<int> temp = {arr[i],arr[j],arr[k]};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//         }
//     }
// }
// vector<vector<int>> ans(st.begin(),st.end());
// int a = ans.size();
//     for(int i=0;i<a;i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//(better solution) TC -> O(n^2*log(M)) SC-> O(n)+O(no of unique triplets)
// set<vector<int>> st;
// for(int i=0;i<n;i++){
//     set<int> hashset;
//     for(int j=i+1;j<n;j++){
//         int third = -(arr[i]+arr[j]);
//         if(hashset.find(third) != hashset.end()){
//             vector<int> temp = {arr[i],arr[j],third};
//             sort(temp.begin(),temp.end());
//             st.insert(temp);
//         }
//         hashset.insert(arr[j]);
//     }
// }
// vector<vector<int>> ans(st.begin(),st.end());
// int a = ans.size();
//     for(int i=0;i<a;i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//(optimal solution) TC -> O(nlogn + n^2)
vector<vector<int>> ans;
sort(arr,arr+n);
for(int i=0;i<n;i++){
    if(i>0 && arr[i]==arr[i-1]) continue;
    int j=i+1;
    int k=n-1;
    while(j<k){
        int sum = arr[i] + arr[j] + arr[k];
        if(sum<0){
            j++;
        } 
        else if(sum>0){
            k--;
        }
        else{
            vector<int> temp = {arr[i],arr[j],arr[k]};
            ans.push_back(temp);
            j++;
            k--;
            while(j<k && arr[j]==arr[j-1]) j++;
            while(j<k && arr[k]==arr[k+1]) k--;
        }
    }
}
int a = ans.size();
    for(int i=0;i<a;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
//4Sum
void FourSum(int arr[],int n){
//(brute force) TC -> O(n^4*log(no of quads)) SC -> O(no of quads)*2
// set<vector<int>> st;
// for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         for(int k=j+1;k<n;k++){
//             for(int l=k+1;l<n;l++){
//             if(a[i]+a[j]+a[k]+a[l]==0){
//                 vector<int> temp = {a[i],a[j],a[k],a[l]};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             }
//         }
//     }
// }
// vector<vector<int>> ans(st.begin(),st.end());
// int m = ans.size();
//     for(int i=0;i<m;i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//(better solution) TC -> O(n^3*log(M)) SC-> O(n)+O(no of unique quads)*2
// set<vector<int>> st;
// for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         set<int> hashset;
//         for(int k=j+1;k<n;k++){
//         int fourth = -(arr[i]+arr[j]+arr[k]);
//         if(hashset.find(fourth) != hashset.end()){
//             vector<int> temp = {arr[i],arr[j],arr[k],fourth};
//             sort(temp.begin(),temp.end());
//             st.insert(temp);
//         }
//         hashset.insert(arr[k]);
//         }
//     }
// }
// vector<vector<int>> ans(st.begin(),st.end());
// int a = ans.size();
//     for(int i=0;i<a;i++){
//         for(int j=0;j<ans[i].size();j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//(optimal solution) O(n^3) SC-> O(no of unique quads)
vector<vector<int>> ans;
sort(arr,arr+n);
for(int i=0;i<n;i++){
    if(i>0 && arr[i]==arr[i-1]) continue;
    for(int j=i+1;j<n;j++){
    if(j>i+1 && arr[j]==arr[j-1]) continue;
    int k=j+1;
    int l=n-1;
    while(k<l){
        int sum = arr[i] + arr[j] + arr[k] + arr[l];
        if(sum<0){
            k++;
        } 
        else if(sum>0){
            l--;
        }
        else{
            vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
            ans.push_back(temp);
            k++;
            l--;
            while(k<l && arr[k]==arr[k-1]) k++;
            while(k<l && arr[l]==arr[l+1]) l--;
        }
    }
    }
}
int a = ans.size();
    for(int i=0;i<a;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
//Number of operations to make an array palindrome
void palindromeArr(int a[],int n){
    int op = 0;
    for(int left=0,right=n-1;left<=right;){
        if(a[left]==a[right]){
            left++;
            right--;
        }
        else if(a[left]<a[right]){
            while(a[left] != a[right]){
                a[left] +=1;
                op++;
            }
            left++;
            right--;
        }
        else {
            while(a[left] != a[right]){
                a[right]++;
                op++;
            }
            right--;
            left++;
        }
    }
    cout<<op;
}
//Count subaarays with xor K
void xorSubarr(int a[],int n,int target){
//(brute force) TC -> O(n^3) SC -> O(1)
//(better solution) TC -> O(n^2) SC -> O(1)
// int cnt = 0;
// for(int i=0;i<n;i++){
//     int XOR = 0;
//     for(int j=i;j<n;j++){
//         // int XOR = 0;
//         // for(int k=i;k<j;k++){
//         //     XOR = XOR^a[k];
//         // }
//         XOR = XOR^a[j];
//         if(XOR == target) cnt++;
//     }
// }
// cout<<cnt;
//(optimal solution) TC -> O(nlogn) SC -> O(n)
int xr = 0;
map<int,int>mpp;
mpp[xr]++; //{0,1}
int cnt = 0;
for(int i=0;i<n;i++){
    xr = xr^a[i];
    //target
    int x = xr^target;
    cnt += mpp[x];
    mpp[xr]++;
}
cout<<cnt;
}
//Merge overlapping intervals
void mergeInterval(vector<vector<int>> &a){
    //(brute force) TC -> O(nlog(n) + 2n) SC -> O(n)
    // int n = a.size();
    // sort(a.begin(),a.end());
    // vector<vector<int>> ans;
    // for(int i=0;i<n;i++){
    //     int start = a[i][0];
    //     int end = a[i][1];
    //     if(!ans.empty() && end <= ans.back()[1]){
    //         continue;
    //     }
    //     for(int j=i+1;j<n;j++){
    //         if(a[j][0] <= end){
    //             end = max(end,a[j][1]);
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     ans.push_back({start,end});
    // }

    // int m = ans.size();
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //(Optimal Solution) O(nlog(n) + n) SC -> O(n)
    int n = a.size();
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || a[i][0] > ans.back()[1]){
            ans.push_back(a[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1],a[i][1]);
        }
    }

    int m = ans.size();
    for(int i=0;i<m;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}
//Merge 2 sorted arrays without extra space
void mergeArr(int a[],int b[],int n,int m){
    //(brute force) TC -> 2*O(n+m) SC -> O(n+m)
    // int arr[n+m];
    // int left = 0;
    // int right = 0;
    // int index = 0;
    // while(left<n && right<m){
    //     if(a[left] <= b[right]){
    //         arr[index] = a[left];
    //         left++,index++;
    //     }
    //     else {
    //         arr[index] = b[right];
    //         right++,index++;
    //     }
    // }
    // while(left<n){
    //     arr[index++] = a[left++];
    // }
    // while(right<m){
    //     arr[index++] = b[right++];
    // }

    // for(int i=0;i<n+m;i++){
    //     if(i<n) a[i] = arr[i];
    //     else b[i-n] = arr[i];
    // }
    //(Optimal Solution) TC ->O(min(n,m) + nlogn + mlogm) SC -> O(1)
    int left = n-1;
    int right = 0;
    while(left>=0 && right<m){
        if(a[left]>b[right]){
            swap(a[left],b[right]);
            left--,right++;
        }
        else {
            break;
        }
    }
    sort(a,a+n);
    sort(b,b+m);

}
//Find the missing number and repeating number
void findMR(int arr[],int n){
    //(brute force) TC -> O(n^2) SC -> O(1)
    // int Rnum = -1;
    // int Mnum = -1;
    // for(int i=1;i<=n;i++){
    //     int cnt = 0;
    //     for(int j=0;j<n;j++){
    //         if(arr[j]==i) cnt++;
    //     }
    //     if(cnt == 2) Rnum = i;
    //     else if(cnt == 0) Mnum = i;
    //     if(Rnum != -1 && Mnum != -1){
    //         break;
    //     }

    // }
    // cout<<Rnum<<" "<<Mnum;
    //(better solution) TC -> O(2n) SC -> O(n)
    // int hash[n+1] = {0};
    // for(int i=0;i<n;i++){
    //     hash[arr[i]]++;
    // }
    // int repeating = -1, missing = -1;
    // for(int i=1;i<=n;i++){
    //     if(hash[i] == 2) repeating = i;
    //     else if(hash[i] == 0) missing = i;
    //     if(repeating != -1 && missing != -1){
    //         break;
    //     }
    // }
    // cout<<repeating<<" "<<missing;
    //(Optimal Solution) O(n) SC -> O(1)
    //S - Sn = x-y
    //S2 - S2n = x^2 - y^2
    int Sn = (n*(n+1))/2;
    int S2n = (n*(n+1)*(2*n+1))/6;
    int S = 0, S2 = 0;
    for(int i=0;i<n;i++){
        S += arr[i];
        S2 += arr[i]*arr[i];
    }
    int val1 = S - Sn;//x-y
    int val2 = S2 - S2n;
    val2 = val2/val1;//x+y
    int x = (val1+val2)/2;
    int y = x - val1;
    cout<<x<<" "<<y;
}
//Count Inversions in an Array(i<j && a[i]>a[j])
int merge1(int arr[],int low,int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    int cnt = 0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
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
    return cnt;
}
int merge_sort1(int arr[],int low,int high){
    int cnt = 0;
    if(low == high) return cnt;
    int mid = (low + high) / 2;
    cnt += merge_sort1(arr, low, mid);
    cnt += merge_sort1(arr, mid+1, high);
    cnt += merge1(arr, low, mid, high);
    return cnt;
}
void countInv(int arr[],int n){
    //(brute force) TC -> O(n^2) SC -> O(1)
    // int cnt = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]>arr[j]) cnt++;
    //     }
    // }
    // cout<<cnt;
    //(optimal solution) TC -> O(nlogn) SC -> O(n)
    cout<<merge_sort1(arr,0,n-1);
}
//Reverse Pairs (i<j && a[i]>2*a[j])
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
int countPairs(int arr[],int low,int mid,int high){
    int cnt = 0;
    int right = mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right]) right++;
        cnt += (right-(mid+1));
    }
    return cnt;
}
int merge_sort(int arr[],int low,int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += merge_sort(arr, low, mid);
    cnt += merge_sort(arr, mid+1, high);
    cnt += countPairs(arr,low,mid,high);
    merge(arr, low, mid, high);
    return cnt;
}
void reversePair(int a[],int n){
    //(brute force) TC -> O(n^2) SC -> O(1)
    // int cnt = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(a[i]>2*a[j]) cnt++;
    //     }
    // }
    // cout<<cnt;
    //(optimal solution) O(2nlogn) SC -> O(n)
    cout<<merge_sort(a,0,n-1);
}
//Maximum Product Subarray
void maxSubarr(int a[],int n){
    //(brute force) TC -> O(n^3) SC -> O(1)
    //(better solution) TC -> O(n^2) SC -> O(1)
    // int maxi = INT_MIN;
    // for(int i=0;i<n;i++){
    //     int product = 1;
    //     for(int j=i;j<n;j++){
    //         // int product = 1;
    //         // for(int k=i;k<j;k++){
    //         //     product = product*a[k];
    //         // }
    //         product = product*a[j];
    //         maxi = max(maxi,product);
    //     }
    // }
    // cout<<maxi;
    //(optimal solution) TC -> O(n) SC -> O(1)
    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre = 1;
        if(suff==0) suff = 1;

        pre = pre*a[i];
        suff = suff*a[n-1-i];
        ans = max(ans,max(pre,suff));
    }
    cout<<ans;
}
//Longest Subarray with 0 sum
void maxlen(int a[],int n){
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += a[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    cout<<maxi;
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    //int b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    //for(int i=0;i<m;i++) cin>>b[i];
    
    maxSubarr(a,n);
    //for(int i=0;i<n;i++) cout<<a[i]<<" ";
    //cout<<endl;
    //for(int i=0;i<m;i++) cout<<b[i]<<" ";
    return 0;
}