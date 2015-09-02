#include "vector.h"


UIntVector::UIntVector(std::size_t size)
{
    _elements = new unsigned int[size];
}

UIntVector::UIntVector(UIntVector const& other)
{
    _elements = new unsigned int[other.size()];

    for (unsigned int i = 0; i < _size; ++i)
        _elements[i] = other[i];
}

UIntVector::UIntVector(std::initializer_list<unsigned int>)
{
}

UIntVector::~UIntVector()
{
    delete [] _elements;
}

unsigned int& UIntVector::operator[](int x)
{
}

const unsigned int& UIntVector::operator[](int x) const
{
}

UIntVector& UIntVector::operator=(UIntVector const& UIntVector)
{
}

const void UIntVector::expand(const int size)
{
    std::size_t new_size       = _size + size;
    unsigned int* new_elements = new unsigned int[new_size];

    std::copy(_elements, _elements + _size, new_elements);
    delete [] _elements;

    _elements = new_elements;
    _size = new_size;
}

const std::size_t UIntVector::size() const
{
    return _size;
}

const void UIntVector::reset()
{
    for (unsigned int i = 0; i < _size; ++i)
        _elements[i] = (unsigned int) {};
}
