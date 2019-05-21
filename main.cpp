#include <sys/types.h>          /* See NOTES */
#include <string>

#include "forkp/general.hpp"
#include "forkp/forkp.hpp"

void taskFu(int id) {
    for (;;){
        std::cout << "Start taskFunc with: " << id << std::endl;
        ::sleep(1);
    }
}

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

    char *args1[] = {(char *) 0 };
    MasterIntance.spawnWorkers("vio", "/home/perceptin/Documents/bingfeng/debug_0507",
    							"/home/perceptin/Documents/bingfeng/debug_0507/run.sh", args1);


    MasterIntance.masterLoop();

    return 0;
}

