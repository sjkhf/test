#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class boss :public worker
{
public:
	//������ʼ������
	boss(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showinfo();
	//��ȡ��λ����
	virtual string getdeptname();
};