#ifndef LINKED_LIST
#define LINKED_LIST
#include "dataStruct.h"
void headInsertOfUserAccount(pUserAccountStruct*, pUserAccountStruct);//用户账号链表头插法
void printUserAccount(pUserAccountStruct*);//打印用户账号
int updateListUserAccount(pUserAccountStruct*, pUserAccountStruct);//更新用户账号
int deleteListUserAccount(pUserAccountStruct*, char*);//删除用户账号
int isListContainUserAccount(pUserAccountStruct*, char*);//链表是否包含该账号 包含返回1，不包含返回0


void headInsertOfStudentInfo(pStudentInfoStruct*, pStudentInfoStruct);//用户信息链表头插法
void printStudentInfo(pStudentInfoStruct*);//打印用户信息
int updateListStudentInfo(pStudentInfoStruct*, pStudentInfoStruct);//更新用户信息
int deleteListStudentInfo(pStudentInfoStruct*, int);//删除用户信息
int isListContainStudentInfo(pStudentInfoStruct*, int);//链表是否包含该用户 包含返回1，不包含返回0
#endif