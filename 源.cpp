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
		std::cout << "echo��" <<str<< std::endl;
}

int main() {
	std::thread thread1(cout_fuc,"Hello",10);//�����߳�thread1����һ������Ϊ����ĺ���ָ�룬�����߳�ִ�еĺ��������Ĳ�������ΪҪ����ĺ���ָ��Ĳ���
	if (thread1.joinable()) {//Ϊ���Ͻ��ԣ����ⲻ��ʹ��join��detach�Ķ���ʹ��join��detach
		thread1.join();//������ȴ����߳̽���
	}
	
	std::string str1;
	std::cin >> str1;
	std::thread thread2(cin_func, str1);
	thread2.detach();//������͸��̷߳��룬��ʹ�����������Ҳ���ᱨ���Ҹ����߳������ں�ִ̨��
	Sleep(3000);
	std::cout << "������over��" << std::endl;
	return 0;
}