/************************************************
* Автор:   Хребтов Андрей                       *
* Задание: Циклы с предусловием и постусловием  *
* Вариант: 13                                   *
*                                               *
*                                               *
*                                               *
************************************************/

#include <iostream>
using namespace std;

int main() {
  const double firstStep = 0.5;
  const double secondStep = 5.0;
  const double start = 0.0;
  const double changePoint = 2.0;
  const double finish = 17.0;
  int stepIndex = 0;
  double argument = start;
  double result;

  do {
    result = argument * argument;
    cout << argument << " " << result << "\n";
    ++stepIndex;
    argument = start + stepIndex * firstStep;
  } while (argument <= changePoint);

  stepIndex = 1;
  argument = changePoint + stepIndex * secondStep;
  while (argument <= finish) {
    result = argument * argument;
    cout << argument << " " << result << "\n";
    ++stepIndex;
    argument = changePoint + stepIndex * secondStep;
  }
  return 0;
}
