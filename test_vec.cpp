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

            UIntVector f(3);
            TS_ASSERT(f[0] == 0);
            TS_ASSERT(f[1] == 0);
            TS_ASSERT(f[2] == 0);

            const UIntVector constA(10);
            TS_ASSERT(constA.size() == 10);
        }

        /**
         * Test assignment
         */
        void test_assign()
        {
            UIntVector a(10);
            a[0] = 1;
            a[9] = 2;
            UIntVector b = a;
            TS_ASSERT(b[0] == 1);
            TS_ASSERT(b[9] == 2);

            UIntVector c(5);
            c[1] = 3;
            c[2] = 4;
            int x = c[1];
            int y = c[2];
            TS_ASSERT(x == 3);
            TS_ASSERT(y == 4);
        }

        /**
         * Test resetting.
         */
        void test_reset()
        {
            UIntVector a(5);
            a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4; a[4] = 5;
            a.reset();
            TS_ASSERT(a[0] == 0);
            TS_ASSERT(a[1] == 0);
            TS_ASSERT(a[2] == 0);
            TS_ASSERT(a[3] == 0);
            TS_ASSERT(a[4] == 0);
        }

        /**
         * Test the add functionality.
         */
        void test_add()
        {
            UIntVector a(13);
            a.add(5);
            TS_ASSERT_EQUALS(a[13], (unsigned int) 5);
            TS_ASSERT_EQUALS(a[10], (unsigned int) 0);

            UIntVector b(a);
            TS_ASSERT_EQUALS(b[13], (unsigned int) 5);
            TS_ASSERT_EQUALS(b[9], (unsigned int) 0);

            a.add(17);
            TS_ASSERT_EQUALS(a[14], (unsigned int) 17);
            TS_ASSERT_THROWS(b[14], std::out_of_range);
        }

        void test_copy_op()
        {
            UIntVector a(5);
            a[2] = (unsigned int) 3;
            UIntVector b(7);
            b = a;
            TS_ASSERT_EQUALS(b[2], (unsigned int) 3);
            TS_ASSERT_EQUALS(a[2], (unsigned int) 3);

            a.add(19);
            TS_ASSERT_THROWS(b[5],std::out_of_range);

            a[2] = (unsigned int) 4;
            TS_ASSERT_EQUALS(b[2], (unsigned int) 3);
            TS_ASSERT_EQUALS(a[2], (unsigned int) 4);

            b[2] = (unsigned int) 5;
            TS_ASSERT_EQUALS(b[2], (unsigned int) 5);
            TS_ASSERT_EQUALS(a[2], (unsigned int) 4);
        }

        void test_copy_self()
        {
            UIntVector a(4);
            a[1] = 8;
            a = a;
            TS_ASSERT(a[1] == 8);
            TS_ASSERT(a[0] == 0);
        }

        /**
         * Test going out-of-bounds.
         */
        void test_index_except()
        {
            UIntVector a(5);
            const UIntVector b(1);
            try
            {
                a[5] = 1;
                TS_ASSERT(false);
            }
            catch (std::out_of_range e) {
                TS_ASSERT(true);
            }
            try
            {
                b[2];
                TS_ASSERT(false);
            }
            catch (std::out_of_range e) {
                TS_ASSERT(true);
            }
        }

        /**
         * Test to add over the internal capacity.
         */
        void test_add_lots()
        {
            UIntVector a(0); // Should default to internal size 10
            for (int i = 0; i < 20; ++i)
                a.add(i);

            TS_ASSERT(a[9] == 9);
            TS_ASSERT(a[10] == 10);
            TS_ASSERT(a[15] == 15);
            TS_ASSERT(a[19] == 19);
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
