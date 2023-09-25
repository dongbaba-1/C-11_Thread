#include <iostream>
#include <thread>
#include <string>
#include <Windows.h>
void cout_fuc(std::string str,int time) {
	for (int i = 0; i < time; ++i) {
		std::cout << str << std::endl;
	}
	
}

void cin_func(std::string str) {
	for(int i = 0;i<10000;++i)
		std::cout << "echo：" <<str<< std::endl;
}

int main() {
	std::thread thread1(cout_fuc,"Hello",10);//创建线程thread1，第一个参数为传入的函数指针，即该线程执行的函数；其后的参数依次为要传入的函数指针的参数
	if (thread1.joinable()) {//为了严谨性，避免不能使用join或detach的对象使用join或detach
		thread1.join();//主程序等待该线程结束
	}
	
	std::string str1;
	std::cin >> str1;
	std::thread thread2(cin_func, str1);
	thread2.detach();//主程序和该线程分离，即使主程序结束，也不会报错，且该子线程依旧在后台执行
	Sleep(3000);
	std::cout << "主程序over！" << std::endl;
	return 0;
}