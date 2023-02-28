#pragma once

template<class Type>
class iterator {
public:
	iterator(Type* ptr) :
		m_ptr(ptr) {}

	iterator& operator++() {
		m_ptr++;
		return *this;
	}

	iterator& operator--() {
		m_ptr--;
		return *this;
	}

	bool operator!=(const iterator& other) const {
		return m_ptr != other.m_ptr;
	}

	Type& operator*() const {
		return *m_ptr;
	}
private:
	Type* m_ptr;
};