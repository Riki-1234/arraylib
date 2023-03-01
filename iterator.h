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

	void operator++(Type) {
		m_ptr++;
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

	iterator operator+(size_t amount) {
		iterator it(*this);
		it.m_ptr += amount;
		return it;
	}
private:
	Type* m_ptr;
};
