#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//�����ϵ�˵Ľṹ��
struct Person
{
	string name;//����
	string sex;//�Ա�
	int age;//����
	string phone;//�绰����
	string addr;//��ͥסַ
};
//���ͨѶ·�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б�����ϵ������
	struct Person arr[MAX];
	int size;
	//ͨѶ¼�ĵ�ǰ��ϵ�˸���
};
//�����ϵ��
void addPerson(struct Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ��Ѿ�����
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�������޷����������ϵ�ˣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//�������
		string name;
		cout << "������������";
		cin >> name;
		abs->arr[abs->size].name = name;
		cout << endl;
		//����Ա�
		string sex;
		cout << "������Ա�";
		cin >> sex;
		abs->arr[abs->size].sex = sex;
		cout << endl;
		//�������
		int age;
		cout << "��������䣺";
		cin >> age;
		abs->arr[abs->size].age = age;
		cout << endl;
		//��ӵ绰����
		string phone;
		cout << "����ӵ绰���룺";
		cin >> phone;
		abs->arr[abs->size].phone = phone;
		cout << endl;
		//���ͨѶ¼��ַ
		string addr;
		cout << "�����ͨѶ¼��ַ��";
		cin >> addr;
		abs->arr[abs->size].addr = addr;
		cout << endl;
		abs->size++;
		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}

}
void showPerson(struct Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�Ϊ��
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ��!" << endl;
		return;
	}
	else
	{
		//��ʾ��ϵ��
		for (int i = 0; i < abs->size; i++)
		{
			cout << "��ϵ��������" << abs->arr[i].name <<"  ";
			cout << "��ϵ���Ա�" << abs->arr[i].sex << "  ";
			cout << "��ϵ�����䣺" << abs->arr[i].age << "  ";
			cout << "��ϵ�˵绰��" << abs->arr[i].phone<< "  ";
			cout << "��ϵ��ͨѶ¼��ַ��" << abs->arr[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�ж���ϵ���Ƿ���ں���
int isExist(struct Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		//�ҵ���ϵ��
		if (abs->arr[i].name == name)
		{
			return i;
		}
	}
	return -1;//û���ҵ���ϵ��
}
void delPerson(struct Addressbooks *abs)
{
	cout << "������Ҫɾ����ϵ��������";
	string name;
	cin >> name;
	cout << endl;
	//1.�ж���ϵ���Ƿ����
	int ret = isExist(abs, name);
	if  (ret== -1)
	{
		cout << "û�и���ϵ��!" << endl;
	}
	//2.�������ɾ����ϵ��
	else
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->arr[i] = abs->arr[i + 1];
		}
		abs->size--;
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findPerson(struct Addressbooks* abs)
{
	cout << "������Ҫ������ϵ��������";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "û�и���ϵ�ˣ�" << endl;
	}
	else
	{
		cout << "��ϵ��������" << abs->arr[ret].name << " ";
		cout << "��ϵ���Ա�" << abs->arr[ret].sex << " ";
		cout << "��ϵ�����䣺" << abs->arr[ret].age << " ";
		cout << "��ϵ�˵绰��" << abs->arr[ret].phone << " ";
		cout << "��ϵ��ͨѶ¼��ַ��" << abs->arr[ret].addr <<endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modfyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸���ϵ��������";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "û�и���ϵ�ˣ�" << endl;
	}
	else
	{
		//�������
		string name;
		cout << "������������";
		cin >> name;
		abs->arr[ret].name = name;
		cout << endl;
		//����Ա�
		string sex;
		cout << "������Ա�";
		cin >> sex;
		abs->arr[ret].sex = sex;
		cout << endl;
		//�������
		int age;
		cout << "��������䣺";
		cin >> age;
		abs->arr[ret].age = age;
		cout << endl;
		//��ӵ绰����
		string phone;
		cout << "����ӵ绰���룺";
		cin >> phone;
		abs->arr[ret].phone = phone;
		cout << endl;
		//���ͨѶ¼��ַ
		string addr;
		cout << "�����ͨѶ¼��ַ��";
		cin >> addr;
		abs->arr[ret].addr = addr;
		cout << endl;
		cout << "�޸���ϵ�˳ɹ���" << endl;
		system("pause");
		system("cls");

	}
}
//���ͨѶ¼
void clearPerson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "�����ϵ�˳ɹ���" << endl;
	system("pause");
	system("cls");
}
//1.��ʾ�˵�����
void showMenu()
{
	cout << "************************************" << endl;
	cout << "***************1.�����ϵ��*********" << endl;
	cout << "***************2.��ʾ��ϵ��*********" << endl;
	cout << "***************3.ɾ����ϵ��*********" << endl;
	cout << "***************4.������ϵ��*********" << endl;
	cout << "***************5.�޸���ϵ��*********" << endl;
	cout << "***************6.�����ϵ��*********" << endl;
	cout << "***************0.�˳�ͨѶ¼*********" << endl;
	cout << "************************************" << endl;

}
int main()
{
	//����ͨѶ¼�ṹ�����
	struct Addressbooks abs;
	abs.size = 0;//��ʼ��
	int select = 0;//�洢�û���ѡ��
	//���ò˵�����
	while (1)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);//ͨ����ַ���ݸı�ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			delPerson(&abs);
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modfyPerson(&abs);
			break;
		case 6://�����ϵ��
			clearPerson(&abs);
			break;
		case 0://�˳��˵�����
			cout << "��ӭ�´�ʹ�ã�" << endl;
			exit(0);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}