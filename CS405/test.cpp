// Uncomment the next line to use precompiled headers
#include "pch.h"
#include <limits>//for negative test
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
/*TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}*/

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Add one entry to the collection
    add_entries(1);

    // Verify the collection now contains one element
    ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Add five entries to the collection
    add_entries(5);

    // Verify the collection now contains five elements
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxSizeGEThanSize) {
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Add entries to the collection one by one, checking max_size after each addition
    for (size_t i = 1; i <= 10; i++)
    {
        add_entries(1);

        // Verify the collection size is incrementing correctly
        ASSERT_EQ(collection->size(), i);

        // Verify max_size is greater than or equal to the current size
        ASSERT_GE(collection->max_size(), collection->size());
    }

}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CapacityGEThanSize) {
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Add entries to the collection one by one, checking capacity after each addition
    for (size_t i = 1; i <= 10; i++)
    {
        add_entries(1);

        // Verify the collection size is incrementing correctly
        ASSERT_EQ(collection->size(), i);

        // Verify capacity is greater than or equal to the current size
        ASSERT_GE(collection->capacity(), collection->size());
    }
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, TestVecResizeInc) {
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Resize the collection from 1 to 10 and verify each resize increases the size correctly
    for (size_t i = 1; i <= 10; i++)
    {
        collection->resize(i);

        // Verify the collection size matches the intended resize value
        ASSERT_EQ(collection->size(), i);
    }
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, TestVecResizeDec) {
    // Resize the collection from 10 down to 1 and verify each resize decreases the size correctly
    for (size_t i = 10; i > 0; i--)
    {
        collection->resize(i);

        // Verify the collection size matches the intended resize value
        ASSERT_EQ(collection->size(), i);
    }
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, TestVecResizeZero) {
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Resize the collection to 10 and verify the size
    collection->resize(10);
    ASSERT_EQ(collection->size(), 10);

    // Resize the collection to 0 and verify it is now empty
    collection->resize(0);
    ASSERT_EQ(collection->size(), 0);
}

// Alternatively you could do one test that does all?
TEST_F(CollectionTest, TestVecResize) {
    int max = 10;

    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Resize the collection from 1 to max (10) and verify each resize
    for (size_t i = 1; i <= max; i++)
    {
        collection->resize(i);

        // Verify the collection size matches the intended resize value
        ASSERT_EQ(collection->size(), i);
    }

    // Resize the collection to 0 and verify it is now empty
    collection->resize(0);
    ASSERT_EQ(collection->size(), 0);

    // Resize the collection back to max (10)
    collection->resize(max);

    // Resize the collection from max (10) down to 1 and verify each resize
    for (size_t i = max; i > 0; i--)
    {
        collection->resize(i);

        // Verify the collection size matches the intended resize value
        ASSERT_EQ(collection->size(), i);
    }
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, TestVecClear) {

    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Add 10 entries to the collection
    add_entries(10);
    ASSERT_EQ(collection->size(), 10);

    // Clear the collection
    collection->clear();

    // Verify the collection is now empty
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, TestVecErase) {
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Add 10 entries to the collection
    add_entries(10);
    ASSERT_EQ(collection->size(), 10);

    // Erase all elements using erase(begin, end)
    collection->erase(collection->begin(), collection->end());

    // Verify the collection is now empty
    ASSERT_EQ(collection->size(), 0);
}
// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, TestVecReserve) {
    // Ensure the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Optionally add some elements to the collection
    add_entries(5);
    ASSERT_EQ(collection->size(), 5);

    // Record the current capacity and size
    size_t initial_capacity = collection->capacity();
    size_t initial_size = collection->size();

    // Reserve a larger capacity
    collection->reserve(20);

    // Verify that the capacity has increased
    ASSERT_GT(collection->capacity(), initial_capacity);

    // Verify that the size has not changed
    ASSERT_EQ(collection->size(), initial_size);
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, TestOutOfRangeException) {
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Add a few entries to the collection
    add_entries(5);
    ASSERT_EQ(collection->size(), 5);

    // Verify accessing out of bounds index throws std::out_of_range
    ASSERT_THROW(collection->at(10), std::out_of_range);
}
// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative
TEST_F(CollectionTest, TestElementsInCorrectOrder) {
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);

    // Add elements to the collection
    for (int i = 0; i < 5; ++i) {
        collection->push_back(i);
    }

    // Verify the collection now contains 5 elements
    ASSERT_EQ(collection->size(), 5);

    // Verify elements are in the correct order
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(collection->at(i), i);
    }
}

TEST_F(CollectionTest, TestIntegerOverflow) {
    // Verify the collection starts empty
    ASSERT_EQ(collection->size(), 0);
    // Add the maximum value for an integer to the collection
    int max_int = std::numeric_limits<int>::max();
    collection->push_back(max_int);

    // Add 1 to the value in the collection, which should cause an overflow
    collection->at(0) += 1;

    // Should wrap around to min limit
    int expected_value = std::numeric_limits<int>::min();

    // Check if the overflow has occurred as expected
    ASSERT_EQ(collection->at(0), expected_value);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}