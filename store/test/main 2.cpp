#include "logger.h"
#include "store.h"
#include <iostream>
#include <string>

struct TickData{
    char symbol[64];
    double price;
    int volume;
};

// 测试写入和排序
void test_init() {
    create_logger("test_init.log", "info", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 12, 1024, true, true, 1);
}

// 测试写入和排序
void test_set() {
    create_logger("test_set_insert_replace.log", "trace", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 12, 1024, true, false, 1);

    TickData tick_1{}, tick_2{}, tick_3{};
    TickData *tick_ptr_ = nullptr;
    tick_1.volume = 1;
    tick_2.volume = 2;
    tick_3.volume = 3;
    strcpy(tick_1.symbol,  "test1");
    strcpy(tick_2.symbol,  "test2");
    strcpy(tick_3.symbol,  "test3");

    SPDLOG_INFO("set");
    {
        tick_ptr_ = &tick_1;
        ots::skv::skv_data skv_key{}, skv_value{};
        skv_key.data = tick_ptr_->symbol;
        skv_key.length = strlen(tick_ptr_->symbol);
        skv_value.data = (char*)tick_ptr_;
        skv_value.length = sizeof(TickData);

        SPDLOG_INFO("set:{}", store.Set(skv_key, skv_value));
    }
    store.ShowCurrentKey();

    SPDLOG_INFO("get");
    {
        tick_ptr_ = &tick_1;
        ots::skv::skv_data skv_key{}, skv_value{};
        skv_key.data = tick_ptr_->symbol;
        skv_key.length = strlen(tick_ptr_->symbol);

        SPDLOG_INFO("get:{}", store.Get(skv_key, skv_value));
        auto ptr = (TickData*)skv_value.data;
        std::cout<<ptr->symbol<<"--"<<ptr->volume<<std::endl;
    }
}



// 测试写入和排序
void test_get() {
    create_logger("test_set_insert_replace.log", "trace", false, false, false);
    ots::skv::Store store;
    store.Init("test.store", 12, 1024, false, false, 1);

    TickData tick_1{}, tick_2{}, tick_3{};
    TickData *tick_ptr_ = nullptr;
    tick_1.volume = 1;
    tick_2.volume = 2;
    tick_3.volume = 3;
    strcpy(tick_1.symbol,  "test1");
    strcpy(tick_2.symbol,  "test2");
    strcpy(tick_3.symbol,  "test3");

    SPDLOG_INFO("get");
    {
        tick_ptr_ = &tick_1;
        ots::skv::skv_data skv_key{}, skv_value{};
        skv_key.data = tick_ptr_->symbol;
        skv_key.length = strlen(tick_ptr_->symbol);

        SPDLOG_INFO("get:{}", store.Get(skv_key, skv_value));
        auto ptr = (TickData*)skv_value.data;
        std::cout<<ptr->symbol<<"--"<<ptr->volume<<std::endl;
    }
}


// 测试sort
int main() {
    test_init();
    test_set();
    test_get();
}
