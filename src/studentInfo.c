#include "../include/system.h"
#include "../include/studentInfo.h"
#include "../include/linkedList.h"

/*
 *学生  通过id查询学生信息
 */
void serachStudentInfoById(pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printf("请输入学生学号:");
	int user_id;
	scanf("%d", &user_id);
	pStudentInfoStruct pCurrent = *ppUser_Info;
	while (pCurrent != NULL) {
		if (pCurrent->userId == user_id) {
			printf("查询成功，该学生信息为:\n");
			printStudentInfoTitle();
			printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->userId, pCurrent->userName, pCurrent->userCourse1Score, pCurrent->userCourse2Score, pCurrent->userCourse3Score);
			return;
		}
		pCurrent = pCurrent->next;
	}
	printf("------------:查询失败，该学生不存在\n");
}

/*
 *学生 通过Name查询学生信息
 */
void serachStudentInfoByName(pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printf("请输入学生姓名:");
	char user_name[USER_NAME_LEN];
	scanf("%s", user_name);
	pStudentInfoStruct pCurrent = *ppUser_Info;
	while (pCurrent != NULL) {
		if (strcmp(pCurrent->userName, user_name) == 0) {
			printf("查询成功，该学生信息为:\n");
			printStudentInfoTitle();
			printf("\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->userId, pCurrent->userName, pCurrent->userCourse1Score, pCurrent->userCourse2Score, pCurrent->userCourse3Score);
			return;
		}
		pCurrent = pCurrent->next;
	}
	printf("------------:查询失败，该学生不存在\n");
}

/*
 *管理员 增加学生信息
 */
void addStudentInfo(const char* User_Info_File_Name, pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printStudentInfoTitle();
	printf("\t\t");
	studentInfoStruct user_info;
	scanf("%d %s %f %f %f", &user_info.userId, user_info.userName, &user_info.userCourse1Score, &user_info.userCourse2Score, &user_info.userCourse3Score);
	user_info.next = NULL;
	if (!isListContainStudentInfo(ppUser_Info, user_info.userId)) {
		headInsertOfStudentInfo(ppUser_Info, &user_info);
		saveStudentInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("新增成功，最新学生信息为:\n");
		serachStudentInfo(ppUser_Info);
	}
	else
		printf("------------:新增失败，该学生存在\n");
}

/*
 *管理员 更新学生信息
 */
void updateStudentInfo(const char* User_Info_File_Name, pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printStudentInfoTitle();
	printf("\t\t");
	studentInfoStruct user_info;
	scanf("%d %s %f %f %f", &user_info.userId, user_info.userName, &user_info.userCourse1Score, &user_info.userCourse2Score, &user_info.userCourse3Score);
	user_info.next = NULL;
	if (updateListStudentInfo(ppUser_Info, &user_info)) {
		saveStudentInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("更新成功，最新学生信息为:\n");
		serachStudentInfo(ppUser_Info);
	}
	else
		printf("------------:更新失败，该学生不存在\n");
}

/*
 *管理员 删除学生信息
 */
void deleteStudentInfo(const char* User_Info_File_Name, pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printf("请输入要删除的学生学号:");
	int userId;
	scanf("%d", &userId);
	if (deleteListStudentInfo(ppUser_Info, userId)) {
		saveStudentInfoDataToFile(User_Info_File_Name, ppUser_Info);
		printf("删除成功，最新学生信息为:\n");
		serachStudentInfo(ppUser_Info);
	}
	else
		printf("------------:删除失败，该学生不存在\n");

}

/*
 *管理员 查询学生信息
 */
void serachStudentInfo(pStudentInfoStruct* ppUser_Info) {
	PRINT_BEGIN;
	printStudentInfoTitle();
	printStudentInfo(ppUser_Info);
}

/*
 *保存学生信息链表到文件中
 */
void saveStudentInfoDataToFile(const char* User_Info_File_Name, pStudentInfoStruct* ppUser_Info) {
	FILE* fp = fopen(User_Info_File_Name, "w+");
	if (NULL == fp) {
		perror("fopen");
		return;
	}
	pStudentInfoStruct pCurrent = *ppUser_Info;
	int ret;
	while (pCurrent != NULL) {
		ret = fprintf(fp, "\t\t%d\t\t%s\t\t%5.2f\t\t%5.2f\t\t%5.2f\n", pCurrent->userId, pCurrent->userName, pCurrent->userCourse1Score, pCurrent->userCourse2Score, pCurrent->userCourse3Score);
		if (ret < 0) {
			perror("fprintf");
			return;
		}
		pCurrent = pCurrent->next;
	}
	fclose(fp);
}

/*
 *打印学生信息标题
 */
void printStudentInfoTitle() {
	printf("\t\t学号\t\t姓名\t\t科目一\t\t科目二\t\t科目三\n");
}
