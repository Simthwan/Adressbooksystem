#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

//��ϵ�˽ṹ��
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//ͨѶ¼�ṹ��
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
	//����ͨѶ¼�ṹ�����
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
			cout << "��ӭ�´�ʹ��!!!" << endl;
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

void show_menu() //��ʾ�˵�;
{
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
	cout << "��ѡ��:(����0-6�е�����)" << endl;
}

void addPerson(Addressbooks *abs) //�����ϵ��
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷��������!!!"<<endl;
		return;
	}
	else {
		string name;
		int sex,age;
		cout << "����������: "<<endl;
		cin >> name;
		abs->person[abs->m_Size].m_Name = name;
		cout << "�������Ա�: " << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->person[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������..." << endl;
		}
		//����
		cout << "����������: " << endl;
		cin >> age;
		abs->person[abs->m_Size].m_Age = age;
		//�绰
		cout << "��������ϵ�绰: " << endl;
		string phone;
		cin >> phone;
		abs->person[abs->m_Size].m_Phone = phone;
		//��ַ
		string address;
		cout << "�������ͥ��ַ: " << endl;
		cin >> address;
		abs->person[abs->m_Size].m_Addr = address;

		//����ͨѶ¼�е�����
		abs->m_Size++;
		cout << "��ӳɹ�!" << endl;
		system("pause"); //�밴���������
		system("cls"); //����
	}
}

void showPerson(Addressbooks *abs) //��ʾ��ϵ��
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ��
	if (abs->m_Size == 0) {
		cout << "��ǰ�ļ�¼Ϊ��..." << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "����:" << abs->person[i].m_Name << " ";
			cout << "�Ա�:" << (abs->person[i].m_Sex==1?"��":"Ů") << " ";
			cout << "����:" << abs->person[i].m_Age << " ";
			cout << "�绰:" << abs->person[i].m_Phone << " ";
			cout << "סַ:" << abs->person[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks *abs,string name) //�����ϵ���Ƿ����
{
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->person[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks *abs) //ɾ����ϵ��
{
	cout << "������Ҫɾ������ϵ��: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			abs->person[i] = abs -> person[i + 1]; //����ǰ��
		}
		abs->m_Size--; //����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���..." << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks *abs) //������ϵ��
{
	cout << "��������Ҫ���ҵ���ϵ��: " << endl;
	string name;
	cin >> name;
	//�ж���ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "����:" << abs->person[ret].m_Name << " ";
		cout << "�Ա�:" << (abs->person[ret].m_Sex == 1 ? "��" : "Ů") << " ";
		cout << "����:" << abs->person[ret].m_Age << " ";
		cout << "�绰:" << abs->person[ret].m_Phone << " ";
		cout << "סַ:" << abs->person[ret].m_Addr << endl;
	}
	else {
		cout << "���޴���..." << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks *abs) //�޸���ϵ��
{
	cout << "��������Ҫ�޸ĵ���ϵ��: " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		int sex, age;
		cout << "����������: " << endl;
		cin >> name;
		abs->person[ret].m_Name = name;
		cout << "�������Ա�: " << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->person[ret].m_Sex = sex;
				break;
			}
			cout << "������������������..." << endl;
		}
		//����
		cout << "����������: " << endl;
		cin >> age;
		abs->person[ret].m_Age = age;
		//�绰
		cout << "��������ϵ�绰: " << endl;
		string phone;
		cin >> phone;
		abs->person[ret].m_Phone = phone;
		//��ַ
		string address;
		cout << "�������ͥ��ַ: " << endl;
		cin >> address;
		abs->person[ret].m_Addr = address;
		cout << "�޸ĳɹ�!" << endl;
	}
	else {
		cout << "���޴���..." << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks *abs)
{
	char n;
	cout << "�Ƿ����������ϵ�ˣ�y/n" << endl;
	cin >> n;
	if (n == 'y') {
		abs->m_Size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	else {
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}