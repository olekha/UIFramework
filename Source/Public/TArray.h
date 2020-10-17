#pragma once
#include <vector>
#include "Public/UFTypes.h"

template<typename ElementType>
class TArray
{
	friend class TArray;

public:
	inline TArray(int InSize = 4)
	{
		v.reserve(InSize);
	}

	inline TArray(std::initializer_list<ElementType> list) : v(list)
	{}

	inline TArray(const TArray<ElementType>& Other)
	{
		v(Other);
	}

	inline explicit TArray(TArray<ElementType>&& Other)
	{
		v(Other);
		Other.GetData().Empty();
	}

	inline void Add(ElementType newElem)
	{
		v.push_back(newElem);
	}

	inline void RemoveAt(size_t Index)
	{
		if(!IsValidIndex(Index))
		{
			return;
		}

		v.erase(v.begin() + Index);
	}

	inline void Append(const TArray<ElementType>& Other)
	{
		v.insert(v.end(), Other.GetData().begin(), Other.GetData().end());
	}

	void Empty()
	{
		v.erase();
	}

	inline TArray& operator=(std::initializer_list<ElementType> list)
	{
		v.erase();
		v(list);

		return *this;
	}

	inline TArray& operator=(const TArray<ElementType>& Other)
	{
		if(this != &Other)
		{
			v.erase();
			v(Other);
		}

		return *this;
	}

	inline TArray& operator=(TArray<ElementType>&& Other)
	{
		if (this != &Other)
		{
			v.erase();
			v(Other);
		}

		return *this;
	}

	inline ElementType& operator[](const int index)
	{
		if (index >= v.size())
		{
			exit(0);
		}

		return v[index];
	}

	inline const ElementType& operator[](const int index) const
	{
		if (index >= v.size())
		{
			exit(0);
		}

		return v[index];
	}

	inline bool IsValidIndex(int32 Index) const
	{
		return Index >= 0 && Index < v.size();
	}

	inline size_t Num() const
	{
		return v.size();
	}

protected:

	inline std::vector<ElementType> GetData() const
	{
		return v;
	}

private:
	std::vector<ElementType> v;
};