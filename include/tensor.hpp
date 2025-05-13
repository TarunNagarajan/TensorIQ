// tensor.hpp (concept)
class Tensor {
public:
  Tensor(const std::array<size_t,4>& shape, int rank);
  size_t rank() const;
  size_t dim(size_t i) const;
  // …
private:
  std::array<size_t,4> _shape;
  int _rank;
  // storage below…
};
