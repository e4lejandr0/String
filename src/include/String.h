#ifndef EA_STRING_H
#define EA_STRING_H

#include <iostream>

namespace ea
{
    class String
    {
    public:
        String(const char* str = nullptr);
        String(const String& other);
        std::size_t length() const;
        const char* c_str() const;
        static void swap(String& first, String& second);
        String& operator=(const String& other);
        virtual ~String();
        friend String operator+(const String& lhs, const String& rhs);
    private:
        char* data_;
        std::size_t length_;
        std::size_t capacity_;
        void resize(std::size_t new_size);
    };
    std::ostream& operator<<(std::ostream& stream, const String& string);
    String operator+(const String& lhs, const String& rhs);
    String& operator+=(String& lhs, const String& rhs);
}
#endif
