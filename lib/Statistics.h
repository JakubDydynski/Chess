#include <vector>

namespace swo::stats {

class Statistics {
 public:
  void collect(int input);

  int sum() const;
  std::size_t count() const { return data.size(); }
  double average() const;

  int max() const;
  int min() const;
  double median();

  double standard_deviation() const;

 private:
  std::vector<int> data;
};

}  // namespace swo::stats
