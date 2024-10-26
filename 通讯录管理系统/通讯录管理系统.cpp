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
	std::cout << "********1、添加联系人*********" << std::endl;
	std::cout << "********2、显示联系人*********" << std::endl;
	std::cout << "********3、删除联系人*********" << std::endl;
	std::cout << "********4、查找联系人*********" << std::endl;
	std::cout << "********5、修改联系人*********" << std::endl;
	std::cout << "********6、清空联系人*********" << std::endl;
	std::cout << "********0、退出通讯录*********" << std::endl;
	std::cout << "******************************" << std::endl;

}

void addPerson(AddressBooks *abs)
{
	if (abs->m_Size == MAX)
	{
		std::cout << "通讯录已满" << std::endl;
	}
	std::string name;
	std::cout << "请输入姓名：";
	std::cin >> name;
	abs->personArray[abs->m_Size].m_Name = name;

	int sex = 0;
	std::cout << "请输入性别(1==男，2==女)：";
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
			std::cout << "请输入正确的性别!" << std::endl;
			std::cout << "请输入性别(1==男，2==女)：";
		}
	}

	int age = 0;
	std::cout << "请输入年龄：";
	std::cin >> age;
	abs->personArray[abs->m_Size].m_Age = age;

	std::string phone;
	std::cout << "请输入电话号码：";
	std::cin >> phone;
	abs->personArray[abs->m_Size].m_Phone = phone;

	std::string addres;
	std::cout << "请输入家庭地址：";
	std::cin >> addres;
	abs->personArray[abs->m_Size].m_Addr = addres;

	abs->m_Size++;

	std::cout << "成功添加联系人！" << std::endl;

	system("pause");
	system("cls");
}

void showPerson(const AddressBooks *abs)
{
	if (abs->m_Size == 0)
	{
		std::cout << "联系人为空！" << std::endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			/*std::cout << i << std::endl;*/
			std::cout << "姓名：" << abs->personArray[i].m_Name << "\t" ;
			std::cout << "性别：" << (abs->personArray[i].m_Sex ==1 ? "男" : "女") << "\t" ;
			std::cout << "年龄：" << abs->personArray[i].m_Age << "\t" ;
			std::cout << "号码：" << abs->personArray[i].m_Phone << "\t" ;
			std::cout << "住址：" << abs->personArray[i].m_Addr << "\t" << std::endl;
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
	std::cout << "请输入要删除的联系人姓名：";
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
		std::cout << name << "已删除" << std::endl;
	}
	else
	{
		std::cout << "查无此人！" << std::endl;
	}
	system("pause");
	system("cls");
}

void findPerson(const AddressBooks* abs)
{
	std::cout << "请输入要查找的联系人姓名：";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		std::cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		std::cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		std::cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		std::cout << "号码：" << abs->personArray[ret].m_Phone << "\t";
		std::cout << "住址：" << abs->personArray[ret].m_Addr << "\t" << std::endl;
	}
	else
	{
		std::cout << "查无此人！" << std::endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(AddressBooks* abs)
{
	std::cout << "请输入要修改的联系人姓名：";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		std::string name;
		std::cout << "请输入姓名：";
		std::cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex = 0;
		std::cout << "请输入性别(1==男，2==女)：";
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
				std::cout << "请输入正确的性别!" << std::endl;
				std::cout << "请输入性别(1==男，2==女)：";
			}
		}

		int age = 0;
		std::cout << "请输入年龄：";
		std::cin >> age;
		abs->personArray[ret].m_Age = age;

		std::string phone;
		std::cout << "请输入电话号码：";
		std::cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		std::string addres;
		std::cout << "请输入家庭地址：";
		std::cin >> addres;
		abs->personArray[ret].m_Addr = addres;

		std::cout << "成功修改联系人！" << std::endl;
	}
	else
	{
		std::cout << "查无此人！" << std::endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(AddressBooks* abs)
{
	abs->m_Size = 0;
	std::cout << "通讯录已清空！" << std::endl;
	system("pause");
	system("cls");
}

int main()
{
	//创建结构体变量
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
			std::cout << "欢迎下次使用" << std::endl;
			return 0;
			break;
		}
	}
}