#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include <iostream>
#include <unordered_map>

class StorageManager {
public:
    StorageManager(size_t storage_size) : storage_size_(storage_size) {
        std::cout << "Storage Manager initialized with storage size: " 
                  << storage_size_ << std::endl;
    }

    void WritePage(int page_id, const std::string& data) {
        storage_[page_id] = data;
        std::cout << "Page " << page_id << " written to storage." << std::endl;
    }

    std::string ReadPage(int page_id) {
        if (storage_.find(page_id) != storage_.end()) {
            std::cout << "Page " << page_id << " read from storage." << std::endl;
            return storage_[page_id];
        } else {
            std::cerr << "Page " << page_id << " not found in storage." << std::endl;
            return "";
        }
    }

private:
    size_t storage_size_;
    std::unordered_map<int, std::string> storage_;
};

#endif // STORAGE_MANAGER_H
