#include <iostream>
using namespace std;


int factorial(int a) {

  if (a == 1 || a == 0) {
    return 1;
  }
  return a * factorial(a - 1);
}




void table(int a,int n){

    if(n==0){
        return;
    }
    table(a,n-1);
    cout<<2<<"x"<<n<<"="<<a*n<<endl;

}


int main() {
  cout << factorial(5)<<endl;
  table(2,8);
  return 0;
}