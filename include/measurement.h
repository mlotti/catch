#ifndef MEASURE_H
#define MEASURE_H

#include <vector>
#include <map>

class Measurement {
 private:
   std::vector<int> points;
 public:

   Measurement() = default;
   virtual ~Measurement() = default;

   void AddPoint(int point);
   std::vector<int> GetPoint() {return points;}

   void Calibrate();
};

#endif
