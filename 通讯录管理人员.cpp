#include<iostream>
#include<String>


using namespace std;
#define Max  100 //���üӷֺ�

void mume()
{
	cout << "ͨѶ¼����ϵͳ�����¼��ֹ��ܣ�" << endl;
	cout << "*****   1�������ϵ��   ***** " << endl;
	cout << "*****   2����ʾ��ϵ��   ***** " << endl;
	cout << "*****   3��ɾ����ϵ��   ***** " << endl;
	cout << "*****   4��������ϵ��   ***** " << endl;
	cout << "*****   5���޸���ϵ��   ***** " << endl;
	cout << "*****   6�������ϵ��   ***** " << endl;
	cout << "*****   0���˳�ͨѶ¼   ***** " << endl;
	cout << "**���������������Ӧ�����:** " << endl;
}

struct personInfo
{
	//����
	string P_name;
	//�Ա�
	int   P_sex;
	//����
	int	   P_age;
	//סַ
	string P_address;
};

struct PhoneInfo
{
	//ͨѶ¼��Ա����
	int P_num;
	//ͨѶ¼��Ա��Ϣ����
	struct personInfo personInfo[Max];
};

//����1��
void addperson(PhoneInfo *PhoneInfo)
{
	if (PhoneInfo->P_num == Max)
	{
		cout << "ͨѶ¼�������޷������������" << endl;
	}
	else
	{
		//����
		string name;
		cout << "�����������Ա��������" << endl;
		cin >> name;
		PhoneInfo->personInfo[PhoneInfo->P_num].P_name = name;//ע�����ж���P_num��������Ҫ->����
		//�Ա�
		int   sex=0;
		do
		{
			cout << "�����������Ա���Ա�" << endl;
			cout << "���ԡ���1" << endl;
			cout << "Ů�ԡ���2" << endl;
			cin >> sex;
		} while (!(sex == 1 || sex == 2));
		PhoneInfo->personInfo[PhoneInfo->P_num].P_sex = sex;
		//����
		int	   age;
		cout << "�����������Ա�����䣺" << endl;
		cin >> age;
		PhoneInfo->personInfo[PhoneInfo->P_num].P_age = age;
		string address;
		cout << "�����������Ա��סַ��" << endl;
		cin >> address;
		PhoneInfo->personInfo[PhoneInfo->P_num].P_address = address;
		//��������
		PhoneInfo->P_num++;
		cout << "��ӳɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//����2
void showperson(PhoneInfo* PhoneInfo)
{
	if (PhoneInfo->P_num == 0)
	{
		cout << "ͨѶ¼Ϊ�գ����Ƚ����������" << endl;
	}
	else
	{
		for (int i = 0; i < PhoneInfo->P_num; i++)
		{
			cout << "������" << PhoneInfo->personInfo[i].P_name <<"\t";
			cout << "�Ա�" << (PhoneInfo->personInfo[i].P_sex ==1?"��":"Ů") << "\t";
			cout << "���䣺" << PhoneInfo->personInfo[i].P_age << "\t";
			cout << "��ַ��" << PhoneInfo->personInfo[i].P_address <<endl;

		}
		cout << "����ɹ�" << endl;
	}
	system("pause");//�����������
	system("cls");//�����Ļ
}

//�ж��Ƿ����ĳ�����֣������ڷ��ص�ַ�����򷵻�-1
int IsExist(PhoneInfo* PhoneInfo,string name)
{
	//���ڱ�����Ѿ��ж��Ƿ���������֣���û�а�����ͨѶ¼Ϊ�յ�ѡ�
	//if (PhoneInfo->P_num == 0)
	//{
	//	//cout << "ͨѶ¼Ϊ�գ����Ƚ����������" << endl;
	//}
	//else 
	//{
		for (int i = 0; i < PhoneInfo->P_num; i++)
		{
			if (PhoneInfo->personInfo[i].P_name == name)
				return  i;//���Է���i+1����Ϊ������Ԫ���Ǽ�һ��
		}
		return -1;
}
//3��ɾ��ĳ����
void deleteperson(PhoneInfo* PhoneInfo)
{
	string name;
	cout << "������Ҫɾ������Ա������" << endl;
	cin >> name;
	int ret = IsExist(PhoneInfo, name);//�˴�Ϊֱ�Ӷ�ָ����в��������ǵ���ָ��Ķ�Ӧ��ֵ  ����2022.4.15
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = ret; i < PhoneInfo->P_num; i++)
		{
			PhoneInfo->personInfo[i] = PhoneInfo->personInfo[i + 1];
		}
		PhoneInfo->P_num--;
		cout << "ɾ���ɹ�"<<endl;
	}
	system("pause");//�����������
	system("cls");//�����Ļ
}

