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
			cout << "无法打开登录文件，将自动生成默认用户名及密码";
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
			cout << "检测到账号密码：" << endl;
			cout << "账号：" << name << endl;
			cout << "密码：" << passwd << endl;
			cout << "请确认是否正确，y/n：";
			char flag = 'n';
			flag = getchar();
			while (char once_use_flag = getchar() != '\n');
			if (flag == 'y')
			{
				system("cls");
				cout << "正在尝试登录中......" << endl;
				Sleep(500);
				//httpserver

			}
			else if (flag == 'n')
			{
				for (;;)
				{
					system("cls");
					cout << "请输入账号（手机号）：";
					cin >> name;
					if (name.size() == 11)
						break;
					else
					{
						cout << "手机号应为11位，请重新输入！";
						Sleep(1000);
					}
				}
				cout << "请输入密码：";
				cin >> passwd;
				cout << "好的，正在保存新的账号密码......";
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
				cout << "\n保存成功！重新加载登录过程......";
				Sleep(1000);
			}
			else
			{
				cout << "不合法的输入，请重新输入！";
				Sleep(1000);
			}
		}
	}
private:
	string name, passwd;
};
#endif // !ACCOUNT_SERVER

