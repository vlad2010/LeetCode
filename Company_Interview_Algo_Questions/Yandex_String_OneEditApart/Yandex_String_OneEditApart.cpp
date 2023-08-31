// Yandex_String_OneEditApart.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cassert>
#include <iostream>

// Second interview with Yandex 31.08.2023
// Solved this task in 1 hour instead of 20 mins, and with a lot of hints from interviewer

//  Implement function OneEditApart() which returns true if it is possible to make one string from another using only one changing operation
// ( delete char, add char, or modify characted )
// Function will return false if it is not possible.

bool OneEditApart(const std::string& s1, const std::string& s2)
{
	size_t maxLength = std::max(s1.size(), s2.size());

	// type = 0 change, type == -1 adding, type == 1 delete symbol
	int type = s1.size() - s2.size();

	if (type > 1 || type < -1)
	{
		return false;
	}

	bool correction = false;

	for (size_t i = 0, j = 0; i < maxLength && j < maxLength; i++, j++)
	{
		if (i >= s1.size() || j >= s2.size())
		{
			return !correction;
		}

		if (s1[i] != s2[j] && !correction)
		{
			switch (type)
			{
			case 0:
				// change symbol
				correction = true;
				break;
			case -1:
				// add symbol
				correction = true;
				j++;
				break;
			case 1:
				// delete symbol
				correction = true;
				i++;
				break;
			}

			if (s1[i] != s2[j] && type != 0)
			{
				return false;
			}
			continue;
		}

		if (s1[i] != s2[j] && correction)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	assert(!OneEditApart("cat", "dog"));
	assert(OneEditApart("cat", "cats"));

	assert(OneEditApart("cat", "cut"));
	assert(OneEditApart("cat", "cast"));
	assert(!OneEditApart("cat", "acts"));

	assert(!OneEditApart("cat", "cta"));
	assert(OneEditApart("cat", "cast"));

	assert(OneEditApart("cat", "ct"));
	assert(OneEditApart("cxt", "cat"));
	assert(!OneEditApart("catt", "casst"));

    std::cout << "All test cases passed! \n";
}