//4��������ϵ��
void findperson(PhoneInfo *PhoneInfo)
{
	string name;
	cout <<"�����������ҵ���ϵ�˵�����" << endl;
	cin >> name;

	//�Լ�д��ʱ���õķ���
	/*for (int i = 0; i < PhoneInfo->P_num; i++)
	{
		while(PhoneInfo->personInfo[i].P_name == name)
		{
			cout << "����" << PhoneInfo->personInfo[i].P_name << "\t";
			cout << "�Ա�" << (PhoneInfo->personInfo[i].P_sex ==1? "��":"Ů") << "\t";
			cout << "����" << PhoneInfo->personInfo[i].P_age << "\t";
			cout << "��ַ" << PhoneInfo->personInfo[i].P_address << endl;
			cout << "��ѯ�ɹ�"<< endl;
			system("pause");
			system("cls");
			break;
		}
	}
	cout << "δ�洢����" << endl;
	system("pause");
	system("cls");*/
	//������д����
	int ret=IsExist(PhoneInfo, name);
	if (ret == -1)
	{
		cout << "δ�洢����" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����" << PhoneInfo->personInfo[ret].P_name << "\t";
		cout << "�Ա�" << (PhoneInfo->personInfo[ret].P_sex == 1 ? "��" : "Ů") << "\t";
		cout << "����" << PhoneInfo->personInfo[ret].P_age << "\t";
		cout << "��ַ" << PhoneInfo->personInfo[ret].P_address << endl;
		cout << "��ѯ�ɹ�" << endl;
		system("pause");
		system("cls");
	}

}

//5���޸���ϵ��
void repairperson(PhoneInfo* PhoneInfo)
{
	string name;
	cout << "����������޸ĵ���ϵ�˵�����" << endl;
	cin >> name;
	int ret=IsExist(PhoneInfo, name);
	if (ret == -1)
	{
		cout << "��ϵ���б���û�д���" << endl;
	}
	else
	{
		cout << "�������޸Ĵ���ϵ���ĸ���Ϣ" << endl;
		cout << "1��������2���Ա�3�����䣬4����ַ(�������Ӧ��ţ�" << endl;
		int info;
		cin >> info;
		while (info == 1 || info == 2 || info == 3 || info == 4)
		{
			switch (info)
			{
			case 1:
			{
				cout << "�������޸ĺ����ϵ��������" << endl;
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
					cout << "�������޸ĺ����ϵ���Ա�" << endl;
					cout << "���ԡ���1��Ů�ԡ���2" << endl;
					cin >> r_sex;
					if (r_sex == 1 || r_sex == 2)
					{ 
						PhoneInfo->personInfo[ret].P_sex = r_sex;
						break;
					}
					cout << "�޸�ʧ��" << endl;
				}
				break;
			}
			break;
			case 3:
			{
				cout << "�������޸ĺ����ϵ�����䣺" << endl;
				int r_age;
				cin >> r_age;
				PhoneInfo->personInfo[ret].P_age = r_age;
			}
			break;
			case 4:
			{
				cout << "�������޸ĺ����ϵ��������" << endl;
				string r_address;
				cin >> r_address;
				PhoneInfo->personInfo[ret].P_address = r_address;	
			}
			break;
			}
			break;
		}
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//6�������ϵ��
void clearperson(PhoneInfo *PhoneInfo)
{
	PhoneInfo->P_num = 0; //��ʽ�����
	cout << "��ϵ�������" << endl;
	system("pause");
	system("cls");
}

int main()
{
	int select;
	//��ʾĿ¼
	
	struct PhoneInfo PhoneInfo;
	PhoneInfo.P_num = 0;

	while (true)
	{
		mume();
		cin >> select;
		//ʵ�ֶ�Ӧ����
		switch (select)
		{
		case 1://1�������ϵ��
			addperson(&PhoneInfo);
			break;
		case 2://2����ʾ��ϵ��
			showperson(&PhoneInfo);//�˴����Բ�ʹ��ָ�봫��
			break;
		case 3:// 3��ɾ����ϵ��
		/*{
			string name;
			cout << "������Ҫɾ����Ա������" << endl;
			cin >> name;
			if (IsExist(&PhoneInfo, name) == -1)
				cout << "ͨѶ¼��û�д�����Ϣ" << endl;
		}*/
			deleteperson(&PhoneInfo);
			break;
		case 4://4��������ϵ��
			findperson(&PhoneInfo);
			break;
		case 5://5���޸���ϵ��
			repairperson(&PhoneInfo);
			break;
		case 6: //6�������ϵ��
			clearperson(&PhoneInfo);
			break;
		case 0: //0���˳�ͨѶ¼
			cout << "��лʹ�ã���ӭ�ٴ�ʹ�ã�" << endl;
			system("pause");
			return 0;
			//break;
		}
	}
	system("pause");
}