#ifndef _VENDOR_H_
#define _VENDOR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

#define frame cout<<"-------------------------------------------------------------------------"<<endl<<endl;
#define jump  

void inimenu();//数据内容
void iniVIP();
void welcome();//欢迎界面
void menu();//商品菜单
int choose();//选择商品
int pay(int choice, int num,double income);//支付找零
void VIPreg();//vip注册
void VIPlogin();//vip登陆
int feedback(int &serial);//意见反馈
int amount();//选择商品数量
int deliver(int p, int choice, int amount);//出货
int deal(int signal, double &income, double &balance, double pr);//交易金额库
void detect(int error);//错误检测
int buttonback();//返回主页按钮
int local_time();//返回时间
bool check(int i);//检查生产日期 

extern vector<string> Names;
extern vector<string> Psws;
extern vector<string>::iterator it;

extern double balance ;//售货机内余额
extern double income ;//售货机正在进行的交易中用户支付的金额
#define number 5//商品种类
extern int error;//错误信号
extern int process ;//程序进程控制
extern int serial ;//意见序号
extern bool isVIP ;

struct item {
    string name;
    double price;
    int amount;
    int manu;
    int span;
} ;

extern item ITEM[number];
#endif

