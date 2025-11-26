#include <iostream>
#include <vector>
#include <algorithm>

#include "measurement.h"

void Measurement::AddPoint(int point) {
     points.push_back(point);
}

void Measurement::Calibrate() {
    std::transform(points.begin(), points.end(),
	points.begin(), [&](int element){ return element * 3; });
}
