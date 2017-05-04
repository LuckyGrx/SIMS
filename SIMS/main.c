#include "simsSystem.h"

int main(int argc,char* argv[]) {
	pUSER_ACCOUNT pUser_Account_Head=NULL;
	pUSER_INFO pUser_Info_Head = NULL;
	systemInit(argv[1], argv[2], &pUser_Account_Head, &pUser_Info_Head);
systemBegin:
	system("cls");//清屏 
	printTitle();
	char user_name[USER_NAME_LEN];
	char user_pwd[USER_PWD_LEN];
	printLogin(user_name, user_pwd);
	int user_role = isLegalAccount(pUser_Account_Head, user_name, user_pwd);
	if (user_role ==0) {//
userMenuBegin:
		system("cls");//清屏 
		printTitle();
		printUserMenu();
		rewind(stdin);
		int select;
		printf("请选择要进行的操作:");
		scanf("%d",&select);
		controlByUser(select, &pUser_Account_Head, &pUser_Info_Head);
		if (select == 1||select==2) {
			printf("------------:按回车返回上一级");
			rewind(stdin);
			char c;
			c=getchar();
			goto userMenuBegin;
		}else if (select == 3)
			return 0;
		else
			goto userMenuBegin;
	}else if (user_role == 1) {
managerMenuBegin:
		system("cls");//清屏 
		printTitle();
		printManagerMenu();
		rewind(stdin);
		int select;
		printf("请选择要进行的操作:");
		scanf("%d", &select);
		//printf("%s\n", MANAGER_MENU[select - 1]);
		//rewind(stdin);
		//char c = getchar();
		controlByManager(argv[1], argv[2], select, &pUser_Account_Head, &pUser_Info_Head);
		if (select>=1&&select<=8) {
			printf("------------:按回车返回上一级");
			rewind(stdin);
			char c;
			c = getchar();
			goto managerMenuBegin;
		}else if (select == 9)
			return 0;
		else
			goto managerMenuBegin;
	}else {
		printf("------------:用户名或密码错误\n");
		printf("------------:按回车键返回上一级，其他键退出");
		rewind(stdin);
		char c;
		c = getchar();
		if (c == '\n')
			goto systemBegin;
		else
			return 0;
	}
	return 0;
}