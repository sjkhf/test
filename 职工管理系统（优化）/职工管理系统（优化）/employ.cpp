#include"employ.h"
employ::employ(int id,string name,int did)//职位编号，名字，职工所在部门编号
{
	this->worknum = id;
	this->name = name;
	this->m_dept = did;
}
 void employ::showinfo()
{
	 cout << "职位编号：" << this->worknum << endl;
	 cout << "职工姓名：" << this->name << endl;
	 cout << "职工所在部门编号：" << this->m_dept << endl;
}
string employ::getdeptname()
 {
	return"员工";
 }