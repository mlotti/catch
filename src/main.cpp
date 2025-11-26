#include <iostream>
#include <vector>

#include "measurement.h"


int main() {

    auto m = new Measurement();

    std::vector<int> point = {1, 2, 3, 4, 5};

    for (int p : point) {
        m->AddPoint(p);
    }

    m->Calibrate();

    auto res = m->GetPoint();

    for (int r : res) {
      std::cout << "Measured: " << r << "\n";
    }

    return 0;
}
