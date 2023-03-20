#include<iostream>
#include<String>


using namespace std;
#define Max  100 //不用加分号

void mume()
{
	cout << "通讯录管理系统有以下几种功能：" << endl;
	cout << "*****   1、添加联系人   ***** " << endl;
	cout << "*****   2、显示联系人   ***** " << endl;
	cout << "*****   3、删除联系人   ***** " << endl;
	cout << "*****   4、查找联系人   ***** " << endl;
	cout << "*****   5、修改联系人   ***** " << endl;
	cout << "*****   6、清空联系人   ***** " << endl;
	cout << "*****   0、退出通讯录   ***** " << endl;
	cout << "**请根据需求输入相应的序号:** " << endl;
}

struct personInfo
{
	//姓名
	string P_name;
	//性别
	int   P_sex;
	//年龄
	int	   P_age;
	//住址
	string P_address;
};

struct PhoneInfo
{
	//通讯录人员数量
	int P_num;
	//通讯录人员信息数组
	struct personInfo personInfo[Max];
};

//功能1；
void addperson(PhoneInfo *PhoneInfo)
{
	if (PhoneInfo->P_num == Max)
	{
		cout << "通讯录已满，无法进行数据添加" << endl;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入添加人员的姓名：" << endl;
		cin >> name;
		PhoneInfo->personInfo[PhoneInfo->P_num].P_name = name;//注意所有对于P_num的引用需要->符号
		//性别
		int   sex=0;
		do
		{
			cout << "请输入添加人员的性别：" << endl;
			cout << "男性——1" << endl;
			cout << "女性——2" << endl;
			cin >> sex;
		} while (!(sex == 1 || sex == 2));
		PhoneInfo->personInfo[PhoneInfo->P_num].P_sex = sex;
		//年龄
		int	   age;
		cout << "请输入添加人员的年龄：" << endl;
		cin >> age;
		PhoneInfo->personInfo[PhoneInfo->P_num].P_age = age;
		string address;
		cout << "请输入添加人员的住址：" << endl;
		cin >> address;
		PhoneInfo->personInfo[PhoneInfo->P_num].P_address = address;
		//更新人数
		PhoneInfo->P_num++;
		cout << "添加成功" << endl;
	}
	system("pause");
	system("cls");
}
//功能2
void showperson(PhoneInfo* PhoneInfo)
{
	if (PhoneInfo->P_num == 0)
	{
		cout << "通讯录为空，请先进行数据添加" << endl;
	}
	else
	{
		for (int i = 0; i < PhoneInfo->P_num; i++)
		{
			cout << "姓名：" << PhoneInfo->personInfo[i].P_name <<"\t";
			cout << "性别：" << (PhoneInfo->personInfo[i].P_sex ==1?"男":"女") << "\t";
			cout << "年龄：" << PhoneInfo->personInfo[i].P_age << "\t";
			cout << "地址：" << PhoneInfo->personInfo[i].P_address <<endl;

		}
		cout << "输出成功" << endl;
	}
	system("pause");//按任意键继续
	system("cls");//清空屏幕
}

//判断是否存在某个名字，若存在返回地址，否则返回-1
int IsExist(PhoneInfo* PhoneInfo,string name)
{
	//由于本身就已经判定是否有这个名字，若没有包含了通讯录为空的选项？
	//if (PhoneInfo->P_num == 0)
	//{
	//	//cout << "通讯录为空，请先进行数据添加" << endl;
	//}
	//else 
	//{
		for (int i = 0; i < PhoneInfo->P_num; i++)
		{
			if (PhoneInfo->personInfo[i].P_name == name)
				return  i;//可以返回i+1，因为数组中元素是减一的
		}
		return -1;
}
//3、删除某个人
void deleteperson(PhoneInfo* PhoneInfo)
{
	string name;
	cout << "请输入要删除的人员姓名：" << endl;
	cin >> name;
	int ret = IsExist(PhoneInfo, name);//此处为直接对指针进行操作，而非调用指针的对应的值  存疑2022.4.15
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = ret; i < PhoneInfo->P_num; i++)
		{
			PhoneInfo->personInfo[i] = PhoneInfo->personInfo[i + 1];
		}
		PhoneInfo->P_num--;
		cout << "删除成功"<<endl;
	}
	system("pause");//按任意键继续
	system("cls");//清空屏幕
}

