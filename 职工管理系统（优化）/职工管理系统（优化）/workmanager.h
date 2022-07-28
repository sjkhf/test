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
	//构造函数
	workmanager();
	//菜单栏
	int showm();
	//添加指针
	worker** m_array=NULL;
	//添加职工系统
	void add_num();
	//建立保存系统
	void save();
	//判断文件是否为空标志
	bool m_FLIEisopen;
	//当文件不为空且有内容，读取总长度
	int get_num();
	//读取文件初始化
	void init_emp();
	//显示职工
	void show_emp();
	//要修改和查找的位置，有利于程序的稳定性
	int isexist(int id);
	//删除职工
	void del_emp();
	//修改职工
	void mod_emp();
	//查找职工
	void find_emp();
	//退出系统
	void exitsystem();
	
	~workmanager();

	int m_num;//对象公司类的总人数
};