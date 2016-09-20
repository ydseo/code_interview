/* main thread는 1부터 MAX까지 세고, 싱글 스레드가 1/3, 2/3 지점에 step을 바꿔가면서 그 때의 count 값을 함께 출력하며 관찰함 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000000000

int flag;
int count;


void *scan(void *data) {
	int id;
	int i = 0;
	id = *((int *)data);

	while(1) {
		i++;
		if(flag == 0) {
			printf("1st step : %d \n", count);
			sleep(1);
		}
		else if(flag == 1) {
			printf("2nd step : %d \n", count);
			sleep(1);
		}
		else {
			printf("final step : %d \n", count);
			break;
		}
	}

}


int main() {
	flag = 0;
	count = 0;
	int i;
	int thread_id;
	int data = 100;
	pthread_t single_thread;

	thread_id = pthread_create(&single_thread, NULL, scan, (void *)&data);
	if(thread_id < 0) {
		perror("thread create error : ");
		exit(0);
	}

	for(i=0; i<MAX; i++) {
		count++;
		if(i == MAX/3)
			flag = 1;
		else if(i == (MAX/3 * 2))
			flag = 2;
	}
	return 0;
}
