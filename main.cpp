#include <gtest/gtest.h>
#include <climits>


int add(int a, int b) {
  return a + b;
}

bool IsEven(int number) {
    return (number % 2) == 0;
}

// Test class
class AddTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Add any setup code if needed
  }

  void TearDown() override {
    // Add any teardown code if needed
  }
};


// MyString class
class MyString {
private:
    char* buffer_;
    int size_;

public:
    explicit MyString(const char* str) {
        size_ = strlen(str);
        buffer_ = new char[size_ + 1];
        strcpy(buffer_, str);
    }

    ~MyString() {
        delete[] buffer_;
    }

    int Length() const {
        return size_;
    }

    const char* GetString() const {
        return buffer_;
    }
};

// Test fixture
class MyStringTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup steps you need to perform before each test
    }

    void TearDown() override {
        // Any teardown steps you need to perform after each test
    }
};


// Test cases :
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

// Testing addition of positive numbers
TEST_F(AddTest, PositiveNumbers) {
  EXPECT_EQ(add(56,73), 129);
  EXPECT_EQ(add(12, 8),20 );
}

// Testing addition of negative numbers
TEST_F(AddTest, NegativeNumbers) {
  EXPECT_EQ(add(-2, -7), -9);
  EXPECT_EQ(add(-15, -40), -55);
}

// Testing addition of mixed (positive and negative) numbers
TEST_F(AddTest, MixedNumbers) {
  EXPECT_EQ(add(7, -5), 2);
  EXPECT_EQ(add(-15, 32), 17);
}

// Testing addition with zero
TEST_F(AddTest, Zero) {
  EXPECT_EQ(add(0, 7), 7);
  EXPECT_EQ(add(-14, 0), -14);
}

// Testing addition with the same number
TEST_F(AddTest, SameNumber) {
  EXPECT_EQ(add(16, 16), 32);
  EXPECT_EQ(add(-15, -15), -30);
}

// Testing addition with min and max integer values
TEST_F(AddTest, MinMaxIntegers) {
  EXPECT_EQ(add(INT_MAX, 0), INT_MAX);
  EXPECT_EQ(add(INT_MIN, 0), INT_MIN);
  EXPECT_EQ(add(INT_MAX, INT_MIN), -1);
}

// Testing addition with overflow and underflow
TEST_F(AddTest, OverflowUnderflow) {
  EXPECT_EQ(add(INT_MAX, 1), INT_MIN);
  EXPECT_EQ(add(INT_MIN, -1), INT_MAX);
}

// Testing addition with reverse order of numbers
TEST_F(AddTest, ReverseOrder) {
  EXPECT_EQ(add(4, 3), 7);
  EXPECT_EQ(add(20, 10), 30);
  EXPECT_EQ(add(-4, -3), -7);
  EXPECT_EQ(add(20, -10), 10);
}

// Testing if positive numbers are even
TEST(IsEvenTest, PositiveNumbers) {
    EXPECT_TRUE(IsEven(4));
    EXPECT_TRUE(IsEven(44));
    EXPECT_TRUE(IsEven(100));
}

// Testing if negative numbers are even
TEST(IsEvenTest, NegativeNumbers) {
    EXPECT_TRUE(IsEven(-6));
    EXPECT_TRUE(IsEven(-40));
    EXPECT_TRUE(IsEven(-100));
}

// Testing if the number zero is even
TEST(IsEvenTest, Zero) {
    EXPECT_TRUE(IsEven(0));
}

// Testing if positive numbers are odd
TEST(IsEvenTest, OddNumbers) {
    EXPECT_FALSE(IsEven(7));
    EXPECT_FALSE(IsEven(15));
    EXPECT_FALSE(IsEven(31));
}

// Checking for the length of the string
TEST_F(MyStringTest, Length) {
    MyString str("Software Engineering for HPC");
    EXPECT_EQ(str.Length(), 28);
}

// Checking for the equality strings
TEST_F(MyStringTest, GetString) {
    MyString str("SWENG!");
    EXPECT_STREQ(str.GetString(), "SWENG!");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
