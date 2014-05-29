#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <time.h>
#include <windows.h>

#define MAXSIZE 1024

struct Message
{
	int num_2bit;
	int num_4bit;
	char buf[MAXSIZE];
	int checksum;
};

int main()
{
    struct Message message;
    srand(time(NULL));
    int n = rand()*255/RAND_MAX;
    message.num_2bit = rand()*n/RAND_MAX;
    message.num_4bit = n-message.num_2bit;

    printf("%d,%d\n",message.num_2bit, message.num_4bit);

    message.checksum = 0;

    int i,sum;

    for(i=0; i<message.num_2bit; i++)
    {
        int temp = rand()*65535/RAND_MAX;
        //printf("%d\n",temp);
        message.buf[i<<1] = temp;
        message.buf[i<<1|1] = temp>>8;
    }

    for(i=0; i<message.num_4bit; i++)
    {
        double temp = (double)rand()*0x7fffffff/RAND_MAX;
        message.buf[message.num_2bit*2+i*4] = (int)temp;
        message.buf[message.num_2bit*2+i*4+1] = (int)temp>>8;
        message.buf[message.num_2bit*2+i*4+2] = (int)temp>>16;
        message.buf[message.num_2bit*2+i*4+3] = (int)temp>>24;
    }

    for(i=0; i<message.num_2bit; ++i)
    {
        sum += (int)message.buf[i<<1];
        sum += (int)message.buf[i<<1|1]*256;
    }
    for(i=0; i<message.num_4bit; ++i)
    {
        sum += (int)message.buf[message.num_2bit*2+i*4];
        sum += (int)message.buf[message.num_2bit*2+i*4+1]*256;
        sum += (int)message.buf[message.num_2bit*2+i*4+2]*256*256;
        sum += (int)message.buf[message.num_2bit*2+i*4+3]*256*256*256;
    }

    printf("%d",sum);

    return 0;
}

