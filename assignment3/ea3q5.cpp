#include <iostream>
#include <stack>
using namespace std;
int main() {
  int T;
  cin >> T;
  while(T--){
    int N;
    cin>>N;
    stack <int> s;
    int need = 1;
    bool possible = true;
    for(int i = 0 ; i < N ; i++){
      int x;
      cin>>x;
      s.push(x);
      while(!s.empty()&& s.top()==need){
        s.pop();
        need++;
      }
    }
if(s.empty())
cout<<"yes";
else 
  cout<<"no";

  }
}