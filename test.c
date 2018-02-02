// just testing shit out
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	char* str = "9a99 9999 9999 0140";
	char* str2 = "0000 0000 0000 e03f";
	char* str3 = "840 532";
	char* str4 = "0000000000802140 0000000000000000";// 9a99 9999 9999 e93f";
	char *end;
	double output;
	double n = atol(str3);
	double m = strtod(str3, &end);
	printf("Test different codes.\n");
	printf("String: %s \n",str4);
	printf("%lf \n",n);
	printf("%lf \n",m);
	return 0;
}