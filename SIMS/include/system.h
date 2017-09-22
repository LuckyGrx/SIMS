#ifndef SYSTEM
#define SYSTEM

#include "dataStruct.h"
#define PRINT_BEGIN {system("cls");printSystemTitle();}

void systemInit(const char*, const char*, pUserAccountStruct*, pStudentInfoStruct*);//初始化用户信息链表和用户账号链表

int isLegalAccount(pUserAccountStruct, char*, char*);//判断登陆是否合法
void printSystemTitle();//打印标题
void printLogin(char*, char*);//登陆

void controlByManager(const char*, const char*, int, pUserAccountStruct* ppUser_Account, pStudentInfoStruct* ppUser_Info);//管理员菜单跳转控制
void controlByStudent(int, pStudentInfoStruct* ppUser_Info);//学生菜单跳转控制

void printSpace(int);//打印空格
void printStudentMenu();//打印学生菜单
void printManagerMenu();//打印老师菜单
#endif