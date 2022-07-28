#include<iostream>
using namespace std;
#include<string>
#include"workmanager.h"
//功能1，先创立一个退出选项在总类manager中加入exitsyatem()函数
// 
//功能2，是首先要实例化一个管理者类，该类作为包括后续功能的总类,并建立worker类包含不同职位类
//建立读取文件



int main()
{
	workmanager person1;
	int choose=0 ;
	while (true)
	{
		person1.showm();
		cout << "输入你的选择：" << endl;
		cin >> choose;
		switch (choose)
		{
		
		case 1:person1.add_num();//添加职工
			break;
		case 2:person1.show_emp();//显示职工
			break;
		case 3://删除职工
			break;
		case 4://修改职工
			break;
		case 5://查找职工
			break;
		case 6://排序职工
			break;
		case 7://清空文件
			break;
		case 0:person1.exitsystem();//退出系统
			break;
		default:
			system("cls");//如果都不是就清空刷新屏幕
			break;
		}
		system("pause");//按任意键
		system("cls");//清屏

	}

}
