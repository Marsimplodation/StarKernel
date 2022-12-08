#include "dictionary.h"
#include "../utils/types.h"

char * charToReturn;

int CharToInt(char * in) {
    int i = 0;
    int ret = 0;
    while(in[i] != 0x0) {
        switch(in[i]) {
            case '1': ret=ret*10 +1; break;
            case '2': ret=ret*10 +2; break;
            case '3': ret=ret*10 +3; break;
            case '4': ret=ret*10 +4; break;
            case '5': ret=ret*10 +5; break;
            case '6': ret=ret*10 +6; break;
            case '7': ret=ret*10 +7; break;
            case '8': ret=ret*10 +8; break;
            case '9': ret=ret*10 +9; break;
            case '0': ret=ret*10 +0; break;
        }
        i++;
    }
    return ret;
}

char * intToChar(int x) {
    int buffer[20];
    int len = 0;
    for(int i = 0; i < 20; i++) {
        buffer[i] = 0;
    }

    while(x >= 10) {
        buffer[len++] = x % 10;
        x/=10;
    }
    if (x>=0) {
        buffer[len++] = x;
    }
    //char charToReturn[len + 2];
    int pos=len - 1;
    for (int i=0; i<len; i++) {
        switch (buffer[i]) {
            case 1: charToReturn[pos--] = '1'; break;
            case 2: charToReturn[pos--] = '2'; break;
            case 3: charToReturn[pos--] = '3'; break;
            case 4: charToReturn[pos--] = '4'; break;
            case 5: charToReturn[pos--] = '5'; break;
            case 6: charToReturn[pos--] = '6'; break;
            case 7: charToReturn[pos--] = '7'; break;
            case 8: charToReturn[pos--] = '8'; break;
            case 9: charToReturn[pos--] = '9'; break;
            case 0: charToReturn[pos--] = '0'; break;
        }
    }
    charToReturn[len] = '\n';
    charToReturn[len+1] = 0x0;
    return (char *)charToReturn;
}

char * longToChar(u64 x) {
    int buffer[20];
    int len = 0;
    for(int i = 0; i < 20; i++) {
        buffer[i] = 0;
    }

    while(x >= 10) {
        buffer[len++] = x % 10;
        x/=10;
    }
    if (x>=0) {
        buffer[len++] = x;
    }
    //char charToReturn[len + 2];
    int pos=len - 1;
    for (int i=0; i<len; i++) {
        switch (buffer[i]) {
            case 1: charToReturn[pos--] = '1'; break;
            case 2: charToReturn[pos--] = '2'; break;
            case 3: charToReturn[pos--] = '3'; break;
            case 4: charToReturn[pos--] = '4'; break;
            case 5: charToReturn[pos--] = '5'; break;
            case 6: charToReturn[pos--] = '6'; break;
            case 7: charToReturn[pos--] = '7'; break;
            case 8: charToReturn[pos--] = '8'; break;
            case 9: charToReturn[pos--] = '9'; break;
            case 0: charToReturn[pos--] = '0'; break;
        }
    }
    charToReturn[len] = '\n';
    charToReturn[len+1] = 0x0;
    return (char *)charToReturn;
}

char getAsciVal(char pchar) {
    switch (pchar) {
    case ':': return 0x3A;
    case '.': return 0x2E;
    case '!':
        return 0x21;
    case ' ':
        return Space;
    case 'A':
            return A;
    case 'B':
            return B;
    case 'C':
            return C;
    case 'D':
            return D;
    case 'E':
            return E;
    case 'F':
            return F;
    case 'G':
            return G;
    case 'H':
            return H;
    case 'I':
            return I;
    case 'J':
            return J;
    case 'K':
            return K;
    case 'L':
            return L;
    case 'M':
            return M;
    case 'N':
            return N;
    case 'O':
            return O;
    case 'P':
            return P;
    case 'Q':
            return Q;
    case 'R':
            return R;
    case 'S':
            return S;
    case 'T':
            return T;
    case 'U':
            return U;
    case 'V':
            return V;
    case 'W':
            return W;
    case 'X':
            return X;
    case 'Y':
            return Y;
    case 'Z':
            return Z;
    case 'a':
            return a;
    case 'b':
            return b;
    case 'c':
            return c;
    case 'd':
            return d;
    case 'e':
            return e;
    case 'f':
            return f;
    case 'g':
            return g;
    case 'h':
            return h;
    case 'i':
            return i;
    case 'j':
            return j;
    case 'k':
            return k;
    case 'l':
            return l;
    case 'm':
            return m;
    case 'n':
            return n;
    case 'o':
            return o;
    case 'p':
            return p;
    case 'q':
            return q;
    case 'r':
            return r;
    case 's':
            return s;
    case 't':
            return t;
    case 'u':
            return u;
    case 'v':
            return v;
    case 'w':
            return w;
    case 'x':
            return x;
    case 'y':
            return y;
    case 'z':
            return z;
    default:
        return pchar;
    }
}
