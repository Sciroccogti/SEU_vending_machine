#include "vendor.h"

void inimenu() {
    ifstream fin("menu.txt");
    char a, b;
    string s;
    stringstream ss;
    int i, j;

    for (i = 0; i < number; i++) {
        j = 0;
        s.erase(0);
        while (fin.get(a)) {
            if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
                s += a;
                b = a;
            } else if (a == ' ' || a == '\n') {
                switch (j) {
                    case 0:
                        ITEM[i].name = s;
                        break;
                    case 1:
                        ITEM[i].price = b - '0';
                        break;
                    case 2:
                        ss << s;
                        ss >> ITEM[i].amount;
                        break;
                    case 3:
                        ss << s;
                        ss >> ITEM[i].manu;
                        break;
                    case 4:
                        ss << s;
                        ss >> ITEM[i].span;
                }
                j++;
                if (j > 4) {
                    break;
                }

                s.erase(0);
                ss.clear();
            }
        }
    }
    fin.close();
}

void welcome() {
    int button;

    frame
    cout << "Welcome to SEU vending machine!" << endl;
    cout << endl << endl << "choose(1)" << "     " << "feedback(2)" << "     "
         << "vip login(3)" << "     " << "vip signup(4)" << "     " << "exit(5)" << endl;
    frame
    cin >> button;
    switch (button) {
        case 1:
            choose();
            break;
        case 2:
            feedback(serial);
            break;
        case 3:
            VIPlogin();
            break;
        case 4:
            VIPreg();
            break;
        case 5:
            frame
            cout << "Thank you for you using!" << endl;
            exit(0);
    }
}

int choose() {
    int choice, i, ok = 0, a;
    string input;
    cout.flags(ios::left);

    do {
        frame
        cout << "Below are the items on sale:" << endl;
        for (i = 0; i < number; i++) {
            cout << setw(10) << ITEM[i].name << ITEM[i].price << " yuan" << endl;
        }
        cout << endl;
        cout << "Please choose the item." << endl;
        frame
        cin >> input;
        for (i = 0; i < number; i++) {
            if (input == ITEM[i].name) {
                if (check(i)) {
                    choice = i;
                    ok = 1;
                    break;
                } else {
                    frame
                    cout << "Sorry! The item chosen is overdued!" << endl;
                    ok = -1;
                    break;
                }
            }
        }
        if (ok == 0) {
            frame
            cout << "I don't have what you want,please input again." << endl << endl;
            continue;
        }
    } while (ok != 1);
    a = amount();
    if (ITEM[i].amount < a) {
        frame
        cout << ITEM[i].name << "Sorry! Not enough items left!" << endl;
        cout << endl << endl << endl << "back" << endl;
        buttonback();
    } else {
        pay(choice, a, income);
    }

    return choice;
}

int amount() {
    frame
    int amount;
    cout << "amount:";
    cin >> amount;
    return amount;
}

int feedback(int &serial) {
    string fb;
    string fbb;
    ifstream ifile;
    ifile.open("feedback.txt");
    ifile >> fb;
    ifile.close();
    ofstream ofile;
    ofile.open("feedback.txt");
    frame
    cout << "Please give us some valuable advice!" << endl;
    cout << endl << endl << endl << "back" << endl;
    frame
    buttonback();
    ofile << fb << serial << "." << fbb;
    serial = serial + 1;
    ofile.close();
    frame
    cout << "thanks for your advice!" << endl;
    cout << endl << endl << endl << "back" << endl;
    frame
    buttonback();
    return 0;
}

int pay(int choice, int num, double income) { //付款成功返回0，错误返回-1
    double pr = ITEM[choice].price * num, input = 0;
    if (isVIP) {
        cout << "Since you are our VIP, you got 25% off!" << endl;
        pr *= 3.0 / 4;
    }
    int signal, detection, isok = 1;
    frame
    cout << "Please pay " << pr << " yuan" << endl;
    frame
    do {
        cin >> input;
        income += input;
        if (income > pr && income - pr <= balance) {
            signal = 0;
            detection = deal(signal, income, balance, pr);
            frame
            cout << "Payment is successful! Thank you!" << endl << endl << endl << "back" << endl;
            deliver(signal, choice, num);
            isok = 0;
            frame
            buttonback();

        } else if (income - pr > balance) {
            frame
            cout << "Sorry, there's not enough balance in the machine!" << endl << "Refunding...Please wait..." << endl;
            frame
            signal = -1;
            deal(signal, income, balance, pr);
            detection = deal(signal, income, balance, pr);
            isok = 0;
        } else if (income == pr) {
            frame
            cout << "Payment is successful! Thank you!" << endl;
            cout << endl << endl << "back" << endl;
            signal = 1;
            deal(signal, income, balance, pr);
            frame
            buttonback();
            detection = deal(signal, income, balance, pr);
            isok = 0;
        } else if (income < pr) {
            cout << "Sorry! The money you paid is not enough! Please pay more!" << endl;
            isok = -1;
            /*int button = 1;
          if (button == 2) {
                signal = -1;
                detection = deal(signal, income, balance, pr);
                break;
            }*/
        }
    } while (isok == -1);
    if (detection == isok) {
        return isok;
    } else {
        detect(999);
    }
}

int deal(int signal, double &income, double &balance, double pr) {
    int isok;
    switch (signal) {
        case 1:
            balance = balance + income;
            income = 0;
            isok = 0;
            break;
        case 0:
            balance = balance - (income - pr);
            frame
            cout << "Here is the charge: " << income - pr << " yuan." << endl;
            cout << "Payment is successful! Thank you!" << endl;
            cout << endl << endl << "back" << endl;
            frame
            balance = balance + income;
            income = 0;
            isok = 0;
            buttonback();
            break;
        case -1:
            frame
            cout << "Here is the refund:" << income << "yuan." << endl;
            cout << endl << endl << "back" << endl;
            frame
            income = 0;
            isok = -1;
            buttonback();
            break;
    }
    return isok;
}

int deliver(int p, int choice, int amount) {
    if (p == 0) {
        cout << "Delivering,please wait.";
        ITEM[choice].amount -= amount;
    }
    return 0;
}

void detect(int error) {
    if (error > 20) {
        cout << "error:" << error << endl;
    }
}

