#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
#include"employ.h"
#include"director.h"
#include"boss.h"
#include<fstream>
#define FLIEname "test.txt"
class workmanager
{
public:
	//���캯��
	workmanager();
	//�˵���
	int showm();
	//���ָ��
	worker** m_array=NULL;
	//���ְ��ϵͳ
	void add_num();
	//��������ϵͳ
	void save();
	//�ж��ļ��Ƿ�Ϊ�ձ�־
	bool m_FLIEisopen;
	//���ļ���Ϊ���������ݣ���ȡ�ܳ���
	int get_num();
	//��ȡ�ļ���ʼ��
	void init_emp();
	//��ʾְ��
	void show_emp();
	//Ҫ�޸ĺͲ��ҵ�λ�ã������ڳ�����ȶ���
	int isexist(int id);
	//ɾ��ְ��
	void del_emp();
	//�޸�ְ��
	void mod_emp();
	//����ְ��
	void find_emp();
	//�˳�ϵͳ
	void exitsystem();
	
	~workmanager();

	int m_num;//����˾���������
};