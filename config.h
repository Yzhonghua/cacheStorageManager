#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>

class Config {
public:
    Config(int cache_size, const std::string& replace_policy)
        : m_cache_size(cache_size), m_replace_policy(replace_policy) {}

    void display() {
        std::cout << "Cache Size: " << m_cache_size << std::endl;
        std::cout << "Replacement Policy: " << m_replace_policy << std::endl;
    }

    int get_cache_size() const { return m_cache_size; }
    std::string get_replace_policy() const { return m_replace_policy; }

private:
    int m_cache_size;
    std::string m_replace_policy;
};

#endif // CONFIG_H
