#include "aspect.hpp"
#include "logaspect.hpp"
#include "timeaspect.hpp"

class IX {
public:
  IX() { }
  virtual ~IX() { }

  virtual void g() = 0;
private:
};

class X {
public:
  void g() {
    std::cout << "it is a test." << std::endl;
  }
};

void TestAop() {
  std::shared_ptr<X> p(new X());
  MakeAspect<TimeElapsedAspect>(p.get())->g();
  MakeAspect<LoggingAspect>(p.get())->g();
}

int main(int argc, char *argv[]) {
  TestAop();
  return 0;
}
