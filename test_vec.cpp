#include <iostream>
#include <stdexcept>
#include <cxxtest/TestSuite.h>
#include "vector.h"


class VectorTestSuite : public CxxTest::TestSuite {
    public:
        /**
         * Test constructors for initialisation.
         */
        void test_init()
        {
            UIntVector a(0);
            TS_ASSERT(a.size() == 0);
            UIntVector b(1);
            TS_ASSERT(b.size() == 1);
            UIntVector c(123);
            TS_ASSERT(c.size() == 123);

            UIntVector d(c);
            TS_ASSERT(d.size() == c.size());
            UIntVector e = c;
            TS_ASSERT(e.size() == c.size());
        }

        /**
         * From test_vec.cpp
         */
        void test_old()
        {
            // Några saker som ska fungera:
            UIntVector a(7);           // initiering med 7 element
            UIntVector b(a);           // kopieringskonstruktor 
            UIntVector c = a;          // kopieringskonstruktor 

            a = b;                 // tilldelning genom kopiering
            a[5] = 7;              // tilldelning till element

            const UIntVector e(10);    // konstant objekt med 10 element
            int i = e[5];          // const int oper[](int) const körs
            i = a[0];              // vektorn är nollindexerad
            i = a[5];              // int oper[](int) körs

            a[5]++;                // öka värdet till 8

            try {
                i = e[10];             // försöker hämta element som ligger utanför e
            } catch (std::out_of_range e) {
                std::cout << e.what() << std::endl;
            }

#if 0
            // Diverse saker att testa
            e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
            b = b;                 // hmm: se till att inte minnet som skall behållas frigörs
#endif

        }
};
