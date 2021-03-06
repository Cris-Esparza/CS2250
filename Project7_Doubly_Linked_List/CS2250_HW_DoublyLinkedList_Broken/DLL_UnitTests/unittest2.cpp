#include "stdafx.h"
#include "CppUnitTest.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedListNode.h"
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DLL_UnitTests
{
	TEST_CLASS(StringTest)
	{
	public:
		ostringstream stream;
		string actualResult;
		string expectedResult;

		////////////////////////////////////////////////////////////////////////////////
		// Constructor Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(Constructor)
		{
			DoublyLinkedList<string> list;
			// The "L" that prefixes the string means that the string is stored
			// as 16-bit characters instead of 8-bit characters and is
			// required by the assert 
			Assert::AreEqual(0, list.GetCount(), L"Constructor Count Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead(), L"Constructor Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail(), L"Constructor Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"Constructor GetNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"Constructor Output Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// AddFront Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AddSingleItemFront)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");

			Assert::AreEqual(1, list.GetCount(), L"AddSingleItemFront Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddSingleItemFront Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddSingleItemFront Tail Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddSingleItemFront Head->Prev Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddSingleItemFront Tail->Next Incorrect", LINE_INFO());
			Assert::AreEqual(1, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddSingleItemFront GetNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "1....1";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemFront Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(AddMultipleItemFront)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			list.AddFront("2");
			list.AddFront("3");
			list.AddFront("4");
			list.AddFront("5");

			Assert::AreEqual(5, list.GetCount(), L"AddMultipleItemFront Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFront Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFront Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFront Head->Prev Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFront Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "5->4->3->2->1....1->2->3->4->5";
			Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFront Output Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// AddBack Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AddSingleItemBack)
		{
			DoublyLinkedList<string> list;
			list.AddBack("1");

			Assert::AreEqual(1, list.GetCount(), L"AddSingleItemBack Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddSingleItemBack Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddSingleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(1, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddSingleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddSingleItemBack Head->Prev Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddSingleItemBack Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "1....1";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemBack Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(AddMultipleItemBack)
		{
			DoublyLinkedList<string> list;
			list.AddBack("1");
			list.AddBack("2");
			list.AddBack("3");
			list.AddBack("4");
			list.AddBack("5");

			Assert::AreEqual(5, list.GetCount(), L"AddMultipleItemBack Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBack Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBack Head->Prev Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBack Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "1->2->3->4->5....5->4->3->2->1";
			Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBack Output Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// AddFrontAddBack Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AddSingleItemFrontAddSingleItemBack)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			list.AddBack("2");

			Assert::AreEqual(2, list.GetCount(), L"AddSingleItemFrontAddSingleItemBack Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddSingleItemFrontAddSingleItemBack Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddSingleItemFrontAddSingleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(2, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddSingleItemFrontAddSingleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddSingleItemFrontAddSingleItemBack Head->Prev Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddSingleItemFrontAddSingleItemBack Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "1->2....2->1";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemFrontAddSingleItemBack Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(AddMultipleItemFrontAddMultipleItemBack)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			list.AddBack("2");
			list.AddFront("3");
			list.AddBack("4");
			list.AddFront("5");
			list.AddBack("6");

			Assert::AreEqual(6, list.GetCount(), L"AddMultipleItemBack Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBack Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(6, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBack Head->Prev Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBack Tail->Next Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "5->3->1->2->4->6....6->4->2->1->3->5";
			Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBack Output Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// AddFrontRemoveFront Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AddSingleItemFrontRemoveSingleItemFront)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			string item = list.RemoveFront();
			Assert::AreEqual<string>("1", item, L"AddSingleItemFrontRemoveSingleItemFront Item Incorrect", LINE_INFO());

			Assert::AreEqual(0, list.GetCount(), L"AddSingleItemFrontRemoveSingleItemFront Count Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead(), L"AddSingleItemFrontRemoveSingleItemFront Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail(), L"AddSingleItemFrontRemoveSingleItemFront Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddSingleItemFrontRemoveSingleItemFront GetNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemFrontRemoveSingleItemFront Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(AddMultipleItemFrontRemoveMultipleItemFront)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			list.AddFront("2");
			list.AddFront("3");
			list.AddFront("4");
			list.AddFront("5");

			string item;
			{
				const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(5), item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(4, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(4, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFrontRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				stream.flush();
				actualResult = stream.str();
				expectedResult = "4->3->2->1....1->2->3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(4), item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(3, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(3, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFrontRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				stream.flush();
				actualResult = stream.str();
				expectedResult = "3->2->1....1->2->3";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(3), item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(2, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(2, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFrontRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				stream.flush();
				actualResult = stream.str();
				expectedResult = "2->1....1->2";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(2), item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFrontRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				stream.flush();
				actualResult = stream.str();
				expectedResult = "1....1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(1), item, L"AddMultipleItemFrontRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(0, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		// AddFrontRemoveBack Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AddSingleItemFrontRemoveSingleItemBack)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			string item = list.RemoveBack();
			Assert::AreEqual<string>(to_string(1), item, L"AddSingleItemFrontRemoveSingleItemBack Item Incorrect", LINE_INFO());
			Assert::AreEqual(0, list.GetCount(), L"AddSingleItemFrontRemoveSingleItemBack Count Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead(), L"AddSingleItemFrontRemoveSingleItemBack Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail(), L"AddSingleItemFrontRemoveSingleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddSingleItemFrontRemoveSingleItemBack GetNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemFrontRemoveSingleItemBack Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(AddMultipleItemFrontRemoveMultipleItemBack)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			list.AddFront("2");
			list.AddFront("3");
			list.AddFront("4");
			list.AddFront("5");

			string item;

			{
				const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(1), item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(4, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(4, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFrontRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5->4->3->2....2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(2), item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(3, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(3, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFrontRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5->4->3....3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(3), item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(2, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(2, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFrontRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5->4....4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(4), item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemFrontRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5....5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(5), item, L"AddMultipleItemFrontRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(0, list.GetCount(), L"AddMultipleItemFrontRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemFrontRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemFrontRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemFrontRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemFrontRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		// AddBackRemoveBack Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AddSingleItemBackRemoveSingleItemBack)
		{
			DoublyLinkedList<string> list;
			list.AddBack("1");
			string item = list.RemoveBack();
			Assert::AreEqual<string>(to_string(1), item, L"AddSingleItemBackRemoveSingleItemBack Item Incorrect", LINE_INFO());
			Assert::AreEqual(0, list.GetCount(), L"AddSingleItemBackRemoveSingleItemBack Count Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead(), L"AddSingleItemBackRemoveSingleItemBack Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail(), L"AddSingleItemBackRemoveSingleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddSingleItemBackRemoveSingleItemBack GetNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemBackRemoveSingleItemBack Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(AddMultipleItemBackRemoveMultipleItemBack)
		{
			DoublyLinkedList<string> list;
			list.AddBack("1");
			list.AddBack("2");
			list.AddBack("3");
			list.AddBack("4");
			list.AddBack("5");

			string item;

			{
				const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(5), item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(4, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(4, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "1->2->3->4....4->3->2->1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(4), item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(3, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(3, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "1->2->3....3->2->1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(3), item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(2, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(2, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "1->2....2->1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(2), item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)tailPrev, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "1....1";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}

			{
				item = list.RemoveBack();
				Assert::AreEqual<string>(to_string(1), item, L"AddMultipleItemBackRemoveMultipleItemBack Item Incorrect", LINE_INFO());
				Assert::AreEqual(0, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemBack Count Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemBack Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemBack GetNbrOfNodes Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemBack Output Incorrect", LINE_INFO());
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		// AddBackRemoveFront Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AddSingleItemBackRemoveSingleItemFront)
		{
			DoublyLinkedList<string> list;
			list.AddBack("1");
			string item = list.RemoveFront();
			Assert::AreEqual<string>(to_string(1), item, L"AddSingleItemBackRemoveSingleItemFront Item Incorrect", LINE_INFO());
			Assert::AreEqual(0, list.GetCount(), L"AddSingleItemBackRemoveSingleItemFront Count Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead(), L"AddSingleItemBackRemoveSingleItemFront Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail(), L"AddSingleItemBackRemoveSingleItemFront Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddSingleItemBackRemoveSingleItemFront GetNbrOfNodes Incorrect", LINE_INFO());

			stream << list;
			actualResult = stream.str();
			expectedResult = "EMPTY LIST";
			Assert::AreEqual(expectedResult, actualResult, L"AddSingleItemBackRemoveSingleItemFront Output Incorrect", LINE_INFO());
		}

		TEST_METHOD(AddMultipleItemBackRemoveMultipleItemFront)
		{
			DoublyLinkedList<string> list;
			list.AddBack("1");
			list.AddBack("2");
			list.AddBack("3");
			list.AddBack("4");
			list.AddBack("5");

			string item;

			{
				const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(1), item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(4, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(4, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "2->3->4->5....5->4->3->2";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(2), item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(3, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(3, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "3->4->5....5->4->3";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(3), item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(2, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(2, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "4->5....5->4";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(4), item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreEqual((int)headNext, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemFront Head->Prev Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemFront Tail->Next Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "5....5";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}

			{
				item = list.RemoveFront();
				Assert::AreEqual<string>(to_string(5), item, L"AddMultipleItemBackRemoveMultipleItemFront Item Incorrect", LINE_INFO());
				Assert::AreEqual(0, list.GetCount(), L"AddMultipleItemBackRemoveMultipleItemFront Count Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead(), L"AddMultipleItemBackRemoveMultipleItemFront Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail(), L"AddMultipleItemBackRemoveMultipleItemFront Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AddMultipleItemBackRemoveMultipleItemFront GetNbrOfNodes Incorrect", LINE_INFO());

				ostringstream stream;
				stream << list;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AddMultipleItemBackRemoveMultipleItemFront Output Incorrect", LINE_INFO());
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		// RemoveItem Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveFromSingleItemList)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			Assert::AreEqual(true, list.RemoveItem("1"), L"RemoveFromSingleItemList Exists Incorrect", LINE_INFO());
			Assert::AreEqual(false, list.RemoveItem("1"), L"RemoveFromSingleItemList Duplicate Incorrect", LINE_INFO());
			Assert::AreEqual(false, list.RemoveItem(to_string(0)), L"RemoveFromSingleItemList Does Not Exist Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead(), L"RemoveFromSingleItemList Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail(), L"RemoveFromSingleItemList Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"RemoveFromSingleItemList GetNbrOfNodes Incorrect", LINE_INFO());
		}

		TEST_METHOD(RemoveFromMultipleItemList)
		{
			{   // Remove items back to front
				DoublyLinkedList<string> list;
				for (int i = 1; i < 6; ++i)
				{
					list.AddFront(to_string(i));
				}
				for (int i = 1; i < 6; ++i)
				{
					Assert::AreEqual(true, list.RemoveItem(to_string(i)), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
					Assert::AreEqual(false, list.RemoveItem(to_string(i)), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				}
				Assert::AreEqual(false, list.RemoveItem(to_string(0)), L"RemoveFromMultipleItemList Does Not Exist Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead(), L"RemoveFromMultipleItemList Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail(), L"RemoveFromMultipleItemList Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"RemoveFromMultipleItemList GetNbrOfNodes Incorrect", LINE_INFO());
			}

			{   // Remove items front to back
				DoublyLinkedList<string> list;
				for (int i = 1; i < 6; ++i)
				{
					list.AddFront(to_string(i));
				}
				for (int i = 5; i > 0; --i)
				{
					Assert::AreEqual(true, list.RemoveItem(to_string(i)), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
					Assert::AreEqual(false, list.RemoveItem(to_string(i)), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				}
				Assert::AreEqual(false, list.RemoveItem("0"), L"RemoveFromMultipleItemList Does Not Exist Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead(), L"RemoveFromMultipleItemList Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail(), L"RemoveFromMultipleItemList Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"RemoveFromMultipleItemList GetNbrOfNodes Incorrect", LINE_INFO());
			}

			{   // Remove items from middle
				DoublyLinkedList<string> list;
				for (int i = 1; i < 6; ++i)
				{
					list.AddFront(to_string(i));
				}
				Assert::AreEqual(true, list.RemoveItem("3"), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.RemoveItem("3"), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(true, list.RemoveItem("2"), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.RemoveItem("2"), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(true, list.RemoveItem("4"), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.RemoveItem("4"), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(true, list.RemoveItem("1"), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.RemoveItem("1"), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(true, list.RemoveItem("5"), L"RemoveFromMultipleItemList Exists Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.RemoveItem("5"), L"RemoveFromMultipleItemList Previously Removed Incorrect", LINE_INFO());
				Assert::AreEqual(false, list.RemoveItem("0"), L"RemoveFromMultipleItemList Does Not Exist Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetHead(), L"RemoveFromMultipleItemList Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)list.GetTail(), L"RemoveFromMultipleItemList Tail Incorrect", LINE_INFO());
				Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"RemoveFromMultipleItemList GetNbrOfNodes Incorrect", LINE_INFO());
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		// RemoveFromEmpty Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(RemoveFromEmpty)
		{
			try
			{
				DoublyLinkedList<string> list;
				list.RemoveFront();
			}
			catch (const string& e)
			{
				Assert::AreEqual(e, string("ERROR:  Cannot remove from an empty list"), L"RemoveFromEmpty Exception Incorrect", LINE_INFO());
			}

			try
			{
				DoublyLinkedList<string> list;
				list.RemoveBack();
			}
			catch (const string& e)
			{
				Assert::AreEqual(e, string("ERROR:  Cannot remove from an empty list"), L"RemoveFromEmpty Exception Incorrect", LINE_INFO());
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		// Search Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(SearchSingleItem)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			Assert::AreEqual(true, list.Search("1"), L"SearchSingleItem Exists Incorrect", LINE_INFO());
			Assert::AreEqual(false, list.Search("0"), L"SearchSingleItem Does Not Exist Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"SearchSingleItem Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"SearchSingleItem Tail Incorrect", LINE_INFO());
			Assert::AreEqual(1, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"SearchSingleItem GetNbrOfNodes Incorrect", LINE_INFO());
		}

		TEST_METHOD(SearchMultipleItems)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			list.AddFront("2");
			list.AddFront("3");
			list.AddFront("4");
			list.AddFront("5");
			Assert::AreEqual(true, list.Search("1"), L"SearchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(true, list.Search("2"), L"SearchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(true, list.Search("3"), L"SearchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(true, list.Search("4"), L"SearchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(true, list.Search("5"), L"SearchMultipleItems Exists Incorrect", LINE_INFO());
			Assert::AreEqual(false, list.Search("0"), L"SearchMultipleItems Does Not Exist Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"SearchMultipleItems Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"SearchMultipleItems Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"SearchMultipleItems GetNbrOfNodes Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// Size Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(Size)
		{
			DoublyLinkedList<string> list;

			// Add 100 items to the list
			for (int i = 0; i < 100; ++i)
			{
				list.AddFront(to_string(i));
				Assert::AreEqual(i + 1, list.GetCount(), L"SizeAdd Count Incorrect", LINE_INFO());
				Assert::AreEqual(i + 1, list.Size(), L"SizeAdd Size Incorrect", LINE_INFO());
			}
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"Size Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"Size Tail Incorrect", LINE_INFO());
			Assert::AreEqual(100, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"Size GetNbrOfNodes Incorrect", LINE_INFO());

			// Remove 100 items from the list
			for (int i = 99; i >= 0; --i)
			{
				string item = list.RemoveFront();
				Assert::AreEqual(item, to_string(i), L"SizeRemove Item Incorrect", LINE_INFO());
				Assert::AreEqual(i, list.GetCount(), L"SizeRemove Count Incorrect", LINE_INFO());
				Assert::AreEqual(i, list.Size(), L"SizeRemove Size Incorrect", LINE_INFO());
			}
			Assert::AreEqual(nullptr, (int)list.GetHead(), L"Size Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail(), L"Size Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"Size GetNbrOfNodes Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// AssignmentOperator Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(AssignmentOperatorEmpty)
		{
			DoublyLinkedList<string> origList;
			DoublyLinkedList<string> newList = origList;

			Assert::AreEqual(0, newList.GetCount(), L"AssignmentOperatorEmpty Count Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)newList.GetHead(), L"AssignmentOperatorEmpty Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)newList.GetTail(), L"AssignmentOperatorEmpty Tail Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)origList.GetHead(), L"AssignmentOperatorEmpty Head Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)origList.GetTail(), L"AssignmentOperatorEmpty Tail Incorrect", LINE_INFO());
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperatorEmpty GetNbrOfNodes Incorrect", LINE_INFO());
		}

		TEST_METHOD(AssignmentOperatorSingleItem)
		{
			DoublyLinkedList<string> origList;
			origList.AddFront("1");
			DoublyLinkedList<string> newList = origList;

			Assert::AreEqual(1, newList.GetCount(), L"AssignmentOperatorSingleItem Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)newList.GetHead(), L"AssignmentOperatorSingleItem Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)newList.GetTail(), L"AssignmentOperatorSingleItem Tail Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperatorSingleItem Head Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperatorSingleItem Tail Incorrect", LINE_INFO());
			Assert::AreEqual(2, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperatorSingleItem GetNbrOfNodes Incorrect", LINE_INFO());

			{
				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "1....1";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperatorSingleItem Output Incorrect", LINE_INFO());
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "1....1";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperatorSingleItem Output Incorrect", LINE_INFO());
			}

			{
				// Remove last item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(1), item, L"AssignmentOperatorSingleItem Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(1, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperatorSingleItem GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperatorSingleItem Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperatorSingleItem Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperatorSingleItem Output Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)newList.GetHead(), L"AssignmentOperatorSingleItem Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)newList.GetTail(), L"AssignmentOperatorSingleItem Tail Incorrect", LINE_INFO());
			}
		}

		TEST_METHOD(AssignmentOperator)
		{
			DoublyLinkedList<string> origList;
			origList.AddFront("1");
			origList.AddFront("2");
			origList.AddFront("3");
			origList.AddFront("4");
			origList.AddFront("5");

			DoublyLinkedList<string> newList = origList;

			Assert::AreEqual(5, newList.GetCount(), L"AssignmentOperator Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			Assert::AreEqual(10, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());

			{
				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove from one of the lists
				string item = newList.RemoveBack();
				Assert::AreEqual<string>(to_string(1), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(9, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2....2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(5), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(8, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3->2....2->3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveBack();
				Assert::AreEqual<string>(to_string(2), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(7, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3....3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(4), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(6, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "3....3";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(3), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(5, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			}
		}

		TEST_METHOD(AssignmentOperatorOverwriteExisting)
		{
			DoublyLinkedList<string> origList;
			DoublyLinkedList<string> newList;
			for (int i = 1; i < 6; ++i)
			{
				origList.AddFront(to_string(i));
				newList.AddBack(to_string(i));
			}

			newList = origList;

			Assert::AreEqual(5, newList.GetCount(), L"AssignmentOperator Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			Assert::AreEqual(10, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());

			{
				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove from one of the lists
				string item = newList.RemoveBack();
				Assert::AreEqual<string>(to_string(1), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(9, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2....2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(5), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(8, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3->2....2->3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveBack();
				Assert::AreEqual<string>(to_string(2), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(7, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3....3->4";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(4), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(6, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "3....3";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(3), item, L"AssignmentOperator Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(5, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperator GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"AssignmentOperator Output Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)newList.GetHead(), L"AssignmentOperator Head Incorrect", LINE_INFO());
				Assert::AreEqual(nullptr, (int)newList.GetTail(), L"AssignmentOperator Tail Incorrect", LINE_INFO());
			}
		}

		TEST_METHOD(AssignmentOperatorSelf)
		{
			DoublyLinkedList<string> list;
			list.AddFront("1");
			list.AddFront("2");
			list.AddFront("3");
			list.AddFront("4");
			list.AddFront("5");

			list = list;

			const DoublyLinkedListNode<string>* const headNext = list.GetHead()->GetNext();
			const DoublyLinkedListNode<string>* const tailPrev = list.GetTail()->GetPrev();
			Assert::AreEqual(5, list.GetCount(), L"AssignmentOperatorSelf Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetHead(), L"AssignmentOperatorSelf Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list.GetTail(), L"AssignmentOperatorSelf Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"AssignmentOperatorSelf GetNbrOfNodes Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetHead()->GetPrev(), L"AssignmentOperatorSelf Head->Prev Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list.GetTail()->GetNext(), L"AssignmentOperatorSelf Tail->Next Incorrect", LINE_INFO());
			Assert::AreEqual((int)headNext, (int)list.GetHead()->GetNext(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
			Assert::AreEqual((int)tailPrev, (int)list.GetTail()->GetPrev(), L"AddMultipleItemBackRemoveMultipleItemBack Tail Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// CopyConstructor Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(CopyConstructor)
		{
			DoublyLinkedList<string> origList;
			origList.AddFront("1");
			origList.AddFront("2");
			origList.AddFront("3");
			origList.AddFront("4");
			origList.AddFront("5");

			DoublyLinkedList<string> newList(origList);

			Assert::AreEqual(5, newList.GetCount(), L"CopyConstructor Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)newList.GetHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)newList.GetTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
			Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());
			Assert::AreEqual(10, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"CopyConstructor GetNbrOfNodes Incorrect", LINE_INFO());

			{
				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove from one of the lists
				string item = newList.RemoveBack();
				Assert::AreEqual<string>(to_string(1), item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(9, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"CopyConstructor GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2....2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(5), item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(8, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"CopyConstructor GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3->2....2->3->4";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveBack();
				Assert::AreEqual<string>(to_string(2), item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(7, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"CopyConstructor GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "4->3....3->4";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(4), item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(6, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"CopyConstructor GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "3....3";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}

			{
				// Remove another item
				string item = newList.RemoveFront();
				Assert::AreEqual<string>(to_string(3), item, L"CopyConstructor Remove Item Incorrect", LINE_INFO());
				Assert::AreEqual(5, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"CopyConstructor GetNbrOfNodes Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetHead(), (int)newList.GetHead(), L"CopyConstructor Head Incorrect", LINE_INFO());
				Assert::AreNotEqual((int)origList.GetTail(), (int)newList.GetTail(), L"CopyConstructor Tail Incorrect", LINE_INFO());

				ostringstream stream;
				stream << newList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"CopyConstructor Output Incorrect", LINE_INFO());
			}
		}

		////////////////////////////////////////////////////////////////////////////////
		// Destructor Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(Destructor)
		{
			DoublyLinkedList<string>* list = new DoublyLinkedList<string>();
			delete list;
			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"Destructor GetNbrOfNodes Empty List Incorrect", LINE_INFO());

			list = new DoublyLinkedList<string>();
			list->AddFront("1");
			list->AddFront("2");
			list->AddFront("3");
			list->AddFront("4");
			list->AddFront("5");

			Assert::AreEqual(5, list->GetCount(), L"Destructor Count Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list->GetHead(), L"Destructor Head Incorrect", LINE_INFO());
			Assert::AreNotEqual(nullptr, (int)list->GetTail(), L"Destructor Tail Incorrect", LINE_INFO());
			Assert::AreEqual(5, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"Destructor GetNbrOfNodes Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list->GetHead()->GetPrev(), L"Destructor Head->Prev Incorrect", LINE_INFO());
			Assert::AreEqual(nullptr, (int)list->GetTail()->GetNext(), L"Destructor Tail->Next Incorrect", LINE_INFO());

			delete list;

			Assert::AreEqual(0, DoublyLinkedListNode<string>::GetNbrOfNodes(), L"Destructor GetNbrOfNodes Incorrect", LINE_INFO());
		}

		////////////////////////////////////////////////////////////////////////////////
		// Insertion Tests
		////////////////////////////////////////////////////////////////////////////////
		TEST_METHOD(Insertion)
		{
			DoublyLinkedList<string> origList;
			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "EMPTY LIST";
				Assert::AreEqual(expectedResult, actualResult, L"Insertion Operator Incorrect", LINE_INFO());
			}

			for (int i = 1; i < 6; ++i)
			{
				origList.AddFront(to_string(i));
			}

			{
				ostringstream stream;
				stream << origList;
				actualResult = stream.str();
				expectedResult = "5->4->3->2->1....1->2->3->4->5";
				Assert::AreEqual(expectedResult, actualResult, L"Insertion Operator Incorrect", LINE_INFO());
			}
		}

	};
}