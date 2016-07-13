#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template<typename T>
int								easyfind(T const &t, int const i) {
	typename T::const_iterator	it;

	it = std::find(t.begin(), t.end(), i);
	if (it != t.end()) {
		return (std::distance(t.begin(), it));
	} else {
		return (-1);
	}
}

#endif
