#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//联系人结构体
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//通讯录结构体
struct Addressbooks {
	struct Person person[MAX];
	int m_Size;
};

void show_menu();
void addPerson(Addressbooks *abs);
void showPerson(Addressbooks *abs);
int isExist(Addressbooks *abs,string name);
void deletePerson(Addressbooks *abs);
void findPerson(Addressbooks *abs);
void modifyPerson(Addressbooks *abs);
void cleanPerson(Addressbooks *abs);

int main(void)
{
	//创建通讯录结构体变量
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		show_menu();
		cin >> select;
		switch (select) {
		case 1: {
			addPerson(&abs);
			break;
		}
		case 2: {
			showPerson(&abs);
			break;
		}
		case 3: {
			deletePerson(&abs);
			break;
		}
		case 4: {
			findPerson(&abs);
			break;
		}
		case 5: {
			modifyPerson(&abs);
			break;
		}
		case 6: {
			cleanPerson(&abs);
			break;
		}
		case 0: {
			cout << "欢迎下次使用!!!" << endl;
			system("pause");
			return 0;
			break;
		}
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void show_menu() //显示菜单;
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
	cout << "请选择:(输入0-6中的数字)" << endl;
}

void addPerson(Addressbooks *abs) //添加联系人
{
	//判断通讯录是否已满
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法继续添加!!!"<<endl;
		return;
	}
	else {
		string name;
		int sex,age;
		cout << "请输入姓名: "<<endl;
		cin >> name;
		abs->person[abs->m_Size].m_Name = name;
		cout << "请输入性别: " << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->person[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入..." << endl;
		}
		//年龄
		cout << "请输入年龄: " << endl;
		cin >> age;
		abs->person[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入联系电话: " << endl;
		string phone;
		cin >> phone;
		abs->person[abs->m_Size].m_Phone = phone;
		//地址
		string address;
		cout << "请输入家庭地址: " << endl;
		cin >> address;
		abs->person[abs->m_Size].m_Addr = address;

		//更新通讯录中的人数
		abs->m_Size++;
		cout << "添加成功!" << endl;
		system("pause"); //请按任意键继续
		system("cls"); //清屏
	}
}

void showPerson(Addressbooks *abs) //显示联系人
{
	//判断通讯录中人数是否为零
	if (abs->m_Size == 0) {
		cout << "当前的记录为空..." << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名:" << abs->person[i].m_Name << " ";
			cout << "性别:" << (abs->person[i].m_Sex==1?"男":"女") << " ";
			cout << "年龄:" << abs->person[i].m_Age << " ";
			cout << "电话:" << abs->person[i].m_Phone << " ";
			cout << "住址:" << abs->person[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks *abs,string name) //检测联系人是否存在
{
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->person[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks *abs) //删除联系人
{
	cout << "请输入要删除的联系人: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->person[i] = abs -> person[i + 1]; //数据前移
		}
		abs->m_Size--; //更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人..." << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks *abs) //查找联系人
{
	cout << "请输入您要查找的联系人: " << endl;
	string name;
	cin >> name;
	//判断联系人是否存在
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名:" << abs->person[ret].m_Name << " ";
		cout << "性别:" << (abs->person[ret].m_Sex == 1 ? "男" : "女") << " ";
		cout << "年龄:" << abs->person[ret].m_Age << " ";
		cout << "电话:" << abs->person[ret].m_Phone << " ";
		cout << "住址:" << abs->person[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人..." << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks *abs) //修改联系人
{
	cout << "请输入您要修改的联系人: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		int sex, age;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->person[ret].m_Name = name;
		cout << "请输入性别: " << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->person[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入..." << endl;
		}
		//年龄
		cout << "请输入年龄: " << endl;
		cin >> age;
		abs->person[ret].m_Age = age;
		//电话
		cout << "请输入联系电话: " << endl;
		string phone;
		cin >> phone;
		abs->person[ret].m_Phone = phone;
		//地址
		string address;
		cout << "请输入家庭地址: " << endl;
		cin >> address;
		abs->person[ret].m_Addr = address;
		cout << "修改成功!" << endl;
	}
	else {
		cout << "查无此人..." << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks *abs)
{
	char n;
	cout << "是否清空所有联系人？y/n" << endl;
	cin >> n;
	if (n == 'y') {
		abs->m_Size = 0;
		cout << "通讯录已清空" << endl;
	}
	else {
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}