//4、查找联系人
void findperson(PhoneInfo *PhoneInfo)
{
	string name;
	cout <<"请输出你想查找的联系人的名字" << endl;
	cin >> name;

	//自己写的时候用的方法
	/*for (int i = 0; i < PhoneInfo->P_num; i++)
	{
		while(PhoneInfo->personInfo[i].P_name == name)
		{
			cout << "姓名" << PhoneInfo->personInfo[i].P_name << "\t";
			cout << "性别" << (PhoneInfo->personInfo[i].P_sex ==1? "男":"女") << "\t";
			cout << "年龄" << PhoneInfo->personInfo[i].P_age << "\t";
			cout << "地址" << PhoneInfo->personInfo[i].P_address << endl;
			cout << "查询成功"<< endl;
			system("pause");
			system("cls");
			break;
		}
	}
	cout << "未存储此人" << endl;
	system("pause");
	system("cls");*/
	//善用已写函数
	int ret=IsExist(PhoneInfo, name);
	if (ret == -1)
	{
		cout << "未存储此人" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "姓名" << PhoneInfo->personInfo[ret].P_name << "\t";
		cout << "性别" << (PhoneInfo->personInfo[ret].P_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄" << PhoneInfo->personInfo[ret].P_age << "\t";
		cout << "地址" << PhoneInfo->personInfo[ret].P_address << endl;
		cout << "查询成功" << endl;
		system("pause");
		system("cls");
	}

}

//5、修改联系人
void repairperson(PhoneInfo* PhoneInfo)
{
	string name;
	cout << "请输出你想修改的联系人的名字" << endl;
	cin >> name;
	int ret=IsExist(PhoneInfo, name);
	if (ret == -1)
	{
		cout << "联系人列表内没有此人" << endl;
	}
	else
	{
		cout << "请问想修改此联系人哪个信息" << endl;
		cout << "1、姓名，2、性别，3、年龄，4、地址(请输入对应序号）" << endl;
		int info;
		cin >> info;
		while (info == 1 || info == 2 || info == 3 || info == 4)
		{
			switch (info)
			{
			case 1:
			{
				cout << "请输入修改后的联系人姓名：" << endl;
				string r_name;
				cin >> r_name;
				PhoneInfo->personInfo[ret].P_name = r_name;
			}
			break;
			case 2:
			{
				int r_sex;
				while (true)
				{
					cout << "请输入修改后的联系人性别：" << endl;
					cout << "男性——1；女性——2" << endl;
					cin >> r_sex;
					if (r_sex == 1 || r_sex == 2)
					{ 
						PhoneInfo->personInfo[ret].P_sex = r_sex;
						break;
					}
					cout << "修改失败" << endl;
				}
				break;
			}
			break;
			case 3:
			{
				cout << "请输入修改后的联系人年龄：" << endl;
				int r_age;
				cin >> r_age;
				PhoneInfo->personInfo[ret].P_age = r_age;
			}
			break;
			case 4:
			{
				cout << "请输入修改后的联系人姓名：" << endl;
				string r_address;
				cin >> r_address;
				PhoneInfo->personInfo[ret].P_address = r_address;	
			}
			break;
			}
			break;
		}
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}

//6、清空联系人
void clearperson(PhoneInfo *PhoneInfo)
{
	PhoneInfo->P_num = 0; //形式上清空
	cout << "联系人已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select;
	//显示目录
	
	struct PhoneInfo PhoneInfo;
	PhoneInfo.P_num = 0;

	while (true)
	{
		mume();
		cin >> select;
		//实现对应功能
		switch (select)
		{
		case 1://1、添加联系人
			addperson(&PhoneInfo);
			break;
		case 2://2、显示联系人
			showperson(&PhoneInfo);//此处可以不使用指针传递
			break;
		case 3:// 3、删除联系人
		/*{
			string name;
			cout << "请输入要删除人员的姓名" << endl;
			cin >> name;
			if (IsExist(&PhoneInfo, name) == -1)
				cout << "通讯录中没有此人信息" << endl;
		}*/
			deleteperson(&PhoneInfo);
			break;
		case 4://4、查找联系人
			findperson(&PhoneInfo);
			break;
		case 5://5、修改联系人
			repairperson(&PhoneInfo);
			break;
		case 6: //6、清空联系人
			clearperson(&PhoneInfo);
			break;
		case 0: //0、退出通讯录
			cout << "感谢使用，欢迎再次使用！" << endl;
			system("pause");
			return 0;
			//break;
		}
	}
	system("pause");
}