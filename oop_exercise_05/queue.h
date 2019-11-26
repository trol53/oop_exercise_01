// Реализации класса очередь для ЛР №5.
// Савров Никита. Группа М80-207б-18
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <memory>
#include <cstdint>

template <class T>
class Queue {
private:
    struct Item;
    class QueueIterator;
    std::shared_ptr<Item> F_elem;
    int size;
public:
    using value_type = T; 
    Queue() : size(0){
        F_elem = std::make_shared<Item>();
    }
    Queue(const Queue& other){
        size = other.Size();
        F_elem = std::make_shared<Item>();
        std::shared_ptr<Item> tnew = F_elem;
        std::shared_ptr<Item> told = other.F_elem;
        for (int i = 0; i < size; i++, tnew = tnew->next, tnew = told->next){
            tnew->next = std::make_shared<Item>(told->next->value);
            tnew->next->prev = tnew;
        }
        if (size >= 2){
            tnew->next = F_elem;
            F_elem->prev = tnew;
        }
    }
    ~Queue (){
        F_elem = nullptr;
    }
    int Size(){
        return size;
    }
    bool Empty(){
        return size == 0;
    }
    void Push(T val){
        InsertP(F_elem, val);
    }
    void Pop(){
        if (this->Empty()){
            std::cout << "Error: empty\n";
            return;
        }
        Remove(F_elem->next);
    }
    T Top(){
        if (this->Empty()){
            std::cout << "Error: empty\n";
        }
        return F_elem->prev->value;
    }
    QueueIterator Begin() {
        if (this->Empty()){
            return QueueIterator(F_elem, this);
        }
        return QueueIterator(F_elem->next, this);
    }
    QueueIterator End() {
        return QueueIterator (F_elem, this);
    }
    QueueIterator Insert(QueueIterator pos, T val){
        InsertP(pos, this);
        return QueueIterator (pos->prev, this);
    }
    QueueIterator Erase(QueueIterator pos){
        QueueIterator res = pos;
        ++res;
        Remove(pos);
        return res;
    }
    void Print(){
        if (size == 0)
            return;
        std::shared_ptr<Item> tmp = F_elem->next;
        for(int i = 0; i <  size; i++, tmp = tmp->next){
            std::cout << tmp->value;
        }
    }

private:
    struct Item{
        T value;
        std::shared_ptr<Item> next;
        std::shared_ptr<Item> prev;
        Item () : next(nullptr), prev(nullptr){
        }
        Item(T val) : value(val), next(nullptr), prev(nullptr){
        }
    };

    class QueueIterator {
    private:
        std::shared_ptr<Item> item;
        Queue const *Ths;
        friend class Queue;
    public:
        using difference_type = uint32_t;
		using value_type = Queue::value_type;
		using reference = Queue::value_type&;
		using pointer = Queue::value_type*;
		using iterator_category = std::bidirectional_iterator_tag;
        QueueIterator(std::shared_ptr<Item> node, Queue const *ths) : item(node), Ths(ths) {    
        };
        QueueIterator(const QueueIterator& other){
            item = other.item;
            Ths = other.Ths;
        }

        reference operator*(){
            return item->value;
        }
        pointer operator->(){
            return &item->value;
        }

        QueueIterator& operator++(){
            if (Ths->size == 0){
                return *this;
            }
            if (Ths->size == 1 && item == Ths->F_elem->next){
                item = Ths->F_elem;
                return *this;
            }
            item = item->next;
            return *this;
        }
        const QueueIterator operator++(int){
            if (Ths->Size() == 0){
                return *this;
            }
            if (Ths->Size() == 1 && item == Ths->F_elem->next){
                item = Ths->F_elem;
                return *this;
            }
            std::shared_ptr<Item> res = item;
            item = item->next;
            return QueueIterator(res);
        }
        QueueIterator& operator-- (){
            if (Ths->Size() == 0)
                return *this;
            item = item->prev;
            return *this;
        }
        const QueueIterator operator-- (int){
            if (Ths->Size() == 0){
                return *this;
            }
            std::shared_ptr<Item> res = item;
            item = item->prev;
            return QueueIterator(res);
        }
        bool operator != (const QueueIterator& other) const noexcept{
            return item != other.item;
        }
        bool operator== (const QueueIterator& other) const noexcept{
            return item == other.item;
        }
    };

    void EmptyInsert (T val){
        F_elem->next = std::make_shared<Item>(val);
        F_elem->next->prev = F_elem;
        F_elem->prev = F_elem->next;
    }

    void InsertP(std::shared_ptr<Item> node, T val){
        if (size == 0){
            EmptyInsert(val);
            size++;
            return;
        }
        std::shared_ptr<Item> newel = std::make_shared<Item>(val);
        newel->next = node;
        newel->prev = node->prev;
        node->prev->next = newel;
        node->prev = newel;
        size++;
    }

    void Remove (std::shared_ptr<Item> node){
        if (size == 1){
            F_elem->next = nullptr;
        } else {
            if (size == 2){
                if (node->next == F_elem){
                    F_elem->next->next = nullptr;
                    F_elem->prev = F_elem->next;
                } else {
                    node->next->prev = F_elem;
                    F_elem->next = node->next;
                }
                size--;
                return;
            }
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        size--;
    }

};

#endif

