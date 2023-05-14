/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:16:09 by ntan              #+#    #+#             */
/*   Updated: 2022/10/27 14:51:20 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

// #include <iterator>
#include <stdexcept>
#include <memory>
#include <iostream>
#include <typeinfo>
#include "utils/ft_containers_utils.hpp"
#include <limits>

namespace ft
{
	
template < typename T, typename Allocator = std::allocator<T> >
class vector
{
	public :
		typedef					T										value_type;
		typedef					Allocator								allocator_type;
	
		typedef	typename		allocator_type::reference				reference;
		typedef	typename		allocator_type::const_reference			const_reference;
		typedef	typename		allocator_type::pointer					pointer;
		typedef	typename		allocator_type::const_pointer			const_pointer;
		
		// typedef	typename		__gnu_cxx::__normal_iterator<pointer, vector>		iterator;
		// typedef	typename		__gnu_cxx::__normal_iterator<const_pointer, vector>			const_iterator;
		typedef	typename		ft::iterator<pointer>					iterator;
		typedef	typename		ft::iterator<const_pointer>				const_iterator;
		typedef	typename		ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	typename		ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		typedef					ptrdiff_t						difference_type;
		typedef					size_t							size_type;
			

	private :
		allocator_type	_alloc;
		pointer			_start;
		pointer			_finish;
		pointer			_end_of_storage;
	
	public : 
		
		/////////////
		/// UTILS ///
		/////////////
		
		// void	print(std::string msg)
		// {
		// 	iterator	beg = this->begin();
		// 	iterator	end = this->end();
		// 	int i = 0;
		// 	std::cout << "\n========\n" << std::endl;

		// 	std::cout << msg << std::endl;
		// 	std::cout << "Capacity : " << this->capacity() << std::endl;	
		// 	std::cout << "Size : " << this->size() << std::endl;			
		// 	while (beg != end)
		// 	{
		// 		std::cout << "[" << i << "] = " << *beg << std::endl;
		// 		beg++; 
		// 		i++;
		// 	}
		// 	std::cout << "\n========\n" << std::endl;
		// }

		/////////////
		
		explicit vector(const allocator_type& alloc = allocator_type()) : 
		_alloc(alloc), _start(NULL), _finish(NULL), _end_of_storage(NULL)
		{}

		explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()) :
		_alloc(alloc), _start(NULL), _finish(NULL), _end_of_storage(NULL)
		{
			if (n > this->max_size())
				throw(std::length_error("Can't construct with this size"));
			insert(begin(), n, val);
		}
		
		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type()) :
		_alloc(alloc), _start(NULL), _finish(NULL), _end_of_storage(NULL)
		{
			insert(begin(), first, last);
		}

		vector (const vector& x) :
		_alloc(x.get_allocator()), _start(NULL), _finish(NULL), _end_of_storage(NULL)
		{
			insert(begin(), x.begin(), x.end());
		}

		~vector()
		{
			clear();
			if (_start != NULL)
				_alloc.deallocate(_start, capacity());
		}
		
		vector &operator=(const vector& x)
		{
			assign(x.begin(), x.end());
			return (*this);
		}

		/////////////////
		/// ITERATORS /// 
		/////////////////

		iterator begin()
		{
			return (iterator(_start));
		}
		
		const_iterator begin() const
		{
			return (const_iterator(_start));
		}

		iterator end()
		{
			return (iterator(_finish));
		}
		
		const_iterator end() const
		{
			return (const_iterator(_finish));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator rend() const
		{
			return ( const_reverse_iterator(begin()) );
		}
		
		////////////////
		/// CAPACITY ///
		////////////////

		size_type	size() const
		{
			return (size_type(_finish - _start));
		}

		size_type	max_size() const
		{
			return (_alloc.max_size());
		}

		void		resize(size_type n, value_type val = value_type())
		{
			if (n > this->size())
				insert(this->end(), n - this->size(), val);
			else if (n < this->size())
				erase(begin() + n, end());
		}

		size_type	capacity() const
		{
			return (size_type(_end_of_storage - _start));													
		}

		bool		empty() const
		{
			return (begin() == end());
		}

		void		reserve(size_type n)
		{
			if (n > this->max_size())
				throw(std::length_error("Length error"));
			if (this->capacity() < n)
			{
				const size_type 	old_size = this->size();
				pointer				tmp = _alloc.allocate(n);
				pointer				new_storage = tmp;
				pointer				old_start = _start;
				while (old_start != _finish)
				{
					_alloc.construct(new_storage, *old_start);
					_alloc.destroy(old_start);
					new_storage++;
					old_start++;
				}
				// std::cout << "BEFORE DEALLOCATE " << _start << std::endl;
				if (_start != NULL)
					_alloc.deallocate(_start, this->capacity());
				_start = tmp;
				_finish = tmp + old_size;
				_end_of_storage = _start + n;
			}
		}

		//////////////////////
		/// ELEMENT ACCESS ///
		//////////////////////
		
		reference operator[](size_type n)
		{
			return ( *(_start + n) );
		}
		
		const_reference operator[] (size_type n) const
		{
			return ( *(_start + n) );
		}

		reference at(size_type n)
		{
			if (n >= this->size())
				throw(std::out_of_range("at element access out of range"));
			return ( (*this)[n] );
		}

		const_reference at (size_type n) const
		{
			if (n >= this->size())
				throw(std::out_of_range("at element access out of range"));
			return ( (*this)[n] );
		}

		reference front()
		{
			return (*begin());
		}
		
		const_reference front() const
		{
			return (*begin());
		}

		reference back()
		{
			return (*(end() - 1));
		}
		
		const_reference back() const
		{
			return (*(end() - 1));
		}

		pointer	data()
		{
			return (std::__addressof(front()));
		}

		const_pointer data() const
		{
			return (std::__addressof(front()));
		}


		/////////////////
		/// MODIFIERS ///
		/////////////////

		template <class InputIterator> 
		void assign (InputIterator first, InputIterator last)
		{
			clear();
			insert(begin(), first, last);
		}
	
		void assign (size_type n, const value_type& val)
		{
			clear();
			insert(begin(), n, val);
		}

		void push_back (const value_type& val)
		{
			if (_finish != _end_of_storage)
			{
				_alloc.construct(_finish, val);
				++_finish;
			}
			else
				insert(end(), val);
		}

		void pop_back()
		{
			--_finish;
			_alloc.destroy(_finish);
		}
		
		iterator insert (iterator position, const value_type& val)
		{
			if (this->size() == this->capacity())
			{
				size_type	old_pos = position - this->begin();
				this->reserve((this->capacity() + 1) * 2);
				position = old_pos + this->begin();
			}
			iterator	it = this->end();
			while (it > position)
			{
				_alloc.construct(it.base(), *(it - 1));
				_alloc.destroy((it - 1).base());
				it--;
			}
			_alloc.construct(it.base(), val);
			_finish++;
			return (position);
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n > this->max_size())
				throw(std::length_error("Length error"));
			// for (size_type i = 0; i < n; i++)
			// {
			// 	position = this->insert(position, val);
			// 	position++;
			// }
			
			ft::vector<value_type> test;
			for (size_type i = 0; i < n; i++)
			{
				test.push_back(val);
			}
			this->insert(position, test.begin(), test.end());
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			if (first == last)
				return;

			if (typeid(typename ft::iterator_traits<InputIterator>::iterator_category) == typeid(std::input_iterator_tag))
			{
				while (first != last)
				{
					position = this->insert(position, *first);
					first++;
					position++;
				}
			}
			else
			{
				InputIterator tmp(first);
				size_type range = 0;
				while (tmp != last)
				{
					tmp++;
					range++;
				}
				if (this->size() + range >= this->capacity())
				{
					size_type old_pos = position - this->begin();
					this->reserve((this->capacity() + range) * 2);
					position = old_pos + this->begin();
				}
				iterator it = this->end() + range - 1;
				while (it >= (position + range))
				{
					_alloc.construct(it.base(), *(it - range));
					_alloc.destroy((it - range).base());
					it--;
				}
				it = position;
				while (first != last)
				{
					_alloc.construct(it.base(), *first);
					it++;
					first++;
				}
				_finish += range;
			}
		}

		iterator erase(iterator position)
		{
			_alloc.destroy(position.base());
			if (position + 1 != this->end())
			{
				iterator it = position;
				while (it < this->end() - 1)
				{
					_alloc.construct(it.base(), *(it + 1));
					_alloc.destroy((it + 1).base());
					it++;
				}
			}
			_finish--;
			return (position);
		}
		
		iterator erase(iterator first, iterator last)
		{
			if (first == last)
				return (first);
			for (iterator it = first; it != last && it != end(); it++)
				_alloc.destroy(it.base());
			iterator it = first;
			while (it + (last - first) < end())
			{
				_alloc.construct(it.base(), *(it + (last - first)));
				_alloc.destroy((it + (last - first)).base());
				it++;
			}
			_finish -= (last - first);
			// while (first != last)
			// {
			// 	last--;
			// 	erase(last);
			// }
			return (first);
		}

		void swap(vector& x)
		{
			allocator_type	tmp_alloc = _alloc;
			pointer			tmp_start = _start;
			pointer			tmp_finish = _finish;
			pointer			tmp_end_of_storage = _end_of_storage;

			_alloc = x._alloc;
			_start = x._start;
			_finish = x._finish;
			_end_of_storage = x._end_of_storage;

			x._alloc = tmp_alloc;
			x._start = tmp_start;
			x._finish = tmp_finish;
			x._end_of_storage = tmp_end_of_storage;
		}

		void clear()
		{
			if (_start != NULL)
			{
				while (_start != _finish)
				{
					_finish--;
					_alloc.destroy(_finish);
				}
			}
		}

		allocator_type get_allocator() const
		{
			return (allocator_type(_alloc));
		}
}; 	/// end of vector class

	template < typename T, typename Alloc >
	bool	operator==(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
	{
		return (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()));
	}
	
	template < typename T, typename Alloc >
	bool	operator<(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
	
	template < typename T, typename Alloc >
	bool	operator!=(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
	{
		return (!(x == y));
	}

	template < typename T, typename Alloc >
	bool	operator>(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
	{
		return (y < x);
	}

	template < typename T, typename Alloc >
	bool	operator<=(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
	{
		return (!(y < x));
	}

	template < typename T, typename Alloc >
	bool	operator>=(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
	{
		return (!(x < y));
	}

	template < typename T, typename Alloc >
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	}

}

#endif