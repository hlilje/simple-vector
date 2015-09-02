#include "vector.h"
#include <stdexcept>


UIntVector::UIntVector(std::size_t size)
{
    _elements = new unsigned int[size];
}

UIntVector::UIntVector(UIntVector const&)
{
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
    if (x < 0)
        throw std::out_of_range("negative index");
    else if ((unsigned int) x >= _size)
        throw std::out_of_range("index larger than vector size");
    return _elements[x];
}

const unsigned int& UIntVector::operator[](int x) const
{
    if (x < 0)
        throw std::out_of_range("negative index");
    else if ((unsigned int) x >= _size)
        throw std::out_of_range("index larger than vector size");
    return _elements[x];
}

UIntVector& UIntVector::operator=(UIntVector const& UIntVector)
{
    return *this;
}

std::size_t UIntVector::size()
{
    return _size;
}

void UIntVector::reset()
{
    for (unsigned int i = 0; i < _size; ++i)
        _elements[i] = (unsigned int) {};
}
