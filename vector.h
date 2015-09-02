#include <cstddef>
#include <initializer_list>


class UIntVector
{
    private:
        unsigned int* _elements;
        std::size_t _size;
    public:
        UIntVector(std::size_t);

        UIntVector(UIntVector const&);

        UIntVector(std::initializer_list<unsigned int>);

        ~UIntVector();


        unsigned int& operator[](int x);

        const unsigned int& operator[](int x) const;

        UIntVector& operator=(UIntVector const& UIntVector);


        std::size_t size();

        void reset();
};
