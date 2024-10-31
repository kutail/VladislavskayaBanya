#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>

//������� ������
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };
//----------------------


//�����
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];

//----------------------
//�������
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void ShowStorage();

template<typename ArrType>
void SetArr(ArrType arr, ArrType dynamicArr, int size);

template<typename ArrType>
void printArr(ArrType dynamicArr, int size);




#if defined(max)
#undef max
#endif


int main()
{
	Start();
	delete[]loginArr;
	delete[]passwordArr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameArr;
	return 0;
}

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);



	std::cout << "\n\n\t\tAVI\n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (isAdmin == true)
		{
			while (isAdmin == true)
			{
				std::string choose;
				do
				{
					std::cout << "������������ ������� ����� ��� ������� �����?" << "\n1 - ������� �����\n2 - ������� �����\n\n����";
					std::getline(std::cin, choose, '\n');
				} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

				if (choose == "1")
				{
					CreateStaticStorage();
					ShowStorage();
				}
				else
				{
					//�������� ������������� �������
				}
				ShopAdminMenu();
			}
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}
}

bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "������ �����: ";
		std::getline(std::cin, login, '\n');
		std::cout << "������� ������: ";
		std::getline(std::cin, pass, '\n');

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passwordArr[0])
			{
				std::cout << "����� ���������� " << loginArr[0] << '\n';
				isAdmin = true;
				return true;
			}

			else if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << "����� ���������� " << loginArr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "������� ������ ����� ��� ������!\n\n";
	}
	return true;
}

void ShopUserMenu()
{
	std::cout << "User";

}

void ShopAdminMenu()
{
	std::string choose{};
	while (true)
	{
		do
		{
			std::cout << "1. ������ �������\n";
			std::cout << "2. �������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �����\n";
			std::cout << "5. �������� ����\n";
			std::cout << "6. �������� �����\n";
			std::cout << "7. �������� ��������\n";
			std::cout << "8. ����� � �������\n\n";
			std::cout << "0. ������� �����\n\n\n";
			// ���������� ����� 
			std::cout << "����: ";
			std::getline(std::cin, choose, '\n');
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); //���������� asci ������� �� 0 �� 8 ���

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			void ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "MainMenuErorr";
		}
	}
}

void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };

	std::string nameStaticArr[staticSize]
	{
		"���� 1,5�","��������������� �������","����������� ����","��������","������������� ����","���� ������ ���������������","�������� ���������",
		"����� �������","����� ������","������ ���������"
	};

	int countStaticArr[staticSize]{ 150, 25, 40, 75, 300, 200, 150, 50, 50, 150 };

	double priceStaticArr[staticSize]{ 1200.0, 1500.0, 2699.0, 2299.0, 150.0, 120.0, 400.0, 259.0, 269.0, 700.0 };

	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);
}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template<typename ArrType>
void printArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}

void ShowStorage()
{
	std::cout << "ID\t��������\t\t\t����\t����������\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << nameArr[i] << "\t\t\t" << priceArr[i] << "\t" << countArr[i] << "\n";
	}
}