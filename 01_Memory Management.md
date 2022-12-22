# Memory Management
To understand the concept of pointer, one should have a brief knowledge of memory organization implemented by the Operating Systems. Memory is used to store instructions and data. The memory is organized in hierachical way to trade off between size and speed of execution.
### Memory Classification
| Type | Size | Speed | Nature |
| ---- | ---- | ----- | ------ |
| Registers | 32 / 64 bits | very fast | volatile |
| Cache | few KBs | faster | volatile |
| RAM | in MB / few GBs | fast | volatile |
| Secondary Storage | in GBs / TBs | slow | non volatile |

1. **Registers :** <br>
These are the most basic and first data storing elements found in the processor (Register bank) made up of flip flops. They are 32 / 64 / 128 such registers depending on the architecture implemented. They are very fast and have response time of few nano seconds only (generally less than 10ns).
2. **Cache :** <br>
They are an intermediate level of of memory between registers and RAM. This memory structure is accessed frequently while executing any program. This cache can be further divided into hierarchical divisions - L1, L2, .... The response time is few 10s of ns (generally 10 - 50 ns).
3. **RAM :** <br>
It is the primary memory, also at times referred as physical memory, where all the data and instructions to be executed are stored. The operating system maintains and handles processes. The size of RAM dictates the size of softwares a system can handle. The respone time is few 100ns.
4. **Secondary Storage :** <br>
This is a non volatile storage that stores all the data and software instructions permanently. The response time is very slow (generally few ms). Any program saved in this memory is copied into main memory first before starting the execution.<br>
![Memory hierarchy](/Resources/Images/memory_classification.jpg)<br>
*image source: ReseachGate, Paper - Emerging NVM: A Survey on Architectural Integration and Research Challenges (January 2018-ACM Transactions on Design Automation of Electronic Systems 23(2), DOI:10.1145/3131848)*
### Cache Memory
Increasing the size of main memory also increased the response time which affected the speed of execution adversely. A solution to this problem is use of intermediate memory called the cache memory that has faster response time than RAM and larger storage space than registers. This acts as the bridge. A cache of N line address bus has 0 to 2<sup>N -1</sup>  address locations, each line holding K bytes (generally word size). The cache divides the antire available address spaceinto M blocks.<br>
Capacity C = M * K bytes, M = 2<sup>N</sup> / K <br>
If the data requested by the process is found in the cache it is called *Cache hit* and if it is not found it is called *Cache miss*. In case of a cache miss in L1 cache, the requested data is looked for in L2 cache and so on. If found in L2 cache, then that chache line (K bytes are copied). The OS does this efficiently as if data requested was i<sup>th</sup> element of the array, the OS would even copy other array elements. If the data is not found in the cache but in the main memory in case of cache miss, an entire page is copied.
## Complilation Process Chain
Compilation is a sequential process where output of one stage is fed as input to next stage. The output is an executable recognized by the operating systems. (eg. Linux recognizes ELF[Executable and Linker format])

The compliation process chain is as follows : <br>
*Source-code -> Preprocessing -> Compilation -> Assembler -> Object-file -> Linker -> Executable* <br>
**Preprocessing :** process of expanding macros, inclusion of header files, etc.<br>
**Compilation :** converting preprocessed file into assembly code. It also performs lexical analysis, syntax analysis, code generation, etc.<br>
**Assembler :** converting assembly code into object code (not to be confused with machine code). Address resolution for external functions(eg. printf(), scanf(), ...), part of some library, is not a part of this step.<br>
**Linker :** it resolves address of external functions used from different libraries. It basically takes multiple object codes and generates a single executable file in the format understood by the Operating System.

The loader (part of operating system) is responsible for loading executable from disk into main memory. Major tasks performed are : <br>
- Validation<br>
- Copying executables from disk to main memory<br>
- Setting up stack<br>
- Setting up registers<br>
- Jumping to program's entry point (main() function)<br>

