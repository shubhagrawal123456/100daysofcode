vector<int> Solution::flip(string A) {
   vector<int>a;
    int ones=0;int zeros=0; int max=INT_MIN;int start=0;int index=0;int ind=0;

for(int i=0;A[i]!='\0';i++){
    if(A[i]=='0'){
        zeros++;
    }else{
        ones++;
    }
    if(zeros-ones<0){
        start=i+1;
        zeros=0;ones=0;
    }
    //cout<<"zeros "<<zeros<<"ones "<<ones<<endl;
    if(max<(zeros-ones)){
        max=zeros-ones;
        ind=start;
        index=i;
    }
    
}
if(max>0){
a.push_back(ind+1);a.push_back(index+1);    
}

return a;
}
