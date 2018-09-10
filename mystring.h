#ifndef _STRING_H_
#define _STRING_H_

#include<iostream>
//typedef int _int;
//typedef bool _bool;
//typedef char _char;
class mystring{
private:
	char* data;
public:
	//不带参数的构造函数
	mystring();
	//申请size长度的空间,并将所有空间初始化为0的构造函数
	mystring(unsigned int size);
	//申请size长度的空间，并将所有空间初始化为ch字符构造函数
	mystring(unsigned int size,char ch);
	//传入字符串，进行初始化的构造函数
	mystring(const char* data);
	//传入string引用进行初始化的构造函数
	mystring(mystring& str);
	//传入字符串，开始字符索引和结束字符索引，进行初始化的构造函数
	mystring(const char* data,int start,int end);
	//析构函数，释放data空间
	~mystring();
	//获得data变量
	char* getData() const;
	mystring& operator+(const mystring& str);
	mystring& operator=(const mystring& str);
	bool operator==(const mystring& str);
	mystring& operator+=(const mystring& str);
	bool operator>(const mystring& str);
	bool operator<(const mystring& str);
	bool operator<=(const mystring& str);
	bool operator>=(const mystring& str);
	bool operator!=(const mystring& str);
	operator char*();



	friend std::istream& operator>>(std::istream& in,mystring& str);
	friend std::ostream& operator<<(std::ostream& out,const mystring& str);
	
};
std::istream& operator>>(std::istream& in,mystring& str);
std::ostream& operator<<(std::ostream& out,const mystring& str);




#endif
