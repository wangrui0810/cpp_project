#include "Thread.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


void *threadFunc(void *arg)
{
	time_t now;
	while(1)
	{
		now = time(NULL);
		sleep(0.01);
		cout << "Sub Thread" << ctime(&now) << endl;
	}
}


int main(int argc, const char *argv[])
{
	time_t now;
    Thread t(threadFunc);
    t.start();
	while(1)
	{
		now = time(NULL);
		sleep(0.01);
		cout << "Main Thread" << ctime(&now) << endl;
	}
    t.join();
    return 0;
}
