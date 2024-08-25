#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include <iostream>
#include "include/replacer.h"

class BufferManager {
public:
    BufferManager(size_t cache_size, Replacer* replacer)
        : cache_size_(cache_size), replacer_(replacer) {
        std::cout << "Buffer Manager initialized with cache size: " 
                  << cache_size_ << std::endl;
    }

    ~BufferManager() {
        delete replacer_;
    }

    void LoadPage(int page_id) {
        std::cout << "Loading page " << page_id << std::endl;

        // 使用 replacer_ 检查和管理页面
        replacer_->AccessPage(page_id);
        std::cout << "Page " << page_id << " loaded into cache." << std::endl;
    }

private:
    size_t cache_size_;
    Replacer* replacer_;
};

#endif // BUFFER_MANAGER_H
