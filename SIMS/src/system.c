#include "../include/system.h"

/*
初始化账户链表和学生信息链表
*/
void systemInit(const char* User_Account_File_Name, const char* User_Info_File_Name, pUserAccountStruct* ppUser_Account, pStudentInfoStruct* ppUser_Info) {
	FILE* fp1 = fopen(User_Account_File_Name, "r");
	FILE* fp2 = fopen(User_Info_File_Name, "r");
	if (NULL == fp1 || NULL == fp2) {
		perror("fopen");
		return;
	}
	userAccountStruct user_account;
	while (fscanf(fp1, "%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole) != EOF) {
		headInsertOfUserAccount(ppUser_Account, &user_account);
	}
	studentInfoStruct user_info;
	while (fscanf(fp2, "%d %s %f %f %f", &user_info.userId, user_info.userName, &user_info.userCourse1Score, &user_info.userCourse2Score, &user_info.userCourse3Score) != EOF) {
		headInsertOfStudentInfo(ppUser_Info, &user_info);
	}
	fclose(fp1);
	fclose(fp2);
}
/*
判断登陆是否合法
*/
int isLegalAccount(pUserAccountStruct pUser_Account, char* user_name, char* user_pwd) {
	while (pUser_Account != NULL) {
		if (strcmp(pUser_Account->userName, user_name) == 0 && strcmp(pUser_Account->userPwd, user_pwd) == 0)
			return pUser_Account->userRole;
		pUser_Account = pUser_Account->next;
	}
	return -1;
}
/*
打印系统标题
*/
void printSystemTitle() {
	for (int k = 0; k < TITLE_WID * 2 + 3; ++k) {
		if (k == 0 || k == TITLE_WID * 2 + 2) {
			for (int i = 0; i < TITLE_LEN; ++i)
				printf("-");
		}
		else if ((k >= 1 && k < 1 + TITLE_WID) || (k >= TITLE_WID + 2 && k <TITLE_WID * 2 + 2)) {
			for (int j = 0; j < TITLE_LEN; ++j) {
				if (j == 0 || j == 1 || j == 2 || j == TITLE_LEN - 1 || j == TITLE_LEN - 2 || j == TITLE_LEN - 3)
					printf("-");
				else
					printf(" ");
			}
		}
		else {
			for (int j = 0; j < TITLE_LEN; ++j) {
				if (j == 0 || j == 1 || j == 2 || j == TITLE_LEN - 1 || j == TITLE_LEN - 2 || j == TITLE_LEN - 3)
					printf("-");
				else if (j<TITLE_LEN / 2 - 7 || j>TITLE_LEN / 2 + 8)
					printf(" ");
				else
					printf("%c", PROJECT_NAME[j - (TITLE_LEN / 2 - 7)]);
			}
		}
		printf("\n");
	}
}
/*
打印登陆界面
*/
void printLogin(char* user_name, char* user_pwd) {
	printSpace(TITLE_LEN / 2 - 4);
	printf("用户名:");
	scanf("%s", user_name);
	rewind(stdin);
	printSpace(TITLE_LEN / 2 - 6);
	printf("用户密码:");
	char c;
	int index = 0;
	while ((c = getch()) != '\r') {
		if (c == '\b')
		{
			if (index > 0) {//最多只能删到没有字符  
				putchar('\b');
				putchar(' ');
				putchar('\b');
				index--;
			}
		}
		if (!((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z') || (c >= '0'&&c <= '9') || c == '_'))//密码只支持大小写字母、数字和下划线    有bug 
			continue;
		putchar('*');
		user_pwd[index++] = c;
	}
	user_pwd[index] = '\0';
	printf("\n");
}
/*
打印空格
*/
void printSpace(int length) {
	for (int j = 0; j < length; ++j)
		printf(" ");
}

/*
打印学生菜单
*/
void printStudentMenu() {
	for (int i = 0; i < 3; ++i) {
		printSpace(TITLE_LEN / 2 - 6);
		printf(USER_MENU[i]);
		printf("\n");
	}
}
/*
打印管理者菜单
*/
void printManagerMenu() {
	for (int i = 0; i < 8;) {
		printSpace(TITLE_LEN / 4);
		printf(MANAGER_MENU[i]);
		printSpace(TITLE_LEN / 4);
		++i;
		printf(MANAGER_MENU[i]);
		printf("\n");
		++i;
	}
	printSpace(TITLE_LEN / 2 - 3);
	printf(MANAGER_MENU[8]);
	printf("\n");
}

/*
管理员菜单跳转控制
*/
void controlByManager(const char* User_Account_File_Name, const char* User_Info_File_Name, int select, pUserAccountStruct* ppUser_Account, pStudentInfoStruct* ppUser_Info) {
	switch (select) {
	case 1:
		//printf("------------:查询成功，最新学生信息为:\n");
		serachStudentInfo(ppUser_Info);
		break;
	case 2:addStudentInfo(User_Info_File_Name, ppUser_Info);
		break;
	case 3:updateStudentInfo(User_Info_File_Name, ppUser_Info);
		break;
	case 4:deleteStudentInfo(User_Info_File_Name, ppUser_Info);
		break;
	case 5:
		//printf("------------:查询成功，最新账户信息为:\n");
		serachUserAccount(ppUser_Account);
		break;
	case 6:addUserAccount(User_Account_File_Name, ppUser_Account);
		break;
	case 7:updateUserAccount(User_Account_File_Name, ppUser_Account);
		break;
	case 8:deleteUserAccount(User_Account_File_Name, ppUser_Account);
		break;
	default:
		break;
	}
}

/*
学生菜单跳转控制
*/
void controlByStudent(int select, pStudentInfoStruct* ppUser_Info) {
	switch (select) {
	case 1:serachStudentInfoByName(ppUser_Info);
		break;
	case 2:serachStudentInfoById(ppUser_Info);
		break;
	default:
		break;
	}
}
