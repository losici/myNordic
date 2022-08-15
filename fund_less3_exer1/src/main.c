#include <zephyr.h>
#include <sys/printk.h>
#include "myfunction.h"


#define SLEEP_TIME_MS 1000

void main(void)
{
    int a = 3,  b = 4;
    while(1)
    {
        printk("The sum of %d and %d is %d\n\r", a, b, sum(a,b));
        k_msleep(SLEEP_TIME_MS);
    }
}