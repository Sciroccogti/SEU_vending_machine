#include "vendor.h"

void VIPreg() {
    string username, password;
    ofstream file;
    file.open("VIPlist.txt");
    frame
    cout << "Please input your username:" << endl;
    cin >> username;
    cout << "Please set a password without \' \':" << endl;
    cin >> password;
    Names.push_back(username);
    Psws.push_back(password);//会员名及密码的保存
    file << username << " ";
    file << password << endl;//导入到管理端
    frame
    cout << "Register successful !" << endl << endl << "back" << endl;
    frame
    buttonback();
}

void iniVIP() {
    ifstream test("VIPlist.txt");
    int num;
    char a;
    while(test.get(a)){
        if(a == '\n'){
            num++;
        }
    }

    ifstream fin("VIPlist.txt");
    string s;
    stringstream ss;
    int i , j;
    for (i = 0; i < num; i++) {//希望.size是用户名数量
        j = 0;
        s.erase();
        while (fin.get(a)) {
            if (a > 32) {
                s += a;
            } else if (a == ' ' || a == '\n') {
                switch (j){
                    case 0:
                        Names.push_back(s);
                        break;
                    case 1:
                        Psws.push_back(s);
                }
                j++;
                if(j > 1){
                    break;
                }

                s.erase();
                ss.clear();
            }
        }
    }
    fin.close();
}

void VIPlogin() {
    string username, password;
    cout.flags(ios::left);
    ifstream fin("VIPlist.txt");
    frame

    int i = 0;
    if (Names.size() == 0) {
        cout << "You have not registered!" << endl << endl << setw(10) << "back" << "signup" << endl;
        frame
        buttonback();

    } else {
        cout << "Input your VIP name:" << endl;
        cin >> username;
        while (Names[i] != username && i != Names.size()) {
            i++;
        }
        if (i == Names.size()) {
            cout << "This name do not exist.\nPlease input your VIP name again or register a new one.";
        } else {
            int j = 0;
            cout<<"Password:"<<endl;
            cin >> password;
            while (Psws[j] != password && j != Psws.size()) {
                j++;
            }
            if (j != i) cout << "Incorrect password!" << endl;
            else {
                isVIP = 1;
                cout << "Welcome back," << " " << username << "!" << endl;
            }
        }
        cout << endl << endl << "back" << endl;
        frame
        buttonback();
    }
}
//void VIPlogin() {
//    string username, password;
//    cout.flags(ios::left);
//    ifstream fin("VIPlist.txt");
//    char a;
//    string s;
//    stringstream ss;
//    int j;
//    frame
//
//    for (j = 0; j < number; j++) {
//        s.erase(0);
//        while (fin.get(a)) {
//            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == '-' || a == '_') {
//                s += a;
//            }
//            Names.push_back(s);
//            s.erase(0);
//            ss.clear();
//        }
//    }
//    int i = 0;
//    if (Names.size() == 0) {
//        cout << "You have not registered!" << endl << endl << setw(10) << "back" << "sign up" << endl;
//        frame
//        buttonback();
//
//    } else {
//        cout << "Input your VIP name:" << endl;
//        cin >> username;
//        while (Names[i] != username && i != Names.size()) {
//            i++;
//        }
//        if (i == Names.size()) {
//            cout << "This name do not exist.\nPlease input your VIP name again or register a new one.\n\nback\n";
//            frame
//            buttonback();
//        } else {
//            int j = 0;
//            cin >> password;
//            while (Psws[j] != password && j != Psws.size()) {
//                j++;
//            }
//            if (j != i) {
//                cout << "Incorrect password!" << endl;
//                frame
//                buttonback();
//            } else {
//                isVIP = 1;
//                cout << "Welcome back," << " " << username << "!" << endl;
//            }
//        }
//    }
//}
