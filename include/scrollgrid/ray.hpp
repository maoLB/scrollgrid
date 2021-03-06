/**
 * Copyright (c) 2015 Carnegie Mellon University, Daniel Maturana <dimatura@cmu.edu>
 *
 * For License information please see the LICENSE file in the root directory.
 *
 */

#ifndef RAY_HPP_TVFS3AKQ
#define RAY_HPP_TVFS3AKQ

#include <boost/tuple/tuple.hpp>

#include <Eigen/Core>
#include <Eigen/Dense>

namespace ca
{
namespace scrollgrid
{

template<typename Scalar>
class Ray3 {
 public:
  typedef Eigen::Matrix<Scalar, 3, 1> Vec3;

 public:
  /**
   * @param origin: origin of ray
   * @param direction: *unit* direction of ray
   *
   * if you want to use origin/endpoint
   * Ray3(origin, (endpoint-origin).normalized());
   *
   */
  Ray3(const Vec3& origin,
       const Vec3& direction) :
         origin(origin),
         direction(direction),
         tmin(Scalar(0)),
         tmax(std::numeric_limits<Scalar>::max()),
         invdir(Scalar(1.) / direction.array()),
         sign(invdir.x() < 0,
              invdir.y() < 0,
              invdir.z() < 0)
  {
  }

 public:
  Vec3 point_at(Scalar t) const {
    return origin + t*direction;
  }

 public:
  Vec3 origin, direction;
  Scalar tmin, tmax; /// ray min and max distances
  Vec3 invdir; // for convenience in AABB intersection
  boost::tuple<int, int, int> sign;

};

}
} /* ca */
#endif /* end of include guard: RAY_HPP_TVFS3AKQ */
