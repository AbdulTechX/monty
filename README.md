# 0x19. C - Stacks, Queues - LIFO, FIFO
 about this project we created a  Monty bytecode Interpreter. The interpreter that reads a bytecode file and executes the bytecode commands.

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

### Monty Interpreter
Welcome to the Monty Bytecode Interpreter. This interpreter was built in the C language and is compliant with ISO90, ISO99, & ISO11. It reads Monty bytecode files of any extension (preferably .m although it doesn't matter), and interprets the opcodes contained.

Our interpreter can be run as either a stack (LIFO) or queue (FIFO). Mode can be switched mid-script. The interpreter can handle a variety of Monty opcodes, including printing, mathematical operations, and more - all handled opcodes are listed below.

#### Installing and Using

   Clone the repository into a new directory:
        $ git clone https://github.com/AbdulTechX/monty.git
##### Compilation & Output

    Your code will be compiled this way:

        $ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

######  Monty Opcodes

* push
    * Usage: push <int>
    * Pushes an element to the stack.
    * The parameter <int> must be an integer.
* pall
    * prints all values in the stack/queue, starting form the top.
* pint
    * prints the top value of the stack/queue.
* pop
    * removes the top element of the stack/queue.
* swap
    * swaps the two top element of the stack/queue
* nod 
    * does nothing
* add
    * adds the top two elements of the stack/queue.
    * The result is stored in the second element from the top and the top
       element is popped.
* sub
    * Subtracts the top element of the stack/queue from the second element
      form the top.
    * The result is stored in the second element from top and the top element
      is removed.


* mul
    * Multiplies the top two elements of the stack/queue.
    * The result is stored in the second element from the top and the
      top element is removed.
*  div
    * Divides the second element from the top of the stack/queue by the 
      top element.
    * The result is stored in the second element from the top and the
      top element is removed.
* mod
        Computes the modulus of the second element from the top of the stack/queue divided by the top element.
        The result is stored in the second element from the top and the top element is removed.

*  pchar
        Prints the character value of the top element of the stack/queue.
        The integer at the top is treated as an ASCII value.

*  pstr
        Prints the string contained in the stack/queue.
        Prints characters element by element until the stack/queue is empty, a value is 0, or an error occurs.

*  rotl
        Rotates the top element of the stack/queue to the bottom.

*   rotr
        Rotates the bottom element of the stack/queue to the top.
*   stack
        Switches a queue to stack mode.

*  queue
        Switches a stack to queue mode.

▶️ Opcodes preceeded by a # are treated as comments and the corresponding line is ignored.

▶️ Lines can be empty and can contain any number of spaces before or after an opcode and its argument (only the first opcode and/or argument is taken into account).
###### Authors

* Abdulazeez Buhari
