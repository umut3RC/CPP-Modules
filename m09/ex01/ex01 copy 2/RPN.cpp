#include "RPN.hpp"

std::stack<int>	st_pushBack(std::stack<int> *st)
{
	std::stack<int> val;

	while (st->size())
	{
		val.push(st->top());
		st->pop();
	}
	return (val);
}

bool	checkArgument(std::string argv)
{
	if (!argv.find_first_not_of(" 0123456789+-/*"))
	{
		std::cerr << "Error: Invalid Characters in argument!\n";
		return (false);
	}
	else
	{
		for (int i = 0; argv[i]; i++)
		{
			//std::cout << argv[i] << " -*- " << i << std::endl;
			if (i % 2 == 0)
			{
				if (argv[i] != ' ' 
					&& (isdigit(argv[i])
					|| argv[i == '-']
					|| argv[i == '+']
					|| argv[i == '/']
					|| argv[i == '*']))
					continue;
				else
				{
					std::cerr << "Error: Invalid Characters in argument!\n";
					return (false);
				}
			}
			else if (argv[i] != ' ')
			{
				std::cerr << "Error: Invalid Characters in argument!\n";
				return (false);
			}
		}
	}
	return (true);
}

int	applySign(char sign, std::stack<int> &st)
{
	int	val = 0;
	//std::cout << "Sign-> " << sign << "\n";
	switch (sign)
	{
	case 43:// +  53
		{
			val = st.top();
			st.pop();
			val += st.top();
			st.pop();
			break;
		}
	case 45:// -  55
		{
			val = st.top();
			st.pop();
			val -= st.top();
			st.pop();
			break;
		}
	case 47:// /  57
		{
			val = st.top();
			st.pop();
			val /= st.top();
			st.pop();
			break;
		}
	case 42:// * 52
		{
			val = st.top();
			st.pop();
			val *= st.top();
			st.pop();
			break;
		}
	default:
		break;
	}
	//std::cout << "->" << st.size() << "\n";
	return (val);
}

// char	getApplySign(std::stack<int> st)
// {
// 	char	ch;
// 	while (st.size() && st.top() < 10)
// 		st.pop();
// 	ch = st.top();
// 	return (ch);
// }

void	calculateValue (std::stack<int> &st)
{
	std::stack<int>	values;
	while ((int)st.size() > 0)
	{
		// std::cout << "top: " << st.top() << "\n";
		// if (st.top() < 10 && st.top() > -1)
		// {
		// 	values.push(st.top());
		// 	st.pop();
		// }
		// else if (st.top() != ' ')
		// {
		// 	values = push_back(&values);
		// 	values.push(applySign(st.top(), values));
		// 	st.pop();
		// }
		if (st.top() < 10)
		{
			values.push(st.top());
			values = st_pushBack(&values);
			st.pop();
		}
		else if (values.size() > 1)
		{
			//std::cout << "else-> " << st.top() << std::endl;
			values.push(applySign(st.top(), values));
			st.pop();
		}
		else
			throw (std::logic_error("Error: Invalid format"));
	}
	std::cout << "--> " << values.top() << std::endl;
}

void	setArgument(char *argv)
{
	try
	{
		if (checkArgument(argv))
		{
			std::stack<int>	args;
			for (int i = (int)strlen(argv) - 1; i > -1; i--)
			{
				if (argv[i] != ' ')
				{
					if (argv[i] >= '*' && argv[i] <= '/')
					{
						//std::cout << "argv: " << argv[i] << "\n";
						args.push((int)argv[i]);
					}
					else
						args.push(argv[i] - '0');
				}
			}
			calculateValue(args);
		}
	}
	catch( const std::exception &e )
	{
		std::cerr << e.what() << '\n';
	}
}

