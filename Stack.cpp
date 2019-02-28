#include <iostream>

#define myType int
#define NILL 0
#define CAN_DEF 234

/*enum SPEC_CONST
{
	NILL = 0,
	CAN_DEF = 234
};*/
class Stack
{
	private:

		const myType canary1;
		int data_size;
		const myType * data;
		int current_position;
		myType hash;
		const myType canary2;

	public:	
	

		Stack(int size)
		{

                        canary1 = CAN_DEF;
                        current_position = NILL;
                        hash = NILL;
                        canary2 = CAN_DEF;

			data_size = size;
			data = (myType *)calloc(size, sizeof(myType) + 2);
		       	data[0] = CAN_DEF;
			data[size + 1] = CAN_DEF;


		}
		~Stack()
		{
			for(int i = 0; i < data_size + 2; i++)
				data[i] = NILL;
			free(data);
			std::cout << "Data became free successfully!"<< std::endl;
		}
		int StackPush(const Stack *stk, myType element)
		{
			int err_par = 0;
			if((err_par = StackOk(stk)) != 0)
			{
				std::cout << "Returned error of type \n" << err_par << std::endl;

			}
			current_position++;
			data[current_position] = element;
			return 0;/////////////////////////////////////////////////////////////////////////////////////
		}
		myType StackPop()
		{
			myType element = data[current_position];
			data[current_position] = 0;
			current_position--;
			return element;
		}
		myType StackTop()
		{
			return data[current_position];
		}
		int StackOk(const Stack *stk)
		{
			int my_errno = 0;
			if(str == nullptr)
			{
				std::cout << "Lack of stack \n" << std::endl;
				my_errno |= 1;
			}		
			if((stk -> data) == nullptr)
			{
                                std::cout << "Lack of data \n" << std::endl;
				my_errno |= 2;
                        }
			if((stk -> current_position) < 0)
                        {
                                std::cout << "Wrong current position \n" << std::endl;
                                my_errno |= 4;
                        }
			if((stk -> current_position) > (stk -> data_size))
                        {
                                std::cout << "Current position higher then data_size: ERROR!\n" << std::endl;
                                my_errno |= 8;
                        }
			if((stk -> canary1) != CAN_DEF || (stk -> canary2) != CAN_DEF || (stk -> data[0]) != CAN_DEF || (stk -> data[data_size + 1]) != CAN_DEF)
			{
				std::cout << "Canary died!!!! NONONONONONONONO" << std::endl;
                                my_errno |= 16;
			}
	
			//CONTROL SUMS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			if(my_errno = 0)
			return 0;
		}
		void StackDump()
		{
		
		}
		myType * StackResize()
		{
			if(current_position >= data_size / 2)
			{
				if(realloc(2 * data_size) < 0)//complete realloc
					std::cout << "Reallocation ERROR!!!!" << std::endl;////STACK_DUMP
				else 
					std::cout << "Reallocation happened successfully, size of data right now is " << data_size << std::endl; 
			}
		}
		myType StackHash()
		{
			int i = 0;
			myType sum = 0;
			for(i = 1; i < data_size + 1; i++)
				sum += i * data[i];
			return sum;
		}

		void StackPrint()
		{
			int i = 0;
			std::cout << "Stack: ";
			for(i = 0; i < data_size + 2; i++)
			{
				std::cout << data[i] << " ";
			}
			std::cout << std::endl;

			std::cout << "canary1 = " << canary1 << std::endl;
                        std::cout << "canary2 = " << canary2 << std::endl;
                        std::cout << "data = " << data << std::endl;
                        std::cout << "current_position = " << canary1 << std::endl;
                        std::cout << "hash = " << Stack::StackHash() << std::endl;

		}
};

int main()
{

	Stack stack(10);
	stack.StackPrint();
	stack.StackPush(7);
        stack.StackPush(9);
        myType a = stack.StackPop();
        stack.StackPush(8);
	stack.StackTop();
	myType hash = stack.StackHash();
	std::cout << "Hash-sum of stack = " << hash << std::endl;
	stack.StackPrint();

	return 0;
}
