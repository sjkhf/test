#include"boss.h"
boss::boss(int id, string name, int did)//ְλ��ţ����֣�ְ�����ڲ��ű��
{
	this->worknum = id;
	this->name = name;
	this->m_dept = did;
}
void boss::showinfo()
{
	cout << "ְλ��ţ�" << this->worknum << endl;
	cout << "ְ��������" << this->name << endl;
	cout << "ְ�����ڲ��ű�ţ�" << this->m_dept << endl;
}
string boss::getdeptname()
{
	return"�ϰ�";
}