#ifndef __LOGASPECT_H
#define __LOGASPECT_H

#include <iostream>

template <typename WrappedType>
class LoggingAspect \
  : public BaseAspect<WrappedType, LoggingAspect<WrappedType> > {
  typedef BaseAspect<WrappedType, LoggingAspect<WrappedType> > BaseAspectWL;

public:
  LoggingAspect(WrappedType *p) : BaseAspectWL(p) { }

  void before(WrappedType *p) {
    std::cout << "entering" << std::endl;
  }

  void after(WrappedType *p) {
    std::cout << "existing" << std::endl;
  }
};

#endif

