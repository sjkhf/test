#include<iostream>
using namespace std;
#include<string>
#include"workmanager.h"
//����1���ȴ���һ���˳�ѡ��������manager�м���exitsyatem()����
// 
//����2��������Ҫʵ����һ���������࣬������Ϊ�����������ܵ�����,������worker�������ְͬλ��
//������ȡ�ļ�



int main()
{
	workmanager person1;
	int choose=0 ;
	while (true)
	{
		person1.showm();
		cout << "�������ѡ��" << endl;
		cin >> choose;
		switch (choose)
		{
		
		case 1:person1.add_num();//���ְ��
			break;
		case 2:person1.show_emp();//��ʾְ��
			break;
		case 3://ɾ��ְ��
			break;
		case 4://�޸�ְ��
			break;
		case 5://����ְ��
			break;
		case 6://����ְ��
			break;
		case 7://����ļ�
			break;
		case 0:person1.exitsystem();//�˳�ϵͳ
			break;
		default:
			system("cls");//��������Ǿ����ˢ����Ļ
			break;
		}
		system("pause");//�������
		system("cls");//����

	}

}
