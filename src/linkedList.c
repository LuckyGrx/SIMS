#include "../include/linkedList.h"
/*
用户账号链表头插法
*/
void headInsertOfUserAccount(pUserAccountStruct* ppHead, pUserAccountStruct user_account) {
	pUserAccountStruct pNew = (pUserAccountStruct)malloc(sizeof(userAccountStruct));
	strcpy(pNew->userName ,user_account->userName);
	strcpy(pNew->userPwd ,user_account->userPwd);
	pNew->userRole = user_account->userRole;
	pNew->next = NULL;
	if (NULL == *ppHead)
		*ppHead = pNew;
	else {
		pNew->next = *ppHead;
		*ppHead = pNew;
	}
}
/*
打印用户账号
*/
void printUserAccount(pUserAccountStruct* ppHead) {
	pUserAccountStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		printf("\t\t\t\t%s\t\t%s\t\t%s\n", pCurrent->userName, pCurrent->userPwd, pCurrent->userRole == 0 ? "普通用户" : "管理员");
		pCurrent = pCurrent->next;
	}
}
/*
更新用户账号
更新成功返回1，更新失败返回0
*/
int updateListUserAccount(pUserAccountStruct* ppHead,pUserAccountStruct pUserAccount) {
	pUserAccountStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (strcmp(pCurrent->userName,pUserAccount->userName)==0) {
			strcpy(pCurrent->userPwd, pUserAccount->userPwd);
			pCurrent->userRole = pUserAccount->userRole;
			return 1;
		}
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
删除用户账号
删除成功返回1，删除失败返回0
*/
int deleteListUserAccount(pUserAccountStruct* ppHead, char* userName) {
	pUserAccountStruct pCurrent = *ppHead;
	pUserAccountStruct pPrevious = *ppHead;
	if (NULL == pCurrent)
		return 0;
	else if (strcmp(userName, (*ppHead)->userName) == 0) {
		*ppHead = pCurrent->next;
		free(pCurrent);//释放对应节点内存
		pCurrent = NULL;  //把free以后没有置为NULL的指针称为野指针
		return 1;
	}
	else {
		while (pCurrent != NULL)//插到中间
		{
			if (strcmp(userName, pCurrent->userName) == 0)
			{
				pPrevious->next = pCurrent->next;
				return 1;
			}
			pPrevious = pCurrent;//保存原有位置
			pCurrent = pCurrent->next;//指向下一个节点
		}
		free(pCurrent);//释放对应节点内存
		pCurrent = NULL;  //把free以后没有置为NULL的指针称为野指针
	}
	return 0;
}
/*
链表是否包含该账号 
包含1，不包含返回0
*/
int isListContainUserAccount(pUserAccountStruct* ppHead, char* userName) {
	pUserAccountStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (strcmp(userName, pCurrent->userName) == 0)
			return 1;
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
学生信息链表头插法
*/
void headInsertOfStudentInfo(pStudentInfoStruct* ppHead, pStudentInfoStruct user_info) {
	pStudentInfoStruct pNew = (pStudentInfoStruct)malloc(sizeof(studentInfoStruct));
	pNew->userId = user_info->userId;
	strcpy(pNew->userName, user_info->userName);
	pNew->userCourse1Score = user_info->userCourse1Score;
	pNew->userCourse2Score = user_info->userCourse2Score;
	pNew->userCourse3Score = user_info->userCourse3Score;
	pNew->next = NULL;
	if (NULL == *ppHead)
		*ppHead = pNew;
	else {
		pNew->next = *ppHead;
		*ppHead = pNew;
	}
}
/*
打印学生信息
*/
void printStudentInfo(pStudentInfoStruct* ppHead) {
	pStudentInfoStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->userId, pCurrent->userName, pCurrent->userCourse1Score, pCurrent->userCourse2Score, pCurrent->userCourse3Score);
		pCurrent = pCurrent->next;
	}
}
/*
更新学生信息
存在该更新用户返回1，不存在返回0
*/
int updateListStudentInfo(pStudentInfoStruct* ppHead, pStudentInfoStruct pUserInfo) {
	pStudentInfoStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (pCurrent->userId == pUserInfo->userId) {
			strcpy(pCurrent->userName, pUserInfo->userName);
			pCurrent->userCourse1Score = pUserInfo->userCourse1Score;
			pCurrent->userCourse2Score = pUserInfo->userCourse2Score;
			pCurrent->userCourse3Score = pUserInfo->userCourse3Score;
			return 1;
		}
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
删除学生信息  
删除成功返回1，删除失败返回0
*/
int deleteListStudentInfo(pStudentInfoStruct* ppHead,int userId) {
	pStudentInfoStruct pCurrent = *ppHead;
	pStudentInfoStruct pPrevious = *ppHead;
	if (NULL == pCurrent)
		return 0;
	else if (userId ==(*ppHead)->userId) {
		*ppHead = pCurrent->next;
		free(pCurrent);
		pCurrent = NULL; 
		return 1;
	}
	else {
		while (pCurrent != NULL)//插到中间
		{
			if (userId == pCurrent->userId)
			{
				pPrevious->next = pCurrent->next;
				return 1;
			}
			pPrevious = pCurrent;//保存原有位置
			pCurrent = pCurrent->next;//指向下一个节点
		}
		free(pCurrent);
		pCurrent = NULL;  
	}
	return 0;
}
/*
链表是否包含该学生 
包含返回1，不包含返回0
*/
int isListContainStudentInfo(pStudentInfoStruct* ppHead, int userId) {
	pStudentInfoStruct pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (userId==pCurrent->userId)
			return 1;
		pCurrent = pCurrent->next;
	}
	return 0;
}
