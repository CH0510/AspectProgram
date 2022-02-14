#include "aspect.hpp"

#include <iostream>
#include <functional>
#include <utility>

struct AA {
	void before() {
		std::cout << "Before from AA" << std::endl;
	}

	void after() {
		std::cout << "After from AA" << std::endl;
	}
};

struct BB {
	void before() {
		std::cout << "before from BB" << std::endl;
	}

	void after() {
		std::cout << "after from BB" << std::endl;
	}
};

struct CC {
	void before() {
		std::cout << "before from CC" << std::endl;
	}

	void after() {
		std::cout << "after from CC" << std::endl;
	}
};

struct TT {
	void g() {
		std::cout << "real g function" << std::endl;
	}

	void h(int a) {
		std::cout << "real h function " << a << std::endl;
	}
};

struct DD {
	void before() {
	}

	void after() {
	}
};

void GT() {
	std::cout << "real GT function" << std::endl;
}

void HT(int a) {
	std::cout << "real HT function " << a << std::endl;
}

void TestAop() {
	TT tt;
	std::function<void()> ff = std::bind(&TT::g, &tt);
	// 组合两个切面 AA BB
	Invoke<AA, BB>([&ff](){ ff(); } );	// 织入成员函数
	Invoke<AA, BB>([&tt]() { tt.g(); });  // 织入对象
	
	int aa = 3;
	Invoke<AA, BB>(&GT);  // 织入方法
	Invoke<AA, BB>([aa](){ HT(aa); });  // 织入带参方法

	// 织入带参数的成员函数和对象
	std::function<void(int)> ff1 = std::bind(&TT::h, &tt, std::placeholders::_1);
	Invoke<AA, BB, CC, DD>([&ff1, aa]() { ff1(aa); });  //组合了四个切面
	Invoke<AA, BB>([&tt, aa]() { tt.h(aa); } );
}


int main(int argc, char *argv[]) {
	TestAop();
	return 0;
}
