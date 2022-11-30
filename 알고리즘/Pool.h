#pragma once

#include <queue>
#include <memory>



template <typename T>
class ObjectPool
{
public:
	ObjectPool() = default;
	
	//대입과 값 전달방식을 막음
	ObjectPool(const ObjectPool<T>& src) = delete;
	ObjectPool<T>& operator=(const ObjectPool<T>& rhs) = delete;



	using Object = std::shared_ptr<T>;

	Object acquireObject();
	//사용할 객체를 보관하고 제공



private:
	std::queue<std::unique_ptr<T>> mFreeList;



};

template <typename T>
typename ObjectPool<T>::Object ObjectPool<T>::acquireObject()
{
	if (mFreeList.empty()) {
		mFreeList.emplace(std::make_unique<T>());
	}



	std::unique_ptr<T> obj(std::move(mFreeList.front()));
	mFreeList.pop();




	Object smartObject(obj.release(), [this](T* t) {
		mFreeList.emplace(t);
		});

	return smartObject;

}