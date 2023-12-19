#include<bits/stdc++.h>
using namespace std;
//hashing of numbers
void num(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //precompute
    int hash[8] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;
    }
    
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<<hash[num]<<endl;
    }
}
//hashing of strings
void strings(){
    string s;
    cin>>s;

    //precompute
    int hash[26] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetch
        cout<<hash[c-'a']<<endl;
    }
}
//hashing of numbers with map
void nums(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //precompute
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    //iterate in the map
    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<<mpp[num]<<endl;
    }
}
int main(){

    nums();
    return 0;
}