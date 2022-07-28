#pragma once
#include<iostream>
using namespace std;
class worker
{
public:
	virtual void showinfo() = 0;//显示个人信息
	virtual string getdeptname() = 0;//获取岗位名称

	int worknum;//获取职位编号
	string name;//获取职工姓名
	int m_dept;//获取职工所在部门编号
};