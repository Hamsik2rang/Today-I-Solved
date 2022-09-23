#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAXN (20'001)

class Deque
{
private:
	int m_container[MAXN];
	int m_front;
	int m_rear;

public:
	Deque() : m_front{ MAXN / 2 }, m_rear{ MAXN / 2 }, m_container{ 0 } {}
	
	void push_front(int x)
	{
		m_container[m_front--] = x;
	}

	void push_back(int x)
	{
		m_container[++m_rear] = x;
	}

	bool empty()
	{
		if (m_rear <= m_front)
		{
			return true;
		}
		return false;
	}

	int pop_front()
	{
		if (empty())
		{
			return -1;
		}
		return m_container[++m_front];
	}

	int pop_back()
	{
		if (empty())
		{
			return -1;
		}
		return m_container[m_rear--];
	}


	int front()
	{
		if (empty())
		{
			return -1;
		}
		return m_container[m_front + 1];
	}

	int back()
	{
		if (empty())
		{
			return -1;
		}
		return m_container[m_rear];
	}

	int size()
	{
		return m_rear - m_front;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	Deque dq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;
		if (command == "push_back")
		{
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (command == "push_front")
		{
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (command == "empty")
		{
			cout << (int)dq.empty() << "\n";
		}
		else if (command == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (command == "pop_back")
		{
			cout << dq.pop_back() << "\n";
		}
		else if (command == "pop_front")
		{
			cout << dq.pop_front() << "\n";
		}
		else if (command == "front")
		{
			cout << dq.front() << "\n";
		}
		else
		{
			cout << dq.back() << "\n";
		}
	}

	return 0;
}