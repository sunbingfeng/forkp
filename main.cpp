#include <sys/types.h>          /* See NOTES */
#include <string>

#include <csignal>

#include "forkp/general.hpp"
#include "forkp/forkp.hpp"

bool init_func() {
    std::cout << "User Init Func Called!" << std::endl;
    return true;
}


int main(int argc, char* argv[])
{
    // for change process name
    forkp::exec_main_argv = argv;

    MasterIntance.user_init_register(init_func);

    MasterIntance.userInitProc();

    MasterIntance.masterLoop();

    return 0;
}

