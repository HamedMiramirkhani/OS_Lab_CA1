#include "types.h"
#include "user.h"
#include "fcntl.h"

void tostring(char str[], int num)
{
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void mode(int arr[],int n,int fd) {
    int minValue = 0, maxCount = 0, i, j;
    char buf[512];

    for (i = 0; i < n; ++i) {
        int count = 0;

        for (j = 0; j < n; ++j) {
            if (arr[j] == arr[i])
                ++count;
        }

        if (count > maxCount) {
            maxCount = count;
            minValue = arr[i];
        }
        if (count == maxCount && arr[i] < minValue){
            minValue = arr[i];
        }
    }
    tostring(buf,minValue);
    write(fd, buf,strlen(buf));
    write(fd,"\n",1);

}

void median(int arr[],int i,int fd){
    char buf[512];
    int t;
    int result;

    for (int f = 0; f < i - 1; f++)
    {
        for (int j = 0; j < i - f - 1; j++)
        {
            if(arr[j] > arr[j + 1]){
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }

    if (i % 2  == 0)
    {
        result = (arr[(i/2)-1] + arr[i/2])/2;
    }
    else
    {
        result = arr[(i-1)/2];
    }
    tostring(buf,result);
    write(fd, buf,strlen(buf));
    write(fd," ",1);
}

void avrage(int arr[],int i,int fd) {
    int avg = 0;
    char buf[512];
    for (int j = 0; j < i; j++) {
        avg += arr[j];
    }
    tostring(buf,avg/ i);
    write(fd, buf,strlen(buf));
    write(fd," ",1);
}

int main(int argc, char *argv[]){

    unlink("mmm_result.txt");
    if(argc > 8)
    {
        printf(1,"%s \n","The limit on length of numbers has exceeded");
        exit();
    }
    int buf[argc-1];
    for(int i=0; i<argc-1; i++)
    {
        buf[i] = atoi(argv[i+1]);
    }
    int fd = open("mmm_result.txt",O_CREATE | O_RDWR);
    avrage(buf,argc-1,fd);
    median(buf,argc-1,fd);
    mode(buf,argc-1,fd);
    close(fd);
    exit();
}