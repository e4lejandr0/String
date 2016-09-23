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
        basic_string(const char* str);
        {
            length_ = std::strlen(ptr);
            capacity_ = length_*2 + 1;
            data_ = new T[capacity_];
            std::strcpy(data_, ptr);
        }
        basic_string(const basic_string& other)
        {
            length_ = other.length_;
            capacity_ = other.capacity_;
            data_ = new T[capacity_];
            std::memcpy(data_, other.data_, length_*sizeof(T));
        }
        basic_string<T>& operator=(const basic_string& rhs)
        {
            basic_string tmp_str = rhs;
            swap(*this, rhs);
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
            return &data_[length+1];
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
        void crop(T* begin, T* end)
        {
            int i = 0;
            length_ = end - begin;
            while(begin != end) {
                data_[i] = *begin;
                ++begin;
            }
            data_[i] = *begin;
        }
        std::vector<string<T>> split(T character)
        {
            std::vector<string<T>> findings;
            //if(char in data_ == character)
            //findgings += character;
            //....
        }
        ~basic_string()
        {

        }
    private:
        std::shared_ptr<data_> data_;
        std::size_t length_;
        std::size_t capacity_;

        static const int START_CAPACITY = 30; 

    }
}

#endif
