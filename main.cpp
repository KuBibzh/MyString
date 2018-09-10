#include<iostream>
#include"mystring.h"
int main(){

	mystring str("fdsdfs");
	mystring str1(str);
	mystring str2("123456789",3,9);
	std::cin>>str2;
	mystring str3(20,0);
	mystring str4(20,'a');
	std::cout<<str<<std::endl<<str1<<std::endl<<str2<<std::endl<<str3<<std::endl<<str4<<std::endl<<str2.getData();
	return 0;
}
