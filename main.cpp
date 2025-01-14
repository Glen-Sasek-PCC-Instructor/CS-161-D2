//*****************************************************************************
// Author:
// Assignment:
// Date:
// Description:
// Sources:
//*****************************************************************************

/*
SAMPLE RUNS
MILES PER GALLON: 10.0
USD PER GALLON: 5.0

MILES       COST
    20     $10.00
    75     $37.50
  500    $250.00
*/

#include <iostream>

// https://en.cppreference.com/w/cpp/header/iomanip
#include <iomanip> // For https://en.cppreference.com/w/cpp/io/manip/setprecision

using namespace std;

int main()
{
  double miles_per_gallon = 0.0;
  double usd_per_gallon = 0.0;

  double usd_per_20_miles = 0.0;
  double usd_per_75_miles = 0.0;
  double usd_per_500_miles = 0.0;

  cout << "MILES PER GALLON: ";
  cin >> miles_per_gallon;

  cout << "USD PER GALLON: ";
  cin >> usd_per_gallon;

  usd_per_20_miles = 20.0 / miles_per_gallon * usd_per_gallon;
  usd_per_75_miles = 75.0 / miles_per_gallon * usd_per_gallon;
  usd_per_500_miles = 500.0 / miles_per_gallon * usd_per_gallon;

  cout << fixed << setprecision(2);

  cout << "MILES       COST" << endl;
  cout << "   20       $" << usd_per_20_miles << endl;
  cout << "   75       $" << usd_per_75_miles << endl;
  cout << "  500       $" << usd_per_500_miles << endl;

  return 0;
}
