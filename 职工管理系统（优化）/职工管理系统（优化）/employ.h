#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class employ :public worker
{
public:
	//������ʼ������
	employ(int id,string name,int did);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdeptname();
};
