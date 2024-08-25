#include <iostream>
#include "config.h"
#include "bufferManager.h"
#include "storageManager.h"
#include "include/lruReplacer.h"

void Usage() {
    std::cout << "Usage: ./CacheStorageManager <replacement_policy>" << std::endl;
}

int main(int argc, char* argv[]) {
    std::cout << "Cache Storage Manager - C++ version" << std::endl;

    if (argc != 2) { 
        Usage();
        return 1;
    }

    std::string replace_policy = argv[1];
    Config config(1024, replace_policy);
    config.display();

    Replacer* replacer = nullptr;
    if (replace_policy == "LRU") {
        replacer = new LRUReplacer(config.get_cache_size());
    } else {
        std::cout << "Unsupported replacement policy" << std::endl;
        return 1;
    }

    BufferManager bufferManager(config.get_cache_size(), replacer);
    StorageManager storageManager(config.get_cache_size());

    // Simulate loading pages and interacting with storage
    storageManager.WritePage(1, "Page 1 Data");
    storageManager.WritePage(2, "Page 2 Data");

    bufferManager.LoadPage(1);
    bufferManager.LoadPage(2);
    bufferManager.LoadPage(3);
    bufferManager.LoadPage(1);  // This should hit in cache
    bufferManager.LoadPage(4);  // This should cause an eviction if cache size is 3
    bufferManager.LoadPage(4);

    bufferManager.printStatistics();

    return 0;
}
