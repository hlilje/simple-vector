#include <algorithm>
#include <cstddef>
#include <initializer_list>

#define BASE_SIZE 100 // Minimum size of array when adding elements


class UIntVector
{
    private:
        unsigned int* _elements;
        std::size_t _size; // Actual internal container size
        std::size_t _num_elements;

        const void expand(const int);
    public:
        UIntVector(std::size_t);

        UIntVector(UIntVector const&);

        UIntVector(std::initializer_list<unsigned int>);

        ~UIntVector();


        unsigned int& operator[](int x);

        const unsigned int& operator[](int x) const;

        UIntVector& operator=(UIntVector const& UIntVector);


        const std::size_t size() const;

        const void reset();

        const void add(const unsigned int x);
};
