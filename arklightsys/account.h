#pragma once
#ifndef ACCOUNT_SERVER
#define ACCOUNT_SERVER
#include "httplib.h"
#include "json.hpp"
#include <iostream>
#include <Windows.h>
using namespace std;
using json = nlohmann::json;
class Account
{
public:
	bool login()
	{
		ifstream fin;
		ofstream fout;
		fin.open("./login", ios::in);
		if (!fin.is_open())
		{
			cout << "�޷��򿪵�¼�ļ������Զ�����Ĭ���û���������";
			Sleep(2000);
			fout.open("./login", ios::out);
			fout << "1000000000000" << endl << "12345678";
			fout.close();
			fout.clear();
		}
		fin.close();
		fin.clear();
		fin.open("./login", ios::in);
		fin >> name >> passwd;
		fin.close();
		fin.clear();
		while (1)
		{
			system("cls");
			cout << "��⵽�˺����룺" << endl;
			cout << "�˺ţ�" << name << endl;
			cout << "���룺" << passwd << endl;
			cout << "��ȷ���Ƿ���ȷ��y/n��";
			char flag = 'n';
			flag = getchar();
			while (char once_use_flag = getchar() != '\n');
			if (flag == 'y')
			{
				system("cls");
				cout << "���ڳ��Ե�¼��......" << endl;
				Sleep(500);
				//httpserver

			}
			else if (flag == 'n')
			{
				for (;;)
				{
					system("cls");
					cout << "�������˺ţ��ֻ��ţ���";
					cin >> name;
					if (name.size() == 11)
						break;
					else
					{
						cout << "�ֻ���ӦΪ11λ�����������룡";
						Sleep(1000);
					}
				}
				cout << "���������룺";
				cin >> passwd;
				cout << "�õģ����ڱ����µ��˺�����......";
				Sleep(1000);
				fout.open("./login", ios::out);
				if (!fout.is_open())
				{
					cout << "Oops, something went wrong! Please contact the developer.";
					exit(1);
				}
				fout << name << endl << passwd;
				fout.close();
				fout.clear();
				cout << "\n����ɹ������¼��ص�¼����......";
				Sleep(1000);
			}
			else
			{
				cout << "���Ϸ������룬���������룡";
				Sleep(1000);
			}
		}
	}
private:
	string name, passwd;
};
#endif // !ACCOUNT_SERVER

