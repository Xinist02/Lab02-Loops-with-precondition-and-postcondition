/************************************************
* Автор:   Хребтов Андрей                       *
* Задание: Циклы с предусловием и постусловием  *
* Вариант: 13                                   *
*                                               *
*                                               *
*                                               *
************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
  double t1, t2, delta1, delta2, lambda1, lambda2;
  cout << "Enter t1, t2, delta1 (cm), delta2 (cm), lambda1, lambda2: ";
  cin >> t1 >> t2 >> delta1 >> delta2 >> lambda1 >> lambda2;

  double delta1Meters = delta1 / 100.0;
  double delta2Meters = delta2 / 100.0;

  double f1 = lambda1 / delta1Meters;
  double f2 = lambda2 / delta2Meters;
  double tc = (f1 * t1 + f2 * t2) / (f1 + f2);

  const double firstStart = 500.0;
  const double firstFinish = 400.0;
  const double secondStart = 250.0;
  const double secondFinish = 150.0;
  const double step = -100.0;

  cout << "\n t (deg) | x (m)\n";
  cout << "-----------------\n";

  int stepIndex = 0;
  double t = firstStart;
  double x;

  do {
    if (t > tc) {
      x = ((t - t1) / (tc - t1)) * delta1Meters;
    } else {
      x = ((t - tc) / (t2 - tc)) * delta2Meters + delta1Meters;
    }
    cout << setw(7) << fixed << setprecision(0) << t << "  |  "  << setprecision(3) << x << "\n";
    ++stepIndex;
    t = firstStart + stepIndex * step;
  } while (t >= firstFinish);

  stepIndex = 0;
  t = secondStart;
  while (t >= secondFinish) {
    if (t > tc) {
      x = ((t - t1) / (tc - t1)) * delta1Meters;
    }
    else {
      x = ((t - tc) / (t2 - tc)) * delta2Meters + delta1Meters;
    }
    cout << setw(7) << fixed << setprecision(0) << t << "  |  " << setprecision(3) << x << "\n";
    ++stepIndex;
    t = secondStart + stepIndex * step;
  }

  return 0;
}