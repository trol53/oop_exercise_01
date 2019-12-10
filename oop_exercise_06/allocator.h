#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "queue.h"
#include <stack>

template<class T, size_t BLOCK_SIZE>
class TAllocator{
    private:
        T* _buffer;
        std::stack<T*> _free;
        size_t last_free;
    public:
        using value_type = T;
	    using pointer = T*;
	    using const_pointer = const T*;
	    using size_type = std::size_t;
        
        TAllocator() noexcept :_buffer(nullptr) {
        }

        ~TAllocator(){
            free (_buffer);
        }

        template <class U>
	    struct rebind {
		    using other = TAllocator<U, BLOCK_SIZE>;
	    };

        T* Allocate(size_t n){ //function for return free pointer
            if (!_buffer){
                _buffer = (T*)malloc(BLOCK_SIZE * sizeof(T));
                FreeStack();
                last_free = BLOCK_SIZE - 1;
            }
            if (n > BLOCK_SIZE) {
                std::cout << "Bad allocate\n";
                return nullptr;
            }
            if (_free.size() == 0){
                std::cout << "bad allocate\n";
                return nullptr;
            }
            _free.pop();
            return _free.top();
        }

        void Deallocate(size_t n){
            free(_free.top());
        }        
    private:
        void FreeStack(){
            for (int i = 0; i < BLOCK_SIZE; i++){
                _free.push(_buffer + i);
            }
        }
};

#endif
