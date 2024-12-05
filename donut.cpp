#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>


int main(void){

    float A = 0, B = 0;
    float theta, phi;
    int k;
    float z[1760];
    char b[1760];
    printf("\x1b[2J");
  
    for(;;){
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for(theta=0; theta<2*M_PI; theta+=0.04){
            for(phi=0; phi<2*M_PI; phi+=0.02){
                float sp = sin(phi), 
                cp = cos(phi), 
                st = sin(theta), 
                ct = cos(theta), 
                sA = sin(A), 
                cA = cos(A), 
                sB = sin(B), 
                cB = cos(B),
                h = ct + 2,
                D = 1 / (sp*h*sA + st*cA + 5),
                t = sp*h*cA - st*sA;

                int x = 40 + 30*D*(cp*h*cB - t*sB),
                y = 12 + 15*D*(cp*h*sB + t*cB),
                o = x + 80*y,
                N = 8*((st*sA - sp*ct*cA)*cB - sp*ct*sA - st*cA - cp*ct*sB);

                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]){
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@%"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
        for(k=0; k<1761; k++){
            putchar(k%80 ? b[k] : 10);
            A += 0.00006;
            B += 0.00003;
            }
        usleep(20000);
    }

    return 0;
}