## Memory Models
The process accesses the memory uding the underlying memory model employed by the hardware architecture.
#### Real Address Mode Memory Model
This memory model is an operating mode of all x86 compatible CPUs. This mode is characterized by 20 bit segmented address spaces as only 16 bit address bus was available. The segmentation is achieved shifting 4 bits of segment register and adding 16 bit offset which formed the 20 bit address
#### Flat Memory Model
In 80386 and succceeding processors, special memory management registers are provided to facilitate sophisticated memory management. They are namely : group descriptor table register **(GDTR)**, load descriptor table register **(LDTR)** and **task register**. The memory appears contiguous to the program. The linear address space contains code segment, data segment, etc while logical address space generated by  the program is used to select an entry in global descriptor table and adds the corresponding address offset. This memory model provides fastest code execution and simple system configuration.
#### Segmented Memory Model
In this memory mode, the linear address space is divided into small parts called *segments*. Code, data and stacks are placed in different segments. A process relies on logical address to access dat from any segment. The processor translates logical address into linear address and uses it to access the memory. This helps prevent corruption of stack and overwriting by other processes. Segmentation is used to achieve *multiprogramming, memory protection and dynamic relocation*.<br>
![Memory models](/Resources/Images/memory_models.jpg)<br>
*image source: fig 1-13. Poniters in C, A hands on approach*
## Memory Layout
A source code after compilation is segregated into 5 main sections:<br>
**1. Code Segment :** This segment consists of instruction codes and is shared among several processes running the same binary. It usually has the read and execute permissions.<br>
**2. Data Segment :** This segment contains global and statically allocated variables initialized with non zero values.<br>
**3. Uninitialized / Block Started by Symbol (BSS) :** It includes all the global as well as local static uninitialized variables. All such variables are 0 by default.This segment doesn't  take up any actual space in object file.<br>
**4. Stack Segment :** It is used to store local variables function parameters and return address.<br>
**5. Heap Segment :** This area is allocated to each process by the OS when the process is created. Dynamic memory is obtained from heap with help of malloc(), callooc() and realloc() function calls. This memory can be accessed only through pointers. if not kept track of properly it leads to memory leaks.<br>
![Memory layout](/Resources/Images/memory_layout.jpg)<br>
*image source: fig 1-14. Poniters in C, A hands on approach*
#### Process of a Function Call
When a function call is made the OS performs a lot of steps in the background.<br>
- allocates a stack frame / activation record for respective function call at runtime and pushes parameters into the stack.<br>
- call the function, the new function parameters are set and then its execution is started.
- once execution is completed return from function is possible by accessing the pointer that saved the calling address. All the old parameters are retreived from stack.
## Virtual Memory Organization
Multiprogramming enables many processes to execute concurrently at any given time. This is enabled by hardware and OS by optimal use of system resources. Many processes share the main memory however each process sees complete memory as a resource dedicated to itself even though only a portion a program is cureently being executed. The key features of virtual memory are :<br>
1. Physical organization<br>
2. Logical organization<br>
3. Protection<br>
4. Relocation<br>
5. Sharing<br>
### Address Spaces
The memory space is shared between two entities, the kernel / OS and the user program.<br>
**- Virtual Address Space :** Virtual memory is a logical entity where user process assumes that entire process is loaded. It consists of virtual page number and page offset field.<br>
**- Physical Address Space :** This is the actual address in the main memory where pages are loaded. The physical page number is obtained after address translation of virtual page number.<br>
![Address translation](/Resources/Images/address_translation.jpg)<br>
*image source: fig 1-18. Poniters in C, A hands on approach*
### Paging
The technique of paging allows the OS to load and unload parts of process in any non-contiguous location of physical memory. The main memory is divided into equal and fixed size frames / pages which is capable of storing pages of any process. They are typically fixed size (1 kb / 4kb) partitions of processes. Paging addresses following tasks : <br>
* Address Space Management : optimized and efficient allocation and management of address space of the process.<br>
* Address Translation : done using specific hardware, also takes cares of page faults.<br>
* Memory Sharing : multiple processes can be run together in same memory space.

A separate page table is maintained for each process being executed that keeps track of pages and their respective physical memory addresses. It also deals with exception handling in case of page faults.<br>
![Paging](/Resources/Images/paging.jpg)<br>
*image source: fig 1-19. Poniters in C, A hands on approach*
