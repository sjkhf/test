#include"director.h"
director::director(int id, string name, int did)//ְλ��ţ����֣�ְ�����ڲ��ű��
{
	this->worknum = id;
	this->name = name;
	this->m_dept = did;
}
void director::showinfo()
{
	cout << "ְλ��ţ�" << this->worknum << endl;
	cout << "ְ��������" << this->name << endl;
	cout << "ְ�����ڲ��ű�ţ�" << this->m_dept << endl;
}
string director::getdeptname()
{
	return"����";
}