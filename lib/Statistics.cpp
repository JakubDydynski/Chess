#include "Statistics.h"

#include <algorithm>
#include <numeric>
#include <cmath>
using namespace swo::stats;

void Statistics::collect(int input) { data.push_back(input); }

int Statistics::sum() const {
  return std::accumulate(std::begin(data), std::end(data), 0);
}
int Statistics::max() const {
  return *std::max_element(std::begin(data), std::end(data));
}

int Statistics::min() const {
  return *std::min_element(std::begin(data), std::end(data));
}

double Statistics::median() {
  int n = count();
  if (n == 0) {
    return 0.0;
  }
  // If size of the arr[] is even
  if (n % 2 == 0) {
    // Applying nth_element
    // on n/2th index
    std::nth_element(data.begin(), data.begin() + n / 2, data.end());

    // Applying nth_element
    // on (n-1)/2 th index
    std::nth_element(data.begin(), data.begin() + (n - 1) / 2, data.end());

    // Find the average of value at
    // index N/2 and (N-1)/2
    return (double)(data[(n - 1) / 2] + data[n / 2]) / 2.0;
  }

  // If size of the arr[] is odd
  else {
    // Applying nth_element
    // on n/2
    std::nth_element(data.begin(), data.begin() + n / 2, data.end());

    // Value at index (N/2)th
    // is the median
    return (double)data[n / 2];
  }
}

double Statistics::average() const { return sum() / count(); }

double Statistics::standard_deviation() const{
  double sum = std::accumulate(std::begin(data), std::end(data), 0.0);
  double mean =  sum / data.size();

  std::vector<double> diff(data.size());
  std::transform(data.begin(), data.end(), diff.begin(),[mean](double x) { return x - mean; });


  double sq_sum = std::inner_product(data.begin(), data.end(), data.begin(), 0.0);
  double stdev = std::sqrt(sq_sum / data.size() - mean * mean);
  return stdev;
}