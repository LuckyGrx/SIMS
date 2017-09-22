#ifndef __ACCOUNT_INFO_H__
#define __ACCOUNT_INFO_H__
#include "dataStruct.h"

void addUserAccount(const char*, pUserAccountStruct*);//管理员 增加用户账号
void updateUserAccount(const char*, pUserAccountStruct*);//管理员 更新用户账号
void deleteUserAccount(const char*, pUserAccountStruct*);//管理员 删除用户账号
void serachUserAccount(pUserAccountStruct*);//管理员 查询用户账号

void saveUserAccountDataToFile(const char*, pUserAccountStruct*);//保存用户账号链表到文件中
void printUserAccountTitle();//打印用户账号标题

#endif // ACCOUNT_INFO

