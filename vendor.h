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

void inimenu();//��������
void iniVIP();
void welcome();//��ӭ����
void menu();//��Ʒ�˵�
int choose();//ѡ����Ʒ
int pay(int choice, int num,double income);//֧������
void VIPreg();//vipע��
void VIPlogin();//vip��½
int feedback(int &serial);//�������
int amount();//ѡ����Ʒ����
int deliver(int p, int choice, int amount);//����
int deal(int signal, double &income, double &balance, double pr);//���׽���
void detect(int error);//������
int buttonback();//������ҳ��ť
int local_time();//����ʱ��
bool check(int i);//����������� 

extern vector<string> Names;
extern vector<string> Psws;
extern vector<string>::iterator it;

extern double balance ;//�ۻ��������
extern double income ;//�ۻ������ڽ��еĽ������û�֧���Ľ��
#define number 5//��Ʒ����
extern int error;//�����ź�
extern int process ;//������̿���
extern int serial ;//������
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

