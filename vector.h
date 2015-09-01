#include <cstddef>


class UIntVector
{
    private:
        std::size_t _size;
    public:
        UIntVector();

        UIntVector(UIntVector const&);

        UIntVector(std::size_t);

        UIntVector(std::initializer_list);

        UIntVector(UIntVector);

        ~UIntVector();

        int& operator[](int x);

        unsigned int& operator[](int x);

        const unsigned int& operator[](int x) const;

        UIntVector& operator=(A const& UIntVector);

        void reset();

        std::size_t size();
};
