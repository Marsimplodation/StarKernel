#ifndef __DICTIONARY__H__
#define __DICTIONARY__H__
#include "../utils/types.h"

typedef enum {Space=0x20, A=0x41, B=0x42, C=0x43, D=0x44, E=0x45, F=0x46, G=0x47, H=0x48, I=0x49, J=0x4A, K=0x4B, L=0x4C, M=0x4D, N=0x4E, O=0x4F, P=0x50, Q=0x51, R=0x52, S=0x53, T=0x54, U=0x55, V=0x56, W=0x57, X=0x58, Y=0x59, Z=0x5A, a=0x61, b=0x62, c=0x63, d=0x64, e=0x65, f=0x66, g=0x67, h=0x68, i=0x69, j=0x6A, k=0x6B, l=0x6C, m=0x6D, n=0x6E, o=0x6F, p=0x70, q=0x71, r=0x72, s=0x73, t=0x74, u=0x75, v=0x76, w=0x77, x=0x78, y=0x79, z=0x7A} Letters;
typedef enum {WHITE=0x0F, RED=0X0C, GREEN=0x02, YELLOW=0x0E} colors;
char getAsciVal(char pchar); 
char * intToChar(int x);
char * longToChar(u64 x);

#endif  //!__DICTIONARY__H__