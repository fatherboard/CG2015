#include <stdio.h>
#include <stdlib.h>

int okLimits(int num){
    if(num >= 0 && num <= 255)
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]){

    int r = -1, g = -1, b = -1, input = 1;

    printf("Convert 0-255 to 0-1\n");

    if(argc >= 4){
        input = 0;
        r = atoi(argv[1]);
	g = atoi(argv[2]);
	b = atoi(argv[3]);
	if(!okLimits(r) || !okLimits(g) || !okLimits(b)){
	    r = -1; g = -1; b = -1;
	    input = 1;
	}
    }

    if(input){
    	while(!okLimits(r)){
       	    printf("RED: ");
	    scanf("%d", &r);
        }
	while(!okLimits(g)){
	    printf("GREEN: ");
	    scanf("%d", &g);
	}
	while(!okLimits(b)){
	    printf("BLUE: ");
	    scanf("%d", &b);
	}
    }

    float fr, fg, fb;

    fr = (float) ((float) r / (float) 255);
    fg = (float) ((float) g / (float) 255);
    fb = (float) ((float) b / (float) 255);

    printf("R: %.02f, G: %.02f, B: %.02f\n", fr, fg, fb);
}
