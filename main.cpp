#include "vendor.h"

double balance = 1000;//�ۻ��������
double income = 0;//�ۻ������ڽ��еĽ������û�֧���Ľ��
int process = 1;//������̿���
int serial = 1;//������
bool isVIP = 0;

item ITEM[number];
 vector<string> Names;
 vector<string> Psws;
vector<string>::iterator it;

int main(int argc, char *argv[]) {
    int num = 0, isok = 0;
    inimenu();
    iniVIP();
    welcome();
    frame
    return 0;
}

int buttonback() {
    string back;
    cin >> back;
    if (back == "back") {
        welcome();
        return 0;
    } else if(back == "signup") {
        VIPreg();
        return 0;
    } else {
        frame
        cout << "Thank you for you using!" << endl;
        return 0;
    }
}