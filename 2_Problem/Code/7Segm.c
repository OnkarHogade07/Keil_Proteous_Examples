#include <reg51.h>

sbit SW_1 = P1^0;
sbit SW_2 = P1^1;
sbit SW_3 = P1^2;
sbit SW_4 = P1^3;
sbit SW_5 = P1^4;
sbit SW_6 = P1^5;
sbit SW_7 = P1^6;
sbit SW_8 = P1^7;

void main() {
    P1 = 0xFF; // Configure port 1 as input

    while (1) {
        if (SW_1 == 0 && SW_2 == 0) {
            P3 = 0x7F;
        } else if (SW_1 == 0 && SW_3 == 0) {
            P3 = 0x6F;
        } else if (SW_1 == 0) {
            P3 = 0x3F;
        } else if (SW_2 == 0) {
            P3 = 0x06;
        } else if (SW_3 == 0) {
            P3 = 0x5B;
        } else if (SW_4 == 0) {
            P3 = 0x4F;
        } else if (SW_5 == 0) {
            P3 = 0x66;
        } else if (SW_6 == 0) {
            P3 = 0x6D;
        } else if (SW_7 == 0) {
            P3 = 0x7D;
        } else if (SW_8 == 0) {
            P3 = 0x07;
        } else {
            P3 = 0x00; // Default state
        }
    }
}
