#include <stdio.h>
#include <stdlib.h>

int okLimits(float num){
    if(num >= 0 && num <= 1)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]){

    float r = -1, g = -1, b = -1;
    int input = 1;

    printf("Convert 0-1 to 0-255\n");

    if(argc >= 4){
        input = 0;
        r = atof(argv[1]);
	g = atof(argv[2]);
	b = atof(argv[3]);
	if(!okLimits(r) || !okLimits(g) || !okLimits(b)){
	    r = -1; g = -1; b = -1;
	    input = 1;
	}
    }

    if(input){
    	while(!okLimits(r)){
       	    printf("RED: ");
	    scanf("%f", &r);
        }
	while(!okLimits(g)){
	    printf("GREEN: ");
	    scanf("%f", &g);
	}
	while(!okLimits(b)){
	    printf("BLUE: ");
	    scanf("%f", &b);
	}
    }

    int dr, dg, db;

    dr = r * 255;
    dg = g * 255;
    db = b * 255;

    printf("R: %d, G: %d, B: %d\n", dr, dg, db);
}
