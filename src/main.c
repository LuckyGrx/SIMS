#include "../include/system.h"
#include "../include/studentInfo.h"
#include "../include/accountInfo.h"

int main(int argc,char* argv[]) {
	if(argc!=3){
		printf("args error!\n");
		return -1;
	}
	pUserAccountStruct pUser_Account_Head=NULL;
	pStudentInfoStruct pUser_Info_Head = NULL;
	systemInit(argv[1], argv[2], &pUser_Account_Head, &pUser_Info_Head);
systemBegin:
	system("cls");//清屏 
	printSystemTitle();
	char user_name[USER_NAME_LEN];
	char user_pwd[USER_PWD_LEN];
	printLogin(user_name, user_pwd);
	int user_role = isLegalAccount(pUser_Account_Head, user_name, user_pwd);
	if (user_role ==0) {//
userMenuBegin:
		system("cls");//清屏 
		printSystemTitle();
		printStudentMenu();
		rewind(stdin);
		int select;
		printf("请选择要进行的操作:");
		scanf("%d",&select);
		controlByStudent(select, &pUser_Info_Head);
		if (1 == select || 2 ==select) {
			printf("------------:按回车返回上一级");
			rewind(stdin);
			char c;
			c=getchar();
			goto userMenuBegin;
		}else if (3 == select)
			return 0;
		else
			goto userMenuBegin;
	}else if (1 == user_role) {
managerMenuBegin:
		system("cls");//清屏 
		printSystemTitle();
		printManagerMenu();
		rewind(stdin);
		int select;
		printf("请选择要进行的操作:");
		scanf("%d", &select);
		controlByManager(argv[1], argv[2], select, &pUser_Account_Head, &pUser_Info_Head);
		if (select>=1&&select<=8) {
			printf("------------:按回车返回上一级");
			rewind(stdin);
			char c;
			c = getchar();
			goto managerMenuBegin;
		}else if (9 == select)
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
