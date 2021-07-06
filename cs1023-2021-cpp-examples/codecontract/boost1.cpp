#include <boost/contract.hpp> 
#include <utility>
#include <type_traits>
#include <iostream>

int inc(int& x) {
    int result;
    boost::contract::old_ptr<int> old_x = BOOST_CONTRACT_OLDOF(x);
    // post condition, often refers to old_values
    boost::contract::check c = boost::contract::function()
        .precondition([&x=std::as_const(x)] {
            BOOST_CONTRACT_ASSERT(x < std::numeric_limits<int>::max());
           //assert(x<std::numeric_limits<int>::max());
        })
        .postcondition([&] {
            BOOST_CONTRACT_ASSERT(x == *old_x + 1);
            BOOST_CONTRACT_ASSERT(result == *old_x);
        })
        .except([&] {
            BOOST_CONTRACT_ASSERT(x == *old_x);
        })
    ;

    --x;
    return result = x++; // Function body.
   // return x++;
}

int main()
{
	int x = 5;
	
	std::cout << x << std::endl;
	int y=inc(x);
	std::cout << x << ":" << y << std::endl;
    //int z = std::numeric_limits<int>::max();
    //std::cout << inc(z) << std::endl;
	return 0;
}