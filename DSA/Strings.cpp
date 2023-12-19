#include<bits/stdc++.h>
using namespace std;

//Remove Outermost Parentheses
string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
         for(int i=0;i<s.size();i++){
             if(s[i]=='('){
                 if(!st.empty()){
                    ans.push_back(s[i]);
                 }
                 st.push(s[i]);
             }
             else{
                 st.pop();
                 if(!st.empty()){
                     ans.push_back(s[i]);
                 }
             }
         }
         return ans;
    }
//Reverse Words in a String
string reverseWords(string s) {
        s+=" ";
        stack<string> st;
    int i;
    string str="";
    for(i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            if(str == ""){
                continue;
            }
            else {
            st.push(str);
            str="";
            }
        }
        else str+=s[i];
    }
    string ans="";
    while(st.size()!=1)
    {
        ans+=st.top()+" ";
        st.pop();
    }
    ans+=st.top();
    return ans;
    }
//Largest Odd Number in String
string largestOddNumber(string num) {
        int i = 0;
        for (int j = num.size() - 1; j >= 0; j--) {
            if ((num[j] - '0') % 2 == 1) {
                return num.substr(0, j + 1);
            }
        }
        return "";
    }
//Longest Common Prefix
string longestCommonPrefix(vector<string>& str) {
         sort(str.begin(),str.end());
    string laststr = str[str.size()-1];
    string firststr = str[0];
    string ch;
    if(!str.empty()){
    int i=0, j=0;
    while(i<firststr.size() && j<laststr.size() && firststr[i]==laststr[j]){
        ch += firststr[i];
        i++;
        j++;
    }
    }
    return ch;
    }
//Rotate String
bool rotateString(string s, string goal) {
     if(s.size()!=goal.size()) return false;
     string ans = s+s;
     if(ans.find(goal) == string::npos) return false;
     else return true;   
    }
//Valid Anagram
bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for (auto x : s) {
            count[x]++;
        }
        
        // Decrement the frequency of characters in string t
        for (auto x : t) {
            count[x]--;
        }
        
        // Check if any character has non-zero frequency
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        
        return true;
    }
//Sort Characters By Frequency
string frequencySort(string s) {
   unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        string ans;
        while(!pq.empty()){
            int f=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            for(int i=0;i<f;i++)
                ans+=ch;          
                
        }
        return ans;
    }
//Maximum Nesting Depth of the Parentheses
int maxDepth(string s) {
        stack<char> st;
        int cnt = 0;
        int ans = -1;
         for(int i=0;i<s.size();i++){
             if(s[i]=='('){
                 st.push(s[i]);
                 cnt++;
             }
             else{ if(!st.empty() && s[i]==')'){
                 st.pop();
                 cnt--;
             }
             }
             ans = max(ans,cnt);
         }
         return ans;
    }
//Roman to Integer
int romanToInt(string s) {
         unordered_map<char, int> m;
        
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
        }
        return ans;
    }
//String to Integer (atoi)
int myAtoi(string s) {
        int i=0;
        int p=0;
        int c=0;
        double t=0;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='+'){
            c++;
            i++;
        }
        if(s[i]=='-'){
        p++;
        i++;
        }
        while(i<s.size()and s[i]>='0' and s[i]<='9')
        {
            t=t*10+(s[i]-'0');
            i++;
        }
        if(c>0&&p>0){
        return 0;
        }
        if(p>0){
          t=-t;
        }
         if(c>0){
            t=t;
        }
        if(t>INT_MAX){
            t=INT_MAX;
        }
        if(t<INT_MIN){
            t=INT_MIN;
        }
      return (int)t;
    }
//Longest Palindromic Substring
int expandFromMiddle(string str, int left, int right) {
        if (str == "" || left > right) return 0;
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Fix the length calculation
    }
string longestPalindrome(string s) {
        if (s.size() < 1) return "";

        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expandFromMiddle(s, i, i);
            int len2 = expandFromMiddle(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1); // Fix the substring extraction
    }
//Sum of Beauty of All Substrings
int beautySum(string s) {
        int sum = 0; //  to store ans;
        int n = s.length();        
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++; // storing every possible substring
                int maxFreq = 0, minFreq = INT_MAX;
                //<!--finding beauty of substing -->
                for (auto it : mp) {
                    maxFreq = max(maxFreq, it.second);
                    minFreq = min(minFreq, it.second);
                }
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
int main(){
    string s = "1234565456324312134";
    cout<<largestOddNumber(s);

    return 0;
}