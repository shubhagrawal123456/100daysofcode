int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int x=0,y=n-1,sum=0;
    for(int i=0;i<B;i++)
    {
        sum+=A[i];
    }
    int res=sum;
    for(int i=0;i<B;i++)
    {
        res -=A[B-i-1];
        res +=A[n-i-1];
         sum=max(res,sum);
    }
    return sum;
}
