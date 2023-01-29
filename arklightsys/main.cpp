#include "httplib.h"
#include "account.h"
#include <Windows.h>
#include <iostream>

using namespace std;
int main() 
{
	Account account;
	cout << "欢迎使用明日方舟脚本登录系统！\n按enter键以继续！";
	while (char once_use_flag = getchar() != '\n');
	account.login();
	return 0;
}