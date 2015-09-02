/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "test_vec.cpp"

static VectorTestSuite suite_VectorTestSuite;

static CxxTest::List Tests_VectorTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_VectorTestSuite( "test_vec.cpp", 7, "VectorTestSuite", suite_VectorTestSuite, Tests_VectorTestSuite );

static class TestDescription_VectorTestSuite_test_init : public CxxTest::RealTestDescription {
public:
 TestDescription_VectorTestSuite_test_init() : CxxTest::RealTestDescription( Tests_VectorTestSuite, suiteDescription_VectorTestSuite, 12, "test_init" ) {}
 void runTest() { suite_VectorTestSuite.test_init(); }
} testDescription_VectorTestSuite_test_init;

#include <cxxtest/Root.cpp>
