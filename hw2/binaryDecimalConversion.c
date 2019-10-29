#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

//the length of binary numbers is always 64
uint64_t convertBinaryToDecimal(char *binaryNum) {
    uint64_t retNum = 0;
    for(int i = 0; i < 64; i++) {
        if(binaryNum[i] != '0') {
            retNum += pow(2, (double)(63 - i));
            printf("retNum: %ld\n", retNum);
        }
    }
    return retNum;
}

//the length of hex nums is always 16
uint16_t convertHexToDecimal(char *hexNum) {
    uint64_t retNum = 0;
    for(int i = 0; i < 16; i++) {
        long powNum = pow(16, (double)(15 - i));
        switch(hexNum[i]) {
            case '1' :
                retNum += powNum * 1;
            case '2' :
                retNum += powNum * 2;
            case '3' :
                retNum += powNum * 3;
            case '4' :
                retNum += powNum * 4;
            case '5' :
                retNum += powNum * 5;
            case '6' :
                retNum += powNum * 6;
            case '7' :
                retNum += powNum * 7;
            case '8' :
                retNum += powNum * 8;
            case '9' :
                retNum += powNum * 9;
            case 'A' :
                retNum += powNum * 10;
            case 'B' :
                retNum += powNum * 11;
            case 'C' :
                retNum += powNum * 12;
            case 'D' :
                retNum += powNum * 13;
            case 'E' :
                retNum += powNum * 14;
            case 'F' :
                retNum += powNum * 15;
        }
    }
    return retNum;
}

// int convertNum(uint64_t num, int base, char* str) { //clever but not what I want :(
//     if (num == 0) {
//         return -1;
//     }
//     int remainder = num % base;
//     int index = convertNum(num / base, base, &str[0]) + 1;
//     if(remainder < 10) {
//         str[index] = (char) (remainder + '0');
//     }
//     else {
//         str[index] = (char) (remainder - 10 + 'A');
//     }
//     return index;
// }

const char* decimalToHex(uint64_t num) {
    static char ret[17] = "";
    for(int i = 15; i >= 0; i--) {
        int remainder = num % 16;
        if(remainder < 10) {
            ret[i] = (char) (remainder + '0');
        }
        else {
            ret[i] = (char) (remainder - 10 + 'A');
        }
        num = num / 16;
    }
    return ret;
}

const char* decimalToBin(uint64_t num) {
    static char ret[65] = "";
    for(int i = 63; i >= 0; i--) {
        int remainder = num % 2;
        ret[i] = (char) (remainder + '0');
        num = num / 2;
    }
    return ret;
}
int main(void) {
    printf("converting 10101111110000101 to decimal: %d\n", (int) convertBinaryToDecimal("0000000000000000000000000000000000000000000000010101111110000101"));
    printf("converting 15F85 to decimal: %d\n", (int)convertHexToDecimal("0000000000015F85"));
    printf("converting 89989 to hex: %s\n", decimalToHex(89989));
    printf("converting 89989 to binary: %s\n", decimalToBin(89989));
    return 0;
}