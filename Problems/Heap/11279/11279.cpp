// This problem can be solved much easier using std::priority_queue.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#define MAXN 100001

using namespace std;

// 1-index start binary tree
struct Heap
{
	int container[MAXN];
	int size;

	Heap()
	{
		for (int i = 0; i < MAXN; i++)
		{
			container[i] = 0;
		}
		this->size = 0;
	}

	bool empty()
	{
		return !size;
	}

	void push(int elem)
	{
		container[++size] = elem;
		auto cur = size;
		
		while (cur > 1)
		{
			auto parent = cur / 2;
			if (container[parent] < container[cur])
			{
				int temp = container[cur];
				container[cur] = container[parent];
				container[parent] = temp;
			}
			else
			{
				break;
			}
			cur = parent;
		}
	}

	int pop()
	{
		int top = container[1];
		container[1] = container[size--];
		auto cur = 1;

		while (cur * 2 <= size)
		{
			int left = cur * 2;
			int right = cur * 2 + 1;

			int next;
			if (right > size)
			{
				next = left;
			}
			else
			{
				next = container[left] < container[right] ? right : left;
			}

			if (container[cur] < container[next])
			{
				auto temp = container[cur];
				container[cur] = container[next];
				container[next] = temp;
			}
			else
			{
				break;
			}

			cur = next;
		}

		return top;
	}
};

Heap maxHeap;

int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int input;
		scanf("%d", &input);

		if (input == 0)
		{
			if (maxHeap.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", maxHeap.pop());
			}
		}
		else
		{
			maxHeap.push(input);
		}
	}

	return 0;
}