#pragma once
#include<iostream>
using namespace std;
class worker
{
public:
	virtual void showinfo() = 0;//��ʾ������Ϣ
	virtual string getdeptname() = 0;//��ȡ��λ����

	int worknum;//��ȡְλ���
	string name;//��ȡְ������
	int m_dept;//��ȡְ�����ڲ��ű��
};