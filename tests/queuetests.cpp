#include "catch_amalgamated.hpp"
#include "QueueOfStrings.hpp"
#include "HotPotato.hpp"
#include <string>
#include <fstream>  


/*
 * Note how few test cases we have as required here.


 This DOES NOT mean there is very little to do; 
    This DOES mean you are expected to test your code.
    Note that we haven't even provided test cases that *call* 
        every function within QueueOfStrings.
        That would probably be a good first thing for you to write...
 */

namespace{

TEST_CASE("MyFirstEnqueue", "[RequiredQueue]")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    REQUIRE( a.front() == "Mike" );
}

TEST_CASE("FrontThrowsWhenNone", "[RequiredQueue]")
{
    QueueOfStrings q;
    REQUIRE_THROWS_AS( q.front(), QueueEmptyException );
}

TEST_CASE("SimpleHotPotato", "[RequiredHotPotato]")
{
    std::ifstream in{"hp_names_1.txt"};
    std::vector<unsigned> numOfPasses{5, 3};
    REQUIRE("Lakshmi" == playHotPotato(in, numOfPasses));
}

TEST_CASE("FrontHasValue", "[FYI]")
{
    QueueOfStrings q;
    q.enqueue("Foxy");
    REQUIRE( q.front() == "Foxy");
}

TEST_CASE("ChangedFrontValue", "[FYI]")
{
    QueueOfStrings q;
    q.enqueue("Foxy");
    q.enqueue("Freddy");
    q.dequeue();
    REQUIRE( q.front() == "Freddy");
}

TEST_CASE("CopyConstructor", "[FYI]")
{
    QueueOfStrings q;
    q.enqueue("Mike");
    q.enqueue("Goomba");
    q.enqueue("Harold");

    QueueOfStrings copyQueue{QueueOfStrings(q)};
    copyQueue.enqueue("David");

    REQUIRE( q.size() == 3);
    REQUIRE( copyQueue.size() == 4);
}

TEST_CASE("EmptyQueue", "[FYI]")
{
    QueueOfStrings q;
    REQUIRE( q.isEmpty() );
    REQUIRE_THROWS_AS( q.front(), QueueEmptyException );
}

TEST_CASE("EmptyQueue2", "[FYI]")
{
    QueueOfStrings q;
    REQUIRE( q.isEmpty() );
    REQUIRE_THROWS_AS( q.front(), QueueEmptyException );
}

TEST_CASE("SingleElementQueue", "[FYI]")
{
    QueueOfStrings q;
    REQUIRE( q.size() == 0 );
    REQUIRE( q.isEmpty() );
    REQUIRE_THROWS_AS( q.front(), QueueEmptyException );
    q.enqueue("Mike");
    REQUIRE( q.size() == 1 );
    REQUIRE( q.isEmpty() == false );
    REQUIRE( q.front() == "Mike" );
    q.dequeue();
    REQUIRE( q.size() == 0 );
    REQUIRE( q.isEmpty() );
    REQUIRE_THROWS_AS( q.front(), QueueEmptyException );
}

TEST_CASE("LargerTestCase", "[FYI]")
{
    std::ifstream in{"names1000.txt"};
    std::vector<unsigned> numOfPasses{5, 3};
    REQUIRE("wda" == playHotPotato(in, numOfPasses));
}

TEST_CASE("DeepCopy")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    QueueOfStrings b{a};
    b.dequeue();
    REQUIRE( a.front() == "Mike" );
    REQUIRE( b.isEmpty() );
}

TEST_CASE("AssignmentCopy")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    QueueOfStrings b;
    b.enqueue("1");
    b.dequeue();
    REQUIRE( a.front() == "Mike" );
    REQUIRE( b.isEmpty() );
}

TEST_CASE("AssignmentCopy2")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    a.enqueue("Alex");
    QueueOfStrings b;
    b.enqueue("Alex");
    b = a;
    b.dequeue();
    REQUIRE( a.front() == "Mike" );
    REQUIRE( a.size() == 2 );
    REQUIRE( b.size() == 1 );
}

TEST_CASE("AssignmentCopy3")
{
    QueueOfStrings a;
    QueueOfStrings b;
    b.enqueue("A");
    b = a;
    REQUIRE( a.isEmpty() );
    REQUIRE( b.isEmpty() );
}

TEST_CASE("AssignmentCopy4")
{
    QueueOfStrings a;
    a.enqueue("A");
    a.enqueue("B");
    a.enqueue("C");
    QueueOfStrings b;
    b.enqueue("4");
    b.enqueue("5");
    b.enqueue("6");
    b = a;
    REQUIRE( a.size() == b.size() );
    while(!a.isEmpty() && !b.isEmpty())
    {
        REQUIRE(a.front() == b.front());
        a.dequeue();
        b.dequeue();
    }
    REQUIRE(a.isEmpty() == b.isEmpty());
}

TEST_CASE("BigNameFileHotPotato", "[AdditionalHotPotato]") {
    std::ifstream in{"baby_names.txt"};
    std::vector<unsigned> numOfPasses{10, 100, 1000, 10000, 100000, 1000000};
    REQUIRE("Cherin" == playHotPotato(in, numOfPasses));
}

TEST_CASE("AssignToSome", "[OTHER SCENARIO]")
{
    QueueOfStrings a;
    QueueOfStrings b;
    a.enqueue("A");
    b.enqueue("A");
    REQUIRE( a.front() == "A" );
    REQUIRE( b.front() == "A" );
    b = a;
    REQUIRE( a.front() == "A" );
    REQUIRE( b.front() == "A" );
}

TEST_CASE("OnePlayerAutomaticallyWins", "[FYI]")
{
    std::ifstream in{"one_name.txt"};
    std::vector<unsigned> numOfPasses{5, 3};
    REQUIRE("John" == playHotPotato(in, numOfPasses));
}

TEST_CASE("EmptyVector", "[FYI]")
{
    std::ifstream in{"one_name.txt"};
    std::vector<unsigned> numOfPasses{};
    REQUIRE_THROWS_AS( playHotPotato(in, numOfPasses), QueueEmptyException );
}

TEST_CASE("ZeroInVector", "[FYI]")
{
    std::ifstream in("one_name.txt");
    std::vector<unsigned> numOfPasses{0};
    REQUIRE("John" == playHotPotato(in, numOfPasses));
}

TEST_CASE("ZeroInVector2", "[FYI]")
{
    std::ifstream in("hp_names_1.txt");
    std::vector<unsigned> numOfPasses{0};
    REQUIRE("Yaphet" == playHotPotato(in, numOfPasses));
}


} // end namespace

