#include "stack.h"
#include <gtest.h>
TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s);
}
TEST(TStack, can_generate_stack_with_leight)
{
	ASSERT_NO_THROW(TStack <int> s(10));
}
TEST(TStack, cant_create_stack_with_0_size)
{
	ASSERT_ANY_THROW(TStack<int> s(0));
}
TEST(TStack, cant_create_stack_with_error_leight)
{
    ASSERT_ANY_THROW(TStack <int> s(-8));
}
TEST(TStack, can_push)
{
    TStack<int> s;
    ASSERT_NO_THROW(s.push(6));
}
TEST(TStack, can_pop)
{
    TStack<int> s;
    s.push(6);
    ASSERT_NO_THROW(s.pop());
}
TEST(TStack, can_resize_stack)
{
    TStack<int> s(3);
    for (int i = 0; i < 5; i++)
    {
        s.push(i);
    }
    EXPECT_EQ(4, s.pop());
}
TEST(TStack, cant_pop_empty_stack)
{
    TStack<int> s;
    ASSERT_ANY_THROW(s.pop());
}
TEST(TStack,can_check_top)
{
    TStack<int> s(5);
    for (int i = 0; i < 5; i++)
    {
        s.push(i);
    }
    EXPECT_EQ(4, s.getTop());
}
TEST(TStack, can_check_on_emptiness_empty_stack)
{
    TStack<int> s;
    EXPECT_EQ(true, s.isEmpty());
}
TEST(TStack, can_check_on_emptiness_not_empty_stack)
{
    TStack<int> s;
    s.push(8);
    EXPECT_EQ(false, s.isEmpty());
}
TEST(TStack, can_clear_stack)
{
    TStack<int> s(5);
    for (int i = 0; i < 5; i++)
    {
        s.push(i);
    }
    s.clear();
    EXPECT_EQ(true,s.isEmpty() );
}
TEST(TStack, cant_check_last_in_empty)
{
    TStack <int> s;
    ASSERT_ANY_THROW(s.getTop());
}
TEST(TStack, check_elemsize_of_clear_stack)
{
    TStack <int> s(12);
    EXPECT_EQ(s.size(), 0);
}
