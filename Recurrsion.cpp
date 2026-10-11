// recurrsion practice question form basic to advance
#include <iostream>
using namespace std;


// factorial of a
int factorial(int a) {

  if (a == 1 || a == 0) {
    return 1;
  }
  return a * factorial(a - 1);
}


// tanle of a till n
void table(int a, int n) {

  if (n == 0) {
    return;
  }
  table(a, n - 1);
  cout << 2 << "x" << n << "=" << a * n << endl;
}

// counts tilll n
void counter(int n) {
  if(n==0){
    return;
  }
  cout<<n<<endl;
  counter(n-1);
  
}

// sum of all numbers from 1 to n
int  sumOfn(int n){
  if(n==1){
    return 1;
  }
  return n+sumOfn(n-1);
}

int main() {
  cout<<sumOfn(2);


  return 0;
}