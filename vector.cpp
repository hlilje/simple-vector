#include "vector.h"


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
}

const unsigned int& UIntVector::operator[](int x) const
{
}

UIntVector& UIntVector::operator=(UIntVector const& UIntVector)
{
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
