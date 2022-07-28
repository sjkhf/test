#include"workmanager.h"

//���캯��
workmanager::workmanager()
{
	this->m_num = 0;
	this->m_array = NULL;

	//�ж��ļ��Ƿ�Ϊ��
	ifstream op;
	op.open(FLIEname, ios::in);
	if (!op.is_open())//is_open�ж��ļ��Ƿ�򿪺���
	{
		
		cout << "�ļ�������" << endl;
		this->m_num = 0;
		this->m_array = NULL;
		this->m_FLIEisopen = true;
			op.close();
			return;
	}
	//�ж��ļ����ڵ�������
	char ch;
	op >> ch;
	if (op.eof())//��һ���ַ����Ϊĩβeof��˵���ļ�Ϊ��
	{
		cout << "�ļ�����Ϊ��" << endl;
		this->m_FLIEisopen = true;
		this->m_num = 0;
		this->m_array = NULL;
		op.close();
		return;
	}
	//�ļ����ڲ���¼����
	int num = this->get_num();
	cout << "�ļ�������" << num << endl;
	this->m_num = num;
	//���ٿռ�
	this->m_array = new worker * [this->m_num];
	this->init_emp();
}
int workmanager::get_num()
{
	ifstream op;
	op.open(FLIEname, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (op >> id && op >> name && op >> did)
	{
		index++;
	}
	op.close();

	return index;
}
void workmanager::init_emp()
{
	ifstream op;
	op.open(FLIEname, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (op >> id && op >> name && op >> did)
	{
		worker* work = NULL;
		if (did == 1)//��ְͨ��
		{
			work = new employ(id, name, did);
		}
		else if (did == 2)//����
		{
			work = new director(id, name, did);
		}
		else if(did == 3)//�ϰ�
		{
			work = new boss(id, name, did);
		}
		this->m_array[index] = work;
		index++;
	}
	op.close();
}
//��ʾְ��
void workmanager::show_emp()
{
	if (this->m_FLIEisopen)
	{
		cout << "�棺�ļ�������" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_num; i++)
		{
			this->m_array[i]->showinfo();
		}
		
	}
	system("pause");
		system("cls");
}
//�˵�����
int workmanager::showm()
{
	cout << "1�������ϵ�ˣ�" << endl;
	cout << "2����ʾ��ϵ�ˣ�" << endl;
	cout << "3��ɾ����ϵ�ˣ�" << endl;
	cout << "4��������ϵ�ˣ�" << endl;
	cout << "5���޸���ϵ�ˣ�" << endl;
	cout << "6�������ϵ�ˣ�" << endl;
	cout << "0���˳�ͨѶ¼��" << endl;
	system("pause");
	return 0;
}
//�˳�����
void workmanager::exitsystem()
{
	system("pause");
	exit(0);
}
void workmanager::save()
{
	ofstream op;//д�ļ�
	op.open(FLIEname, ios::out | ios::app);//���ļ���ʽд��

	for (int i = 0; i < this->m_num; i++)
	{
		op << this->m_array[i]->worknum <<
			this->m_array[i]->name
			<< this->m_array[i]->m_dept << endl;

	}
}
void workmanager::add_num()//���Ĺ�����������Ҫ��ӵ�����
{
	int add_num=0;
	cout << "������Ҫ��ӵ�ְ��������" << endl;
	cin >> add_num;
	//int newsize = this->m_num + add_num;
	//worker** newspace =new worker * [newsize];//����һ���µ�ָ�����������������Ҫ�Ŀռ䣬ǰ����ռ�����new.
	if(add_num>0)	
	{ 	
		int newsize = this->m_num + add_num;
		worker** newspace = new worker * [newsize];//����һ���µ�ָ�����������������Ҫ�Ŀռ䣬ǰ����ռ�����new.
		if (this->m_array != NULL)
		{
			for (int i = 0; i < newsize; i++)
			{
				newspace[i] = this->m_array[i];
			}
		}//��ԭ������ָ����ֵ�ͽ���array�����¿ռ����档
		for (int i = 0; i < add_num; i++)//����ռ��Ϊ��ָ�����鸳ֵ����newsizeΪNʱ����ô�������i����newsize-1����������ô�Ͳ����Ե��ڣ���Ϊ���ں�����ִ�е�newsize����
		{
			int id1;
			string name;
			int idept;
			cout << "������ְλ��ţ�" << endl;
			cin >> id1;
			cout << "������Ա��������" << endl;
			cin >> name;
			cout << "�����λ��ţ�" << endl;
			cout << "1,Ա��2,����3,�ϰ�" << endl;
			cin >> idept;
			//����һ��worker���ָ�����洢��������ӵ�����
			worker* work = NULL;//ÿ��Ҫ��ʼ����Ȼ�ڴ洢��һ����������ݳ�ͻ��
			switch (idept)
			{
			case 1:
				work = new employ(id1, name, idept);
				break;
			case 2:
				work = new director(id1, name, idept);
				break;
			case 3:
				work = new boss(id1, name, idept);
				break;
			default:
				break;
			}
			//������ɺ��������¿ռ�
			newspace[this->m_num + i] = work;//����������Ǿ͸����ӵ�һ�������ֱ�Ӽӣ�����Ҫ���»��׳��쳣��
			
		}
		delete[] this->m_array;//�ͷ�ԭ�пռ�
		this->m_array = newspace;//�����¿ռ�ָ��
			this->m_num = newsize;
			cout << "��ӳɹ�" << endl;
			this->save();//�������ݵ��ļ�
	}
	else
	{
		cout << "�޷����" << endl;
	}
	system("pause");
	system("cls");
}
int workmanager::isexist(int id)
{
	int index = -1;
	
		for (int i = 0; i < this->m_num ; i++)
		{
			if(this->m_array [i]->worknum =id)
			{
			index = i; 
			break;
			}
	    }
		return index;

}
void workmanager::del_emp()
{
	cout << "������Ҫɾ����λ�ã�" << endl;
	int id;
	cin >> id;
	int index = this->isexist(id);
	if (index != -1)
	{
		for (int i = index; i < this->m_num ; i++)
		{
			this->m_array[i] = this->m_array[i + 1];
		}
		this->m_num--;
		this->save();
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "ɾ��ʧ��" << endl;
	}
	system("pause");
	system("cls");
	
}
void workmanager::mod_emp()
{
	cout << "����Ҫ�޸ĵ�ְ����ţ�" << endl;
	int id;
	cin >> id;
	int ret = this->isexist(id);
	if (ret != -1)
	{
		delete this->m_array[ret];
		int newid = 0;
		string name = "";
		int select = 0;
		cout << "�鵽��" << id << "��Ա��,�޸��±��" << endl;
		cin >> newid;
		cout << "�޸������ƣ�" << endl;
		cin >> name;
		cout << "����1��ְ��������2����������3���ϰ�" << endl;
		cin >> select;
		worker* work = NULL;
		switch (select)
		{
		case 1:work = new employ(newid, name, select);
			break;
		case 2:work = new director(newid, name, select);
			break;
		case 3:work = new boss(newid, name, select);
			break;
		}
		this->m_array[ret] = work;

	}	cout << "�޸ĳɹ�" << this->m_array[ret]->worknum << endl;
	this->save();
}
//void workmanager:: save()
//{
//	ofstream op;//д�ļ�
//	op.open(FLIEname,ios::out|ios::app);//���ļ���ʽд��
//	
//	for (int i = 0; i < this->m_num; i++)
//	{
//		op << this->m_array[i]->worknum <<
//			 this->m_array[i]->name 
//			<< this->m_array[i]->m_dept << endl;
//		
//	}
	
	/*op.close();*/
//}



//��������
workmanager::~workmanager()//�ֶ��ͷ�
{
	if (this->m_array)
	{
		delete[]this->m_array;//�ͷ�ԭ�пռ�
		this->m_array = NULL;
	}
}