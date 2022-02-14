#ifndef __TIMEASPECT_HPP
#define __TIMEASPECT_HPP

#include "aspect.hpp"

#include <iostream>
#include <chrono>

template <typename WrappedType>
class TimeElapsedAspect \
  : public BaseAspect<WrappedType, TimeElapsedAspect<WrappedType>> {
  typedef BaseAspect<WrappedType, TimeElapsedAspect<WrappedType>> BaseAspectWT;
  typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double> > time_point;

  time_point m_tmBegin;

public:
  TimeElapsedAspect(WrappedType *p) : BaseAspectWT(p) { }

  void before(WrappedType *p) {
    m_tmBegin = std::chrono::system_clock::now();
  }

  void after(WrappedType *p) {
    time_point end = std::chrono::system_clock::now();
    std::cout << "Time: " << (end - m_tmBegin).count() << std::endl;
  }
};

#endif
