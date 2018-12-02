// UseSQLite3.cpp : �������̨Ӧ�ó������ڵ㡣
#define _CRT_SECURE_NO_WARNINGS  

/**
*Date: 2018/12/02 18:32
*Author:yqq
*Descriptions:  

	���� sqlite3 ���ݿ�, 

	1.�������ݿ�
	2.��ɾ�Ĳ�
		
*/


#include "stdafx.h"
#include "sqlite3.h"
#include <iostream>

#pragma comment(lib, "sqlite3.lib")  //��̬��

using namespace std;

sqlite3 * pDB = NULL;

//�����û�
bool AddUser(const string& sName, const string& sAge);
//ɾ���û�
bool DeleteUser(const string& sName);
//�޸��û�
bool ModifyUser(const string& sName, const string& sAge);
//�����û�
bool SelectUser();

//����user��
bool Create();

int _tmain(int argc, _TCHAR* argv[])
{
	//��·������utf-8����
	//���·���а������ģ���Ҫ���б���ת��
	int nRes = sqlite3_open("testDB.db", &pDB); //ok
	if (nRes != SQLITE_OK)
	{
		cout << "Open database fail: " << sqlite3_errmsg(pDB);
		goto QUIT;
	}
	//����user��
	if (!Create())
	{
		goto QUIT;
	}

	//��ӡ���Ǯ���
	if (!AddUser("zhao", "18")
		|| !AddUser("qian", "19")
		|| !AddUser("sun", "20")
		|| !AddUser("li", "21"))
	{
		goto QUIT;
	}

	//ɾ�����ԡ�
	if (!DeleteUser("zhao"))
	{
		goto QUIT;
	}

	//�޸ġ��
	if (!ModifyUser("sun", "15"))
	{
		goto QUIT;
	}

	//�����û�
	if (!SelectUser())
	{
		goto QUIT;
	}

QUIT:
	sqlite3_close(pDB);

	system("pause");
	return 0;
}

bool Create()
{
	std::string strSql = "";
	//strSql += "create table if not exists user(\
		id int(10) primary key AUTO_INCREMENT  not null,\
		name varchar(100) not null\
		);";  // ���������user ��, �򴴽� user�� 

	//ע��: sqlite ������ķ�ʽ   ��  mysql ��΢��ͬ
	strSql += "create table if not exists user(  \
		id integer primary key autoincrement,\
		name varchar(64),\
		age integer\
		);";

	char *pszErrMsg = NULL;
	int nRet = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &pszErrMsg);
	if (SQLITE_OK != nRet)
	{
		std::cout << "������ʧ��:" << pszErrMsg  << std::endl;
		return false;
	}
	std::cout << "������ �ɹ�!" << std::endl;


	return true;
}

bool AddUser(const string& sName, const string& sAge)
{
	string strSql = "";
	strSql += "insert into user(name,age)";
	strSql += "values('";
	strSql += sName;
	strSql += "',";
	strSql += sAge;
	strSql += ");";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "add user fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "add user success: " << sName.c_str() << "\t" << sAge.c_str() << endl;
	}

	return true;
}

bool DeleteUser(const string& sName)
{
	string strSql = "";
	strSql += "delete from user where name='";
	strSql += sName;
	strSql += "';";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "delete user fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "delete user success: " << sName.c_str() << endl;
	}

	return true;
}

bool ModifyUser(const string& sName, const string& sAge)
{
	string strSql = "";
	strSql += "update user set age =";
	strSql += sAge;
	strSql += " where name='";
	strSql += sName;
	strSql += "';";

	char* cErrMsg;
	int nRes = sqlite3_exec(pDB, strSql.c_str(), 0, 0, &cErrMsg);
	if (nRes != SQLITE_OK)
	{
		cout << "modify user fail: " << cErrMsg << endl;
		return false;
	}
	else
	{
		cout << "modify user success: " << sName.c_str() << "\t" << sAge.c_str() << endl;
	}

	return true;
}

static int UserResult(void *NotUsed, int argc, char **argv, char **azColName)
{
	for (int i = 0; i < argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << ", ";
	}
	cout << endl;

	return 0;
}

bool SelectUser()
{
	char* cErrMsg;
	int res = sqlite3_exec(pDB, "select * from user;", UserResult, 0, &cErrMsg);

	if (res != SQLITE_OK)
	{
		cout << "select fail: " << cErrMsg << endl;
		return false;
	}

	return true;
}
