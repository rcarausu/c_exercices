#include <stdio.h>
#include <string.h>

/* Write the functon htoi(s) which converts a string of hex digits (including an optional 0x or 0X) into
   its equivalent integer value.
   The allowable digits are 0 through 9, a thorugh f, and A through F.
 */

char char_to_uppercase(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 32;	
	}
	return c;
}

int power(int num, int p) {
	int res = 1;
	int i = 0;
	while (i < p) {
		res = res * num;
		i++;
	}
	return res;
}
	

int hex_to_digit(char c) {
	int i = 0;
	char hex_string[] = "0123456789ABCDEF";
	while (i < strlen(hex_string)) {
		if (char_to_uppercase(c) == hex_string[i]) {
			return i;
		}
		i++;
	}
	return -1;
}

int htoi(char hex_string[]) {
	int i = 0;
	int count = 0;
	int num = 0;
	int digit = 0;
		
	// skipping hex 0X and 0x initialization
	if (hex_string[i] == '0' && (char_to_uppercase(hex_string[i+1]) == 'X')) {
		i = i + 2;		
	}
	count = strlen(hex_string) - i - 1;
	while (i < strlen(hex_string)) {
		digit = hex_to_digit(hex_string[i]);
		if (digit != -1) {
			num = num + (digit * power(16, count));
			count--;
			i++;
		} else {
			printf("%s is not a correct hex string\n", hex_string);
			return -1;	
		}			
	} 
	return num;
}

void main() {
	printf("testing 0xFF, expected is 255, result is: %d\n", htoi("0xFF"));
	printf("testing Ab04, expected is 43780, result is: %d\n", htoi("Ab04"));
	printf("testing bad_string, expected is -1, result is: %d\n", htoi("bad_string"));
}
