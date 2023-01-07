#pragma once

#include "templates/Container/Container.hpp"

namespace Epp {
namespace templates {

template<class E>
class List: public Container<E> {

EPP_CLASS_INFO

protected:
	template<class F>
	class Node {
	public:
		Node *past = nullptr;
		Node *next = nullptr;
		E element;

	public:
		Node() {

		}

		~Node() {
			if (this->past == this || this->next == this) {
				// 头节点，无需处理连接关系
			} else {
				// 如果此节点非头节点，在被析构时自动处理其前后节点的连接关系
				this->past->next = this->next;
				this->next->past = this->past;
			}
		}

		Node(const E &e) :
				Node(this, this, e) {

		}

		Node(Node *past, Node *next, const E &e) {
			this->past = past;
			this->next = next;

			this->element = e;
		}
	};

protected:
	Node<E> *head = nullptr;

public:
	List() {

	}

	virtual ~List() {

	}

protected:
	Node<E>* getNode(u64 index) const {
		Node<E> *p = this->head;

		if (index < this->n / 2) {
			for (u64 i = 0; i < index; i++) {
				p = p->next;
			}
		} else {
			for (u64 i = 0; i < this->n - index; i++) {
				p = p->past;
			}
		}
		return p;
	}

public:
	void setHead(u64 index) {
		if (this->checkIndex(index) == false) {
			return;
		}

		this->head = getNode(index);
	}

public:
	virtual const E& getElement(u64 index) const {
		if (this->checkIndex(index) == false) {
			return this->getFirst();
		}

		return this->getNode(index)->element;
	}

	virtual void setElement(u64 index, const E &e) const {
		if (this->checkIndex(index) == false) {
			return;
		}

		this->getNode(index)->element = e;
	}

public:
	virtual void addElement(const E &e) override {
		if (this->head == nullptr) {	// 特殊情况，头节点为空
			this->head = new Node<E>(e);
		} else {	// 一般情况
			Node<E> *newNode = new Node<E>(this->head->past, this->head, e);

			this->head->past->next = newNode;
			this->head->past = newNode;
		}

		this->n++;
	}

	virtual void deleteElement(u64 index) override {
		if (this->checkIndex(index) == false) {
			return;
		}

		if (index == 0) {	// 特殊情况，删除头节点
			if (this->n == 1) {	// 链表只有一个节点
				SafeDelete(this->head);
			} else {
				this->head = this->head->next;
				Delete(this->head->past);
			}
		} else {	// 一般情况
			Delete(this->getNode(index));
		}

		this->n--;
	}

	virtual void updateElement(u64 index, const E &e) override {
		if (this->checkIndex(index) == false) {
			return;
		}

		this->getNode(index)->element = e;
	}

public:
	virtual void insertElement(u64 index, const E &e, bool rear = true) override { //默认在元素后方插入
		if (this->checkIndex(index) == false) {
			return;
		}

		Node<E> *p = this->getNode(index);

		if (rear == true) {	// 在后方插入
			Node<E> *newNode = new Node<E>(p, p->next, e);

			p->next->past = newNode;
			p->next = newNode;
		} else {
			Node<E> *newNode = new Node<E>(p->past, p, e);

			p->past->next = newNode;
			p->past = newNode;
		}

		this->n++;
	}
};

template<class E>
const base::Class *List<E>::ClassInfo = base::Class::Register<List<E>, Container<E>>("Epp::templates::List<E>", nullptr);

}
}

