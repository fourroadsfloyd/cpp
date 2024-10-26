#include <iostream>
#include <string>

#define MAX 1000

struct Person {
	std::string m_Name;
	int m_Sex;
	int m_Age;
	std::string m_Phone;
	std::string m_Addr;
};
struct AddressBooks {
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu()
{
	std::cout << "******************************" << std::endl;
	std::cout << "********1�������ϵ��*********" << std::endl;
	std::cout << "********2����ʾ��ϵ��*********" << std::endl;
	std::cout << "********3��ɾ����ϵ��*********" << std::endl;
	std::cout << "********4��������ϵ��*********" << std::endl;
	std::cout << "********5���޸���ϵ��*********" << std::endl;
	std::cout << "********6�������ϵ��*********" << std::endl;
	std::cout << "********0���˳�ͨѶ¼*********" << std::endl;
	std::cout << "******************************" << std::endl;

}

void addPerson(AddressBooks *abs)
{
	if (abs->m_Size == MAX)
	{
		std::cout << "ͨѶ¼����" << std::endl;
	}
	std::string name;
	std::cout << "������������";
	std::cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;

	int sex = 0;
	std::cout << "�������Ա�(1==�У�2==Ů)��";
	while(true)
	{
		std::cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->m_Size].m_Sex = sex;
			break;
		}
		else
		{
			std::cout << "��������ȷ���Ա�!" << std::endl;
			std::cout << "�������Ա�(1==�У�2==Ů)��";
		}
	}

	int age = 0;
	std::cout << "���������䣺";
	std::cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;

	std::string phone;
	std::cout << "������绰���룺";
	std::cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;

	std::string addres;
	std::cout << "�������ͥ��ַ��";
	std::cin >> addres;
	abs->personArray[abs->m_Size].m_Addr = addres;

	abs->m_Size++;

	std::cout << "�ɹ������ϵ�ˣ�" << std::endl;

	system("pause");
	system("cls");
}

void showPerson(const AddressBooks *abs)
{
	if (abs->m_Size == 0)
	{
		std::cout << "��ϵ��Ϊ�գ�" << std::endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			/*std::cout << i << std::endl;*/
			std::cout << "������" << abs->personArray[i].m_Name << "\t" ;
			std::cout << "�Ա�" << (abs->personArray[i].m_Sex ==1 ? "��" : "Ů") << "\t" ;
			std::cout << "���䣺" << abs->personArray[i].m_Age << "\t" ;
			std::cout << "���룺" << abs->personArray[i].m_Phone << "\t" ;
			std::cout << "סַ��" << abs->personArray[i].m_Addr << "\t" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(const AddressBooks *abs,std::string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
			return i;
	}
	return -1;
}

void deletePerson(AddressBooks* abs)
{
	std::cout << "������Ҫɾ������ϵ��������";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		std::cout << name << "��ɾ��" << std::endl;
	}
	else
	{
		std::cout << "���޴��ˣ�" << std::endl;
	}
	system("pause");
	system("cls");
}

void findPerson(const AddressBooks* abs)
{
	std::cout << "������Ҫ���ҵ���ϵ��������";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		std::cout << "������" << abs->personArray[ret].m_Name << "\t";
		std::cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		std::cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		std::cout << "���룺" << abs->personArray[ret].m_Phone << "\t";
		std::cout << "סַ��" << abs->personArray[ret].m_Addr << "\t" << std::endl;
	}
	else
	{
		std::cout << "���޴��ˣ�" << std::endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBooks* abs)
{
	std::cout << "������Ҫ�޸ĵ���ϵ��������";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		std::string name;
		std::cout << "������������";
		std::cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		std::cout << "�������Ա�(1==�У�2==Ů)��";
		while (true)
		{
			std::cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				std::cout << "��������ȷ���Ա�!" << std::endl;
				std::cout << "�������Ա�(1==�У�2==Ů)��";
			}
		}

		int age = 0;
		std::cout << "���������䣺";
		std::cin >> age;
		abs->personArray[ret].m_Age = age;

		std::string phone;
		std::cout << "������绰���룺";
		std::cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		std::string addres;
		std::cout << "�������ͥ��ַ��";
		std::cin >> addres;
		abs->personArray[ret].m_Addr = addres;

		std::cout << "�ɹ��޸���ϵ�ˣ�" << std::endl;
	}
	else
	{
		std::cout << "���޴��ˣ�" << std::endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(AddressBooks* abs)
{
	abs->m_Size = 0;
	std::cout << "ͨѶ¼����գ�" << std::endl;
	system("pause");
	system("cls");
}

int main()
{
	//�����ṹ�����
	AddressBooks abs;
	abs.m_Size = 0;

	while (1)
	{
		showMenu();

		int select;

		std::cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			clearPerson(&abs);
			break;
		case 0:
			std::cout << "��ӭ�´�ʹ��" << std::endl;
			return 0;
			break;
		}
	}
}