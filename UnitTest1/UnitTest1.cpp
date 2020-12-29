#include "pch.h"
#include "CppUnitTest.h"
#include "../laba12.2.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Spusok* first = NULL;
			Spusok* last = NULL;
			Spusok* T;

			int index = 4, N = 11;
			Creata(first, last, index, N);

			T = first;
			COUT(T, 0, N, index);

			T = first;
			int x = 11;
			Process(T, x, 0);
			T = first;
			int l = T->inf;
			Assert::AreEqual(l, 15);
		}
	};
}
