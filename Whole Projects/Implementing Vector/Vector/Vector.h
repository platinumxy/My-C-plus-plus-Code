#pragma once
#include <utility>

template<typename T, int DEFAULTSIZE=2>
class Vector
{
public:
	Vector() {
		ReAlloc(DEFAULTSIZE);
	}

	~Vector() {
		Clear(); // to avoid calling deletion method when vector leaves scope
		::operator delete (Data, MaxSize * sizeof(T)); 
	}

	void PushBack(const T& item) {
		checkForReAlloc();
		Data[UsedSize] = item;
		UsedSize++;
	}
	void PushBack(T&& item) {
		checkForReAlloc();
		Data[UsedSize] = std::move(item);
		UsedSize++;
	}

	template<typename ... Args> // To take unlimited args and construct items inplace 
	T& ExplaceBack(Args&&... args) {
		checkForReAlloc();
		new(&Data[UsedSize]) T(std::forward<Args>(args)...) //using new to construt T in the asssind data type
		return Data[UsedSize++];
	}


	void PopBack() {
		if (UsedSize > 0) {
			UsedSize--;
			Data[UsedSize].~T(); //Manulaly calling delete on all items 
		}
	}

	void Clear() {
		while (UsedSize != 0) PopBack(); 
	}
	size_t Size() const { return MaxSize; }
	size_t Length() const { return UsedSize; }

	const T& operator[](size_t index) const {
		if (index < 0) {
			index = UsedSize - index;
		}

		return Data[index];
	}
	T& operator[](size_t index){
		if (index < 0) {
			index = UsedSize - index;
		}// Accout for negative index (quality of life)

		return Data[index];
	}

private:
	T* Data = nullptr;
	size_t MaxSize = 0;
	size_t UsedSize = 0;

	void checkForReAlloc()
	{
		if (UsedSize >= MaxSize) {
			ReAlloc(MaxSize + (MaxSize / 2));
		}
	}

	void ReAlloc(size_t NewSize) {			
		T* NewDataBlock = (T*)::operator new(NewSize * sizeof(T)); // to contruct 

		size_t size = MaxSize;
		if (NewSize < size) 
			size = NewSize;

		for (size_t i = 0; i < size; i++) 
			NewDataBlock[i] = std::move(Data[i]);

		size_t tmpUsedSize = UsedSize;
		Clear();// call destructors on all items 
		UsedSize = tmpUsedSize; // as Clear resets used size
		::operator delete (Data, MaxSize * sizeof(T)); // to delete the requested size of data
		Data = NewDataBlock;
		MaxSize = NewSize;
	}
	
};