#include"workmanager.h"

//构造函数
workmanager::workmanager()
{
	this->m_num = 0;
	this->m_array = NULL;

	//判断文件是否为空
	ifstream op;
	op.open(FLIEname, ios::in);
	if (!op.is_open())//is_open判断文件是否打开函数
	{
		
		cout << "文件不存在" << endl;
		this->m_num = 0;
		this->m_array = NULL;
		this->m_FLIEisopen = true;
			op.close();
			return;
	}
	//判断文件存在但无数据
	char ch;
	op >> ch;
	if (op.eof())//读一个字符如果为末尾eof就说明文件为空
	{
		cout << "文件内容为空" << endl;
		this->m_FLIEisopen = true;
		this->m_num = 0;
		this->m_array = NULL;
		op.close();
		return;
	}
	//文件存在并记录数据
	int num = this->get_num();
	cout << "文件人数：" << num << endl;
	this->m_num = num;
	//开辟空间
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
		if (did == 1)//普通职工
		{
			work = new employ(id, name, did);
		}
		else if (did == 2)//经理
		{
			work = new director(id, name, did);
		}
		else if(did == 3)//老板
		{
			work = new boss(id, name, did);
		}
		this->m_array[index] = work;
		index++;
	}
	op.close();
}
//显示职工
void workmanager::show_emp()
{
	if (this->m_FLIEisopen)
	{
		cout << "真：文件无数据" << endl;
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
//菜单功能
int workmanager::showm()
{
	cout << "1、添加联系人：" << endl;
	cout << "2、显示联系人：" << endl;
	cout << "3、删除联系人：" << endl;
	cout << "4、查找联系人：" << endl;
	cout << "5、修改联系人：" << endl;
	cout << "6、清空联系人：" << endl;
	cout << "0、退出通讯录：" << endl;
	system("pause");
	return 0;
}
//退出程序
void workmanager::exitsystem()
{
	system("pause");
	exit(0);
}
void workmanager::save()
{
	ofstream op;//写文件
	op.open(FLIEname, ios::out | ios::app);//以文件形式写入

	for (int i = 0; i < this->m_num; i++)
	{
		op << this->m_array[i]->worknum <<
			this->m_array[i]->name
			<< this->m_array[i]->m_dept << endl;

	}
}
void workmanager::add_num()//他的功能是输入所要添加的人数
{
	int add_num=0;
	cout << "输入所要添加的职工人数：" << endl;
	cin >> add_num;
	//int newsize = this->m_num + add_num;
	//worker** newspace =new worker * [newsize];//定义一个新的指针给他传入我们所需要的空间，前面给空间必须加new.
	if(add_num>0)	
	{ 	
		int newsize = this->m_num + add_num;
		worker** newspace = new worker * [newsize];//定义一个新的指针给他传入我们所需要的空间，前面给空间必须加new.
		if (this->m_array != NULL)
		{
			for (int i = 0; i < newsize; i++)
			{
				newspace[i] = this->m_array[i];
			}
		}//当原来数组指针有值就将，array给到新空间里面。
		for (int i = 0; i < add_num; i++)//定义空间后为，指针数组赋值，当newsize为N时，那么添加数组i就在newsize-1处结束，那么就不可以等于，因为等于后他会执行到newsize处。
		{
			int id1;
			string name;
			int idept;
			cout << "请输入职位编号：" << endl;
			cin >> id1;
			cout << "请输入员工姓名：" << endl;
			cin >> name;
			cout << "输入岗位编号：" << endl;
			cout << "1,员工2,经理3,老板" << endl;
			cin >> idept;
			//定义一个worker类的指针来存储我们所添加的数据
			worker* work = NULL;//每次要初始化不然在存储下一个会造成数据冲突。
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
			//接受完成后将他赋给新空间
			newspace[this->m_num + i] = work;//缓冲区溢出那就给他加的一点嘛，不能直接加，加了要出事会抛出异常；
			
		}
		delete[] this->m_array;//释放原有空间
		this->m_array = newspace;//更改新空间指向
			this->m_num = newsize;
			cout << "添加成功" << endl;
			this->save();//保存数据到文件
	}
	else
	{
		cout << "无法添加" << endl;
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
	cout << "输入所要删除的位置：" << endl;
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
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "删除失败" << endl;
	}
	system("pause");
	system("cls");
	
}
void workmanager::mod_emp()
{
	cout << "输入要修改的职工编号：" << endl;
	int id;
	cin >> id;
	int ret = this->isexist(id);
	if (ret != -1)
	{
		delete this->m_array[ret];
		int newid = 0;
		string name = "";
		int select = 0;
		cout << "查到第" << id << "号员工,修改新编号" << endl;
		cin >> newid;
		cout << "修改新名称：" << endl;
		cin >> name;
		cout << "输入1：职工。输入2：经理。输入3：老板" << endl;
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

	}	cout << "修改成功" << this->m_array[ret]->worknum << endl;
	this->save();
}
//void workmanager:: save()
//{
//	ofstream op;//写文件
//	op.open(FLIEname,ios::out|ios::app);//以文件形式写入
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



//析构函数
workmanager::~workmanager()//手动释放
{
	if (this->m_array)
	{
		delete[]this->m_array;//释放原有空间
		this->m_array = NULL;
	}
}