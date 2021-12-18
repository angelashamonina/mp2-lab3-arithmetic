#include <arithmetic.h>
#include <gtest.h>
TEST(Lexem, can_create_lexeme)
{
	double l = 23;
	EXPECT_NO_THROW(Lexem s(l));
}
TEST(Lexem, can_lexeme_number)
{
	double l = 23;
	Lexem A(l);
	EXPECT_EQ(l, A.GetValue());
}
TEST(Lexem, can_lexeme_operation)
{
	string l = "+";
	Lexem A(l);
	EXPECT_EQ(l, A.GetOperation());
}
TEST(Lexem, can_lexeme_function)
{
	string l = "cos";
	Lexem A(l);
	EXPECT_EQ(l, A.GetOperation());
}
TEST(Lexem, can_get_lexeme_type)
{
	double l = 23;
	Lexem A(l);
	EXPECT_EQ(A.GetType(),true);
}

TEST(Arithmetic, can_be_divided_into_vector_of_lexems)
{
	string s = "a+b-(2*4+5)";
	Arithmetic res;
	EXPECT_NO_THROW(res.vectorLexem(s));
}
TEST(Arithmetic, can_sum_two_num)
{
	Arithmetic res;
	string s = "24+42";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_EQ(66.0, res.calculation());
}
TEST(Arithmetic, can_sum_more_num)
{
	Arithmetic res;
	string s = "24+42-13-6";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_EQ(47.0, res.calculation());

}
TEST(Arithmetic, expression_with_brackets)
{
	Arithmetic res;
	string s = "24/(4.2-0.2)";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_NEAR(6.0, res.calculation(), 1e-5);
}
TEST(Arithmetic, unar_minus_without_brackets)
{
	Arithmetic res;
	string s = "9+-10";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_EQ(-1.0, res.calculation());
}
TEST(Arithmetic, unar_minus_with_div1)
{
	Arithmetic res;
	string s = "9/-10";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_EQ(-0.9, res.calculation());
}
TEST(Arithmetic, unar_minus_with_div2)
{
	Arithmetic res;
	string s = "9/-(5+5)";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_EQ(-0.9, res.calculation());
}
TEST(Arithmetic,can_more_one_unar_minus)
{
	Arithmetic res;
	string s = "9-------9";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_EQ(0.0, res.calculation());
}
TEST(Arithmetic, can_all_operations) {
	Arithmetic res;
	string s = "6.25 + 4. / 8*5.-3";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_NEAR(5.75, res.calculation(), 1e-5);
}
TEST(Arithmetic, can_all_functions) {
	Arithmetic res;
	string s = "sin(1)+cos(1)+log(1)";
	res.vectorLexem(s);
	res.Postfix();
	EXPECT_NEAR(1.38177, res.calculation(), 1e-5);
}
TEST(Arithmetic, throw_when_operation_before_closing_bracket)
{
	Arithmetic res;
	string s = "6+(7+9/)";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_when_function_after_closing_bracket)
{
	Arithmetic res;
	string s = "(15/3)log(1)";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_when_number_after_closing_bracket)
{
	Arithmetic res;
	string s = "(15/3)1";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_when_opening_bracket_after_number)
{
	Arithmetic res;
	string s = "42(100*3)";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_wrong_brackets)
{
	Arithmetic res;
	string s = "42-((((100*3)";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_last_is_operation)
{
	Arithmetic res;
	string s = "18+6*";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_first_is_operation)
{
	Arithmetic res;
	string s = "*18+6";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_first_is_brackets)
{
	Arithmetic res;
	string s = ")18+6*";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_last_is_opening_bracket)
{
	Arithmetic res;
	string s = "16+1*(";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, no_throw_unary_minus_after_opening_bracket)
{
	Arithmetic res;
	string s = "38*(-6)";
	res.vectorLexem(s);
	ASSERT_NO_THROW(res.Correct());
}
TEST(Arithmetic, throw_when_opening_bracket_after_closing)
{
	Arithmetic res;
	string s = "(5/3)(12+5)";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_when_extra_brackets)
{
	Arithmetic res;
	string s = "29*5()";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
TEST(Arithmetic, throw_when_number_after_number)
{
	Arithmetic res;
	string s = "7 1 8 - 1";
	res.vectorLexem(s);
	ASSERT_ANY_THROW(res.Correct());
}
