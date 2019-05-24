#include "forkp/general.hpp"

#include <unistd.h>
#include <fcntl.h>

#include "forkp/master.hpp"

namespace forkp {


    extern char **exec_main_argv = NULL;

    bool st_feed_watchdog( int src, WorkerStat_Ptr& workstat) {
        char read_buf;

        read(src, &read_buf, 1);
        if (workstat->this_miss_cnt > 0)
            workstat->this_miss_cnt = 0;

        return true;
    }

    bool st_transform_to_fd( int src, int des ) {
        char buff[512];
        int ret = 0;

        while ((ret = read(src, buff, 512)) > 0)
            write(des, buff, ret);

        return true;
    }

    bool st_rename_process(const char* name) {
        if (!name &&  !strlen(name))
            return false;

        if (exec_main_argv && exec_main_argv[0]) {
            BOOST_LOG_T(info) << "Rename original process name! ";
            std::size_t len = strlen(exec_main_argv[0]);
            strncpy(exec_main_argv[0], name, len);

            return true;
        }

        return false;
    }

    int st_make_nonblock(int socket)
    {
        int flags = 0;

        flags = fcntl (socket, F_GETFL, 0);
    	flags |= O_NONBLOCK;
        fcntl (socket, F_SETFL, flags);

        return 0;
    }

}

