#include"monom.h"
#include"gtest.h"

TEST(TMonom, can_create_monom_1)
{
	ASSERT_NO_THROW(TMonom M);
}

TEST(TMonom, can_create_monom_2)
{
	ASSERT_NO_THROW(TMonom M(112,2));
}

TEST(TMonom, can_not_create_monom_2)
{
	ASSERT_ANY_THROW(TMonom M(1000, 2));
}

TEST(TMonom, can_add_monoms_with_the_same_deg)
{
	TMonom m_one(100, 10);
	TMonom m_two(100, 5);

	TMonom res(100, 15);

	EXPECT_EQ(m_one + m_two, res);
}

TEST(TMonom, can_not_add_monoms_with_the_different_deg)
{
	TMonom m_one(100, 10);
	TMonom m_two(101, 5);

	ASSERT_ANY_THROW(m_one + m_two);
}

TEST(TMonom, can_sub_monoms_with_the_same_deg)
{
	TMonom m_one(100, 10);
	TMonom m_two(100, 5);

	TMonom res(100, 5);

	EXPECT_EQ(m_one - m_two, res);
}

TEST(TMonom, can_not_sub_monoms_with_the_different_deg)
{
	TMonom m_one(100, 10);
	TMonom m_two(101, 5);

	ASSERT_ANY_THROW(m_one - m_two);
}

TEST(TMonom, can_mult_monom_on_const)
{
	TMonom m(100, 10);
	double c = 2;

	TMonom res(100, 20);

	EXPECT_EQ(m * 2, res);
}

TEST(TMonom, can_assign)
{
	TMonom m(100, 10);
	TMonom m_one;

	m_one = m;

	EXPECT_EQ(m_one, m);
}

TEST(TMonom, can_get_dag)
{
	TMonom m(100, 1);

	EXPECT_EQ(100, m.GetDeg());
}

TEST(TMonom, can_get_coef)
{
	TMonom m(100, 1);

	EXPECT_EQ(1, m.GetCoef());
}