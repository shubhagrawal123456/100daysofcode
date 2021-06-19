int Solution::hammingDistance(const vector<int> &A) {
    long res = 0;

for(int i = 0; i< 32;i++) {
    long counton = 0;
    
    for(int val : A) {
        if((val & (1<<i)) != 0){
            counton++;
        }
    }
    
    long countoff = A.size() - counton;
    long diff = counton * countoff *2;
    
    res+= diff;
}

return res % 1000000007;
}
