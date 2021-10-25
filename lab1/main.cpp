#include "daemon.h"

int main(int argc, char** argv) 
{
    if (argc != 2)
    {
        return -1;
    }

    if (!daemon::startDaemonization(argv[1]))
        return -1;

    return 0;
}
