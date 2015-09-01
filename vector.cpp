#include "vector.h"


UIntVector::UIntVector()
{

}

UIntVector::UIntVector(UIntVector const&)
{
}

UIntVector::UIntVector(std::size_t)
{
}

UIntVector::UIntVector(std::initializer_list<unsigned int>)
{
}

UIntVector::~UIntVector()
{
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
}
