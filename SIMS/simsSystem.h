#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define TITLE_LEN 100
#define TITLE_WID 2
#define USER_INFO_TITLE_BEGIN TITLE_LEN / 8
#define USER_ACCOUNT_TITLE_BEGIN TITLE_LEN / 3
#define USER_NAME_LEN 20
#define USER_PWD_LEN 20
#define PRINT_BEGIN {system("cls");printTitle();}

typedef struct user_account_tag {//用户账号结构体
	char userName[USER_NAME_LEN];
	char userPwd[USER_PWD_LEN];
	int userRole;
	struct user_account_tag* next;
}USER_ACCOUNT, *pUSER_ACCOUNT;

typedef struct user_info_tag {//用户信息结构体
	int user_id;
	char user_name[USER_NAME_LEN];
	float user_course1_score;
	float user_course2_score;
	float user_course3_score;
	struct user_info_tag* next;
}USER_INFO, *pUSER_INFO;

char* PROJECT_NAME;
char* MANAGER_MENU[9];
char* USER_MENU[3];

void headInsertOfUserAccount(pUSER_ACCOUNT*, pUSER_ACCOUNT);//用户账号链表头插法
void printUserAccount(pUSER_ACCOUNT*);//打印用户账号
int updateLinkedUserAccount(pUSER_ACCOUNT*, pUSER_ACCOUNT);//更新用户账号
int deleteLinkedUserAccount(pUSER_ACCOUNT*, char*);//删除用户账号
int isListContainUserAccount(pUSER_ACCOUNT*, char*);//链表是否包含该账号 包含返回1，不包含返回0


void headInsertOfUserInfo(pUSER_INFO*, pUSER_INFO);//用户信息链表头插法
void printUserInfo(pUSER_INFO*);//打印用户信息
int updateLinkedUserInfo(pUSER_INFO*, pUSER_INFO);//更新用户信息
int deleteLinkedUserInfo(pUSER_INFO*, int);//删除用户信息
int isListContainUserInfo(pUSER_INFO*, int);//链表是否包含该用户 包含返回1，不包含返回0

void systemInit(const char*, const char*, pUSER_ACCOUNT*, pUSER_INFO*);//初始化用户信息链表和用户账号链表
void saveUserInfoDataToFile(const char*, pUSER_INFO*);//保存学生信息链表到文件中
void saveUserAccountDataToFile(const char*, pUSER_ACCOUNT*);//保存用户账号链表到文件中
void printTitle();//打印标题
void printUserMenu();//打印学生菜单
void printManagerMenu();//打印老师菜单
void printLogin(char*, char*);//登陆

int isLegalAccount(pUSER_ACCOUNT, char*, char*);//判断登陆是否合法
void controlByManager(const char*, const char*, int, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info);//管理员菜单跳转控制
void controlByUser(int, pUSER_ACCOUNT* ppUser_Account, pUSER_INFO* ppUser_Info);//学生菜单跳转控制
void printUserInfoTitle();//打印学生信息标题
void printUserAccountTitle();//打印用户账号标题
void printSpace(int);//打印空格

void serachStudentInfoById(pUSER_INFO*);//学生  通过id查询学生信息
void serachStudentInfoByName(pUSER_INFO*);//学生  通过id查询学生信息

void addUserInfo(const char*, pUSER_INFO*);//管理员 增加学生信息
void updateUserInfo(const char*, pUSER_INFO*);//管理员 更新学生信息
void deleteUserInfo(const char*, pUSER_INFO*);//管理员 删除学生信息
void serachUserInfo(pUSER_INFO*);//管理员 查询学生信息

void addUserAccount(const char*, pUSER_ACCOUNT*);//管理员 增加用户账号
void updateUserAccount(const char*, pUSER_ACCOUNT*);//管理员 更新用户账号
void deleteUserAccount(const char*, pUSER_ACCOUNT*);//管理员 删除用户账号
void serachUserAccount(pUSER_ACCOUNT*);//管理员 查询用户账号