#include <stdio.h>
int main(void){
	printf("__STDC_VERSION__ = %ld\n", __STDC_VERSION__);
	int a=0;
    if(a++<1&&a++>0&&a++<3)
    	printf("True: %d\n", a);
    else
    	printf("False: %d\n", a);
    return 0;
}