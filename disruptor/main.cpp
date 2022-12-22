#include "dirruptor/spmc.h"
#include "logger.h"
//#include "atomic_disruptor.h"
#include <iostream>

typedef struct {
    char data[128];
    size_t th;
} TestBufferData;


int main() {
    bool init_log = ots::utils::create_logger("test.log", "trace", false, false, false);
    {
        auto page = disruptor::Page("test.store", true);
        page.GetShm();
        auto file_path = page.GetFilePath();
        auto address = page.GetShmDataAddress();
    }

    {
        auto notebook = disruptor::Notebook<TestBufferData>();
        notebook.Init("test", 1024 * 1024 * 1, true, true);
        SPDLOG_INFO("start.");
        for (auto i = 0; i < 1024 * 1024 * 1; i++) {
            TestBufferData t{};
            auto tmp = notebook.OpenData();
            tmp->th = i;
            notebook.Commit();
        }
        SPDLOG_INFO("end.");
    }

    {
        auto notebook = disruptor::Notebook<TestBufferData>();
        notebook.Init("test", 1024 * 1024 * 1, false, false);
        SPDLOG_INFO("start.");
        for (auto i = 0; i < 1024 * 1024 * 1; i++) {
            notebook.WaitFor(i);
            auto ret = notebook.GetData(i);
            std::cout << ret->th << std::endl;
        }
        SPDLOG_INFO("end.");
    }

    {
        auto notebook = disruptor::Notebook<TestBufferData>();
        notebook.Init("test", 1024 * 1024 * 2, true, true);
        SPDLOG_INFO("start.");
        for (auto i = 0; i < 1024 * 1024 * 2; i++) {
            TestBufferData t{};
            //            auto idx = notebook.ClaimIndex();
            auto tmp = notebook.OpenData();
            tmp->th = i;
            notebook.Commit();
        }
        SPDLOG_INFO("end.");
    }

    {
        auto notebook = disruptor::Notebook<TestBufferData>();
        notebook.Init("test", 1024 * 1024 * 2, false, false);
        SPDLOG_INFO("start.");
        for (auto i = 0; i < 1024 * 1024 * 2; i++) {
            notebook.WaitFor(i);
            auto ret = notebook.GetData(i);
            std::cout << ret->th << std::endl;
        }
        SPDLOG_INFO("end.");
    }
    return 0;
}
