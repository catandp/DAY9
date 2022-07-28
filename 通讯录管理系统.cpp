#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//设计联系人的结构体
struct Person
{
	string name;//姓名
	string sex;//性别
	int age;//年龄
	string phone;//电话号码
	string addr;//家庭住址
};
//设计通讯路结构体
struct Addressbooks
{
	//通讯录中保存联系人数组
	struct Person arr[MAX];
	int size;
	//通讯录的当前联系人个数
};
//添加联系人
void addPerson(struct Addressbooks* abs)
{
	//判断通讯录是否已经满了
	if (abs->size == MAX)
	{
		cout << "通讯录已满，无法继续添加联系人！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//添加姓名
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->arr[abs->size].name = name;
		cout << endl;
		//添加性别
		string sex;
		cout << "请添加性别：";
		cin >> sex;
		abs->arr[abs->size].sex = sex;
		cout << endl;
		//添加年龄
		int age;
		cout << "请添加年龄：";
		cin >> age;
		abs->arr[abs->size].age = age;
		cout << endl;
		//添加电话号码
		string phone;
		cout << "请添加电话号码：";
		cin >> phone;
		abs->arr[abs->size].phone = phone;
		cout << endl;
		//添加通讯录地址
		string addr;
		cout << "请添加通讯录地址：";
		cin >> addr;
		abs->arr[abs->size].addr = addr;
		cout << endl;
		abs->size++;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}

}
void showPerson(struct Addressbooks* abs)
{
	//判断通讯录是否为空
	if (abs->size == 0)
	{
		cout << "通讯录为空!" << endl;
		return;
	}
	else
	{
		//显示联系人
		for (int i = 0; i < abs->size; i++)
		{
			cout << "联系人姓名：" << abs->arr[i].name <<"  ";
			cout << "联系人性别：" << abs->arr[i].sex << "  ";
			cout << "联系人年龄：" << abs->arr[i].age << "  ";
			cout << "联系人电话：" << abs->arr[i].phone<< "  ";
			cout << "联系人通讯录地址：" << abs->arr[i].addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//判断联系人是否存在函数
int isExist(struct Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		//找到联系人
		if (abs->arr[i].name == name)
		{
			return i;
		}
	}
	return -1;//没有找到联系人
}
void delPerson(struct Addressbooks *abs)
{
	cout << "请输入要删除联系人姓名：";
	string name;
	cin >> name;
	cout << endl;
	//1.判断联系人是否存在
	int ret = isExist(abs, name);
	if  (ret== -1)
	{
		cout << "没有该联系人!" << endl;
	}
	//2.如果存在删除联系人
	else
	{
		for (int i = ret; i < abs->size; i++)
		{
			abs->arr[i] = abs->arr[i + 1];
		}
		abs->size--;
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(struct Addressbooks* abs)
{
	cout << "请输入要查找联系人姓名：";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "没有该联系人！" << endl;
	}
	else
	{
		cout << "联系人姓名：" << abs->arr[ret].name << " ";
		cout << "联系人性别：" << abs->arr[ret].sex << " ";
		cout << "联系人年龄：" << abs->arr[ret].age << " ";
		cout << "联系人电话：" << abs->arr[ret].phone << " ";
		cout << "联系人通讯录地址：" << abs->arr[ret].addr <<endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modfyPerson(Addressbooks* abs)
{
	cout << "请输入要修改联系人姓名：";
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "没有该联系人！" << endl;
	}
	else
	{
		//添加姓名
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->arr[ret].name = name;
		cout << endl;
		//添加性别
		string sex;
		cout << "请添加性别：";
		cin >> sex;
		abs->arr[ret].sex = sex;
		cout << endl;
		//添加年龄
		int age;
		cout << "请添加年龄：";
		cin >> age;
		abs->arr[ret].age = age;
		cout << endl;
		//添加电话号码
		string phone;
		cout << "请添加电话号码：";
		cin >> phone;
		abs->arr[ret].phone = phone;
		cout << endl;
		//添加通讯录地址
		string addr;
		cout << "请添加通讯录地址：";
		cin >> addr;
		abs->arr[ret].addr = addr;
		cout << endl;
		cout << "修改联系人成功！" << endl;
		system("pause");
		system("cls");

	}
}
//清空通讯录
void clearPerson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "清空联系人成功！" << endl;
	system("pause");
	system("cls");
}
//1.显示菜单界面
void showMenu()
{
	cout << "************************************" << endl;
	cout << "***************1.添加联系人*********" << endl;
	cout << "***************2.显示联系人*********" << endl;
	cout << "***************3.删除联系人*********" << endl;
	cout << "***************4.查找联系人*********" << endl;
	cout << "***************5.修改联系人*********" << endl;
	cout << "***************6.清空联系人*********" << endl;
	cout << "***************0.退出通讯录*********" << endl;
	cout << "************************************" << endl;

}
int main()
{
	//创建通讯录结构体变量
	struct Addressbooks abs;
	abs.size = 0;//初始化
	int select = 0;//存储用户的选择；
	//调用菜单界面
	while (1)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);//通过地址传递改变实参
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			delPerson(&abs);
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modfyPerson(&abs);
			break;
		case 6://清空联系人
			clearPerson(&abs);
			break;
		case 0://退出菜单界面
			cout << "欢迎下次使用！" << endl;
			exit(0);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}