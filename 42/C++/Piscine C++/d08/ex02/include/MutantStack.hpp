#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void) {};
	virtual ~MutantStack(void) {};
	MutantStack(MutantStack const &src);
	MutantStack&	operator=(MutantStack const &rhs);

	class iterator
	{
	public:
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator++(void) { self_type i = *this; ptr_++; return i; }
		self_type operator++(int junk) {(void)junk; ptr_++; return *this; }
		self_type operator--(void) { self_type i = *this; ptr_--; return i; }
		self_type operator--(int junk) {(void)junk; ptr_--; return *this; }
		reference operator*(void) { return *ptr_; }
		pointer operator->(void) { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
	};

	class const_iterator
	{
	public:
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef int difference_type;
		typedef std::forward_iterator_tag iterator_category;
		const_iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator++(void) { self_type i = *this; ptr_++; return i; }
		self_type operator++(int junk) {(void)junk; ptr_++; return *this; }
		self_type operator--(void) { self_type i = *this; ptr_--; return i; }
		self_type operator--(int junk) {(void)junk; ptr_--; return *this; }
		const value_type &operator*(void) { return *ptr_; }
		const pointer operator->(void) { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
	};

	iterator		begin(void) {
		return (iterator(&MutantStack::c[0]));
	}

	iterator		end(void) {
		return (iterator(&MutantStack::c[this->size()]));
	}

	const_iterator	begin(void) const {
		return (const_iterator(&MutantStack::c[0]));
	}

	const_iterator	end(void) const {
		return (const_iterator(&MutantStack::c[this->size()]));
	}

protected:
private:
};

#endif
