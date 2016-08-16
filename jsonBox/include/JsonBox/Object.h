#ifndef JB_OBJECT_H
#define JB_OBJECT_H

#include <iostream>
#include <map>
#include <string>

#include "Value.h"

namespace JsonBox {
	/**
	 * Represents a JSON object. It's a map with added methods. So the JSON
	 * object type can be used the same way as a standard STL map of string and
	 * Value, but can be more easily output in a stream.
	 * @see JsonBox::Value
	 */
	class Object {
	public:
		typedef std::map<std::string, Value> container;
		typedef container::key_type key_type; //键类型
		typedef container::mapped_type mapped_type; //值类型
		typedef container::value_type value_type; //键值对pair
		typedef container::size_type size_type; // 应该是个数的类型，一般就为int吧
		typedef container::difference_type difference_type;
		typedef container::key_compare key_compare; //我认为是 对键进行排序的比较函数
		typedef container::allocator_type allocator_type; //分配器
		typedef container::reference reference; // 这里应该是pair<string,Value>
		typedef container::const_reference const_reference;
		typedef container::pointer pointer; //分配器指针
		typedef container::const_pointer const_pointer;
		typedef container::iterator iterator;//迭代器
		typedef container::const_iterator const_iterator;
		typedef container::reverse_iterator reverse_iterator;//反向迭代器
		typedef container::const_reverse_iterator const_reverse_iterator;

		explicit Object(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

		template <typename InputIterator>
		explicit Object(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : data(first, last, comp, alloc) {
		}

		Object(const Object &other);

		Object &operator=(const Object &other);
		
		bool operator==(const Object &rhs) const;
		
		bool operator!=(const Object &rhs) const;
		
		bool operator<(const Object &rhs) const;
		
		bool operator<=(const Object &rhs) const;
		
		bool operator>(const Object &rhs) const;
		
		bool operator>=(const Object &rhs) const;

		allocator_type get_allocator() const;

		mapped_type &operator[](const key_type &key);

		iterator begin();

		const_iterator begin() const;

		iterator end();

		const_iterator end() const;

		reverse_iterator rbegin();

		const_reverse_iterator rbegin() const;

		reverse_iterator rend();

		const_reverse_iterator rend() const;

		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		void clear();

		std::pair<iterator, bool> insert(const_reference value);

		iterator insert(iterator hint, const_reference value);

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last) {
			data.insert(first, last);
		}

		void erase(iterator position);

		void erase(iterator first, iterator last);

		size_type erase(const key_type &key);

		void swap(Object &other);

		size_type count(const key_type &key) const;

		iterator find(const key_type &key);

		const_iterator find(const key_type &key) const;

		std::pair<iterator, iterator> equal_range(const key_type &key);

		std::pair<const_iterator, const_iterator> equal_range(const key_type &key) const;

		iterator lower_bound(const key_type &key);

		const_iterator lower_bound(const key_type &key) const;

		iterator upper_bound(const key_type &key);

		const_iterator upper_bound(const key_type &key) const;

		key_compare key_comp() const;
	private:
		container data;
	};

	/**
	 * Output operator overload for the JSON object. Outputs in standard JSON
	 * format. Indents the output and escapes the minimum characters.
	 * @param output Output stream in which to write the object's JSON.
	 * @param o Object to output into the stream.
	 * @return Output stream filled with the JSON code.
	 */
	std::ostream& operator<<(std::ostream& output, const Object& o);
}

#endif
