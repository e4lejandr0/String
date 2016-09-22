#include <cstring>
#include <cctype>

#include "include/String.h"

#include <iostream>

#define SMALL_STRING_LENGTH 31

namespace ea
{
    String::String(const char* str)
    {
        if(str != nullptr) {
            try {
                length_ = strlen(str);
                capacity_ = length_ + 1;
                data_ = new char[capacity_];
                strcpy(data_, str);
            }
            catch(std::exception& e) {
                throw;
            }
        }
        else {
            capacity_ = SMALL_STRING_LENGTH;
            data_ = new char[capacity_];
            length_ = 0;
        }
    }
    String::String(const String& other)
    {
        try{
            length_ = other.length_;
            capacity_ = other.capacity_;
            data_ = new char[capacity_];
            strcpy(data_, other.data_);
        }
        catch(std::exception& e) {
            throw;
        }
    }
    std::size_t String::length() const
    {
        return length_;
    }
    const char* String::c_str() const
    {
        return data_;
    }
    void String::resize(std::size_t new_size)
    {
        if(new_size > length_) {
            try {
                char* tmp_buf = new char[new_size+1];
                tmp_buf[new_size] = '\0';
                strcpy(tmp_buf, data_);
                delete[] data_;
                data_ = tmp_buf;
                capacity_ = new_size;
            }
            catch(std::exception& e) {
                throw;
            }
        }
    }
    void String::swap(String& first, String& second)
    {
        char* tmp_data = first.data_;
        std::size_t tmp_length = first.length_;
        std::size_t tmp_capacity = first.capacity_;
        first.data_ = second.data_;
        first.length_ = second.length_;
        first.capacity_ = second.capacity_;
        second.data_ = tmp_data;
        second.length_ = tmp_length;
        second.capacity_ = tmp_capacity;
    }
    String& String::operator=(const String& other)
    {
        String tmp_str = other;
        swap(*this, tmp_str);
    }
    String::~String()
    {
        delete[] data_;
    }
    
    std::ostream& operator<<(std::ostream& stream, const String& string)
    {
        stream << string.c_str(); //this might not be strictly null-terminated
        return stream;
    }
    String operator+(const String& lhs, const String& rhs)
    {
        String ret_str;
        ret_str.data_ = new char[lhs.length_ + rhs.length_ + 1];
        ret_str.data_[0] = '\0';
        if(lhs.data_) {
            strcpy(ret_str.data_, lhs.data_);
        }
        if(rhs.data_) {
            strcat(ret_str.data_, rhs.data_);
        }
        ret_str.length_ = ret_str.capacity_ = lhs.length_ + rhs.length_ + 1;
        return ret_str;
    }
    String& operator+=(String& lhs, const String& rhs)
    {
        lhs = lhs + rhs;
        return lhs;
    }
}
