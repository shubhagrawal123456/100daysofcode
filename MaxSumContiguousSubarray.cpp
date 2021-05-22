int Solution::maxSubArray(const vector<int> &A) {
    int n=A.size();
    int s=0,maxs=INT_MIN;
    for(int i=0;i<n;i++)
    {
        s+=A[i];
        maxs=max(s,maxs);
        if(s<0)
        s=0;
    }
    return maxs;
}
