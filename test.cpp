#include <iostream>
#include <fstream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <minesweeper.h>

using namespace std;

class Test : public CPPUNIT_NS::TestCase
{
    CPPUNIT_TEST_SUITE(Test);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_reveal);
    CPPUNIT_TEST_SUITE_END();

    public:
        void test_constructor();
        void test_reveal();
        void test_reveal_bomb();
        void setUp(void);
};

void Test::setUp(void) {}

void Test::test_constructor()
{
    Minesweeper game = Minesweeper("in.txt");
    vector<vector<int>> test_board = {{1, 2, -1, 1}, {1, -1, 2, 1}, {1, 2, 1, 1},{0, 1, -1, 1}};

    CPPUNIT_ASSERT_EQUAL(0, game.get_count_revealed());
    vector<vector<int>> board = game.get_answer_board();

    for (int i = 0; i < TABLE_DIMENSION; i++)
    {
        for (int j = 0; j < TABLE_DIMENSION; j++)
        {
            CPPUNIT_ASSERT_EQUAL(test_board[i][j], board[i][j]);
        }
    }
}

void Test::test_reveal()
{
    Minesweeper game = Minesweeper("in.txt");
    game.reveal(0, 0);
    CPPUNIT_ASSERT_EQUAL(1, game.get_count_revealed());
    vector<vector<int>> board = game.get_current_board();
    CPPUNIT_ASSERT_EQUAL(1, board[0][0]);
}

/*void Test::test3()
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