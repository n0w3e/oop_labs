#include "../include/memory_resource.h"
#include "../include/dynamic_array.h"
#include <gtest/gtest.h>

struct ComplexType {
    int id;
    double value;
    ComplexType(int id, double value) : id(id), value(value) {}
};
/*
TEST(MemoryResourceTest, AllocationDeallocation) {
    FixedMemoryResource memoryResource(32, 5);
    
    void* ptr1 = memoryResource.allocate(32);
    void* ptr2 = memoryResource.allocate(32);

    memoryResource.deallocate(ptr1, 32);
    memoryResource.deallocate(ptr2, 32);
    
    void* ptr3 = memoryResource.allocate(32);
    EXPECT_EQ(ptr3, ptr1);
}
*/

TEST(DynamicArrayTest, PushBackAndAccess) {
    FixedMemoryResource memoryResource(32, 10);
    DynamicArray<int> intArray(&memoryResource);

    intArray.push_back(10);
    intArray.push_back(20);
    intArray.push_back(30);

    EXPECT_EQ(intArray.size(), 3);
    EXPECT_EQ(intArray[0], 10);
    EXPECT_EQ(intArray[1], 20);
    EXPECT_EQ(intArray[2], 30);
}

TEST(DynamicArrayTest, ComplexTypeHandling) {
    FixedMemoryResource memoryResource(64, 10);
    DynamicArray<ComplexType> complexArray(&memoryResource);

    complexArray.push_back(ComplexType(1, 10.5));
    complexArray.push_back(ComplexType(2, 20.5));

    EXPECT_EQ(complexArray.size(), 2);
    EXPECT_EQ(complexArray[0].id, 1);
    EXPECT_EQ(complexArray[0].value, 10.5);
    EXPECT_EQ(complexArray[1].id, 2);
    EXPECT_EQ(complexArray[1].value, 20.5);
}

TEST(DynamicArrayTest, Iterator) {
    FixedMemoryResource memoryResource(32, 10);
    DynamicArray<int> intArray(&memoryResource);

    intArray.push_back(1);
    intArray.push_back(2);
    intArray.push_back(3);

    int sum = 0;
    for (const auto& value : intArray) {
        sum += value;
    }
    EXPECT_EQ(sum, 6);
}
