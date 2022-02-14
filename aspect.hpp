#ifndef __ASPECT_HPP
#define __ASPECT_HPP

#include <memory>

template <typename WrappedType, typename DerivedAspect>
class BaseAspect {
protected:
  WrappedType *m_wrappedPtr;  // 被织入的对象

  // 获取派生的切面对象
  DerivedAspect* getDerived() {
    return static_cast<DerivedAspect*>(this);
  }

  // 被织入对象的删除器，用来自动触发切面中的 After 方法
  struct AfterWrapper {
    DerivedAspect *m_derived;

    AfterWrapper(DerivedAspect *derived) : m_derived(derived) { }
    void operator()(WrappedType* p) {
      m_derived->after(p);
    }
  };

public:
  explicit BaseAspect(WrappedType *p) : m_wrappedPtr(p) { }

  void before(WrappedType *p) {
    // Default do nothing
  }

  void after(WrappedType *p) {
    // Default do nothing
  }

  // 重载指针用来织入切面 (before 和 after)
  std::shared_ptr<WrappedType> operator->() {
    getDerived()->before(m_wrappedPtr);
    return std::shared_ptr<WrappedType>(m_wrappedPtr, AfterWrapper(getDerived()));
  }
};

// 织入切面的工厂函数，返回包含被织入对象的切面
template <template <typename> class Aspect, typename WrappedType>
Aspect<WrappedType> MakeAspect(WrappedType* p) {
  return Aspect<WrappedType>(p);
}

#endif
