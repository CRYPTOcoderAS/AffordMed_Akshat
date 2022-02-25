#include <bits/stdc++.h>
using namespace std;

int main() {
 //inputs from the API of 4 params
    vector<int> primes= {2,3,5,7,11,13};
    vector<int> fibo = {1,1,2,3,5,8,13,21};
    vector<int> odd= {1,3,5,7,9,11,13,15,17,19,21,23};
    vector<int> rand= {5,17,3,19,76,24,1,5,10,34,8,27,7};


  // set is used to get unique numbers in sorted order
    set<int> s;

    for(int i=0;i<primes.size();i++){
      s.insert(primes[i]);
    }
    for(int i=0;i<fibo.size();i++){
      s.insert(fibo[i]);
    }
    for(int i=0;i<odd.size();i++){
      s.insert(odd[i]);
    }
    for(int i=0;i<rand.size();i++){
      s.insert(rand[i]);
    }
//printing set
  for(auto i : s){
    cout<<i<<" ";
  }
  cout<<endl;
  
}

