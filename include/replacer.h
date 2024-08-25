#ifndef REPLACER_H
#define REPLACER_H

class Replacer {
public:
    virtual ~Replacer() {}
    virtual void AccessPage(int page_id) = 0;
    virtual int Evict() = 0;
    virtual void Print() const = 0;
};

#endif // REPLACER_H
