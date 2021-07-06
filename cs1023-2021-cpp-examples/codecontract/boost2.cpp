#include <boost/contract.hpp>
#include <utility>
#include <algorithm>
#include<iterator>
#include <iostream>
#include <vector>
#include <concepts>

// TDD : Test Driven Development
//  Specify in unambiguous terms what you want the program to do - Documentation
// Dafny (static), Eiffel (static, runtime)

// Turing complete - anything that can be computed
// Busy beaver functions are uncomputable


// [ expects : vec.size() >=1]
// [ ensures : sortedness ]
template <std::totally_ordered T> 
void mysort(std::vector<T>& vec)
{
	boost::contract::old_ptr_if_copyable<std::vector<T>> old_v = BOOST_CONTRACT_OLDOF(vec); 
	boost::contract::check c = boost::contract::function()
	.precondition([&vec=std::as_const(vec)]{
		BOOST_CONTRACT_ASSERT(vec.size()>=1);

	})
	.postcondition([&vec=std::as_const(vec)]{

		size_t sz=vec.size();
		for(unsigned i=0;i<sz-1;i++)
		{
			BOOST_CONTRACT_ASSERT(vec[i]<=vec[i+1]);
		}
	});
	size_t sz= vec.size();
	for(unsigned i=0;i<sz-1;i++)
	{
		for(unsigned j=i+1;j<sz-1;j++)
		{
			if(vec[i]>vec[j])
			{
				std::swap(vec[i],vec[j]);
			}
		}
	}
	return;
}

int main()
{
	std::vector<int> v = {-1,-4,-23,0,98,45,23,53};
	std::copy(std::begin(v),std::end(v),std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
	mysort(v);
	std::copy(std::begin(v),std::end(v),std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;
	return 0;
}