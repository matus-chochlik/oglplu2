/**
 *  @file eagine/flat_map.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_FLAT_MAP_1509260923_HPP
#define EAGINE_FLAT_MAP_1509260923_HPP

#include <utility>
#include <algorithm>
#include <stdexcept>
#include <vector>

namespace eagine {

template <typename Key, typename Val, typename Cmp>
struct flat_map_ops
{
	typedef std::pair<const Key, Val> value_type;
	struct value_compare
	{
		Cmp key_comp;
		bool operator()(const value_type& a, const value_type& b) const
		{
			return key_comp(a.first, b.first);
		}

		bool operator()(const value_type& a, const Key& b) const
		{
			return key_comp(a.first, b);
		}

		bool operator()(const Key& a, const value_type& b) const
		{
			return key_comp(a, b.first);
		}
	} value_comp;

	template <typename I>
	static bool empty(I b, I e)
	noexcept
	{
		return b == e;
	}

	template <typename I>
	static auto size(I b, I e)
	noexcept
	{
		using ::std::distance;
		return static_cast<std::size_t>(distance(b, e));
	}

	template <typename I>
	auto lower_bound(I b, I e, const Key& key) const
	noexcept
	{
		return ::std::lower_bound(b, e, key, value_comp);
	}

	template <typename I>
	auto upper_bound(I b, I e, const Key& key) const
	noexcept
	{
		return ::std::upper_bound(b, e, key, value_comp);
	}

	template <typename I>
	auto equal_range(I b, I e, const Key& key) const
	noexcept
	{
		return ::std::equal_range(b, e, key, value_comp);
	}

	template <typename I>
	auto find(I b, I e, const Key& key) const
	noexcept
	{
		b = lower_bound(b, e, key);
		if((b != e) && value_comp.key_comp(b->first, key))
		{
			b = e;
		}
		return b;
	}

	template <typename I>
	auto& at(I b, I e, const Key& key) const
	{
		b = find(b, e, key);
		if(b == e) throw std::out_of_range("Invalid flat map key");
		return b->second;
	}

	template <typename I>
	auto& get(I b, I e, const Key& key) const
	{
		b = find(b, e, key);
		assert(b != e);
		return b->second;
	}
};

template <typename Key, typename Val, typename Cmp, typename Derived>
class flat_map_view_crtp
{
private:
	const Derived&
	_self(void) const { return *static_cast<const Derived*>(this); }

	Derived&
	_self(void) { return *static_cast<Derived*>(this); }

	auto _b(void) const { return _self().begin(); }
	auto _b(void) { return _self().begin(); }

	auto _e(void) const { return _self().end(); }
	auto _e(void) { return _self().end(); }
protected:
	typedef flat_map_ops<Key, Val, Cmp> _ops_t;
	_ops_t _ops;
public:
	typedef Key key_type;
	typedef Val mapped_type;
	typedef std::pair<const Key, Val> value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;

	typedef Cmp key_compare;
	typedef typename _ops_t::value_compare value_compare;

	const key_compare& key_comp(void) const
	{
		return _ops.value_comp.key_comp;
	}

	const value_compare& value_comp(void) const
	{
		return _ops.value_comp;
	}

	bool empty(void) const
	{
		return _ops.empty(_b(), _e());
	}

	auto size(void) const
	{
		return _ops.size(_b(), _e());
	}

	auto find(const Key& key)
	{
		return _ops.find(_b(), _e(), key);
	}

	auto find(const Key& key) const
	{
		return _ops.find(_b(), _e(), key);
	}

	auto lower_bound(const Key& key)
	{
		return _ops.lower_bound(_b(), _e(), key);
	}

	auto lower_bound(const Key& key) const
	{
		return _ops.lower_bound(_b(), _e(), key);
	}

	auto upper_bound(const Key& key)
	{
		return _ops.upper_bound(_b(), _e(), key);
	}

	auto upper_bound(const Key& key) const
	{
		return _ops.upper_bound(_b(), _e(), key);
	}

	auto equal_range(const Key& key)
	{
		return _ops.equal_range(_b(), _e(), key);
	}

	auto equal_range(const Key& key) const
	{
		return _ops.equal_range(_b(), _e(), key);
	}

	Val& at(const Key& key)
	{
		return _ops.at(_b(), _e(), key);
	}

	const Val& at(const Key& key) const
	{
		return _ops.at(_b(), _e(), key);
	}
};

template <
	typename Key,
	typename Val,
	typename Cmp = std::less<Key>,
	typename Allocator = std::allocator<std::pair<const Key, Val>>
> class flat_map
 : public flat_map_view_crtp<Key, Val, Cmp, flat_map<Key, Val, Cmp, Allocator>>
{
private:
	typedef flat_map_view_crtp<
		Key, Val, Cmp,
		flat_map<Key, Val, Cmp, Allocator>
	> _base;

	typedef std::vector<std::pair<const Key, Val>, Allocator> _cvec_t;
	typedef std::vector<std::pair<Key, Val>, Allocator> _vec_t;
	_vec_t _vec;

	typename _cvec_t::const_iterator
	_cast(typename _vec_t::const_iterator i) {
		return *reinterpret_cast<typename _cvec_t::const_iterator*>(&i);
	}

	typename _cvec_t::iterator
	_cast(typename _vec_t::iterator i) {
		return *reinterpret_cast<typename _cvec_t::iterator*>(&i);
	}

	typename _vec_t::const_iterator
	_cast(typename _cvec_t::const_iterator i) {
		return *reinterpret_cast<typename _vec_t::const_iterator*>(&i);
	}

	typename _vec_t::iterator
	_cast(typename _cvec_t::iterator i) {
		return *reinterpret_cast<typename _vec_t::iterator*>(&i);
	}
public:
	using typename _base::key_type;
	using typename _base::mapped_type;
	using typename _base::value_type;
	using typename _base::key_compare;
	typedef typename _vec_t::size_type size_type;
	typedef typename _vec_t::difference_type difference_type;
	typedef typename _cvec_t::iterator iterator;
	typedef typename _cvec_t::const_iterator const_iterator;
	typedef Allocator allocator_type;

	using _base::key_comp;
	using _base::value_comp;
	using _base::lower_bound;

	flat_map(void) = default;
	flat_map(const flat_map&) = default;
	flat_map(flat_map&&) = default;
	flat_map& operator = (const flat_map&) = default;
	flat_map& operator = (flat_map&&) = default;

	flat_map(std::initializer_list<std::pair<Key, Val>> il)
	{
		assign(il);
	}

	void assign(std::initializer_list<std::pair<Key, Val>> il)
	{
		_vec = _vec_t(il);
		std::sort(_vec.begin(), _vec.end(), value_comp());
	}

	bool empty(void) const
	{
		return _vec.empty();
	}

	size_type size(void) const
	{
		return _vec.size();
	}

	size_type max_size(void) const
	{
		return _vec.max_size();
	}

	void reserve(size_type sz)
	{
		_vec.reserve(sz);
	}

	void clear(void)
	{
		_vec.clear();
	}

	iterator begin(void)
	{
		return _cast(_vec.begin());
	}

	const_iterator begin(void) const
	{
		return _cast(_vec.begin());
	}

	iterator end(void)
	{
		return _cast(_vec.end());
	}

	const_iterator end(void) const
	{
		return _cast(_vec.end());
	}

	std::pair<iterator, bool>
	insert(const value_type& value)
	{
		auto p = this->_ops.lower_bound(
			_vec.begin(), _vec.end(),
			value.first
		);
		if(p->first == value.first) {
			p->second = value.second;
			return {_cast(p), false};
		}
		return {_cast(_vec.insert(p, value)), true};
	}

	iterator
	insert(iterator p, const value_type& value)
	{
		if(p == end()) {
			if(_vec.empty() || value_comp()(_vec.back(), value)) {
				return _cast(_vec.insert(_cast(p), value));
			}
			p = _cast(this->_ops.lower_bound(
				_vec.begin(), _vec.end(),
				value.first
			));
		}
		if(value.first == p->first) {
			p->second = value.second;
			return p;
		}
		if(key_comp()(value.first, p->first)) {
			if(p != begin()) {
				p = _cast(this->_ops.lower_bound(
					_vec.begin(), _cast(p),
					value.first
				));
			}
		} else {
			p = _cast(this->_ops.lower_bound(
				_cast(p), _vec.end(),
				value.first
			));
		}
		return _cast(_vec.insert(_cast(p), value));
	}

	iterator erase(iterator p)
	{
		return _cast(_vec.erase(_cast(p)));
	}

	iterator erase(iterator f, iterator t)
	{
		return _cast(_vec.erase(_cast(f), _cast(t)));
	}

	size_type erase(const Key& key)
	{
		auto p = this->_ops.equal_range(
			_vec.begin(),
			_vec.end(),
			key
		);
		_vec.erase(p.first, p.second);
		return size_type(std::distance(p.first, p.second));
	}
};

} // namespace eagine

#endif // include guard
