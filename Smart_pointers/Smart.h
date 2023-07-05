#pragma once

template<class T>
class Unique
{
private:
	T* ptr;
	
public:
	Unique(T* ptr = nullptr) : ptr{ ptr } {}
	Unique(const Unique& copy) = delete;
	~Unique() { reset(); }

public:
	T* get() const { return ptr; }
	T& operator* () const{ return *ptr; }
	T* operator-> () const{ return &ptr; }
	T* release() 
	{ 
		T* temp = ptr;
		ptr = nullptr;
		return temp;
	}
	void reset() 
	{ 
		if (!ptr)
		{
			delete ptr;
			ptr == nullptr;
		}
	}
	Unique& operator= (const Unique& copy) = delete;
	Unique& swap(Unique& arg)
	{
		T* temp = ptr;
		this->ptr = arg.ptr;
		arg.ptr = temp;
		return *this;
	}
};

template<class T>
class Shared
{
private:
	T* ptr;
	size_t* count;

public:
	Shared(T* ptr = nullptr) : ptr{ ptr }, count{ new size_t{1} } {}
	Shared(const Shared& copy)
	{
		count = copy.count;
		++(*count);
		ptr = copy.ptr;
	}
	~Shared() { reset(); }

public:
	T* get() const { return ptr; }
	T& operator* () const { return *ptr; }
	T* operator-> () const { return &ptr; }
	size_t& use_count() { return *count; }
	void reset()
	{
		if (!(--*count))
			delete ptr;
	}
	Shared& operator= (const Shared& copy)
	{
		if (this == copy)
			return *this
		reset();
		count = copy.count;
		++(*count);
		ptr = copy.ptr;
	}
	Shared& swap(Shared& arg)
	{
		T* temp_ptr = ptr;
		size_t* temp_count = count;
		this->ptr = arg.ptr;
		this->count = arg.count;
		arg.ptr = temp_ptr;
		arg.ptr = temp_count;
	}
};