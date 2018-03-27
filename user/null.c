#include "types.h"
#include "user.h"

int main(int argc, char * argv[])
{
    int *p = 0;
    printf(1, "This null pointer dereference should fail.\n");
    printf(1, "P = ", *p);
    exit();
}