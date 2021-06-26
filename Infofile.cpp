#include "stdafx.h"
#include "Infofile.h"
#include "GlobalVal.h"

CInfofile::CInfofile()
{
}


CInfofile::~CInfofile()
{ 
}


//读取登陆信息

//验证账号
bool CInfofile::ReadLoginAccount(CString &account) {
	for (vector<message>::iterator it = MessVec.begin(); it != MessVec.end(); it++)
	{
		if (it->m_Account == account) {
			now_account = account;
			return true;
		}
	}
	return false;
}

//验证密码
bool CInfofile::ReadLoginPwd(CString &pwd) {
	for (vector<message>::iterator it = MessVec.begin(); it != MessVec.end(); it++)
	{
		if (it->m_PWD == pwd)
			return true;
	}
	return false;
}

//修改密码
void CInfofile::WritePwd(char* name, char* pwd) {
	int lenth = MessVec.size();
	for (int i = 0; i < lenth; i++) {
		if (MessVec[i].m_Account == name)
			MessVec[i].m_PWD = pwd;
	}
}

// 读取员工数据
void CInfofile::ReadDocline() {

	CFileFind fileFind;//查找文件是否存在
	CString strFileName;
	strFileName = _T("Data/stock.txt");
	if (!fileFind.FindFile(strFileName))
	{
		::MessageBox(NULL, TEXT("读取用户信息文件失败"), NULL, MB_OK);
	}

	CStdioFile file;
	file.Open(strFileName, CFile::modeRead);
	CString strTemp,str;
	file.ReadString(strTemp);					//第一行为属性标记，不读进文件

	while (file.ReadString(strTemp))				//strTemp读取整行
	{
		AfxExtractSubString(str, strTemp, 0, '|');
		if (str == "账号名")
			continue;
		if (str == "")
			break;
		message* mes = new message;
		//整行读取后用函数处理字符串
		AfxExtractSubString(mes->m_Account, strTemp, 0, '|');		//对strTemp进行字符串切割，AfxExtractSubString四个参数（存放，字符串，第几个，分割标志）
		AfxExtractSubString(mes->m_Name, strTemp, 1, '|');
		AfxExtractSubString(mes->m_PWD, strTemp, 2, '|');
		AfxExtractSubString(mes->m_WorkYear, strTemp, 3, '|');
		AfxExtractSubString(mes->m_Psition, strTemp, 4, '|');
		AfxExtractSubString(mes->m_Salary, strTemp, 5, '|');
		mes->m_Tax.Format(_T("%lf"),Tax(_ttoi64(mes->m_Salary)));
		MessVec.push_back(*mes);
		delete mes;
	}
	file.Close();
}

//员工信息写入文件
void CInfofile::WirteDocline() {
	ofstream ofs(_F_STOCK);//输出方式打开文件

	if (MessVec.size() > 0)	//员工信息有内容才执行
	{
		ofs << "账号名" << '|' << "员工姓名" << '|' << "密码" << '|'
			<< "工龄"  << '|' << "职称"  << '|' << "工资"<< endl; //写入表头

											//通过迭代器取出链表内容，写入文件，以“|”分隔，结尾加换行
		for (vector<message>::iterator it = MessVec.begin(); it != MessVec.end(); it++)
		{
			ofs << it->m_Account << '|';
			ofs << it->m_Name << '|';
			ofs << it->m_PWD << '|';
			ofs << it->m_WorkYear << '|';
			ofs << it->m_Psition << '|';
			ofs << it->m_Salary  << endl;
		}
	}
	ofs.close();
}

//添加新员工信息
void CInfofile::Addline(CString name, int num, int price) {

}

double CInfofile::Tax(double money)
{
	money = money - 5000;
	float mshui;
	//税金计算代码
	if (money <= 0)
	{
		mshui = 0;
	}
	if (money <= 3000 && money >= 0)
	{
		mshui = money *0.03;
	}
	if (money <= 12000 && money > 3000)
	{
		mshui = money *0.1 - 210;
	}
	if (money <= 25000 && money > 12000)
	{
		mshui = money * 0.2 - 1410;
	}
	if (money <= 35000 && money > 25000)
	{
		mshui = money * 0.25 - 2660;
	}
	if (money <= 55000 && money > 35000)
	{
		mshui = money * 0.3 - 4410;
	}
	if (money <= 80000 && money > 55000)
	{
		mshui = money * 0.35 - 7160;
	}
	if (money > 80000)
	{
		mshui = money * 0.45 - 15160;
	}
	return mshui;
}
