#include "libcmaes/cmaparameters.h"
#include <functional>
#include <print>

#include <libcmaes/cmaes.h>

auto sphere_function(std::span<const double> xs) {
  auto ret{0.0};
  for (auto i{0u}; i < xs.size(); ++i) {
    ret += xs[i] * xs[i];
  }
  return ret;
}

auto make_cmaes(libcmaes::CMAParameters<> params) {
  using namespace std::placeholders;
  return std::bind(libcmaes::cmaes<>, _2, params);
}

auto run_experiment(auto &&solver, auto &&evaluation_fn) -> void {
  const auto result = solver(evaluation_fn);
}

auto main() -> int {
  using namespace libcmaes;

  const auto x0 = std::vector{10, 10.0};
  const auto init_sigma{1.0};

  
  auto params = CMAParameters<>{
    x0,

  }

  constexpr int dim = 10; // problem dimensions.
  std::vector<double> x0(dim, 10.0);
  double sigma = 0.1;
  // int lambda = 100; // offsprings at each generation.
  CMAParameters<> cmaparams(x0, sigma);
  // cmaparams.set_algo(BIPOP_CMAES);
  CMASolutions cmasols = cmaes(fsphere, cmaparams);
}
