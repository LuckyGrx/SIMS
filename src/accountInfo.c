#include "../include/system.h"
#include "../include/accountInfo.h"
#include "../include/linkedList.h"

/*
管理员 增加用户账号
*/
void addUserAccount(const char* User_Account_File_Name, pUserAccountStruct* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printf("\t\t\t\t");
	userAccountStruct user_account;
	scanf("%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole);
	user_account.next = NULL;
	if (!isListContainUserAccount(ppUser_Account, user_account.userName)) {
		headInsertOfUserAccount(ppUser_Account, &user_account);
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("新增成功，最新账户信息为:\n");
		serachUserAccount(ppUser_Account);
	}
	else
		printf("------------:新增失败，该账户存在\n");
}
/*
管理员 更新用户账号
*/
void updateUserAccount(const char* User_Account_File_Name, pUserAccountStruct* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printf("\t\t\t\t");
	userAccountStruct user_account;
	scanf("%s %s %d", user_account.userName, user_account.userPwd, &user_account.userRole);
	user_account.next = NULL;
	if (updateListUserAccount(ppUser_Account, &user_account)) {
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("更新成功，最新账户信息为:\n");
		serachUserAccount(ppUser_Account);
	}
	else
		printf("------------:更新失败，该账户不存在\n");
}
/*
管理员 删除用户账号
*/
void deleteUserAccount(const char* User_Account_File_Name, pUserAccountStruct* ppUser_Account) {
	PRINT_BEGIN;
	printf("请输入要删除的账户姓名:");
	char userName[USER_NAME_LEN];
	scanf("%s", userName);
	if (deleteListUserAccount(ppUser_Account, userName)) {
		saveUserAccountDataToFile(User_Account_File_Name, ppUser_Account);
		printf("删除成功，最新账户信息为:\n");
		serachUserAccount(ppUser_Account);
	}
	else
		printf("------------:删除失败，该账户不存在\n");

}
/*
管理员 查询用户账号
*/
void serachUserAccount(pUserAccountStruct* ppUser_Account) {
	PRINT_BEGIN;
	printUserAccountTitle();
	printUserAccount(ppUser_Account);
}

/*
打印用户账号标题
*/
void printUserAccountTitle() {
	printf("\t\t\t\t姓名\t\t密码\t\t角色\n");
}

/*
保存用户账号链表到文件中
*/
void saveUserAccountDataToFile(const char* User_Account_File_Name, pUserAccountStruct* ppUser_Account) {
	FILE* fp = fopen(User_Account_File_Name, "w+");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	pUserAccountStruct pCurrent = *ppUser_Account;
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
