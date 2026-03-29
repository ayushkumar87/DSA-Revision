//1:st approach -Memeoization
class Solution {
public:
    int solve(int n,vector<int>& arr){
        if(n<=1){
            return n;
        }
        if(arr[n]!=-1){
            return arr[n];
        }

        arr[n]=solve(n-1,arr)+solve(n-2,arr);
        return arr[n];
    }
    int fib(int n) {
        vector<int> arr(n+1, -1);
        return solve(n, arr);
    }
};


// 2nd approach Tabulation
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};