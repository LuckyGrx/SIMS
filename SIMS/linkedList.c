#include"simsSystem.h"
/*
用户账号链表头插法
*/
void headInsertOfUserAccount(pUSER_ACCOUNT* ppHead, pUSER_ACCOUNT user_account) {
	pUSER_ACCOUNT pNew = (pUSER_ACCOUNT)malloc(sizeof(USER_ACCOUNT));
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
void printUserAccount(pUSER_ACCOUNT* ppHead) {
	pUSER_ACCOUNT pCurrent = *ppHead;
	while (pCurrent != NULL) {
		printf("\t\t\t\t%s\t\t%s\t\t%s\n", pCurrent->userName, pCurrent->userPwd, pCurrent->userRole == 0 ? "普通用户" : "管理员");
		pCurrent = pCurrent->next;
	}
}
/*
更新用户账号
更新成功返回1，更新失败返回0
*/
int updateLinkedUserAccount(pUSER_ACCOUNT* ppHead,pUSER_ACCOUNT pUserAccount) {
	pUSER_ACCOUNT pCurrent = *ppHead;
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
int deleteLinkedUserAccount(pUSER_ACCOUNT* ppHead, char* userName) {
	pUSER_ACCOUNT pCurrent = *ppHead;
	pUSER_ACCOUNT pPrevious = *ppHead;
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
链表是否包含该账号 包含1，不包含返回0
*/
int isListContainUserAccount(pUSER_ACCOUNT* ppHead, char* userName) {
	pUSER_ACCOUNT pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (strcmp(userName, pCurrent->userName) == 0)
			return 1;
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
用户信息链表头插法
*/
void headInsertOfUserInfo(pUSER_INFO* ppHead, pUSER_INFO user_info) {
	pUSER_INFO pNew = (pUSER_INFO)malloc(sizeof(USER_INFO));
	pNew->user_id = user_info->user_id;
	strcpy(pNew->user_name, user_info->user_name);
	pNew->user_course1_score = user_info->user_course1_score;
	pNew->user_course2_score = user_info->user_course2_score;
	pNew->user_course3_score = user_info->user_course3_score;
	pNew->next = NULL;
	if (NULL == *ppHead)
		*ppHead = pNew;
	else {
		pNew->next = *ppHead;
		*ppHead = pNew;
	}
}
/*
打印用户信息
*/
void printUserInfo(pUSER_INFO* ppHead) {
	pUSER_INFO pCurrent = *ppHead;
	while (pCurrent != NULL) {
		printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->user_id, pCurrent->user_name, pCurrent->user_course1_score, pCurrent->user_course2_score, pCurrent->user_course3_score);
		pCurrent = pCurrent->next;
	}
}
/*
更新用户信息
存在该更新用户返回1，不存在返回0
*/
int updateLinkedUserInfo(pUSER_INFO* ppHead, pUSER_INFO pUserInfo) {
	pUSER_INFO pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (pCurrent->user_id == pUserInfo->user_id) {
			strcpy(pCurrent->user_name, pUserInfo->user_name);
			pCurrent->user_course1_score = pUserInfo->user_course1_score;
			pCurrent->user_course2_score = pUserInfo->user_course2_score;
			pCurrent->user_course3_score = pUserInfo->user_course3_score;
			return 1;
		}
		pCurrent = pCurrent->next;
	}
	return 0;
}
/*
删除用户信息  
删除成功返回1，删除失败返回0
*/
int deleteLinkedUserInfo(pUSER_INFO* ppHead,int userId) {
	pUSER_INFO pCurrent = *ppHead;
	pUSER_INFO pPrevious = *ppHead;
	if (NULL == pCurrent)
		return 0;
	else if (userId ==(*ppHead)->user_id) {
		*ppHead = pCurrent->next;
		free(pCurrent);
		pCurrent = NULL; 
		return 1;
	}
	else {
		while (pCurrent != NULL)//插到中间
		{
			if (userId == pCurrent->user_id)
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
链表是否包含该用户 包含返回1，不包含返回0
*/
int isListContainUserInfo(pUSER_INFO* ppHead, int userId) {
	pUSER_INFO pCurrent = *ppHead;
	while (pCurrent != NULL) {
		if (userId==pCurrent->user_id)
			return 1;
		pCurrent = pCurrent->next;
	}
	return 0;
}