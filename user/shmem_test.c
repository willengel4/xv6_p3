#include "types.h"
#include "user.h"
#include "param.h"

#define PGSIZE 4096

int main(int argc, char * argv[])
{
    void *ptr;

    ptr = shmem_access(-1);
    if(ptr != NULL)
    {
        printf(1, "test failed\n");
        exit();
    }

    ptr = shmem_access(-100);
    if(ptr != NULL)
    {
        printf(1, "test failed\n");
        exit();
    }

    ptr = shmem_access(4);
    if(ptr != NULL)
    {
        printf(1, "test failed\n");
        exit();
    }

    ptr = shmem_access(100);
    if(ptr != NULL)
    {
        printf(1, "test failed\n");
        exit();
    }

    ptr = shmem_access(2);
    if(ptr == NULL)
    {
        printf(1, "test failed\n");
        exit();
    }

    if(((int)ptr) != USERTOP - PGSIZE*1)
    {
        printf(1, "test failed\n");
        exit();
    }

    ptr = shmem_access(3);
    if(((int)ptr) != USERTOP - PGSIZE*2)
    {
        printf(1, "test failed\n");
        exit();
    }

    ptr = shmem_access(0);
    if(((int)ptr) != USERTOP - PGSIZE*3)
    {
        printf(1, "test failed\n");
        exit();
    }

    ptr = shmem_access(1);
    if(((int)ptr) != USERTOP - PGSIZE*4)
    {
        printf(1, "test failed\n");
        exit();
    }


    char *ptr2;
    int i;

    for(i = 0; i < 4; i++)
    {
        ptr2 = shmem_access(i);
        if(ptr2 == NULL)
        {
            printf(1, "test failed\n");
            exit();
        }

        char c = 'c';
        ptr2[100] = 'c'; //write

        char d = *(ptr2 + 100);

        if(c != d)
        {
            printf(1, "test failed\n");
            exit();          
        }
    }


    exit();
}