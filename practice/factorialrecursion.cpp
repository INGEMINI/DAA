#include <iostream>
using namespace std;

int factorial(int n)
{
  return (n == 0) ? 1 : n * factorial(n - 1);
}

int main()
{

  int n = 5;
  cout << " factorial : " << factorial(n);
  return 0;
}
