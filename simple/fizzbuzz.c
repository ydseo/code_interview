/* 1부터 100 까지 3의 배수는 fizz 5의 배수는 buzz 둘 다 해당하는 경우 fizz buzz를 출력하는 프로그램을 작성 */


#include <stdio.h>

int main() {

	int i;
	for(i=1; i<=100; i++) {
		
		if((i % 15) == 0) {
			printf("fizz buzz ");
		}
		else if((i % 3) == 0) {
			printf("fizz ");
		} else if((i % 5) == 0) {
			printf("buzz ");
		} else {
			printf("%d ", i);
		}

	}

	return 0;
}

