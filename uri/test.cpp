#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll sum, diff;

ll priceToConsumption(ll price) {
  ll consumption = 0;

  if (price < 200) {
    consumption = price / 2.0;
    price = 0;
  } else {
    consumption = 100;
    price -= 200;
  }

  if (price < (9900 * 3)) {
    consumption += price / 3.0;
    price = 0;
  } else {
    consumption += 9900;
    price -= 9900 * 3;
  }

  if (price < (990000 * 5)) {
    consumption += price / 5.0;
    price = 0;
  } else {
    consumption += 990000;
    price -= 990000 * 5.0;
  }

  consumption += price / 7.0;

  return consumption;

}

ll consumptionToPrice(ll consumption) {
  ll price = 0;

  // First 100 - 2
  if (consumption < 100) {
   price += consumption * 2; 
   consumption = 0;
  } else {
    price += 200;
    consumption -= 100;
  }

  // First 1000 - 3
  if (consumption < 9900) {
    price += consumption * 3;
    consumption = 0;
  } else {
    price += 9900 * 3;
    consumption -= 9900;
  }

  // First 10000 - 5
  if (consumption < 990000) {
    price += consumption * 5;
    consumption = 0;
  } else {
    price += 990000 * 5;
    consumption -= 990000;
  }

  price += consumption * 7;

  return price;
}


int main() {

  ll a;

  while(cin >> a && a != 0) {
    cout << "Price: " << consumptionToPrice(a) << endl;
    cout << "Consumption: " << priceToConsumption(a) << endl;
  }

  return 0;
}