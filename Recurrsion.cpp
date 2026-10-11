#include <iostream>
using namespace std;

int factorial(int a) {

  if (a == 1 || a == 0) {
    return 1;
  }
  return a * factorial(a - 1);
}

void table(int a, int n) {

  if (n == 0) {
    return;
  }
  table(a, n - 1);
  cout << 2 << "x" << n << "=" << a * n << endl;
}

void counter(int n) {
  if(n==0){
    return;
  }
  cout<<n<<endl;
  counter(n-1);
  
}

// sum of all numbers from 1 to n

int main() {


  return 0;
}