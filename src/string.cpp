#include "include/string.h"

namespace ea
{
    template<typename T>
    basic_string<T>::basic_string<T>()
        :
        data_(new T[data]),
        length_(0),
        capacity(START_CAPACITY)
    {
    }
    template<typename T>
    basic_string<T>::basic_string<T>(const char* ptr)
    {
        length_ = std::strlen(ptr);
        capacity_ = length_*2 + 1;
        data_ = new T[capacity_];
        std::strcpy(data_, ptr);
    }
    template<typename T>
    basic_string<T>::basic_string<T>(const basic_string<T>& other)
    {
        length_ = other.length_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        std::memcpy(data_, other.data_, length_*sizeof(T));
    }
    template<typename T>
    basic_string<T>::basic_string<T>& operator=(const basic_string& rhs)
    {
        basic_string tmp_str = rhs;
        swap(*this, rhs);
    }
    template<typename T>
    std::vector<basic_string<T>> find(const basic_string<T>& pattern) const
    {
        std::vector<basic_string<T>> findings;
        for(int i = 0; i < length_; ++i)
        {
            if(data_[i] == pattern[0]) {
                basic_string<T> found;
                for(int j = 0; j < pattern.length(); ++j) {
                    found += data_[j];
                }
                if(!found.empty()) {
                    findings.push_back(found);
                }
            }
        }
        return findings;
    }  
    template<typename T>
    const T* begin() const
    {
        return &data_[0];
    }
    template<typename T>
    const T* end() const
    {
        return &data_[length+1];
    }
    template<typename T>
    void basic_string<T>::trim()
    {
        int space_count = 0;
        auto current = begin();
        while(*current == ' ') {
            ++space_count;
        }
        while(*current != '')
        length_ = strlen(begin() + clean.length+1);
    }
    void crop(basic_string::iterator& begin, basic_string::iterator end);
    ~basic_string();
}
