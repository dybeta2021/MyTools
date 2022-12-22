#include "logger.h"
#include "store.h"
#include <iostream>
#include <string>

// 测试写入和排序
void test_init() {
    create_logger("test_init.log", "info", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 12, 16, true, true, 1);
}

// 测试写入和排序
void test_set_insert_replace() {
    create_logger("test_set_insert_replace.log", "trace", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 12, 16, true, false, 1);

    //writer
    for (int i = 0; i<16; i++) {
        std::string tmp = "test" + std::to_string(i);
        const char *key_data = tmp.c_str();
        const char *value_data = tmp.c_str();
        ots::skv::skv_data key{};
        key.data = (char *) key_data;
        key.length = strlen(key_data);
        ots::skv::skv_data value{};
        value.data = (char *) value_data;
        value.length = strlen(value_data);
        store.Set(key, value);
        SPDLOG_DEBUG("\n");
    }

    //writer
    for (int i = 16; i>0; i--) {
        std::string tmp = "test" + std::to_string(i);
        const char *key_data = tmp.c_str();
        const char *value_data = tmp.c_str();
        ots::skv::skv_data key{};
        key.data = (char *) key_data;
        key.length = strlen(key_data);
        ots::skv::skv_data value{};
        value.data = (char *) value_data;
        value.length = strlen(value_data);
        store.Set(key, value);
        SPDLOG_DEBUG("\n");
    }
}



void test_get() {
    create_logger("test_get.log", "info", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 512, 1024, false, false, 1);

    for (int i = 0; i < 16; i++) {
        std::string tmp = "test" + std::to_string(i);
        const char *key_data = tmp.c_str();
        ots::skv::skv_data key{};
        key.data = (char *) key_data;
        key.length = strlen(key_data);
        ots::skv::skv_data value{};
        const auto ret = store.Get(key, value);
        if (ret == 0) {
            std::cout << "i: " << i << ", key: " << key.data << ", value: " << value.data << std::endl;
        }
        SPDLOG_DEBUG("\n");
    }
    //    store.ShowCurrentKey();
}


// 测试sort
int main() {
//    test_init();
//    test_set_insert_replace();
    test_get();
}
