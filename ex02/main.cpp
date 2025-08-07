#include "MutantStack.hpp"

int main()
{
	std::cout << "MutantStack basic operations:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	std::cout << "\nIterating MutantStack (forward):" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nIterating MutantStack (reverse):" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	for (; rit != rite; ++rit)
		std::cout << *rit << std::endl;

	std::cout << "\nTesting const iterators:" << std::endl;
	const MutantStack<int> cmstack(mstack);
	MutantStack<int>::const_iterator cit = cmstack.begin();
	MutantStack<int>::const_iterator cite = cmstack.end();
	for (; cit != cite; ++cit)
		std::cout << *cit << std::endl;

	std::cout << "\nTesting reverse const iterators:" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = cmstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = cmstack.rend();
	for (; crit != crite; ++crit)
		std::cout << *crit << std::endl;
	
	std::cout << "\nTesting assignment operator:" << std::endl;
	MutantStack<int> assignStack;
	assignStack = mstack;
	for (MutantStack<int>::iterator ait = assignStack.begin(); ait != assignStack.end(); ++ait)
		std::cout << *ait << std::endl;


	std::cout << "\nTesting compatitibilty with std::stack:" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Top of std::stack: " << s.top() << std::endl;
	return 0;
}
