#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_7.2(iter)/PR_7.2(iter).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSearchMinEven)
		{
			const int n = 3;
			const int k = 4;
			int Low = 7;
			int High = 65;

			int** testArray = new int* [n];
			for (int i = 0; i < n; i++) {
				testArray[i] = new int[k];
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < k; j++) {
					testArray[i][j] = Low + rand() % (High - Low + 1);
				}
			}

			int minEven;
			SearchMinEven(testArray, n, k, minEven);

			Assert::AreEqual(48, minEven);

			for (int i = 0; i < n; i++) {
				delete[] testArray[i];
			}
			delete[] testArray;
		}
	};
}
