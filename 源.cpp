#include <iostream>
#include <thread>
#include <string>

void cout_fuc(std::string str,int time) {
	for (int i = 0; i < time; ++i) {
		std::cout << str;
		std::cout << std::this_thread::get_id() << std::endl;
		//this_thread::get_id()这个函数打印该线程id
	}
	
}

void cin_func(std::string str) {
	for(int i = 0;i<10000;++i)
		std::cout << "echo：" <<str<< std::endl;
}

void foo(int& x) {
	x += 1;
}
void foo2(int* x) {
	std::cout << *x << std::endl;
}
int main() {
	//第一节
	//std::thread thread1(cout_fuc,"Hello",1000);//创建线程thread1，第一个参数为传入的函数指针，即该线程执行的函数；其后的参数依次为要传入的函数指针的参数
	//if (thread1.joinable()) {//为了严谨性，避免不能使用join或detach的对象使用join或detach
	//	std::cout << "join函数即将执行"<<std::endl;
	//	thread1.join();//主程序等待该线程结束
	//}
	
	//std::string str1;
	//std::cin >> str1;
	//std::thread thread2(cin_func, str1);
	//thread2.detach();//主程序和该线程分离，即使主程序结束，也不会报错，且该子线程依旧在后台执行
	//Sleep(3000);
	//std::cout << "主程序over！" << std::endl;
	
	//第二节
	//传递临时变量的问题
	//wrong：std::thread thread(foo, 1);//foo函数需要一个引用的参数，而数值1不是引用
	//int a = 1;
	//std::thread thread(foo, std::ref(a));//std::ref将一个变量包装为引用
	//int& b = a;
	//std::thread thread2(foo, std::ref(b));
	//if(thread.joinable())
	//	thread.join();//join正如其含义，创建一个线程仅仅是创建，
	//				//要通过join才能加入到该进程的线程队列中；相应的detach就是分离这个线程和进程
	//thread2.join();
	//std::cout << a << std::endl;

	//传递指针或引用 指向局部变量或被释放指针的问题
	int* ptr = new int(1000);
	std::thread thread3(foo2, ptr);//创建线程时已经传递了ptr？？这里有疑问
	//ptr = nullptr;
	delete ptr;//释放指针

	thread3.join();

	//类成员函数作为入口函数，类对象被提前释放
	return 0;
}
