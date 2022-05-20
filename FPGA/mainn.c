#define TERMINAL "/dev/ttyPS0"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/mman.h>
#include <math.h>
#include <time.h>

int num1[255];
int num2[255];
int i;

int main()
{
    unsigned int gpio_size = 0x8000;
    off_t gpio_pbase = 0x41200000;
    long long *gpio64_vptr;
    long long *bram64_vptr;
    int fd2;

    char *portname = TERMINAL;
    int fd;
    int wlen;
    char *xstr = "Hesaplanacak degerleri giriniz: \n";
    int xlen = strlen(xstr);
    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0)
    {
        printf("Error opening %s: %s\n", portname, strerror(errno));
        return -1;
    }
    wlen = write(fd, xstr, xlen);
    if (wlen != xlen)
    {
        printf("Error from write: %d, %d\n", wlen, errno);
    }

    do
    {
        unsigned char buf[80];
        int rdlen;

        rdlen = read(fd, buf, sizeof(buf) - 1);
        if (rdlen > 0)
        {

            buf[rdlen] = 0;
            printf("%s \n", buf);

            int flag = 0;
            for (i = 0; i < strlen(buf); i++)
            {
                if (buf[i] == ' ')
                {
                    flag = 1;
                }
                else
                {
                    if (flag == 0)
                    {
                        num1[i] = buf[i] - '0';
                    }
                    else
                    {
                        num2[i] = buf[i] - '0';
                    }
                }
            }
            int val1 = num1[1] + num1[0] * 10;
            int val2 = num2[4] + num2[3] * 10;

            if ((fd2 = open("/dev/mem", O_RDWR | O_SYNC)) != -1)
            {
                gpio64_vptr = (long long *)mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, gpio_pbase);
                *(gpio64_vptr) = val1;
                *(gpio64_vptr + 1) = val2;

                int pres = *(gpio64_vptr + 1);
                printf("%d \n:", pres);

                char res[20];
                sprintf(res, "%d", pres);
                int reslen = strlen(res);
                write(fd, res, reslen);

                close(fd2);
            }
        }
        else if (rdlen < 0)
        {
            printf("Error from read: %d: %s\n", rdlen, strerror(errno));
        }
        else
        { /* rdlen == 0 */
            printf("Timeout from read\n");
        }

    } while (1);
}
