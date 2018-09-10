#include<cstring>
#include<iostream>
#include<fstream>
#include"mystring.h"

//不带参数的构造函数
//将私有成员data指向空
mystring::mystring(){
	data=NULL;
}
mystring::mystring(unsigned int size){
	if(0==size){
		data=NULL;
		return ;
	}
	data=new char[size];
	memset(data,0,size);
}
mystring::mystring(unsigned int size,char ch){
	if(0==size){
		data=NULL;
		return ;
	}
	data=new char[size];
	memset(data,(int)ch,size);
}
//参数data 常量字符指针
mystring::mystring(const char* data){
	if(data==NULL){
		this->data=NULL;
		return;
	}
	this->data=new char[strlen(data)+1];
	strcpy(this->data,data);
}
mystring::mystring(mystring& str){
	if(str.data==NULL){
		data=NULL;
		return; 
	}
	this->data=new char[strlen(str.data)+1];
	strcpy(data,str.data);
}
mystring::mystring(const char* data,int start,int end){
	if(NULL==data){
		data=NULL;
		return ;
	}
	this->data=new char[end-start+2];
	strncpy(this->data,data+start-1,end-start+1);
	this->data[end-start+2]='\0';
}
char* mystring::getData() const{
	return data;
}
mystring& mystring::operator=(const mystring& str){
	if(str.data==NULL){
		this->data=NULL;
		return *this;
	}
	delete[] this->data;
	this->data=new char[strlen(str.data)+1];
	strcpy(this->data,str.data);
	return *this;
}
bool mystring::operator>(const mystring& str){
	return strcmp(this->data,str.data)>0?true:false;
}
bool mystring::operator<(const mystring& str){
	return strcmp(this->data,str.data)<0?true:false;
}
bool mystring::operator>=(const mystring& str){
	return strcmp(this->data,str.data)>=0?true:false;
}
bool mystring::operator<=(const mystring& str){
	return strcmp(this->data,str.data)<=0?true:false;
}
bool mystring::operator==(const mystring& str){
	return strcmp(this->data,str.data)==0?true:false;
}
bool mystring::operator!=(const mystring& str){
	return strcmp(this->data,str.data)!=0?true:false;
}
std::ostream& operator<<(std::ostream& out,const mystring& str){
	return out<<str.data;
}
std::istream& operator>>(std::istream& in,mystring& str){
	int size=10;
	int i=0;
	char* temp = new char[size+1];
	while(1){
		if('\n'==in.peek()) break;
		if(i>size){
			size+=2;
			char* temp_buf=new char[size+1];
			strcpy(temp_buf,temp);
			delete[] temp;
			temp=temp_buf;

		}
		temp[i]=in.get();
		++i;
	}
	temp[i]='\0';
	if(str.data!=NULL){
		delete[] str.data;
	}
	str.data=new char[size+1];
	strcpy(str.data,temp);
	return in;
}
mystring::~mystring(){
	delete[] data;
}

