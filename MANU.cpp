#include "vendor.h"

int local_time() {
    int tt;
    time_t t;
    struct tm *local;
    time(&t);
    local = localtime(&t);
    tt = (local->tm_year + 1900) * 10000 + (local->tm_mon + 1)
                                           * 100 + (local->tm_mday);
    return tt;
}

bool check(int i) {
    int now = local_time(), sy = ITEM[i].span / 365,
            sm = (ITEM[i].span - sy * 365) / 30, sd = ITEM[i].span - sm * 10,
            my = ITEM[i].manu / 10000, mm = (ITEM[i].manu % 10000) / 100,
            md = ITEM[i].manu % 100, dmax;
    bool ok = true;

    my += sy;
    mm += sm;
    md += sd;
    switch (mm) {
        case 2:
            if (my % 4 || !(my % 100)) {
                dmax = 28;
            } else {
                dmax = 29;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dmax = 30;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dmax = 31;
    }
    if(md > dmax) {
        mm++;
        md -= dmax;
    }
    if(mm > 12) {
        my++;
        mm -= 12;
    }
    if (now / 10000 > my || (now % 10000) / 100 > mm || now % 100 > md) {
        ok = false;
    }
    return ok;
}
