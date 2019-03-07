#include "boost/variant.hpp"
#include <iostream>
#include <vector>

typedef double Volume, Weight;
typedef int Id;
typedef bool BallastType;

struct Container
{
    Volume volume_allowance;
    Weight weight_allowance;
    bool is_air_conditioned;
    Id id;
};

struct MultiContainer
{
    std::vector<Container> containers;
    Id id;
};

struct Ballast
{
    BallastType type;
    Weight weight;
};

/**
 * Boost.Variant guarantees that objects of type Block always
 * hold a valid instance of one of the three sub-types:
 * they are never ’empty’. This is called a never-empty guarantee.
 */
using Block = boost::variant<Ballast, Container, MultiContainer>;

struct Weight_allowance : boost::static_visitor<Weight>
{
    Weight operator()(const Container& cont) const
    {
      return cont.weight_allowance;
    }

    Weight operator()(const MultiContainer& multi) const
    {
      Weight wgt (0);
      for (const Container& cont : multi.containers)
        wgt += cont.weight_allowance;
      return wgt;
    }

    Weight operator()(const Ballast&) const
    {
      return Weight(0);
    }
};

struct Is_ballast : boost::static_visitor<bool>
{
    bool operator()(const Ballast&) const { return true; }

    template <typename T>
    bool operator()(const T&) const { return false; }
};

int main()
{
  Block b;
  Weight w = boost::apply_visitor(Weight_allowance(), b);
  std::cout << w;
  return 0;
}