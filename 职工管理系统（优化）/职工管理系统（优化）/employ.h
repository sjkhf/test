#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class employ :public worker
{
public:
	//创建初始三变量
	employ(int id,string name,int did);
	//显示个人信息
	virtual void showinfo();
	//获取岗位名称
	virtual string getdeptname();
};
