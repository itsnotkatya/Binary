//
// Created by Екатерина on 19/10/2019.
//
#include <iostream>
using namespace std;
#include "functions.h"


int Power (int n) {
    int d = ( 1 << n);
    cout << d << endl;
    return 0;
}

int Bit (int n) {
    for(int i=0; i<8; i++) {
        cout << (n & (256 >> i + 1) ? '1' : '0');
    }
}

int One(int n) {
    int i = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            i++;
        }
        n = n/2;
    }
    cout << "Количество единиц в двоичном коде числа равно " << i << endl;
    return 0;
}

int NumBit(int n) {
    int k;
    for (int i=0; i<8; i++) {
        if (n % 2 == 1) {
            k = i;
        }
        n = n/2;
    }
    cout << "Номер старшего бита равен "  << k << endl;
    return 0;
}

int getBitOne(int i, int n) {
    int d = (1 << i);
    return n | d;

}

int getBitZero(int i, int n) {
    int d = ~(1 << i);
    return n & d;
}


int getBitDifferent(int i, int n) {
    int d = (1 << i);
    return n | d;
}

 int moveBit(unsigned int n) {
    n = n & ~(1 << 7);
    unsigned int res = (n << 1) | 1;
    return res ;
}

int countBit (int n) {
    int count = 0;
    for (int i = 0; i < 8; i ++) {
        if (((n << i) == 1) & ((n << (i + 1)) == 1)) {
            count ++;
        }
        n = n << i;
    }
    return count;
}

int swapBit(int i, int n, int k) {
    int d1  = (i >> n) & 1;
    int d2  = (i >> k) & 1;

    int mask1 = ~ (1 << n);
    int mask2 = ~ (1 << k);

    i = i & mask1 & mask2;
    i = i | (d1 << k);
    i = i | (d2 << n);

    return i;
}

int deleteBit(int n, int i) {
    int mask1 = (1 << (i - 1));
    int mask2 = ~ mask1;
    return ((n >> 1) & mask2 )| (n & mask1);
}