#ifndef __CONST_INFO_H__
#define __CONST_INFO_H__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>
#include<ctype.h>
#define TITLE_LEN 100
#define TITLE_WID 2
#define USER_INFO_TITLE_BEGIN TITLE_LEN / 8
#define USER_ACCOUNT_TITLE_BEGIN TITLE_LEN / 3
#define USER_NAME_LEN 20
#define USER_PWD_LEN 20
//

const char* const PROJECT_NAME = { "学生信息管理系统" };
const char* const MANAGER_MENU[9] = { "1. 查询学生信息" ,"5. 查询用户账号","2. 增加学生信息" ,"6. 增加用户账号" ,"3. 更新学生信息" ,"7. 更新用户账号" ,"4. 删除学生信息","8. 删除用户账号",
"9. 退出" };
const char* const USER_MENU[3] = { "1. 姓名查询" ,"2. 学号查询" ,"3. 退出" };

#endif // CONST_INFO

