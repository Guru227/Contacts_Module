 objects = interface.o prompts.o functions.o implementations.o
 call_module : $(objects)
	gcc -o call_module $(objects)
	
interface.o : interface_headers.h
prompts.o : prompts_headers.h
functions.o : functions_headers.h
implementations.o : implementations_headers.h

.PHONY : clean cleanall
clean : 
	-rm $(objects)
cleanall :
	-rm call_module $(objects)
