#pragma once
#define _F_LOGIN "./Data/login.ini"
#define _F_STOCK "./Data/stock.txt"
#include <vector>
#include <fstream>
#include <iomanip>		//设置文字输出对齐setw函数

using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;
using std::setw;
typedef struct Account_Message {
	CString m_Tax;
	CString m_Account;			//账户ID信息
	CString m_Name;		//账户真实姓名
	CString m_PWD;		//密码
	CString m_WorkYear;	//工龄
	CString m_Psition;	//职称
	CString m_Salary;		//工资
}message;


class CInfofile
{
public:
	CInfofile();
	~CInfofile();

	//读取登陆信息
	bool ReadLoginAccount(CString &name);
	bool ReadLoginPwd(CString& pwd);
	//修改密码
	void WritePwd(char* name, char* pwd);

	// 读取员工数据
	void ReadDocline();

	//员工信息写入文件
	void WirteDocline();


	//添加新员工信息
	void Addline(CString name, int num, int price);

	std::vector<Account_Message> MessVec;			//员工信息容器，用于对接文件系统

	double Tax(double money);
};

