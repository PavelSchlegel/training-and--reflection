#include <gtest/gtest.h>
#include <mylib.hpp>
#include <gmock/gmock.h>

TEST(mylib, check_return_value)
{
    //сравнение выражений на раверство
    EXPECT_EQ(return_one(), 1);
}

TEST(mylib, check_array)
{
    int arr[] = {0, 0, 0};
    arr_init(arr);
    ASSERT_EQ(arr[0], 0);
    ASSERT_EQ(arr[1], 1);
    ASSERT_EQ(arr[2], 2);
}

class Mock :public DBConnnetion
{
    public:
    MOCK_METHOD(bool, open, (const std::string& db_name), (override));
    MOCK_METHOD(bool, clous, (), (override));
    MOCK_METHOD(void, execQuery, (), (override));

};

TEST(Mock, test_mock)
{
    using ::testing::Return;
    Mock mock;
    EXPECT_CALL(mock, open).Times(::testing::AtLeast(1)).WillOnce(Return(true));
    EXPECT_CALL(mock, clous).Times(::testing::AtLeast(1)).WillOnce(Return(false));
    EXPECT_CALL(mock, execQuery).Times(::testing::AtLeast(1));

    ClassThatUsesDB test(&mock);
    test.openConnection();
    test.useConnection();
    test.clousConnection();
}
/*
    ASSERT_LE  (v1 <= v2);
    ASSERT_NE  (v1 != v2);
    ASSERT_GT (v1 > v2);
    ASSERT_TRUE (true);
    ASSERT_LT (v1 < v2);
    ASSERT_GE (v1 >= v2);

    строки
    ASSERET_STREQ (str1 == str2);
    ASSERTE_STRCASEEQ (str1 == str2) строки без регистра
    ASSERT_STRNE (str1 != str2);
    ASSERTE_STRCASENE (str1 != str2) без регистра

    исключения
    ASSETR_THROW (statement, expected_exception) проверка иск. определенного типа
    ASSERT_NO_THROW(statement) не выбрасывает искл
    ASSERT_ANY_THROW(statement) что выбрасывает искл. любого типа

    с точкой
    ASSERT_FLOAT_EQ(val1, val2) == одной точности
    ASSERT_DOUBLE_EQ(val1, val2) == двойной точности
    ASSERT_NEAR(v1, v2, abs_error) Проверяет, что два значения с плавающей точкой находятся в пределах заданной дистанции друг от друга.
*/

