#pragma once

#include "templates/Container/Container.hpp"

namespace Epp {
namespace templates {

template<class E>
class Array: public Container<E> {

EPP_CLASS_INFO

private:
	static u64 DefaultCapacity;
	static f32 DefaultGrowthSpeed;

public:
	static u64 GetDefaultCapacity() {
		return DefaultCapacity;
	}

	static void SetDefaultCapacity(u64 capacity) {
		DefaultCapacity = capacity;
	}

	static f32 GetDefaultGrowthSpeed() {
		return DefaultGrowthSpeed;
	}

	static void SetDefaultGrowthSpeed(f32 growthSpeed) {
		DefaultGrowthSpeed = growthSpeed;
	}

private:
	u64 capacity = 0;
	f32 growthSpeed = 0;

private:
	E *data = nullptr;

public:
	Array() :
			Array(DefaultCapacity, DefaultGrowthSpeed) {

	}

	virtual ~Array() {

	}

public:
	Array(u64 capacity) :
			Array(capacity, DefaultGrowthSpeed) {

	}

	Array(u64 capacity, f32 growthSpeed) {
		// 上锁
		setCapacity(capacity);
		this->growthSpeed = growthSpeed;
		// 解锁
	}

public:
	u64 getCapacity() const {
		return this->capacity;
	}

	void setCapacity(u64 capacity) {
		if (capacity == getCapacity()) {
			return;
		} else {
			if (capacity < this->getN()) {	// 特殊情况
				return;
			}

			// 创建临时数据空间
			E *tempData = new E[capacity];

			// 上锁
			// 复制内容
			if (this->data != nullptr and this->getN() > 0) {
				Copy(this->data, tempData, this->getN());	// 仅使用内存复制，不调用复制构造函数
			}

			// 交换内存空间
			Swap(this->data, tempData);

			// 重设数组容量
			this->capacity = capacity;

			// 解锁

			// 删除临时数据
			SafeDelete(tempData, true);
		}
	}

public:
	f32 getGrowthSpeed() const {
		return this->growthSpeed;
	}

	void setGrowthSpeed(f32 growthSpeed) {
		if (growthSpeed <= 1.0) {
			base::Exception("Array growth rate cannot be negative");
		}

		this->growthSpeed = growthSpeed;
	}

private:
	void tryGrow() {
		this->setCapacity(this->getCapacity() * this->getGrowthSpeed());
	}

	void tryNarrow() {
		if (2 * this->getN() < this->getCapacity()) {
			this->setCapacity(this->getN() * 2);
		}
	}

public:
	virtual const E& getElement(u64 index) const override {
		if (index >= this->getN()) {
			base::Exception("Illegal parameter");
		}

		return this->data[index];
	}

	virtual void setElement(u64 index, const E &e) const override {
		if (index >= this->getN()) {
			base::Exception("Illegal parameter");
		}

		this->data[index] = e;
	}

public:
	virtual void addElement(const E &e) override {
		if (this->getN() == this->getCapacity()) {
			tryGrow();
		}

		this->data[this->n] = e;
		this->n++;
	}

	virtual void deleteElement(u64 index) override {
		if (index >= this->getN()) {
			base::Exception("Illegal parameter");
		}

		for (u64 i = index; i < this->n - 1; i++) {
			this->data[i] = this->data[i + 1];
		}

		this->n--;
	}

	virtual void updateElement(u64 index, const E &e) override {
		if (index >= this->getN()) {
			base::Exception("Illegal parameter");
		}

		this->data[index] = e;
	}

	virtual u64 searchElement(const E &e) override {
		const void *p = &e;
		(void) p;
		for (u64 i = 0; i < this->getN(); i++) {
//			if (e == this->getElement(i)) {
//				return i;
//			}
			break;
		}

		base::Exception("Search completed but no matching results");
		return -1;
	}

public:
	virtual u64 searchElement(bool (*customizedCompareFunc)(E &e1, E &e2), E &e) override {
		const void *p = &e;
		(void) p;
		if (customizedCompareFunc == nullptr) {
			base::Exception("Illegal parameter");
		}

		for (u64 i = 0; i < this->getN(); i++) {
//			if (customizedCompareFunc(this->getElement(i), e) == true) {
//				return i;
//			}
			break;
		}

		base::Exception("Search completed but no matching results");
		return -1;
	}

};

template<class E>
const base::Class *Array<E>::ClassInfo = base::Class::Register<Array<E>, Container<E>>("Epp::templates::Array<E>", nullptr);

template<class E>
u64 Array<E>::DefaultCapacity = 100;

template<class E>
f32 Array<E>::DefaultGrowthSpeed = 2.0;

}
}

