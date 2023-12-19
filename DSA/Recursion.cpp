#include<bits/stdc++.h>
using namespace std;

//print name n times
void f(int i, int n){
    if(i>n) return;
    cout<<"Aug"<<endl;
    f(i+1,n);
}
//print linearly from 1 to n
void f1(int i, int n){
    if(i>n) return;
    cout<<i<<endl;
    f1(i+1,n);
}
//print n to 1
void f2(int i, int n){
    if(i<1) return;
    cout<<i<<endl;
    f2(i-1,n);
}
//print from 1 to n (backtracking)
void f3(int i, int n){
    if(i<1) return;
    f3(i-1,n);
    cout<<i<<endl;
}
//print n to 1 (backtracking)
void f4(int i, int n){
    if(i>n) return;
    f4(i+1,n);
    cout<<i<<endl;
}
//Sum of first n numbers (parameterised)
void f5(int i, int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    f5(i-1,sum+i);
}
//Sum of first n numbers (functional)
int f6(int n){
    if(n==0) return 0;
    return n + f6(n-1);
}
//Fibonacci numbers (Multiple Recursion)
int f7(int n){
    if(n<=1) return n;
    else return f7(n-1) + f7(n-2);
}
//Binary strings with no consecutive 1s.
void generateHelper(string prefix, char lastDigit, int length, vector<string>& result) {
    if (length == 0) {
        result.push_back(prefix);
        return;
    }

    // Append '0' to the prefix and make a recursive call
    generateHelper(prefix + '0', '0', length - 1, result);

    // Append '1' to the prefix only if the last digit was '0' or if the prefix is empty
    if (lastDigit == '0' || prefix.empty()) {
        generateHelper(prefix + '1', '1', length - 1, result);
    }
}
vector<string> generateString(int N) {
    vector<string> result;
    generateHelper("", ' ', N, result);
    return result;
}
//Generate Parentheses
void helper1(vector<string> &ans,int n,int oc,int cc,string s){
        if(oc == n && cc == n){
            ans.push_back(s);
            return;
        }
        if(oc<n){
            helper1(ans,n,oc+1,cc,s+'(');
        }
        if(cc<oc){
            helper1(ans,n,oc,cc+1,s+')');
        }
    }
vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int oc = 0, cc = 0;
        helper1(ans,n,oc,cc,"");
        return ans;
    }
//Subsets Or Power Set
void helper2(int ind,vector<int> &ans,vector<int>& nums,vector<vector<int>> &sol,int n){
        if(ind == n){
            sol.push_back(ans);
            return;
        }
        ans.push_back(nums[ind]);
        helper2(ind+1,ans,nums,sol,n);
        ans.pop_back();
        helper2(ind+1,ans,nums,sol,n);
    }
void subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> sol;
        helper2(0,ans,nums,sol,n);
        sort(sol.begin(),sol.end());
        for(int i=0;i<sol.size();i++){
            for(int j=0;j<sol[i].size();j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }
//Subsequences with sum k
void helper3(vector<int> &nums, set<vector<int>> &ans, vector<int> &a, long long k, int ind, int sum) {
    if (ind == a.size()) {
        if(sum == k){
        ans.insert(nums);
        }
        return;
    }
        nums.push_back(a[ind]);
        sum += a[ind];
        helper3(nums, ans, a, k, ind + 1, sum);
        sum -= a[ind];
        nums.pop_back();
        helper3(nums, ans, a, k, ind + 1, sum);
}
void subarraysWithSumK(vector<int> a, long long k) {
    vector<int> nums;
    set<vector<int>> ans;
    helper3(nums,ans, a, k, 0, 0);
    vector<vector<int>> sol(ans.begin(),ans.end());
    for(int i=0;i<sol.size();i++){
            for(int j=0;j<sol[i].size();j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
}
//Combination Sum TC -> (2^(target))*k
void helper4(int ind,vector<int>& candidates, int target,vector<vector<int>> &ans, vector<int> &temp){
          if(ind == candidates.size() || target == 0){
              if(target == 0){
                  ans.push_back(temp);
              }
              return;
          }

          if(candidates[ind]<=target){
              temp.push_back(candidates[ind]);
              helper4(ind,candidates,target-candidates[ind],ans,temp);
              temp.pop_back();
          }
          helper4(ind + 1,candidates,target,ans,temp);
    }
void combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> temp;
      helper4(0,candidates,target,ans,temp);
       for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
//Combination Sum II TC -> (2^(n))*k
void helper5(int ind,vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp){
          if( target == 0 ){
              ans.push_back(temp);
              return;
          }

          for(int i=ind;i<candidates.size();i++){
              if(i>ind && candidates[i] == candidates[i-1]) continue;
              if(candidates[i]>target) break;
              temp.push_back(candidates[i]);
              helper5(i + 1,candidates,target-candidates[i],ans,temp);
              temp.pop_back();
          }
    }
void combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> temp;
      sort(candidates.begin(),candidates.end());
      helper5(0,candidates,target,ans,temp);
      for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
//Subset Sum
void helper6(int ind,int sum,vector<int> &num,vector<int> &ans){
	if(ind == num.size()){
		ans.push_back(sum);
		return;
	}

	helper6(ind+1,sum + num[ind],num,ans);

	helper6(ind+1,sum,num,ans);
}
void subsetSum(vector<int> &num){
	vector<int> ans;
	helper6(0,0,num,ans);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }	
}
//Subsets II
void helper7(int ind,vector<int>& nums,vector<int>& ds,vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper7(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
void subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        helper7(0,nums,ds,ans);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
//Combination Sum III
void findCombinations(int ind,int n,int k,vector<int> &nums,vector<vector<int>> &ans,vector<int> &ds){
         if( n == 0 && ds.size() == k){
              ans.push_back(ds);
              return;
          }

          for(int i=ind;i<nums.size();i++){
              if(nums[i]>n) break;
              ds.push_back(nums[i]);
              findCombinations(i + 1,n-nums[i],k,nums,ans,ds);
              ds.pop_back();
          }
    }
vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0,n,k,nums,ans,ds);
        return ans;
    }
//Letter Combinations of a Phone Number
void backtracking(map<char,string> &digitToChar, vector<string> &res, int i, string digits, string curStr)
{
        if (curStr.size() == digits.size()){
            res.push_back(curStr);
            return;
        }
        for(auto &c:digitToChar[digits[i]]) backtracking(digitToChar, res, i+1, digits, curStr + c);
    }
vector<string> letterCombinations(string digits) {
        vector<string> res;
        map<char, string> digitToChar = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        if(digits.size())
            backtracking(digitToChar,res,0,digits,"");
        return res;
    }
//Palindrome Partitioning
bool isPalindrome(string &s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
void func(int ind,string &s,vector<string> &ds,vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind,i-ind+1));
                func(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        func(0,s,ds,ans);
        return ans;
    }
//Word Search
int m,n;
vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
bool findWord(int i,int j,int ind,vector<vector<char>>& board,string word){
        if(ind == word.size()) return true;

        if(i<0 || i>=n || j<0 || j>=m || board[i][j] == '$') return false;

        if(board[i][j] != word[ind]) return false;

        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir : directions){
            int i_new = i + dir[0];
            int j_new = j + dir[1];

            if(findWord(i_new,j_new,ind+1,board,word)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0] == board[i][j] && findWord(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
//N-Queens
void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftRow[row] == 0 && upperDiagonal[n-1 + col - row] == 0 &&
             lowerDiagonal[row+col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                lowerDiagonal[row+col] = 1;
                solve(col+1,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperDiagonal[n-1 + col - row] = 0;
                lowerDiagonal[row+col] = 0;
            }
        }
    }
vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int> leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        solve(0,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
        return ans;
    }
//Rat in a Maze Problem
void solve(int i,int j,vector<vector<int>> &m,int n, vector<string> &ans,string move,vector<vector<int>> &visited,int di[],int dj[]){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";
        for(int ind=0;ind<4;ind++){
            int i_new = i + di[ind];
            int j_new = j + dj[ind];
            
            if(i_new >= 0 && i_new < n && j_new >= 0 && j < n && !visited[i_new][j_new]
            && m[i_new][j_new] == 1){
                visited[i][j] = 1;
                solve(i_new,j_new,m,n,ans,move + dir[ind],visited,di,dj);
                visited[i][j] = 0;
            }
        }
    }
vector<string> findPath(vector<vector<int>> &m, int n) {
      vector<string> ans;
      vector<vector<int>> visited(n,vector<int> (n,0));
      int di[] = {1,0,0,-1};
      int dj[] = {0,-1,1,0};
      if(m[0][0] == 1) solve(0,0,m,n,ans,"",visited,di,dj);
      return ans;
    }
//Word Break
unordered_set<string> st;
int n;
int t[301];
bool solve(int ind,string &s){
        if(ind == n) return true;
        if(st.find(s) != st.end()) return true;
        if(t[ind] != -1) return t[ind];
        for(int l=1;l<n;l++){
            string temp = s.substr(ind,l);
            if(st.find(temp) != st.end() && solve(ind+l,s)) return t[ind] = true;
        }
        return t[ind] = false;
    }
bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(t,-1,sizeof(t));
        for(auto &word : wordDict){
            st.insert(word);
        }
        return solve(0,s);
    }
// Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int node,int n,int color[],bool graph[101][101],int col){
        for(int k=0;k<n;k++){
            if(k != node && graph[k][node] == 1 && color[k] == col){
                return false;
            }
        }
        return true;
    }
bool solve(int node,int m,int n,int color[],bool graph[101][101]){
        if(node == n) return true;
        
        for(int i=1;i<=m;i++){
            if(isSafe(node,n,color,graph,i) == true){
                color[node] = i;
                if(solve(node+1,m,n,color,graph) == true) return true;
                color[node] = 0;
            }
        }
        
        return false;
    }
bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        if(solve(0,m,n,color,graph) == true) return true;
        return false;
    }
