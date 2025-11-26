#include <catch2/catch_test_macros.hpp>

#include "measurement.h"

TEST_CASE("Calibrate") {

    auto m = new Measurement();
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    for (auto p : myVector) {
        m->AddPoint(p);
    }

    m->Calibrate();

    std::vector<int> resultVector = {3, 6, 9, 12, 15};

    REQUIRE(m->GetPoint() == resultVector);
}

