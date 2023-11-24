#include <iostream>
#include <fstream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <minesweeper.h>

class Test : public CPPUNIT_NS::TestCase
{
    CPPUNIT_TEST_SUITE(Test);
    CPPUNIT_TEST(mount_board);
    //CPPUNIT_TEST(test2);
    CPPUNIT_TEST_SUITE_END();

    void createMockFile();
    

    public:
        void mount_board();
        //void test2();
        void setUp(void);
};

void Test::setUp(void)
{}

void Test::mount_board()
{
    Minesweeper game;
    char file[] = "in.txt"; 

    vector<vector<int>> board = game.mount_board(file);

    // Verifique se a matriz foi preenchida corretamente
    CPPUNIT_ASSERT_EQUAL(TABLE_DIMENSION, static_cast<int>(board.size()));
    for (int i = 0; i < TABLE_DIMENSION; ++i) {
        CPPUNIT_ASSERT_EQUAL(TABLE_DIMENSION, static_cast<int>(board[i].size()));
    }
}

/*void Test::test2()
{
    
}

void Test::test3()
{

}

void Test::test4()
{

}

void Test::test5()
{

}*/

CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main(int argc, char* argv[])
{
    CPPUNIT_NS::TestResult controller;
    CPPUNIT_NS::TestResultCollector collectedresults;
    controller.addListener(&collectedresults);

    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);

    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(controller);

    return collectedresults.wasSuccessful() ? 0 : 1;
}