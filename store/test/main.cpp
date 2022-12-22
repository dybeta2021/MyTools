#include "logger.h"
#include "store.h"
#include <iostream>
#include <string>

// 测试写入和排序
void test_init() {
    create_logger("test_init.log", "info", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 512, 1024, true, true, 1);

    //writer
    for (int i = 512; i >= 0; i--) {
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
    //    store.ShowCurrentKey();
}

// 测试写入和排序
void test_replace() {
    create_logger("test_replace.log", "info", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 512, 1024, true, true, 1);

    //writer
    for (int i = 512; i >= 0; i--) {
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

    for (int i = 512; i >= 0; i--) {
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

    for (int i = 512; i >= 0; i--) {
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
    //    store.ShowCurrentKey();
}

void test_set() {
    create_logger("test_set.log", "info", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 512, 1024, true, false, 1);

    //writer
    for (int i = 512; i >= 0; i--) {
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
    //    store.ShowCurrentKey();
}

void test_get() {
    create_logger("test_get.log", "trace", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 512, 1024, false, false, 1);
    SPDLOG_DEBUG("123");
    store.ShowCurrentKey();


    for (int i = 0; i < 512; i++) {
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


void test_del() {
    create_logger("test_del.log", "info", false, false, false);
    {
        SPDLOG_INFO("Init");
        ots::skv::Store store;
        store.Init("test.store", 512, 1024, true, true, 1);
        store.ShowCurrentKey();
    }

    {
        SPDLOG_INFO("Set");
        ots::skv::Store store;
        store.Init("test.store", 512, 1024, true, false, 1);
        //writer
        for (int i = 512; i >= 0; i--) {
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
        store.ShowCurrentKey();
    }

    {
        SPDLOG_INFO("Del");
        ots::skv::Store store;
        store.Init("test.store", 512, 1024, true, false, 1);
        //writer
        for (int i = 512; i >= 0; i--) {
            std::string tmp = "test" + std::to_string(i);
            const char *key_data = tmp.c_str();
            const char *value_data = tmp.c_str();
            ots::skv::skv_data key{};
            key.data = (char *) key_data;
            key.length = strlen(key_data);
            ots::skv::skv_data value{};
            value.data = (char *) value_data;
            value.length = strlen(value_data);
            store.Del(key);
            SPDLOG_DEBUG("\n");
        }
        store.ShowCurrentKey();
    }
}


void test_reset_value() {
    create_logger("test_reset_key.log", "info", false, false, false);
    {
        SPDLOG_INFO("Init");
        ots::skv::Store store;
        store.Init("test.store", 512, 32, true, true, 1);
        store.ShowCurrentKey();
    }

    {
        SPDLOG_INFO("Set");
        ots::skv::Store store;
        store.Init("test.store", 512, 32, true, false, 1);
        for (int item = 0; item < 16; item++) {
            SPDLOG_INFO("item: {}.", item);
            {
                for (int i = 511; i >= 0; i--) {
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
                }
            }
        }
        store.ShowCurrentKey();
    }

    {
        SPDLOG_INFO("Get");
        ots::skv::Store store;
        store.Init("test.store", 512, 32, false, false, 1);

        for (int i = 0; i < 512; i++) {
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
    }
}

// 测试sort
int main() {
//    test_init();
//    test_set();
    test_get();
//    test_del();
//    test_reset_value();

//    test_replace();
}
