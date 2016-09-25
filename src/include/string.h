#include <vector>
#include <memory>
#include <cstring>
#include <algorithm>

#ifndef EA_STRING_H
#define EA_STRING_H


namespace ea 
{
    template<typename T>
    class basic_string
    {
    public:
        basic_string()
            :
            data_(new T[START_CAPACITY]),
            length_(0),
            capacity_(START_CAPACITY)
        {

        }
        basic_string(const char* str)
        {
            length_ = std::strlen(str);
            capacity_ = length_*2 + 1;
            data_ = new T[capacity_];
            std::strcpy(data_, str);
        }
        basic_string(const basic_string& other)
        {
            length_ = other.length_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            std::memcpy(data_, other.data_, length_*sizeof(T));
        }
        basic_string<T>& operator=(basic_string rhs)
        {
            swap(*this, rhs);
            return *this;
        }
        const T* find_first_not_of(T character) const
        {
            auto current = begin();
            while(*current != character) {
                ++current;
            }
            return current;
        }
        const T* find_last_not_of(T character) const
        {
            auto current = end()-1;
            while(*current != character) {
                ++current;
            }
            return current;
        }
        const T* begin() const
        {
            return &data_[0];
        }
        const T* end() const
        {
            return &data_[length_+1];
        }
        void trim()
        {
            auto start = find_first_not_of(' ');
            auto finish = find_last_not_of(' ');
            length_ = finish - start;
            for(int i = 0; start != finish + 1; ++start) {
                data_[i] = *start;
            }
        }
        void crop(const T* begin, const T* end)
        {
            int i = 0;
            length_ = end - begin;
            while(begin != end) {
                data_[i] = *begin;
                ++begin;
            }
            data_[i] = *begin;
        }
        std::vector<basic_string<T>> split(T character)
        {
            std::vector<basic_string<T>> findings;
            //if(char in data_ == character)
            //findings += character;
            //....
        }
        static void swap(ea::basic_string<T>& first, ea::basic_string<T>& second)
        {
            std::swap(first.data_, second.data_);
            std::swap(first.length_, second.length_);
            std::swap(first.capacity_, second.capacity_);
        }
        ~basic_string()
        {
            delete[] data_;
        }
    private:
        T* data_;
        std::size_t length_;
        std::size_t capacity_;

        static const int START_CAPACITY = 30; 
    };
}

template<typename T>
std::ostream& operator<<(std::ostream& str, const ea::basic_string<T>& string)
{
    for(auto i = string.begin(); i != string.end(); ++i) {
        str << *i;
    }
}

std::istream& operator>>(std::istream& str, ea::basic_string<char>& string)
{
    return str;
}

#endif
