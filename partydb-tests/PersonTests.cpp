#include "stdafx.h"
#include "CppUnitTest.h"

#include <string>
#include "Person.h"
#include "Birthdate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace partydbtests
{
	TEST_CLASS(PersonTests)
	{
	public:

		TEST_METHOD(PersonConstruction)
		{
			Birthdate test_date = Birthdate(11, 13, 1928);
			string test_name = "Mickey";
			Person<BY_BIRTHDAY> mickey = Person<BY_BIRTHDAY>(test_name, test_date);

			Assert::AreEqual(test_date.getMonth(), mickey.getBirthday().getMonth());
			Assert::AreEqual(test_date.getDay(), mickey.getBirthday().getDay());
			Assert::AreEqual(test_date.getYear(), mickey.getBirthday().getYear());
			Assert::AreEqual(test_name, mickey.getName().getValue());
		}

		TEST_METHOD(BirthdateConstruction) {
			Birthdate test_date = Birthdate(11, 13, 1928);
		}
	};
}