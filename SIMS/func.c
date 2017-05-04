#include "simsSystem.h"

char* PROJECT_NAME = { "学生信息管理系统" };
char* MANAGER_MENU[9] = { "1. 查询学生信息" ,"5. 查询用户账号","2. 增加学生信息" ,"6. 增加用户账号" ,"3. 更新学生信息" ,"7. 更新用户账号" ,"4. 删除学生信息","8. 删除用户账号",
"9. 退出" };
char* USER_MENU[3] = { "1. 姓名查询" ,"2. 学号查询" ,"3. 退出" };
/*
初始化账户链表和学生信息链表
*/
void systemInit(const char* User_Account_File_Name,const char* User_Info_File_Name, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info) {
	FILE* fp1 = fopen(User_Account_File_Name,"r");
	FILE* fp2 = fopen(User_Info_File_Name, "r");
	if (NULL == fp1 || NULL==fp2) {
		perror("fopen");
		return ;
	}
	USER_ACCOUNT user_account;
	while (fscanf(fp1, "%s %s %d", user_account.userName, user_account.userPwd,&user_account.userRole) != EOF) {
		headInsertOfUserAccount(ppUser_Account, &user_account);
	}
	USER_INFO user_info;
	while (fscanf(fp2, "%d %s %f %f %f", &user_info.user_id, user_info.user_name,&user_info.user_course1_score, &user_info.user_course2_score, &user_info.user_course3_score) != EOF) {
		headInsertOfUserInfo(ppUser_Info, &user_info);
	}
	fclose(fp1);
	fclose(fp2);
}
/*
保存学生信息链表到文件中
*/
void saveUserInfoDataToFile(const char* User_Info_File_Name, pUSER_INFO* ppUser_Info) {
	FILE* fp = fopen(User_Info_File_Name, "w+");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	pUSER_INFO pCurrent = *ppUser_Info;
	int ret;
	while (pCurrent != NULL) {
		ret = fprintf(fp, "\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->user_id, pCurrent->user_name, pCurrent->user_course1_score, pCurrent->user_course2_score, pCurrent->user_course3_score);
		if (ret < 0) {
			perror("fprintf");
			return;
		}
		pCurrent = pCurrent->next;
	}
	fclose(fp);
}
/*
保存用户账号链表到文件中
*/
void saveUserAccountDataToFile(const char* User_Account_File_Name,pUSER_ACCOUNT* ppUser_Account) {
	FILE* fp = fopen(User_Account_File_Name, "w+");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	pUSER_ACCOUNT pCurrent = *ppUser_Account;
	int ret;
	while (pCurrent != NULL) {
		ret = fprintf(fp, "\t\t\t\t%s\t\t%s\t\t%d\n", pCurrent->userName, pCurrent->userPwd, pCurrent->userRole);
		if (ret < 0) {
			perror("fprintf");
			return;
		}
		pCurrent = pCurrent->next;
	}
	fclose(fp);
}
/*
判断登陆是否合法
*/
int isLegalAccount(pUSER_ACCOUNT pUser_Account, char* user_name,char* user_pwd) {
	while (pUser_Account != NULL) {
		if (strcmp(pUser_Account->userName, user_name) == 0 && strcmp(pUser_Account->userPwd, user_pwd) == 0)
			return pUser_Account->userRole;
		pUser_Account = pUser_Account->next;
	}
	return -1;
}
/*
管理员菜单跳转控制
*/
void controlByManager(const char* User_Account_File_Name, const char* User_Info_File_Name, int select, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info ) {
	switch (select) {
	case 1:
		//printf("------------:查询成功，最新学生信息为:\n");
		serachUserInfo(ppUser_Info);
		break;
	case 2:addUserInfo(User_Info_File_Name,ppUser_Info);
		break;
	case 3:updateUserInfo(User_Info_File_Name,ppUser_Info);
		break;
	case 4:deleteUserInfo(User_Info_File_Name,ppUser_Info);
		break;
	case 5:
		//printf("------------:查询成功，最新账户信息为:\n");
		serachUserAccount(ppUser_Account);
		break;
	case 6:addUserAccount(User_Account_File_Name,ppUser_Account);
		break;
	case 7:updateUserAccount(User_Account_File_Name,ppUser_Account);
		break;
	case 8:deleteUserAccount(User_Account_File_Name,ppUser_Account);
		break;
	case 9:
		break;
	default:
		break;
	}
}
/*
学生菜单跳转控制
*/
void controlByUser(int select, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info) {
	switch (select) {
	case 1:serachStudentInfoByName(ppUser_Info); 
		break;
	case 2:serachStudentInfoById(ppUser_Info);
		break;
	case 3:
		break;
	default:
		break;
	}
}
/*
学生  通过id查询学生信息
*/
void serachStudentInfoById(pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printf("请输入学生学号:");
	int user_id;
	scanf("%d", &user_id);
	pUSER_INFO pCurrent = *ppUser_Info;
	while (pCurrent != NULL) {
		if (pCurrent->user_id == user_id) {
			printf("查询成功，该学生信息为:\n");
			printUserInfoTitle();
			printf("%\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->user_id, pCurrent->user_name, pCurrent->user_course1_score, pCurrent->user_course2_score, pCurrent->user_course3_score);
			return ;
		}
		pCurrent = pCurrent->next;
	}
	printf("------------:查询失败，该学生不存在\n");
}
/*
学生 通过Name查询学生信息
*/
void serachStudentInfoByName(pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printf("请输入学生姓名:");
	char user_name[USER_NAME_LEN];
	scanf("%s", user_name);
	pUSER_INFO pCurrent = *ppUser_Info;
	while (pCurrent != NULL) {
		if (strcmp(pCurrent->user_name, user_name)==0) {
			printf("查询成功，该学生信息为:\n");
			printUserInfoTitle();
			printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->user_id, pCurrent->user_name, pCurrent->user_course1_score, pCurrent->user_course2_score, pCurrent->user_course3_score);
			return;
		}
		pCurrent = pCurrent->next;
	}
	printf("------------:查询失败，该学生不存在\n");
}
/*
管理员 增加用户信息
*/
void addUserInfo(const char* User_Info_File_Name, pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printUserInfoTitle();
	printf("\t\t");
	USER_INFO user_info;
	scanf("%d %s %f %f %f", &user_info.user_id, user_info.user_name, &user_info.user_course1_score, &user_info.user_course2_score, &user_info.user_course3_score);
	user_info.next = NULL;
	if (!isListContainUserInfo(ppUser_Info, user_info.user_id)) {
		headInsertOfUserInfo(ppUser_Info, &user_info);
		saveUserInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("新增成功，最新学生信息为:\n");
		serachUserInfo(ppUser_Info);
	}
	else
		printf("------------:新增失败，该学生存在\n");
}
/*
管理员 更新用户信息
*/
void updateUserInfo(const char* User_Info_File_Name,pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printUserInfoTitle();
	printf("\t\t");
	USER_INFO user_info;
	scanf("%d %s %f %f %f", &user_info.user_id, user_info.user_name, &user_info.user_course1_score,&user_info.user_course2_score,&user_info.user_course3_score);
	user_info.next = NULL;
	if (updateLinkedUserInfo(ppUser_Info, &user_info)) {
		saveUserInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("更新成功，最新学生信息为:\n");
		serachUserInfo(ppUser_Info);
	}
	else
		printf("------------:更新失败，该学生不存在\n");
}
/*
管理员 删除用户信息
*/
void deleteUserInfo(const char* User_Info_File_Name, pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printf("请输入要删除的学生学号:");
	int userId;
	scanf("%d", &userId);
	if (deleteLinkedUserInfo(ppUser_Info, userId)) {
		saveUserInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("删除成功，最新学生信息为:\n");
		serachUserInfo(ppUser_Info);
	}else
		printf("------------:删除失败，该学生不存在\n");

}
/*
管理员 查询用户信息
*/
void serachUserInfo(pUSER_INFO* ppUser_Info) {
	PRINT_BEGIN;
	printUserInfoTitle();
	printUserInfo(ppUser_Info);
}
/*
管理员 增加用户账号
*/
void addUserAccount(const char* User_Account_File_Name, pUSER_ACCOUNT* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printf("\t\t\t\t");
	USER_ACCOUNT user_account;
	scanf("%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole);
	user_account.next = NULL;
	if (!isListContainUserAccount(ppUser_Account, user_account.userName)) {
		headInsertOfUserAccount(ppUser_Account, &user_account);
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("新增成功，最新账户信息为:\n");
		serachUserAccount(ppUser_Account);
	}else
		printf("------------:新增失败，该账户存在\n");
}
/*
管理员 更新用户账号
*/
void updateUserAccount(const char* User_Account_File_Name, pUSER_ACCOUNT* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printf("\t\t\t\t");
	USER_ACCOUNT user_account;
	scanf("%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole);
	user_account.next = NULL;
	if (updateLinkedUserAccount(ppUser_Account, &user_account)) {
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("更新成功，最新账户信息为:\n");
		serachUserAccount(ppUser_Account);
	}else
		printf("------------:更新失败，该账户不存在\n");
}
/*
管理员 删除用户账号
*/
void deleteUserAccount(const char* User_Account_File_Name, pUSER_ACCOUNT* ppUser_Account) {
	PRINT_BEGIN;
	printf("请输入要删除的账户姓名:");
	char userName[USER_NAME_LEN];
	scanf("%s", userName);
	if (deleteLinkedUserAccount(ppUser_Account, userName)) {
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("删除成功，最新账户信息为:\n");
		serachUserAccount(ppUser_Account);
	}else
		printf("------------:删除失败，该账户不存在\n");

}
/*
管理员 查询用户账号
*/
void serachUserAccount(pUSER_ACCOUNT* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printUserAccount(ppUser_Account);
}
/*
打印标题
*/
void printTitle() {
	for (int k = 0; k < TITLE_WID * 2 + 3; ++k) {
		if (k == 0 || k == TITLE_WID * 2 + 2) {
			for (int i = 0; i < TITLE_LEN; ++i)
				printf("-");
		}
		else if (k >= 1 && k < 1 + TITLE_WID || k >= TITLE_WID + 2 && k <TITLE_WID * 2 + 2) {
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
打印学生菜单
*/
void printUserMenu() {
	for (int i = 0; i < 3; ++i) {
		printSpace(TITLE_LEN / 2-6);
		printf(USER_MENU[i]);
		printf("\n");
	}
}
/*
打印老师菜单
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
	printSpace(TITLE_LEN / 2-3);
	printf(MANAGER_MENU[8]);
	printf("\n");
}
/*
登陆
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
		if (!(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'||c=='_'))//密码只支持大小写字母、数字和下划线    有bug 
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
打印学生信息标题
*/
void printUserInfoTitle() {
	printf("\t\t学号\t\t姓名\t\t科目一\t\t科目二\t\t科目三\n");
}
/*
打印用户账号标题
*/
void printUserAccountTitle() {
	printf("\t\t\t\t姓名\t\t密码\t\t角色\n");
}