//Sudoku Solver
bool isSafe(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[row][i] == c) return false;
            if(board[i][col] == c) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }
bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.'){
                    for(char c='1';c<='9';c++){
                        if(isSafe(board,i,j,c)){
                            board[i][j] = c;

                            if(solve(board) == true)
                                return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
void solveSudoku(vector<vector<char>>& board) {
       solve(board); 
    }
//Expression Add Operators
vector<string> ans;
void rec(int i,string s,long sum,long prev,string &num, int target){
        //base case
        if(i == num.size()){
            if(sum == target){
                ans.push_back(s);
                return;
            }
        }
        //recursion
        for(int j=i;j<num.size();j++){
            if(j>i && num[i] == '0') return;
            long number = stol(num.substr(i,j-i+1));
            if(i==0){
                rec(j+1,s+num.substr(i,j-i+1),number,number,num,target);
            }
            else{
                rec(j+1,s+'+'+num.substr(i,j-i+1),sum+number,number,num,target);
                rec(j+1,s+'-'+num.substr(i,j-i+1),sum-number,-number,num,target);
                rec(j+1,s+'*'+num.substr(i,j-i+1),sum-prev+(prev*number),prev*number,num,target);
            }
        }
    }
vector<string> addOperators(string num, int target) {
        rec(0,"",0,0,num,target);
        return ans;
    }

int main(){
    // int n;
    // cin>>n;
    // vector<int> nums(n);
    // for(int i=0;i<n;i++) cin>>nums[i];
    string s;
    cin>>s;
    vector<string> v = letterCombinations(s);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    

    return 0;
}