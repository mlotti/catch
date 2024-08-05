#include <iostream>

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

int main()
{


  int x = Factorial(1);

  std::cout << "---------------------- " << "\n";
  std::cout << x << "\n";
  std::cout << "---------------------- " << "\n";

  return 0;
}
