#pragma once

struct node
{
	int value;
	node *next;
};

class list
{
private:
	node* first, *last;
public:
	list()
	{
		first = nullptr;
		last = nullptr;
	}

	void add_node(int n)
	{
		node *tmp = new node;
		tmp->value = n;
		tmp->next = nullptr;

		if (first == nullptr)
		{
			first = tmp;
			last = tmp;
		}
		else
		{
			last->next = tmp;
			last = last->next;
		}
	}

	int get_node_value(int n)
	{
		node *tmp = first;
		for (int i = 0; i < n; i++)
		{
			
		}
	}
};

class Math
{
public:
	static int Add(int, int);
	static int Add(int, int, int);
	static int Add(double, double);
	static int Add(double, double, double);
	static int Mul(int, int);
	static int Mul(int, int, int);
	static int Mul(double, double);
	static int Mul(double, double, double);
	static int Add(int count, ...);
	static char* Add(const char *, const char *);
};
