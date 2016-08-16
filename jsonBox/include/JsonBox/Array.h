#ifndef JB_ARRAY_H
#define JB_ARRAY_H

#include <iostream>
#include <vector>

#include "Value.h"

namespace JsonBox {
	/**
	 * Represents an array of values in JSON. It's a vector with added methods.
	 * So it can be used the same way as a standard STL vector, but can be more
	 * easily output in a stream.
	 * @see JsonBox::Value
	 */
	class Array {
	public:
		typedef std::vector<Value> container;
		typedef container::value_type value_type; //元素类型
		typedef container::allocator_type allocator_type;//分配器类型
		typedef container::size_type size_type; //元素个数类型，我感觉一般就是int
		typedef container::difference_type difference_type;
		typedef container::reference reference;//我估计是自身元素的类型，这里的话就是Value
		typedef container::const_reference const_reference;
		typedef container::pointer pointer;//我的理解：迭代器里面的指针
		typedef container::const_pointer const_pointer;
		typedef container::iterator iterator; //返回可变的迭代器
		typedef container::const_iterator const_iterator; //返回不可变的迭代器
		typedef container::reverse_iterator reverse_iterator;
		typedef container::const_reverse_iterator const_reverse_iterator;

		Array(const allocator_type &alloc = allocator_type());//默认参数，初始化分配器

		explicit Array(size_type count, const_reference value = value_type(), const allocator_type &alloc = allocator_type());

		template <typename InputIterator>
		Array(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : data(first, last) {
		}

		Array(const Array &other);

		Array &operator=(const Array &other);

		bool operator==(const Array &rhs) const;

		bool operator!=(const Array &rhs) const;

		bool operator<(const Array &rhs) const;

		bool operator<=(const Array &rhs) const;

		bool operator>(const Array &rhs) const;

		bool operator>=(const Array &rhs) const;

        
        
		void assign(size_type count, const_reference value);

		template <typename InputIterator>
		void assign(InputIterator first, InputIterator last) {
			data.assign(first, last);
		}
        //返回分配器
		allocator_type get_allocator() const;
        //返回第几个元素
		reference at(size_type pos);

		const_reference at(size_type pos) const;

		reference operator[](size_type pos); //返回第几个元素，这里类型为Value

		const_reference operator[](size_type pos) const;

		reference front();

		const_reference front() const;

		reference back();

		const_reference back() const;

		iterator begin();

		const_iterator begin() const;

		iterator end();

		const_iterator end() const;

		reverse_iterator rbegin(); //应该是反序迭代器

		const_reverse_iterator rbegin() const;

		reverse_iterator rend();

		const_reverse_iterator rend() const;

		bool empty() const;

		size_type size() const; //元素个数

		size_type max_size() const; //元素最大容量

		void reserve(size_type size);

		size_type capacity() const;

		void clear();

		
        
        //插入元素
        iterator insert(iterator pos, const_reference value);

		void insert(iterator pos, size_type count, const_reference value);

		template <typename InputIterator>
		void insert(iterator pos, InputIterator first, InputIterator last) {
			data.insert(pos, first, last);
		}
        
        
        

		iterator erase(iterator pos);

		iterator erase(iterator first, iterator last);//删除迭代器区间的元素

        
        
		void push_back(const_reference value);//把新元素插在后面

		void pop_back();

		void resize(size_type count, const_reference value = value_type());

		void swap(Array &other);//交换两个数组的值
	private:
		container data;
	};

	/**
	 * Output operator overload for the JSON array. Outputs in standard JSON
	 * format. Indents the output and esapes the minimum characters.
	 * @param output Output stream in which to write the array's JSON.
	 * @param a Array to output into the stream.
	 * @return Output stream filled with the JSON code.
	 */
	std::ostream &operator<<(std::ostream &output, const Array &a);
}

#endif
