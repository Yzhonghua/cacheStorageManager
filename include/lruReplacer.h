#ifndef LRU_REPLACER_H
#define LRU_REPLACER_H

#include "replacer.h"
#include <list>
#include <unordered_map>

class LRUReplacer : public Replacer {
public:
    LRUReplacer(size_t capacity) : capacity_(capacity) {}

    void AccessPage(int page_id) override {
        total_++;
        auto it = cache_map_.find(page_id);
        if (it != cache_map_.end()) {
            hits_++;
            cache_list_.erase(it->second);
        } else {
            misses_++;
        }
        cache_list_.push_front(page_id);
        cache_map_[page_id] = cache_list_.begin();

        if (cache_map_.size() > capacity_) {
            int last = cache_list_.back();
            cache_list_.pop_back();
            cache_map_.erase(last);
        }
    }

    int Evict() override {
        if (cache_list_.empty()) return -1;
        int last = cache_list_.back();
        cache_list_.pop_back();
        cache_map_.erase(last);
        return last;
    }

    void Print() const override {
        std::cout << "Total Requests: " << total_ << std::endl;
        std::cout << "Cache Hits: " << hits_ << std::endl;
        std::cout << "Cache Misses: " << misses_ << std::endl;
        if (total_ > 0) {
            std::cout << "Hits Rate: " << (static_cast<double>(hits_) / total_) * 100 << "%" << std::endl;
        } else {
            std::cout << "No requests made, no hit rate to report." << std::endl;
        }
    }

private:
    size_t capacity_;
    std::list<int> cache_list_;
    std::unordered_map<int, std::list<int>::iterator> cache_map_;

private:
    int total_{0};
    int hits_{0};
    int misses_{0};
};

#endif // LRU_REPLACER_H
