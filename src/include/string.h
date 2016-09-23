#ifndef EA_STRING_H
#define EA_STRING_H


namespace ea 
{
    template<typename T>
    class basic_string
    {
    public:
        basic_string();
        basic_string(const char* str);
        basic_string(const basic_string& other);
        basic_string& opertor=(const basic_string& rhs);
        std::vector<basic_string> find(const basic_string& pattern) const;  
        template<typename T>
        const T* begin() const
        const T* end() const;
        void trim();
        void crop(basic_string::iterator& begin, basic_string::iterator end);
        ~basic_string();
    private:
        std::shared_ptr<data_> data_;
        std::size_t length_;
        std::size_t capacity_;

        static const int START_CAPACITY = 30; 

    }
}

#endif
