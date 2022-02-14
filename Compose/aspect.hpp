#ifndef __ASPECT_HPP
#define __ASPECT_HPP

#include <functional>

struct Aspect {
	template <typename Func>
	Aspect(const Func& f) : m_func(f) {
	}
	
	// 基础模板
	template <typename T>
	void invoke(T&& value) {
		value.before();
		m_func();
		value.after();
	}

	template <typename Head, typename... Tail>
	void invoke(Head&& head, Tail&&... tail) {
		head.before();
		invoke(std::forward<Tail>(tail)...);
		head.after();
	}

private:
	std::function<void()> m_func;
};

template <typename... AP>
void Invoke(const std::function<void()>& f) {
	Aspect msp(f);
	msp.invoke(AP()...);
}



#endif
