#include <sys/types.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "ndelay.h"
#include "socket.h"

int
socket_udp (void)
{
    int s = 0;

    s = socket (AF_INET, SOCK_DGRAM, 0);
    if (s == -1)
        return -1;
    if (ndelay_on (s) == -1)
    {
        close (s);
        return -1;
    }

    return s;
}
