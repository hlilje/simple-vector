#include <cstddef>
#include <initializer_list>


class UIntVector
{
    private:
        std::size_t _size;
    public:
        UIntVector();

        UIntVector(UIntVector const&);

        UIntVector(std::size_t);

        UIntVector(std::initializer_list<unsigned int>);

        ~UIntVector();


        unsigned int& operator[](int x);

        const unsigned int& operator[](int x) const;

        UIntVector& operator=(UIntVector const& UIntVector);


        void reset();

        std::size_t size();
};
