#include "httplib.h"
#include "account.h"
#include <Windows.h>
#include <iostream>

using namespace std;
int main() 
{
	Account account;
	cout << "��ӭʹ�����շ��۽ű���¼ϵͳ��\n��enter���Լ�����";
	while (char once_use_flag = getchar() != '\n');
	account.login();
	return 0;
}