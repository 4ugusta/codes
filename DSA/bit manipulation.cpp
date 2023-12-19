#include<bits/stdc++.h>
using namespace std;

//Bit Manipulation
vector<int> bitManipulation(int num, int i){
    vector<int> ans;
    int get = 0, set = 0,clear = 0;
    int mask = (1<<(i-1));

    if(num&mask){
        get = 1;
    }
    set = (num|mask);
    clear = (num&(~mask));
    ans.push_back(get);
    ans.push_back(set);
    ans.push_back(clear);
    return ans;
}
//Check whether K-th bit is set or not
bool isKthBitSet(int n, int k)
{
    int mask = (1<<(k-1));
    if(n&mask){
        return true;
    }
    return false;
}
//Odd Even
string oddEven(int N){
    if((N&1) == 0) return "even";
    else return "odd";
}

int main(){
    int n;
    cin>>n;
    cout<<oddEven(n);

}