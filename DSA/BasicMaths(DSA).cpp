#include<bits/stdc++.h>
using namespace std;

//Count Digits
void countdigits(){
    int n;
    cin>>n;
    
    int num = (int)(log10(n)+1);
    cout<<num;
    //Or
    int cnt = 0;
    while(n>0){
        cnt=cnt+1;
        n = n/10;
    }
    cout<<cnt<<endl;
    
}
//Reverse a number
void RN(){
    int n;
    cin>>n;
    int rev = 0;
    while(n>0){
        int lastdigit = n%10;
        rev = rev*10 + lastdigit;
        n = n/10;
    }
    cout<<rev<<endl; 
}
//Check Palindrome
void PD(){
    int n;
    cin>>n;
    int rev = 0;
    int dup = n;
    while(n>0){
        int lastdigit = n%10;
        rev = rev*10 + lastdigit;
        n = n/10;
    }
    if(dup == rev) cout<<"true";
    else cout<<"false";
}
//Armstrong Numbers
void AN(){
    int n;
    cin>>n;
    int sum = 0;
    int dup = n;
    while(n>0){
        int ld = n%10;
        sum = sum + (ld*ld*ld);
        n = n/10;
    }
    if(dup == sum) cout<<"true";
    cout<<"false";
}
//Print all divisors
void divisors(){
    int n;
    cin>>n;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            cout<<i<<" ";
            cnt = cnt + 1;
        }

    }
    cout<<"\n"<<cnt<<endl;
    //Or
    vector<int> v;
    for(int j=1; j*j<=n; j++){
        if(n%j == 0){
            v.push_back(j);
            if((n/j) != j){
                v.push_back(n/j);
            }
        }
    }
    sort(v.begin(),v.end());
    for(auto it : v) cout<<it<<" ";
}
//Check for Prime
void CP(){
    int n;
    cin>>n;
    int cnt = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            cnt++;
            if((n/i) != i) cnt++;
        }
    }
    if(cnt == 2) cout<< "true";
    else cout<<"false";

}
//GCD or HCF
void GCD(){
    int a;
    int b;
    cin>>a>>b;
    int gcd =1;
    for(int i=1; i<=min(a,b);i++){
        if(a%i==0 && b%i==0) gcd = i;
    }
    cout<<gcd<<endl;
    //Or
    while(a>0 && b>0){
        if(a>b) a = a%b;
        else b = b%a;
    }
    if(a==0) cout<<b;
    else cout<<a;
}
int main(){
    GCD();
    return 0;
}