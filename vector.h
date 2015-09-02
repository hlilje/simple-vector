#include <algorithm>
#include <cstddef>
#include <initializer_list>


class UIntVector
{
    private:
        unsigned int* _elements;
        std::size_t _size; // Actual internal container size
        std::size_t _num_elements;

        const void expand(const int);
    public:
        UIntVector(std::size_t);

        UIntVector(const UIntVector&);

        UIntVector(UIntVector&&);

        UIntVector(std::initializer_list<unsigned int>);

        ~UIntVector();


        unsigned int& operator[](int x);

        const unsigned int& operator[](int x) const;

        UIntVector& operator=(const UIntVector& UIntVector);

        UIntVector& operator=(UIntVector&&);


        const std::size_t size() const;

        const void reset();

        const void add(const unsigned int x);
};
