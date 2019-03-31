#include <iostream>
#include <cstdio>
#include <cstdlib>

#define myType int
#define nullptr 0

enum SPEC_CONST
{
	NILL = 0,  
	CAN_DEF = 234
};

std::string DUMP[] = 
{
	"Can't find stack, something went wrong!",
	"Can't find data in stack!",
	"Wrong current position(below zero)!",
	"Current position higher then data_size!",
	"Canary died!",
	"Reallocation of additional memory failed!",
	"Reallocation of odd memory failed!",
	"StackPush failed!",
	"StackPop failed!"
};

class Stack
{
	private:

		myType canary1;
		int data_size_;
		myType * data_;
		int current_position;
		int my_errno;
		myType hash;
		myType canary2;

	public:	
	

		Stack(int size)
		{

                        canary1 = CAN_DEF;
                        current_position = NILL;
                        hash = NILL;
                        canary2 = CAN_DEF;
			my_errno = 0;
			data_size_ = size;
			data_ = (myType *)calloc(size, sizeof(myType) + 2); // new
		       	data_[0] = CAN_DEF;
			data_[size + 1] = CAN_DEF;


		}
		~Stack()
		{
			for(int i = 0; i < data_size_ + 2; i++)
				data_[i] = 0;
			free(data_); // delete
			std::cout << "Data became free successfully!"<< std::endl;
		}
		void StackPush(myType element)
		{
			StackOk();
			StackDump();
			hash = StackHash();
                        current_position++;
                        data_[current_position] = element;
			if(hash == StackHash() && element != 0)
			{
				StackOk();
				my_errno |= 128;//"StackPush failed!"
				StackDump();
			}
			StackOk();
			StackRealloc();
			StackDump();
			
		}
		myType StackPop()
		{ 
			StackOk();
			StackDump();
			hash = StackHash();
			myType element = data_[current_position];
			data_[current_position] = 0;
			current_position--;
			if(hash == StackHash() && element != 0)
			{
				StackOk();
				my_errno |= 256;//"StackPop failed!"
				StackDump();
			}
			StackOk();
			StackRealloc();
			StackDump();
			return element;
		}
		myType StackTop()
		{
			return data_[current_position];
		}
		int StackOk() // cleans my_errno before checking
		{
			my_errno = 0;
			if(this == nullptr)
			{
				std::cout << "Can't find stack, something went wrong!" << std::endl;
				my_errno |= 1;
				return my_errno;
			}		
			if((this -> data_) == nullptr)
			{
                                std::cout << "Can't find data in stack!" << std::endl;
				my_errno |= 2;
				return my_errno;
                        }
			if((this -> current_position) < 0)
                        {
                                std::cout << "Wrong current position(below zero)!" << std::endl;
                                my_errno |= 4;
				return my_errno;
                        }
			if((this -> current_position) >= (this -> data_size_))
                        {
                                std::cout << "Current position higher then data_size!" << std::endl;
                                my_errno |= 8;
				return my_errno;
                        }
			if((this -> canary1) != CAN_DEF || (this -> canary2) != CAN_DEF || (this -> data_[0]) != CAN_DEF || (this -> data_[data_size_ + 1]) != CAN_DEF)
			{
				std::cout << "Canary died!" << std::endl;
                                my_errno |= 16;
				return my_errno;
			}

			if(my_errno = 0)
				return my_errno;
		}
		void StackDump()////////////////
		{
			int j = 0;
			if(my_errno != 0)
			{
				while(my_errno > 0)
				{
					if(my_errno % 2 != 0)	
						std::cout << DUMP[j]  << std::endl;
					my_errno /= 2;
					j++;
				}
			}
		}
		void StackRealloc()
		{
			/*myType* info = nullptr;
			if(current_position >= data_size_ / 2)
			{
				if((info = (myType*)realloc(data_, 2 * data_size_)) == nullptr)
				{
					std::cout << "Reallocation of additional memory failed!" << std::endl;
					my_errno |= 32;
				}
				else
				{
					data_ = info;
					data_[data_size_ + 1] = 0;
					data_size_ *= 2;	
					data_[data_size_ + 1] = canary2;
					StackPrint();
					std::cout << "Reallocation increased memory successfully, size of data right now is " << data_size_ << std::endl;
				}	
			}
			if(current_position <= data_size_ / 8)
                        {
                                if((info = (myType*)realloc(data_, data_size_ / 2)) == nullptr)
				{
                                        std::cout << "Reallocation of odd memory failed!" << std::endl;
					my_errno |= 64;
				}
                                else
                                {
                             		data_ = info;
                                        data_size_ /= 2;
                                        data_[data_size_ + 1] = canary2;
					StackPrint();
                                        std::cout << "Reallocation decreased memory successfully, size of data right now is " << data_size_ << std::endl;
                                }
                        }*/
		}

		// too easy
		myType StackHash()
		{
			int i = 0;
			myType sum = 0;
			for(i = 1; i < data_size_ + 1; i++)
				sum += myType(i) * data_[i];
			return sum;
		}

		void StackPrint()
		{
			int i = 0;
			std::cout << "Stack: ";
			for(i = 0; i < data_size_ + 2; i++)
			{
				std::cout << "data[" << &data_[i] << "] = " << data_[i] << " " << std::endl;
			}
			std::cout << "canary1 = " << canary1 << std::endl;
                        std::cout << "canary2 = " << canary2 << std::endl;
                        std::cout << "data = " << data_ << std::endl;
                        std::cout << "current_position = " << canary1 << std::endl;
                        std::cout << "hash = " << Stack::StackHash() << std::endl;
                        std::cout << std::endl;
                        std::cout << std::endl;

		}
};

int main()
{

	Stack stack(10);
	stack.StackPrint();
	stack.StackPush(7);
        stack.StackPush(8);
        myType a = stack.StackPop();
	stack.StackPush(8);
        stack.StackPush(9);
	stack.StackPush(10);
	stack.StackPush(11);
	stack.StackPush(12);
	stack.StackPush(13);
	stack.StackPush(14);
	stack.StackPush(15);
	stack.StackPush(16);
	stack.StackPush(17);
	stack.StackPush(18);
	stack.StackPush(19);
	stack.StackPush(20);
	stack.StackTop();
	stack.StackPop();
	stack.StackPop();
	stack.StackPop();
	stack.StackPop();
	stack.StackPop();
	stack.StackPop();
	myType hash = stack.StackHash();
	std::cout << "Hash-sum of stack = " << hash << std::endl;
	stack.StackPrint();
	stack.~Stack();

	return 0;
}
