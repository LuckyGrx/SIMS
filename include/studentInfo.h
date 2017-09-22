#ifndef __STUDENT_INFO_H__
#define __STUDENT_INFO_H__
#include "dataStruct.h"

void addStudentInfo(const char*, pStudentInfoStruct*);//管理员 增加学生信息
void updateStudentInfo(const char*, pStudentInfoStruct*);//管理员 更新学生信息
void deleteStudentInfo(const char*, pStudentInfoStruct*);//管理员 删除学生信息
void serachStudentInfo(pStudentInfoStruct*);//管理员 查询学生信息
void serachStudentInfoById(pStudentInfoStruct*);//学生  通过id查询学生信息
void serachStudentInfoByName(pStudentInfoStruct*);//学生  通过id查询学生信息

void saveStudentInfoDataToFile(const char*, pStudentInfoStruct*);//保存学生信息链表到文件中
void printStudentInfoTitle();//打印学生信息标题

#endif
