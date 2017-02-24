#include"TList.h"
#include<gtest.h>

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList,check_the_size_after_insert_first )
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertFirst(2);

	EXPECT_EQ(list.GetSize(), 2);
}

TEST(TList, check_the_size_after_insert_last)
{
	TList<int> list;
	list.InSertLast(1);
	list.InSertLast(2);

	EXPECT_EQ(list.GetSize(), 2);
}

TEST(TList, check_the_size_after_random_insert)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(2);
	list.InSertInPos(1, 3);

	EXPECT_EQ(list.GetSize(), 3);
}

TEST(TList, check_the_size_after_random_insert_and_del_first)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.DeleteFirst();

	EXPECT_EQ(list.GetSize(), 2);
}

TEST(TList, check_the_size_after_random_insert_and_del_last)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.DeleteLast();

	EXPECT_EQ(list.GetSize(), 2);
}
TEST(TList, check_the_size_after_random_insert_and_del_pos)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.Delete(2);

	EXPECT_EQ(list.GetSize(), 2);
}

TEST(TList,check_the_pos_after_insert_first_1)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertFirst(2);
	list.InSertFirst(3);

	EXPECT_EQ(list.Show(1), 3);
}
TEST(TList, check_the_pos_after_insert_first_2)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertFirst(2);
	list.InSertFirst(3);

	EXPECT_EQ(list.Show(2), 2);
}
TEST(TList, check_the_pos_after_insert_first_3)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertFirst(2);
	list.InSertFirst(3);

	EXPECT_EQ(list.Show(3), 1);
}

TEST(TList, check_the_pos_after_insert_last_1)
{
	TList<int> list;
	list.InSertLast(1);
	list.InSertLast(2);
	list.InSertLast(3);

	EXPECT_EQ(list.Show(1), 1);
}
TEST(TList, check_the_pos_after_insert_last_2)
{
	TList<int> list;
	list.InSertLast(1);
	list.InSertLast(2);
	list.InSertLast(3);

	EXPECT_EQ(list.Show(2), 2);
}
TEST(TList, check_the_pos_after_insert_last_3)
{
	TList<int> list;
	list.InSertLast(1);
	list.InSertLast(2);
	list.InSertLast(3);

	EXPECT_EQ(list.Show(3), 3);
}

TEST(TList, check_the_pos_after_insert_random_1)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);

	EXPECT_EQ(list.Show(1), 1);
}
TEST(TList, check_the_pos_after_insert_random_2)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);

	EXPECT_EQ(list.Show(2), 3);
}
TEST(TList, check_the_pos_after_insert_random_3)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);

	EXPECT_EQ(list.Show(3), 2);
}

TEST(TList, check_the_pos_after_del_insert_1)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.DeleteFirst();

	EXPECT_EQ(list.Show(1), 3);
}

TEST(TList, check_the_pos_after_del_insert_2)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.DeleteFirst();
	list.DeleteFirst();

	EXPECT_EQ(list.Show(1), 2);
}

TEST(TList, check_the_pos_after_del_last_1)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.DeleteLast();

	EXPECT_EQ(list.Show(2), 3);
}
TEST(TList, check_the_pos_after_del_last_2)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.DeleteLast();
	list.DeleteLast();

	EXPECT_EQ(list.Show(1), 1);
}
TEST(TList, check_the_pos_after_del_in_pos_1)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.Delete(1);

	EXPECT_EQ(list.Show(1), 3);
}
TEST(TList, check_the_pos_after_del_in_pos_2)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.Delete(2);

	EXPECT_EQ(list.Show(1), 1);
}
TEST(TList, check_the_pos_after_del_in_pos_3)
{
	TList<int> list;
	list.InSertFirst(1);
	list.InSertLast(3);
	list.InSertInPos(2, 2);
	list.Delete(3);

	EXPECT_EQ(list.Show(2), 3);
}


