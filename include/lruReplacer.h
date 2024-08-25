#ifndef LRU_REPLACER_H
#define LRU_REPLACER_H

#include "replacer.h"
#include <list>
#include <unordered_map>

class LRUReplacer : public Replacer {
public:
    LRUReplacer(size_t capacity) : capacity_(capacity) {}

    void AccessPage(int page_id) override {
        auto it = cache_map_.find(page_id);
        if (it != cache_map_.end()) {
            cache_list_.erase(it->second);
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

private:
    size_t capacity_;
    std::list<int> cache_list_;
    std::unordered_map<int, std::list<int>::iterator> cache_map_;
};

#endif // LRU_REPLACER_H
